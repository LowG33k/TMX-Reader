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

#include "Tileset.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    Tileset::Tileset( TiXmlNode* tilesetNode ) :
        m_firstGlobalId( 0 ),
        m_sourcePath( "" ),
        m_name( "" ),
        m_tileWidth( 0 ),
        m_tileHeight( 0 ),
        m_spacing( 0 ),
        m_margin( 0 ),
        m_image()
    {
        TiXmlElement* tilesetElt = tilesetNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = tilesetElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "firstgid" )
                m_firstGlobalId = attribute->IntValue();
            else if (name == "source")
                m_sourcePath = attribute->Value();
            else if (name == "name")
                m_name = attribute->Value();
            else if (name == "tilewidth")
                m_tileWidth = attribute->IntValue();
            else if (name == "tileheight")
                m_tileHeight = attribute->IntValue();
            else if (name == "spacing")
                m_spacing = attribute->IntValue();
            else if (name == "margin")
                m_margin = attribute->IntValue();
            else
                std::cerr << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        // Browse all node
        TiXmlNode* currentTilesetNode = tilesetElt->FirstChild();
        while( currentTilesetNode )
        {
            if( currentTilesetNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                if( std::string( currentTilesetNode->Value() ) == "properties" )
                    m_properties = Properties( currentTilesetNode );
                else if( std::string( currentTilesetNode->Value() ) == "image" )
                    m_image = Image( currentTilesetNode );
                else if( std::string( currentTilesetNode->Value() ) == "tileoffset" )
                    m_offset = TileOffset( currentTilesetNode );
                else if( std::string( currentTilesetNode->Value() ) == "tile" )
                    push_back( Tile( currentTilesetNode ) );
            }
            currentTilesetNode = currentTilesetNode->NextSibling();
        }//*/

        //if( !m_sourcePath.empty() )
            //load( m_sourcePath );
    }

    // See header file.
    void Tileset::printToStream( std::ostream& stream ) const
    {
        stream << "#--------------------------------" << std::endl;
        stream << "# Tileset:" << std::endl;
        stream << "# First global Id: " << m_firstGlobalId << std::endl;
        stream << "# Source: " << m_sourcePath << std::endl;
        stream << "# Name: " << m_name << std::endl;
        stream << "# Tile size: " << m_tileWidth << "x" << m_tileHeight << std::endl;
        stream << "# Spacing: " << m_spacing << std::endl;
        stream << "# Margin: " << m_margin << std::endl;

        m_properties.printToStream( stream );
        m_image.printToStream( stream);
        m_offset.printToStream( stream );

        stream << "# -Tiles: " << std::endl;

        for( auto tileIt = begin(); tileIt != end(); ++tileIt )
            tileIt->printToStream( stream );

        stream << "#" << std::endl;
        stream << "#--------------------------------" << std::endl;
    }

} // end namespace TMX
