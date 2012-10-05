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

#include "Object.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    Object::Object( TiXmlNode *objectNode ) :
        m_name( "" ),
        m_type( "" ),
        m_x( 0 ),
        m_y( 0 ),
        m_width( 0 ),
        m_height( 0 ),
        m_gid( 0 ),
        m_visible( true )
    {
        TiXmlElement* objectElt = objectNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = objectElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "name" )
                m_name = attribute->Value();
            else if( name == "type" )
                m_type = attribute->Value();
            else if (name == "x")
                m_x = attribute->IntValue();
            else if(name == "y")
                m_y = attribute->IntValue();
            else if( name == "width" )
                m_width = attribute->IntValue();
            else if( name == "height" )
                m_height = attribute->IntValue();
            else if( name == "gid" )
                m_gid = attribute->IntValue();
            else if( name == "visible" )
                m_visible = attribute->IntValue();
            else
                std::cerr << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        // Browse all node
        TiXmlNode* currentObjectNode = objectElt->FirstChild();
        while( currentObjectNode )
        {
            if( currentObjectNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                if( std::string( currentObjectNode->Value() ) == "properties" )
                    m_properties = Properties( currentObjectNode );
                /*else if( std::string( currentObjectNode->Value() ) == "image" )
                    m_image = Image( currentObjectNode );
                else if( std::string( currentObjectNode->Value() ) == "tileoffset" )
                    m_offset = TileOffset( currentObjectNode );
                else if( std::string( currentObjectNode->Value() ) == "tile" )
                    push_back( Tile( currentObjectNode ) );*/
            }
            currentObjectNode = currentObjectNode->NextSibling();
        }
    }

    // See header file.
    void Object::printToStream( std::ostream& stream ) const
    {
        stream << "#--------------------------------" << std::endl;
        stream << "# Object:" << m_name << std::endl;
        stream << "# Type: " << m_type << std::endl;
        stream << "# Position: " << m_x << "," << m_y << std::endl;
        stream << "# Dim.: " << m_width << "x" << m_height << std::endl;
        stream << "# Gid: " << m_gid << std::endl;
        stream << "# Is visible: " << m_visible << std::endl;

        m_properties.printToStream( stream );

        stream << "#--------------------------------" << std::endl;
    }

} // end namespace TMX
