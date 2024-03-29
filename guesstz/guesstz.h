/*
 * Copyright (c) 1994-2021 Carnegie Mellon University.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The name "Carnegie Mellon University" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For permission or any legal
 *    details, please contact
 *      Carnegie Mellon University
 *      Center for Technology Transfer and Enterprise Creation
 *      4615 Forbes Avenue
 *      Suite 302
 *      Pittsburgh, PA  15213
 *      (412) 268-7393, fax: (412) 268-7395
 *      innovation@andrew.cmu.edu
 *
 * 4. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by Computing Services
 *     at Carnegie Mellon University (http://www.cmu.edu/computing/)."
 *
 * CARNEGIE MELLON UNIVERSITY DISCLAIMS ALL WARRANTIES WITH REGARD TO
 * THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS, IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY BE LIABLE
 * FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#ifndef GUESSTZ_H
#define GUESSTZ_H

#include <libical/ical.h>

typedef struct guesstz guesstz_t;

/** @brief Open the guesstz database at the specified file path.
 *
 *  The file is kept open during the lifetime of the returned
 *  database handle. The return value always points to a database
 *  handle. Use guesstz_error() to assert if there was any error.
 *
 *  @param fpath the file path of the database
 *  @return the database handle
 */
extern guesstz_t *guesstz_open(const char *fpath);


/** @brief Close the guesstz database and free its resources.
 *
 *  @param gtzp the database handle to close. It is safe to
                pass a NULL value or a pointer to NULL.
 */
extern void guesstz_close(guesstz_t **gtzp);


/** @brief Check the error state of the database handle.
 *
 *  Indicates if the last operation on the database handle resulted
 *  in an error. Errors are unrecoverable and the result of
 *  operations executed on an erroneous handle is undefined.
 *
 *  @param gtz the database handle
 *  @return a null-terminated string indicating an error,
 *          or NULL if there is no error
 */
extern const char *guesstz_error(guesstz_t *gtz);

/** @brief Guess the IANA timezone name of a VTIMEZONE
 *
 *  Two timezones are considered equal if their observance
 *  onsets and UTC offsets match within the given time range.
 *  Observances are expanded until the minimum of the given
 *  time range end and the end of the database time range.
 *
 *  @param gtz the database handle
 *  @param vtz a VCALENDAR component containing a VTIMEZONE
 *  @param trstart the UTC start time of the time range
 *  @param trend the UTC end time of the time range
 *  @return a null-terminated string containing the IANA time
 *          timezone name, or NULL if no name is found.
 *          The return value must be free()d by the caller.
 */
extern char *guesstz_guess(guesstz_t *gtz, icalcomponent *vtz,
                           icaltimetype trstart, icaltimetype trend);

/** @brief Encode the database in JSON
 *
 *  @param gtz the database handle
 *  @return a null-terminated string containing the JSON format
 */
extern char *guesstz_encode(guesstz_t *gtz);

#endif // GUESSTZ_H
