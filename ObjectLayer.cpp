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

#include "ObjectLayer.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    ObjectLayer::ObjectLayer( TiXmlNode* objectLayerNode ) :
        m_name( "" ),
        m_x( 0 ),
        m_y( 0 ),
        m_width( 0 ),
        m_height( 0 )
    {
        TiXmlElement* objectLayerElt = objectLayerNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = objectLayerElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if (name == "name")
                m_name = attribute->Value();
            else if (name == "x")
                m_x = attribute->IntValue();
            else if (name == "y")
                m_y = attribute->IntValue();
            else if (name == "width")
                m_width = attribute->IntValue();
            else if (name == "height")
                m_height = attribute->IntValue();
            else
                std::cout << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        // Browse all node
        TiXmlNode* currentObjectLayerNode = objectLayerElt->FirstChild();
        while( currentObjectLayerNode )
        {
            if( currentObjectLayerNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                if( std::string( currentObjectLayerNode->Value() ) == "properties" )
                    m_properties = Properties( currentObjectLayerNode );
                else if( std::string( currentObjectLayerNode->Value() ) == "object" )
                    push_back( Object( currentObjectLayerNode ) );
            }
            currentObjectLayerNode = currentObjectLayerNode->NextSibling();
        }
    }

    // See header file.
    ObjectLayer::~ObjectLayer( void )
    {

    }

    // See header file.
    void ObjectLayer::printToStream( std::ostream& stream ) const
    {
        stream << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        stream << "# ObjectLayer:" << std::endl;
        stream << "# Name: " << m_name << std::endl;
        stream << "# Width: " << m_width << std::endl;
        stream << "# Height: " << m_height << std::endl;

        m_properties.printToStream( stream );

        stream << "# -Objects: " << std::endl;

        for( auto objectIt = begin(); objectIt != end(); ++objectIt )
            objectIt->printToStream( stream );

        stream << "#" << std::endl;
        stream << "#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    }

} // end namespace TMX
