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

#ifndef __Image_HPP__
#define __Image_HPP__

#include <string>
#include "tinyxml/tinyxml.h"

namespace TMX
{

    class Image
    {
        public:
            //! \brief Default constructor.
            Image( void );

            //! \brief Default constructor.
            //! \param tilesetNode Xml node contains image.
            Image( TiXmlNode* imageNode );

            //! \brief Get image path.
            //! \return The image path.
            std::string sourcePath( void ) const;

            //! \brief Get image transparency.
            //! \return The image transparency.
            std::string trans( void ) const;

            //! \brief Get image tile width.
            //! \return The image tile width.
            unsigned int width( void ) const;

            //! \brief Get image tile height.
            //! \return The image tile height.
            unsigned int height( void ) const;

            //! \brief Print all map informations on screen.
            void printToStream( std::ostream& stream = std::cout ) const;

        private:
            std::string m_sourcePath; ///< Image path.
            std::string m_trans; ///< Image transparency color.
            unsigned int m_width; ///< Image width.
            unsigned int m_height; ///< Image height.
    };

} // end namespace TMX

#endif // __Image_HPP__
