/*
 * Copyright (c) 2012 Loïc Marchand - loic.marchand73@gmail.com
 *
 * This software is provided 'as-is', without any express or implied warranty. In no event will
 * the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose, including commercial applications,
 * and to alter it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original
 * software. If you use this software in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original
 * software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include "Data.hpp"
#include <iostream>
#include <string>
#include "Utils.hpp"
#include "base64/base64.h"

namespace TMX
{

    // See header file.
    Data::Data( void ) :
        m_encoding( Xml ),
        m_compression( None )
    {

    }

    // See header file.
    Data::Data( TiXmlNode* dataNode ) :
        m_encoding( Xml ),
        m_compression( None )
    {
        TiXmlElement* datatElt = dataNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = datatElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "encoding" )
            {
                if( std::string( attribute->Value() ) == "csv" )
                    m_encoding = Csv;
                else if( std::string( attribute->Value() ) == "base64")
                    m_encoding = Base64;
            }
            else if( name == "compression" )
            {
                if( std::string( attribute->Value() ) == "gzip" )
                    m_compression = Gzip;
                else if( std::string( attribute->Value() ) == "zlib")
                    m_compression = Zlib;
                else
                    std::cerr << "Invalid data compression" << std::endl;
            }
            else
                std::cerr << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        TiXmlNode* currentDataNode = datatElt->FirstChild();
        if( m_encoding == Xml )
        {
            // Browse all node
            while( currentDataNode )
            {
                if( currentDataNode->Type() == TiXmlNode::TINYXML_ELEMENT )
                {
                    if( std::string( currentDataNode->Value() ) == "tile" )
                        push_back( Tile( currentDataNode ) );
                }
                currentDataNode = currentDataNode->NextSibling();
            }
        }
        else if( m_encoding == Csv )
            parsingCSVDatas( currentDataNode->Value() );
        else if( m_encoding == Base64 )
            parsingBase64Datas( currentDataNode->Value() );
    }

    // See header file.
    void Data::parsingCSVDatas( const std::string& datas )
    {
        std::string dataBuffer;
        std::stringstream ss( datas );

        while( std::getline( ss, dataBuffer, ',' ) )
            push_back( Tile( fromString< int >( dataBuffer ) ) );
    }

    // See header file.
    void Data::parsingBase64Datas( const std::string& datas )
    {
        static const unsigned FLIPPED_HORIZONTALLY_FLAG = 0x80000000;
        static const unsigned FLIPPED_VERTICALLY_FLAG   = 0x40000000;
        static const unsigned FLIPPED_DIAGONALLY_FLAG   = 0x20000000;

        std::string decodedDatas = base64_decode( datas );

        // Preparing the data
        const size_t n = decodedDatas.size();
        unsigned char* data = new unsigned char[n];
        memcpy( data, decodedDatas.c_str(), n);
        unsigned id = 0;

        // Parsing data to extract tiles
        for (unsigned i = 0; i < n; i+=4)
        {
            id = data[i] |
                 data[i + 1] << 8 |
                 data[i + 2] << 16 |
                 data[i + 3] << 24;

            // Clear the flags
            id &= ~(FLIPPED_HORIZONTALLY_FLAG |
                    FLIPPED_VERTICALLY_FLAG |
                    FLIPPED_DIAGONALLY_FLAG);

            push_back( Tile( id ) );
        }
    }

    // See header file.
    void Data::printToStream( std::ostream &stream ) const
    {
        stream << "#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        stream << "# Data :" << std::endl;
        stream << "# encoding : ";
        if( m_encoding == Xml )
            stream << "XML";
        else if( m_encoding == Csv )
            stream << "CSV";
        if( m_encoding == Base64 )
            stream << "Base 64";
        stream << std::endl << "# compression : ";
        if( m_compression == None )
            stream << "none";
        else if( m_compression == Zlib )
            stream << "ZLib";
        if( m_compression == Gzip )
            stream << "GZip";
        stream << std::endl;

        for( auto tileIt = begin(); tileIt != end(); ++tileIt )
            tileIt->printToStream( stream );

        stream << "#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
    }

} // end namespace TMX
