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

#ifndef __Tile_HPP__
#define __Tile_HPP__

#include "Properties.hpp"
#include "tinyxml/tinyxml.h"

namespace TMX
{

    class Tile
    {
        public:
            //! \brief Default destructor.
            Tile( void );

            //! \brief Default destructor.
            Tile( unsigned int id );

            //! \brief Default constructor.
            //! \param tilesetNode Xml node contains tileset.
            Tile( TiXmlNode* tileNode );

            //! \brief Get Tile id.
            //! \return The id id.
            unsigned int id( void ) const;

            //! \brief Print all tileset informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            unsigned int m_id;
            Properties m_properties;
    };

} // end namespace TMX

#endif // __Tile_HPP__
