/********************************************************************\
 * gncBase.hpp -- Base class for more classes                       *
 *                                                                  *
 * This program is free software; you can redistribute it and/or    *
 * modify it under the terms of the GNU General Public License as   *
 * published by the Free Software Foundation; either version 2 of   *
 * the License, or (at your option) any later version.              *
 *                                                                  *
 * This program is distributed in the hope that it will be useful,  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    *
 * GNU General Public License for more details.                     *
 *                                                                  *
 * You should have received a copy of the GNU General Public License*
 * along with this program; if not, contact:                        *
 *                                                                  *
 * Free Software Foundation           Voice:  +1-617-542-5942       *
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652       *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 *                                                                  *
\********************************************************************/
/** @addtogroup Engine
    @{ */
/** @addtogroup Base
    @{ */
/** @file gncBase.hpp
    @brief Base class for most classes.
    @author Copyright (C) 2023 Brian Rater <blrnh94@gmail.com>
*/

#ifndef GNC_BASE_HPP_
#define GNC_BASE_HPP

#include "guid.h"

extern "C"
{
}


struct QofBook;

class gncBase
{
	
public:
	gncBase(QofBook &book, GncGUID guid);
	~gncBase();
	
	QofBook &get_book() { return m_book; }
	void set_book(QofBook &book);
	
	GncGUID get_guid() { return m_gncGUID; }

	std::string get_display_name() { return m_displayName; }
	void set_display_name(const std::string &displayname);
	
protected:
	QofBook &m_book;
	bool m_dirty;
	GncGUID m_gncGUID;
	std::string m_displayName;
	
private:
	
}

#endif /* GNC_BASE_HPP_*/
/** @} */
/** @} */_
}