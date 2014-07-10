/* wrap-gettext.c -- gettext() wrapper

   Copyright (C) SUSE Linux
   Written by Stanislav Brabec, 2014

trace-wrappers is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

trace-wrappers is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with trace-wrappers; see the file COPYING.  If not, a
copy can be downloaded from  http://www.gnu.org/licenses/lgpl.html,
or obtained by writing to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "wrap.h"
#include <locale.h>

#define int_category_decl		int
#define	int_category_format		"%s"

const char *int_category_func (int category)
{
	static char int_category_buffer[64];

	switch (category)
	{
	case LC_CTYPE:
		return "LC_CTYPE";
	case LC_NUMERIC:
		return "LC_NUMERIC";
	case LC_TIME:
		return "LC_TIME";
	case LC_COLLATE:
		return "LC_COLLATE";
	case LC_MONETARY:
		return "LC_MONETARY";
	case LC_MESSAGES:
		return "LC_MESSAGES";
	case LC_ALL:
		return "LC_ALL";
	case LC_PAPER:
		return "LC_PAPER";
	case LC_NAME:
		return "LC_NAME";
	case LC_ADDRESS:
		return "LC_ADDRESS";
	case LC_TELEPHONE:
		return "LC_TELEPHONE";
	case LC_MEASUREMENT:
		return "LC_MEASUREMENT";
	case LC_IDENTIFICATION:
		return "LC_IDENTIFICATION";
	default:
		snprintf (int_category_buffer, 64, "%d (unknown category)", category);
		return int_category_buffer;
	}
}

install_wrap_on_end_3 (char_pointer, dcgettext, constant_char_pointer, constant_char_pointer, int_category);
install_wrap_on_end_5 (char_pointer, dcngettext, constant_char_pointer, constant_char_pointer, constant_char_pointer, unsigned_long_int, int_category);
install_wrap_on_end_1 (char_pointer, textdomain, constant_char_pointer);
install_wrap_on_end_2 (char_pointer, bindtextdomain, constant_char_pointer, constant_char_pointer);
install_wrap_on_end_2 (char_pointer, bind_textdomain_codeset, constant_char_pointer, constant_char_pointer);

/* These are probably useless, as they are defined as macros */
install_wrap_on_end_1 (char_pointer, gettext, constant_char_pointer);
install_wrap_on_end_2 (char_pointer, dgettext, constant_char_pointer, constant_char_pointer);
install_wrap_on_end_3 (char_pointer, ngettext, constant_char_pointer, constant_char_pointer, unsigned_long_int);
install_wrap_on_end_4 (char_pointer, dngettext, constant_char_pointer, constant_char_pointer, constant_char_pointer, unsigned_long_int);
