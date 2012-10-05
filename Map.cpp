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

#include "Map.hpp"
#include "tinyxml/tinyxml.h"
#include "Utils.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "TileLayer.hpp"

namespace TMX
{

    // See header file.
    Map::Map( void ) :
        m_version(),
        m_orientation( Orthogonal ),
        m_width( 0 ),
        m_height( 0 ),
        m_tileWidth( 0 ),
        m_tileHeight( 0 )
    {

    }

    // See header file.
    Map::Map( const std::string& filename ) :
        m_version(),
        m_orientation( Orthogonal ),
        m_width( 0 ),
        m_height( 0 ),
        m_tileWidth( 0 ),
        m_tileHeight( 0 )
    {
        load( filename );
    }

    // See header file.
    Map::~Map( void )
    {
        // Release tilesets
        std::for_each( m_tilesets.begin(), m_tilesets.end(), Delete() );
        // Release tile layers
        std::for_each( m_tileLayers.begin(), m_tileLayers.end(), Delete() );
        // Release object layers
        std::for_each( m_objectLayers.begin(), m_objectLayers.end(), Delete() );
    }

    // See header file.
    void Map::load( const std::string& filename )
    {
        // Create map file.
        TiXmlDocument mapFile( filename );
        if( !mapFile.LoadFile() )
        {
            std::cerr << "Error when loading \"" << filename << "\" file." << std::endl;
            std::cerr << "Error #" << mapFile.ErrorId() << " : " << mapFile.ErrorDesc() << std::endl;
            return;
        }
        // Create map handle
        TiXmlHandle mapHandle( &mapFile );

        TiXmlElement* mapElt = mapHandle.FirstChildElement().ToElement(); // convert to element
        TiXmlAttribute* attribute = mapElt->FirstAttribute(); // Get first attribute

        while( attribute ) // browse all attribute
        {
            std::string name  = attribute->Name(); // Get attribute name

            if( name == "version" )
                m_version = attribute->Value();
            else if (name == "orientation")
            {
                if( std::string( attribute->Value() ) == "orthogonal" )
                    m_orientation = (Orientation)attribute->IntValue();
                else if( std::string( attribute->Value() ) == "isometric" )
                    m_orientation = (Orientation)attribute->IntValue();
            }
            else if (name == "width")
                m_width = attribute->IntValue();
            else if (name == "height")
                m_height = attribute->IntValue();
            else if (name == "tilewidth")
                m_tileWidth = attribute->IntValue();
            else if (name == "tileheight")
                m_tileHeight = attribute->IntValue();
            else
                std::cout << "unsupported attribs:" + name + ":" + attribute->Value() << std::endl;

            attribute = attribute->Next(); // Next attribute
        }

        // Browse all node
        TiXmlNode* mapNode = mapElt->FirstChild();
        while( mapNode )
        {
            if( mapNode->Type() == TiXmlNode::TINYXML_ELEMENT )
            {
                if( std::string( mapNode->Value() ) == "properties" )
                    m_properties = Properties( mapNode );
                else if( std::string( mapNode->Value() ) == "tileset" )
                    m_tilesets.push_back( new Tileset( mapNode ) );
                else if( std::string( mapNode->Value() ) == "layer" )
                {
                    m_tileLayers.push_back( new TileLayer( mapNode ) );
                    m_layers.push_back( m_tileLayers.back() );
                }
                /*else if( std::string( mapNode->Value() ) == "imagelayer" )
                    m_layers.push_back( new TileLayer( mapNode ) );
                else if( std::string( mapNode->Value() ) == "colorlayer" )
                    m_layers.push_back( new TileLayer( mapNode ) );*/
                else if( std::string( mapNode->Value() ) == "objectgroup" )
                {
                    m_objectLayers.push_back( new ObjectLayer( mapNode ) );
                    m_layers.push_back( m_objectLayers.back() );
                }
            }
            mapNode = mapNode->NextSibling();
        }
    }

    // See header file.
    std::string Map::version( void ) const
    {
        return m_version;
    }

    // See header file.
    Map::Orientation Map::orientation( void ) const
    {
        return m_orientation;
    }

    // See header file.
    unsigned int Map::width( void ) const
    {
        return m_width;
    }

    // See header file.
    unsigned int Map::height( void ) const
    {
        return m_height;
    }

    // See header file.
    unsigned int Map::tileWidth( void ) const
    {
        return m_tileWidth;
    }

    // See header file.
    unsigned int Map::tileHeight( void ) const
    {
        return m_tileHeight;
    }

    // See header file.
    void Map::printToStream( std::ostream& stream ) const
    {
        stream << "##############################################" << std::endl;
        stream << "# MAP: " << std::endl;
        stream << "# Version: " << m_version << std::endl;
        stream << "# Orientation: " << ( ( m_orientation == Orthogonal ) ? "Orthogonal" : "Isometric" ) << std::endl;
        stream << "# Dimension: " << m_width << "x" << m_height << std::endl;
        stream << "# Tile dimension: " << m_tileWidth << "x" << m_tileHeight << std::endl;

        m_properties.printToStream( stream );

        for( auto tilsetIt = m_tilesets.begin(); tilsetIt != m_tilesets.end(); ++tilsetIt )
            (*tilsetIt)->printToStream( stream );

        for( auto tileLayerIt = m_layers.begin(); tileLayerIt != m_layers.end(); ++tileLayerIt )
            (*tileLayerIt)->printToStream( stream );

        stream << "##############################################" << std::endl;
    }

} // end namespace TMX
