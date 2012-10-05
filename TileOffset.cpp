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

#include "TileOffset.hpp"
#include <iostream>

namespace TMX
{
    // See header file.
    TileOffset::TileOffset( void ) : m_x( 0 ), m_y( 0 )
    {

    }

    // See header file.
    TileOffset::TileOffset( TiXmlNode *tileOffsetNode ) : m_x( 0 ), m_y( 0 )
    {
        TiXmlElement* tileOffsetElt = tileOffsetNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = tileOffsetElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "x" )
                m_x = attribute->IntValue();
            else if (name == "y")
                m_y = attribute->IntValue();
            else
                std::cout << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }
    }

    // See header file.
    int TileOffset::x( void ) const
    {
        return m_x;
    }

    // See header file.
    int TileOffset::y( void ) const
    {
        return m_y;
    }

    // See header file.
    void TileOffset::printToStream( std::ostream& stream ) const
    {
        stream << "#................................" << std::endl;
        stream << "# Tile offset: " << m_x << ", " << m_y << std::endl;
        stream << "#................................" << std::endl;
    }

} // end namespace TMX
