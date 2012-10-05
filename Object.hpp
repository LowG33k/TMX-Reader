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

#ifndef __Object_HPP__
#define __Object_HPP__

#include "Properties.hpp"
#include "tinyxml/tinyxml.h"
#include <string>

namespace TMX
{

    class Object
    {
        public:
            //! \brief Default constructor.
            //! \param objectNode Xml node contains object.
            Object( TiXmlNode* objectNode );

            //! \brief Print all tileset informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            std::string m_name; ///< Name of object.
            std::string m_type; ///< Object type.
            int m_x; ///< Object x position.
            int m_y; ///< Object y position.
            unsigned int m_width; ///< Object width.
            unsigned int m_height; ///< Object height.
            unsigned int m_gid; ///< Tile gid ( optional ).
            bool m_visible; ///< True if object is shown, false also.

            Properties m_properties; ///<
    };

} // end namespace TMX

#endif // __Object_HPP__
