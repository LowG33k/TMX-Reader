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

#ifndef __Data_HPP__
#define __Data_HPP__

#include "Tile.hpp"
#include "tinyxml/tinyxml.h"
#include <vector>

namespace TMX
{

    enum Encoding
    {
        Xml,
        Base64,
        Csv
    };

    enum Compression
    {
        None,
        Gzip,
        Zlib
    };

    class Data : public std::vector< Tile >
    {
        public:
            //! \brief Default constructor.
            Data( void );

            //! \brief Default constructor.
            //! \param dataNode Xml node contains data.
            Data( TiXmlNode* dataNode );

            //! \brief Parsing CSV datas
            void parsingCSVDatas( const std::string& datas );

            //! \brief Parsing base 64 datas
            void parsingBase64Datas( const std::string& datas );

            //! \brief Print all tileset informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            Encoding m_encoding;
            Compression m_compression;
    };

} // end namespace TMX

#endif // __Data_HPP__
