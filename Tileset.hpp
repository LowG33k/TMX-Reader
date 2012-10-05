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

#ifndef __Tileset_HPP__
#define __Tileset_HPP__

#include "Tile.hpp"
#include "Properties.hpp"
#include "Image.hpp"
#include "TileOffset.hpp"
#include "tinyxml/tinyxml.h"
#include <vector>

namespace TMX
{

    class Tileset : public std::vector< Tile >
    {
        public:
            //! \brief Default constructor.
            //! \param tilesetNode Xml node contains tileset.
            Tileset( TiXmlNode* tilesetNode );

            //! \brief Print all tileset informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

            //! \brief Load à TSX ( TileSet Xml ) file.
            //! \param filename Name of TSX file.
            //void load( const std::string& filename );

        private:
            unsigned int m_firstGlobalId; ///< First global id for tileset.
            std::string m_sourcePath; ///< Source of TSX file, empty if haven't a TSX file.
            std::string m_name; ///< Name of image file.
            unsigned int m_tileWidth; ///< Tile width.
            unsigned int m_tileHeight; ///< Tile height.
            int m_spacing; ///< Spacing between tiles.
            int m_margin; ///< Margin since border of picture.

            Image m_image; ///< Tileset image.
            Properties m_properties; ///<
            TileOffset m_offset;

    };

    typedef std::vector< Tileset* > Tilesets;///< Define an array of tileset

} // end namespace TMX

#endif // __Tileset_HPP__
