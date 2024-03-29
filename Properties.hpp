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

#ifndef __Properties_HPP__
#define __Properties_HPP__

#include <string>
#include <map>
#include <ostream>
#include "tinyxml/tinyxml.h"

namespace TMX
{

    typedef std::pair< std::string, std::string > Property;

    class Properties : public std::map< std::string, std::string >
    {
        public:
            //! \brief Default constructor.
            Properties( void );

            //! \brief Default constructor.
            //! \param propertiesNode Xml node contains tileset.
            Properties( TiXmlNode* propertiesNode );

            //! \brief Print all map informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;
    };

} // end namespace TMX

#endif // __Properties_HPP__
