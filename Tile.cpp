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

#include "Tile.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    Tile::Tile( void ) : m_id( 0 )
    {

    }

    // See header file.
    Tile::Tile( unsigned int id ) : m_id( id )
    {

    }

    // See header file.
    Tile::Tile( TiXmlNode* tileNode ) : m_id( 0 )
    {
        TiXmlElement* tileElt = tileNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = tileElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "gid" || name == "id" )
                m_id = attribute->IntValue();
            else
                std::cerr << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        // Browse all node
        TiXmlNode* currentTileNode = tileElt->FirstChild();
        while( currentTileNode )
        {
            if( currentTileNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                if( std::string( currentTileNode->Value() ) == "properties" )
                    m_properties = Properties( currentTileNode );
                /*else if( std::string( currentTilesetNode->Value() ) == "image" )
                    m_image = Image( currentTilesetNode );*/
            }
            currentTileNode = currentTileNode->NextSibling();
        }
    }

    // See header file.
    void Tile::printToStream( std::ostream& stream ) const
    {
        stream << "#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
        stream << "# Tile: " << m_id << std::endl;

        m_properties.printToStream( stream );

        stream << "#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;

    }

} // end namespace TMX
