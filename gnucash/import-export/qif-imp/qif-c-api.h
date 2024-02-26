/********************************************************************\
 * qif-c-api.h - C API for importing Quicken Interchange Format     *
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

/** @file
     @brief C interface to import QIF data
     *
     qif-c-api.h
     @author Copyright (c) 2024 Brian Rater
 */

#ifndef QIF_C_API_H
#define QIF_C_API_H

typedef struct QifData QifData;

#ifdef __cplusplus
extern "C" {
#endif

/************
qif-to-gnc  needs
gchar tmp_transaction_status = 'n';
/* Clear / Reconcile transaction if not specified in QIF file. */
if (gnc_prefs_get_bool (GNC_PREFS_GROUP, GNC_PREF_DEFAULT_TRANS_STATUS_CLEARED))
    tmp_transaction_status = 'c';
else if (gnc_prefs_get_bool (GNC_PREFS_GROUP, GNC_PREF_DEFAULT_TRANS_STATUS_RECONCILED))
    tmp_transaction_status = 'y';
***************/

struct QifData;
struct QifDisplayInfo;
struct QifMapEntry;

/***************
 * from gnc_ui_qif_import_finish_cb:
 * remove duplicate transactions  gnc:prune-matching-transactions
 * import the account tree into the existing one  gnc:account-tree-catenate-and-merge
 * save the user's map preferences  qif-import:save-map-prefs
 * returns true if the map preferences could be saved.
 */
gboolean qif_apply_import (QifData &qif);

/*
 * returns true if any duplicate transactions have been found
 */
gboolean qif_duplicate_transactions (QifData &qif);

/*
 * qif-import:refresh-match-selection
 */
void qif_set_match_transactions(QifData &qif, int transaction_index);

/*
 * Return the first duplicate transaction or null if there are none.
 */
Transaction * qif_get_first_duplicate_transaction(QifData &qif, boolean &selected);

/*
 * Return the next duplicate transaction or null if there are none.
 */
Transaction * qif_get_next_duplicate_transaction(QifData &qif, boolean &selected);

/*
 * Returns true if cancelled by user.
 */
gboolean qif_convert_to_gnc(QifData &qif);

/*
 * Returns true if cancelled by user.
 */
gboolean qif_account_tree_find_duplicates(QifData &qif);

/*
 * Clears pause and cancel states for import.
 */
void qif_clear_pause_cancel(QifData &qif);

/*
 * Either sets or unsets the pause.
 */
void qif_toggle_pause(QifData &qif);

gboolean qif_new_securities(QifData &qif);

/*
 * Returns true if there are updates.  It should update the
 * internal list of securities that was formerly stored in the
 * UI data.
 */
gboolean qif_update_security_hash(QifData &qif);

/*
 * Implements this from assistant-qif-import.c:
 *     * If there are no memo mappings, jump this step. *
 *     if (scm_is_list (wind->memo_display_info) && scm_is_null (wind->memo_display_info))
 *       return TRUE;
 *     return FALSE;
 */
gboolean qif_memo_to_display(QifData &qif);

/*
 * Implements this from assistant-qif-import.c:
 * If there are no category mappings, jump this step.
 *     if (scm_is_list (wind->cat_display_info) && scm_is_null (wind->cat_display_info))
 *         return TRUE;
 *     return FALSE;
 */
gboolean qif_category_to_display(QifData &qif);

QifDisplayInfo &qif_get_account_display_info(QifData &qif);
QifMapEntry &qif_get_account_map_entry(QifData &qif);

QifDisplayInfo &qif_get_category_display_info(QifData &qif);
QifMapEntry &qif_get_category_map_entry(QifData &qif);

QifDisplayInfo &qif_get_memo_display_info(QifData &qif);
QifMapEntry &qif_get_memo_map_entry(QifData &qif);

boolean qif_get_first_loaded_file(QifData &qif, char **filename, boolean &selectedFile);
boolean qif_get_next_loaded_file(QifData &qif, char **filename, boolean &selectedFile);

void qif_unload_selected_file(QifData &qif);

/* qif-import:fix-from-acct */
void qif_fix_from_account(QifData &qif, char *accountName);

/* qif-file:check-from-acct */
boolean qif_selected_account_has_transactions(QifData &qif);

/* returns true if a file has been selected */
boolean qif_is_selected_file(QifData &qif);

char *qif_selected_account_name(QifData &qif);

/* qif-file:reparse-dates */
void qif_reparse_date(QifData &qif, char *format);

/* make-qif-file */
void qif_make_file(QifData &qif);

/* qif-import:reset-cancel-pause */
void qif_import_reset_cancel_pause(QifData &qif);

/* qif-file:read-file */
boolean qif_file_read(QifData &qif, char **error);  // TODO needs progress dialog, make error safe

/* qif-file:parse-fields */
boolean qif_file_parse(QifData &qif, boolean &date_ambiguity, boolean &ambiguousDates, char **error);  // TODO needs progress dialog, make error safe

/* returns an array of strings that describe the possible date formats that could be
 * used in the QIF file.  The user will select one from a dialog.  The caller must allocate an
 * array of pointers.  Returns the number of pointers actually set.
 */
int qif_file_parse_date_formats(QifData &qif, char *date_formats[], int max_date_formats);

/* qif-dialog:unload-qif-file.  Unloads the selected file. */
void qif_file_unload(QifData &qif);

void qif_register_progress_dialog_callback(QifData &qif, void (*setProgressMessage)(char *));

/* Unregister the progress dialog callback */
void qif_unregister_progress(QifData &qif);

/* Pause or resume */
void qif_pause_parse(QifData &qif);

boolean qif_file_is_loaded(QifData &qif, char *file_path_and_name);

/* Cancel any operation currently in progress. */
/* qif-import:cancel */
void qif_cancel(QifData &qif);

/* qif-import:qif-to-gnc-undo */
void qif_file_undo(QifData &qif);

#ifdef __cplusplus
}
#endif

