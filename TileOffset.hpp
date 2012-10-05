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

#ifndef __TileOffset_HPP__
#define __TileOffset_HPP__

#include "tinyxml/tinyxml.h"

namespace TMX
{

    class TileOffset
    {
        public:
            //! \brief Default constructor.
            TileOffset( void );

            //! \brief Default constructor.
            //! \param tileOffsetNode Xml node contains tile offset.
            TileOffset( TiXmlNode* tileOffsetNode );

            //! \brief Get X offset
            //! \return X offset value.
            int x( void ) const;

            //! \brief Get Y offset
            //! \return Y offset value.
            int y( void ) const;

            //! \brief Print all map informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            int m_x; ///< X offset.
            int m_y; ///< Y offset.
    };

} // end namespace TMX

#endif // __TileOffset_HPP__
