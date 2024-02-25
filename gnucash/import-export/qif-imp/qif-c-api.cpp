/********************************************************************\
 * qifDialog.cpp - Dialog for importing Quicken Interchange Format  *
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

    wind->imported_files        = SCM_EOL;
    wind->selected_file         = SCM_BOOL_F;
    wind->gnc_acct_info         = SCM_BOOL_F;
    wind->cat_display_info      = SCM_BOOL_F;
    wind->cat_map_info          = SCM_BOOL_F;
    wind->acct_display_info     = SCM_BOOL_F;
    wind->acct_map_info         = SCM_BOOL_F;
    wind->memo_display_info     = SCM_BOOL_F;
    wind->memo_map_info         = SCM_BOOL_F;
    wind->security_hash         = SCM_BOOL_F;
    wind->security_prefs        = SCM_BOOL_F;
    wind->new_securities        = SCM_BOOL_F;
    wind->ticker_map            = SCM_BOOL_F;
    wind->imported_account_tree = SCM_BOOL_F;
    wind->match_transactions    = SCM_BOOL_F;

    load_map_prefs = scm_c_eval_string ("qif-import:load-map-prefs");
    mapping_info = scm_call_0 (load_map_prefs); /* <- gets/creates session/book */
    wind->gnc_acct_info         = scm_list_ref (mapping_info, scm_from_int (0));
    wind->acct_map_info         = scm_list_ref (mapping_info, scm_from_int (1));
    wind->cat_map_info          = scm_list_ref (mapping_info, scm_from_int (2));
    wind->memo_map_info         = scm_list_ref (mapping_info, scm_from_int (3));
    wind->security_hash         = scm_list_ref (mapping_info, scm_from_int (4));
    wind->security_prefs        = scm_list_ref (mapping_info, scm_from_int (5));

    create_ticker_map = scm_c_eval_string ("make-ticker-map");
    wind->ticker_map            = scm_call_0 (create_ticker_map);

/** Constructor for QifDialog.
 */
QifDialog::QifDialog()
{
}

/** Destructor for QifDialog.
 */
QifDialog::~QifDialog()
{
}

/** This is used within the dialog to get a list of all the new
 *  accounts the importer thinks it's going to make.  Passed to the
 *  account picker.
 *
 *  Returned is a tree-structured list of all the old and new accounts
 *  like so : (name new? children).  Trees are sorted alphabetically.
 *  This should probably change but it's better than no sort at all.
 */
void QifDialog::getAllAccounts()
{

}
