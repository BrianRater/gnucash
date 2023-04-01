/********************************************************************\
 * gncCustomer.hpp -- the Core Customer Interface                     *
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
/* @addtogroup Business
    @{ */
/** @addtogroup Customer
    @{ */
/** @file gncCustomer.hpp
    @brief Core Customer Interface
    @author Copyright (C) 2001,2002 Derek Atkins <warlord@MIT.EDU>
    @author Copyright (C) 2023 Brian Rater <blrnh94@gmail.com>
*/


#ifndef GNC_CUSTOMER_HPP
#define GNC_CUSTOMER_HPP

/** @struct GncCustomer

credit, discount and shipaddr are unique to GncCustomer\n
id, name, notes, terms, addr, currency, taxtable, taxtable_override
taxincluded, active and jobs are identical to ::GncVendor.

@param	QofInstance     inst;
@param	char *          id;
@param	char *          name;
@param	char *          notes;
@param	GncBillTerm *   terms;
@param	GncAddress *    addr;
@param	gnc_commodity * currency;
@param	GncTaxTable*    taxtable;
@param	gboolean        taxtable_override;
@param	GncTaxIncluded  taxincluded;
@param	gboolean        active;
@param	GList *         jobs;
@param	gnc_numeric     credit;
@param	gnc_numeric     discount;
@param	GncAddress *    shipaddr;

*/

#include "gncBillTerm.h"
#include "gncAddress.h"
#include "gnc-commodity.h"
#include "gncTaxTable.h"
#include "gnc-numeric.h"

#include "gncBase.h"

class gncCustomer : public gncBase
{
public:
	
	gncCustomer(QofBook &book, GncGUID guid);
	~gncCustomer();
	
	std::string get_customer_id(return m_id;);
	void set_customer_id(const std::string &id);
	
	std::string get_customer_name(return m_name;);
	void set_customer_name(const std::string &name);
	
	std::string get_customer_notes(return m_notes;);
	void set_customer_notes(const std::string &notes);
	
	GncBillTerm *get_customer_terms() { return m_terms;}
	void set_customer_terms(GncBillTerm &term);
	
	GncAddress get_customer_address() {return m_address;);
	void set_customer_address(const GncAddress &address);
	
	GncAddress get_customer_ship_address() {return m_shipaddr;);
	void set_customer_ship_address(const GncAddress &address);
	
	GncTaxIncluded get_customer_tax_included() { return m_taxIncluded;};
	void set_customer_tax_included(GncTaxIncluded taxIncluded);
	
	bool get_customer_active() {return m_active;};
	void set_customer_active(bool active);
	
	gnc_numeric get_customer_discount() {return m_discount;};
	void set_customer_discount(const gnc_numeric &discount);
	
	gnc_numeric get_customer_credit() {return m_credit;};
	void set_customer_credit(const gnc_numeric &credit);
	
	gnc_commodity get_customer_currency() {return m_currency;};
	void set_customer_currency(const gnc_commodity &currency);
	
	bool get_customer_tax_table_override() { return m_taxtable_override;};
	void set_customer_tax_table_override(bool override);
	
	GncTaxTable *get_customer_tax_table() {return m_taxtable;};
	void set_customer_tax_table(const GncTaxTable &table);
	
	void add_customer_job(const GncJob &job);
	
	void remove_customer_job(const GncJob &job);
	
protected:
    std::string     m_id;
    std::string     m_name;
    std::string     m_notes;
    GncBillTerm *   m_terms;
    GncAddress      m_addr;
    gnc_commodity * m_currency;
    GncTaxTable*    m_taxtable;
    bool            m_taxtable_override;
    GncTaxIncluded  m_taxincluded;
    bool            m_active;
    std::list<GncJob&> m_jobs;
    gnc_numeric *   m_balance; /* cached customer balance, will not be stored */
    gnc_numeric     m_credit;
    gnc_numeric     m_discount;
    GncAddress *    m_shipaddr;
    
private:
    gncCustomer();

};

#endif /* GNC_CUSTOMER_HPP */
/** @} */
/** @} */_