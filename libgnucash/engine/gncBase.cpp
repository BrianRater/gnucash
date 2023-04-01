/********************************************************************\
 * gncBase.cpp -- Base class for more classes                       *
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

/*
 * Base class for most classes.
 * 
 * Copyright (C) 2023 Brian Rater <blrnh94@gmail.com>
*/

gncBase::gncBase(QofBook book, GncGUID guid)
: m_book(book),
  m_dirty(false),
  m_guid(guid)
{
	
}

void gncBase::set_book(QofBook &book) 
{ 
	m_book = book; 
	dirty = true; 
}

void gncBase::set_display_name(const std::string &displayname) 
{
	m_displayName = displayName; 
	dirty = true; 
}







