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

#ifndef __Map_HPP__
#define __Map_HPP__

#include <string>
#include <ostream>
#include "Tileset.hpp"
#include "ILayer.hpp"
#include "TileLayer.hpp"
#include "ObjectLayer.hpp"
#include "Properties.hpp"

namespace TMX
{

    class Map
    {
        public:
            enum Orientation
            {
                Orthogonal,
                Isometric
            };

            //! \brief Default constructor. Use for create an empty map.
            Map( void );

            //! \brief Create map with a file.
            Map( const std::string& filename );

            //! \brief Default destructor.
            ~Map( void );

            //! \brief Use for loading a TMX file map.
            //! \param filename Map file name.
            void load( const std::string& filename );

            //! \brief Get map version used.
            //! \return A string contains map version.
            std::string version( void ) const;

            //! \brief Get map orientation type.
            //! \note Currently, map supported only Orthogonal and Isometric map.
            //! \return The map orientation.
            Orientation orientation( void ) const;

            //! \brief Get map width.
            //! \return The map width.
            unsigned int width( void ) const;

            //! \brief Get map height.
            //! \return The map height.
            unsigned int height( void ) const;

            //! \brief Get map tile width.
            //! \return The map tile width.
            unsigned int tileWidth( void ) const;

            //! \brief Get map tile height.
            //! \return The map tile height.
            unsigned int tileHeight( void ) const;

            //! \brief Get map tilesets.
            //! \return Map tilesets.
            Tilesets getTilesets( void ) const;

            //! \brief Get all layer, order like in the map file.
            //! \return Map layers
            Layers getLayers( void ) const;

            //! \brief Print all map informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            std::string m_version; ///< Contains map version.
            Orientation m_orientation; ///< Contains map orientation.
            unsigned int m_width; ///< Contains map width.
            unsigned int m_height; ///< Containts map height.
            unsigned int m_tileWidth; ///< Contains map tile width.
            unsigned int m_tileHeight; ///< Contains map tile height.

            Tilesets m_tilesets; ///< All map tilesets.
            Layers m_layers; ///< All map layers ( contains tile, object, image and color layers )
            TileLayers m_tileLayers; ///< Tile layers
            ObjectLayers m_objectLayers;
            //ImageLayers m_imageLayers;
            //ColorLayers m_colorLayers;
            Properties m_properties;
    };

} // end namespace TMX

#endif // __Map_HPP__
