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

#include "Image.hpp"
#include <iostream>

namespace TMX
{

    // See header file.
    Image::Image( void ) :
        m_sourcePath( "" ),
        m_trans( "" ),
        m_width( 0 ),
        m_height( 0 )
    {

    }

    // See header file.
    Image::Image( TiXmlNode* imageNode ) :
        m_sourcePath( "" ),
        m_trans( "" ),
        m_width( 0 ),
        m_height( 0 )
    {
        TiXmlElement* imageElt = imageNode->ToElement(); // convert to element
        TiXmlAttribute* attribute = imageElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "source" )
                m_sourcePath = attribute->Value();
            else if (name == "trans")
                m_trans = attribute->Value();
            else if (name == "width")
                m_width = attribute->IntValue();
            else if (name == "height")
                m_height = attribute->IntValue();
            else
                std::cout << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }
    }

    // See header file.
    std::string Image::sourcePath( void ) const
    {
        return m_sourcePath;
    }

    // See header file.
    std::string Image::trans( void ) const
    {
        return m_trans;
    }

    // See header file.
    unsigned int Image::width( void ) const
    {
        return m_width;
    }

    // See header file.
    unsigned int Image::height( void ) const
    {
        return m_height;
    }

    // See header file.
    void Image::printToStream( std::ostream& stream ) const
    {
        stream << "#§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << std::endl;
        stream << "# Image: " << std::endl;
        stream << "# Source: " << m_sourcePath << std::endl;
        stream << "# Trans: " << m_trans << std::endl;
        stream << "# Dim: " << m_width << "x" << m_height << std::endl;
        stream << "#§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§" << std::endl;
    }

} // end namespace TMX
