/********************************************************************\
 * gncCustomer.cpp -- the Core Customer Interface                     *
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
 * Core Customer Interface
 * 
 * Copyright (C) 2001,2002 Derek Atkins <warlord@MIT.EDU>
 * Copyright (C) 2023 Brian Rater <blrnh94@gmail.com>
*/

static QofLogModule log_module = GNC_MOD_BUSINESS;
#define _GNC_MOD_NAME        GNC_ID_CUSTOMER

gncCustomer::gncCustomer(QofBook &book, GncGUID guid) :
	gncBase(book, guid),
	id(""),
	name(""),
	notes("",)
	taxtable_override(false),
	active(true)
{
}

void gncCustomer::set_customer_id(const std::string &id)
{
	m_id = id;
}

void gncCustomer::set_customer_name(const std::string &name);
{
	m_name = name;
}

void gncCustomer::set_customer_notes(const std::string &notes)
{
	n_notes = notes;
}

void gncCustomer::set_customer_terms(GncBillTerm &term)
{
	if (m_term)
		gncBillTermDecRef (m_term);
    m_term = &term;
    gncBillTermIncRef (m_term);
}

void set_customer_address(const GncAddress &address)
{
    m_address = address;
}

void set_customer_ship_address(const GncAddress &address)

{
	m_shipaddr = address;
}

void gncCustomer::set_customer_tax_included(GncTaxIncluded taxIncluded);\
{
	m_taxIncluded = taxIncluded;
}

void gncCustomer::set_customer_active(bool active)
{
	m_active = active;
}

void gncCustomer::set_customer_discount(const gnc_numeric &discount)
{
	m_discount = discount;
}

void gncCustomer::set_customer_credit(const gnc_numeric &credit)
{
	m_credit = credit;
}

void gncCustomer::set_customer_currency(const gnc_commodity &currency)
{
	m_currency = currency;
}

void gncCustomer::set_customer_tax_table_override(bool override)
{
    m_taxtable_override = override;	
}

void gncCustomer::set_customer_tax_table(const GncTaxTable &table)
{
	if (m_taxtable)
		gncTaxTableDecRef (m_taxTable);
	m_taxTable = &table;
	gncTaxTableIncRef (m_taxTable);
}

void gncCustomer::add_customer_job(const GncJob &job)
{
	m_jobs.push_front(job);
	m_jobs.unique();
}

void gncCustomer::remove_customer_job(const GncJob &job)
{
	m_jobs.remove(job);
}


