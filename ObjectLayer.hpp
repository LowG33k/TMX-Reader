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

#ifndef __ObjectLayer_HPP__
#define __ObjectLayer_HPP__

#include "ILayer.hpp"
#include "Object.hpp"
#include "Properties.hpp"
#include "tinyxml/tinyxml.h"
#include <string>
#include <vector>

namespace TMX
{

    class ObjectLayer : public ILayer, public std::vector< Object >
    {
        public:
            //! \brief Default constructor.
            //! \param objectLayerNode Xml node contains object layer.
            ObjectLayer( TiXmlNode* objectLayerNode );

            //! \brief Default destructor.
            ~ObjectLayer( void );

            //! \brief Print all tileset informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            std::string m_name; ///< Name of layer.
            unsigned int m_x; ///< X position of layer.
            unsigned int m_y; ///< Y position of layer.
            unsigned int m_width; ///< Width of layer.
            unsigned int m_height; ///< Height of layer.

            Properties m_properties; ///< Layer properties.
    };

    typedef std::vector< ObjectLayer* > ObjectLayers;

} // end namespace TMX

#endif // __ObjectLayer_HPP__
