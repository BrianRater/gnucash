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
gboolean qif-apply-import (QifData &qif);

/*
 * returns true if any duplicate transactions have been found
 */
gboolean qif-duplicate-transactions (QifData &qif);

/*
 * Return the first matching transaction or null if there are none.
 */
Transaction * qif-get-first-match-transaction(QifData &qif);

/*
 * Return the next matching transaction or null if there are none.
 */
Transaction * qif-get-next-match-transaction(QifData &qif);

/*
 * Returns true if cancelled by user.
 */
gboolean qif-convert-to-gnc(QifData &qif);

/*
 * Returns true if cancelled by user.
 */
gboolean qif-account-tree-find-duplicates(QifData &qif);

/*
 * Clears pause and cancel states for import.
 */
void qif-clear-pause-cancel(QifData &qif);

/*
 * Either sets or unsets the pause.
 */
void qif-toggle-pause(QifData &qif);

gboolean qif-new-securities(QifData &qif);

/*
 * Returns true if there are updates.  It should update the
 * internal list of securities that was formerly stored in the
 * UI data.
 */
gboolean qif-update-security-hash(QifData &qif);

/*
 * Implements this from assistant-qif-import.c:
 *     * If there are no memo mappings, jump this step. *
 *     if (scm_is_list (wind->memo_display_info) && scm_is_null (wind->memo_display_info))
 *       return TRUE;
 *     return FALSE;
 */
gboolean qif-memo-to-display(QifData &qif);

/*
 * Implements this from assistant-qif-import.c:
 * If there are no category mappings, jump this step.
 *     if (scm_is_list (wind->cat_display_info) && scm_is_null (wind->cat_display_info))
 *         return TRUE;
 *     return FALSE;
 */
gboolean qif-category-to-display(QifData &qif);

QifDisplayInfo &qif-get-account-display-info(QifData &qif);
QifMapEntry &qif-get-account-map-entry(QifData &qif);

QifDisplayInfo &qif-get-category-display-info(QifData &qif);
QifMapEntry &qif-get-category-map-entry(QifData &qif);

QifDisplayInfo &qif-get-memo-display-info(QifData &qif);
QifMapEntry &qif-get-memo-map-entry(QifData &qif);

boolean qif-get-first-loaded-file(QifData &qif, char **filename, boolean &selectedFile);
boolean qif-get-next-loaded-file(QifData &qif, char **filename, boolean &selectedFile);

void qif-unload-selected-file(QifData &qif);

// qif-import:fix-from-acct
void qif-fix-from-account(QifData &qif, char *accountName);

// qif-file:check-from-acct
boolean qif-selected-account-has-transactions(QifData &qif);

// returns true if a file has been selected
boolean qif-is-selected-file(QifData &qif);

char *qif-selected-account-name(QifData &qif);

// qif-file:reparse-dates
void qif-reparse-date(QifData &qif, char *format);

// make-qif-file
void qif-make-file(QifData &qif);

// qif-import:reset-cancel-pause
void qif-import-reset-cancel-pause(QifData &qif);

// qif-file:read-file
boolean qif-file-read(QifData &qif, char **error);  // TODO needs progress dialog, make error safe

// qif-file:parse-fields
boolean qif-file-parse(QifData &qif, boolean &warnings, boolean &ambiguousDates, char **error);  // TODO needs progress dialog, make error safe



// qif-dialog:unload-qif-file
void qif-file-unload(QifData &qif);

#ifdef __cplusplus
}
#endif

