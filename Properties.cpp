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

#include "Properties.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    Properties::Properties( void )
    {

    }

    // See header file.
    Properties::Properties( TiXmlNode* propertiesNode )
    {
        TiXmlElement* propertiesElt = propertiesNode->ToElement(); // convert to element

        // Browse all node
        TiXmlNode* currentPropertiesNode = propertiesElt->FirstChild();
        while( currentPropertiesNode )
        {
            if( currentPropertiesNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                TiXmlAttribute* attribute = currentPropertiesNode->ToElement()->FirstAttribute(); // Get first attribute
                Property newProperty;
                while( attribute ) // browse all attribute
                {
                    std::string name  = attribute->Name(); // Get attribute name

                    if( name == "name" )
                        newProperty.first = attribute->Value();
                    else if (name == "value")
                        newProperty.second = attribute->Value();
                    else
                        std::cerr << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

                    attribute = attribute->Next(); // Next attribute
                }
                insert( newProperty );
            }
            currentPropertiesNode = currentPropertiesNode->NextSibling();
        }
    }

    // See header file.
    void Properties::printToStream( std::ostream& stream ) const
    {
        if( !empty() )
        {
            stream << "#++++++++++++++++++++++++++++++++" << std::endl;
            stream << "# Properties: " << std::endl;
            for( auto property : *this )
                stream << "# " << property.first << ": " << property.second << std::endl;
            stream << "#++++++++++++++++++++++++++++++++" << std::endl;
        }
    }

} // end namespace TMX
