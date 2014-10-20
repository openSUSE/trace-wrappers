/* dlwrap/wrap.h -- macros for easy definitions of dynamic library wrappers

   Copyright (C) Novell, Inc.
   Written by Stanislav Brabec, 2010-2014

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

#include <stdio.h>

/* fprintf() formatting of types */
#undef	void_printf
#define	char_pointer_printf		"\"%s\""
#define	constant_char_pointer_printf	"\"%s\""
#define	void_pointer_printf		"%p"
#define	size_t_printf			"%p"
#define	int_printf			"%d"
#define	long_int_printf			"%ld"
#define	unsigned_long_int_printf	"%lu"

/* fprintf() argument processing of types */

/* Default is identity: no special processing is required for printf() for standard types. */
#undef	void_printfunc
#define	char_pointer_printfunc
#define	constant_char_pointer_printfunc
#define	void_pointer_printfunc
#define	size_t_printfunc
#define	int_printfunc
#define	long_int_printfunc
#define	unsigned_long_int_printfunc

#undef dlwrap_macro_0_nonvoid
#define dlwrap_macro_0_nonvoid(return_type, name) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "() = "); \
	fflush (stderr); \
	return_code = dlwrap_orig_1_nonvoid(return_type, name); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_0_void
#define dlwrap_macro_0_void(return_type, name) \
	fprintf (stderr, "DLWRAP: " #name "()\n"); \
	fflush (stderr); \
	dlwrap_orig_1_void(return_type, name);

#undef dlwrap_macro_1_nonvoid
#define dlwrap_macro_1_nonvoid(return_type, name, arg1_type, arg1) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ") = ", \
		arg1_type##_printfunc (arg1)); \
	fflush (stderr); \
	return_code = dlwrap_orig_1_nonvoid(return_type, name, arg1_type, arg1); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_1_void
#define dlwrap_macro_1_void(return_type, name, arg1_type, arg1) \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ")\n", \
		arg1_type##_printfunc (arg1)); \
	fflush (stderr); \
	dlwrap_orig_1_void(return_type, name, arg1_type, arg1);

#undef dlwrap_macro_2_nonvoid
#define dlwrap_macro_2_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ") = ", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2)); \
	fflush (stderr); \
	return_code = dlwrap_orig_2_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_2_void
#define dlwrap_macro_2_void(return_type, name, arg1_type, arg1, arg2_type, arg2) \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ")\n", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2)); \
	fflush (stderr); \
	dlwrap_orig_2_void(return_type, name, arg1_type, arg1, arg2_type, arg2);

#undef dlwrap_macro_3_nonvoid
#define dlwrap_macro_3_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ") = ", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3)); \
	fflush (stderr); \
	return_code = dlwrap_orig_3_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_3_void
#define dlwrap_macro_3_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ")\n", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3)); \
	fflush (stderr); \
	dlwrap_orig_3_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3);

#undef dlwrap_macro_4_nonvoid
#define dlwrap_macro_4_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ", " arg4_type##_printf ") = ", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3), arg4_type##_printfunc (arg4)); \
	fflush (stderr); \
	return_code = dlwrap_orig_4_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_4_void
#define dlwrap_macro_4_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ", " arg4_type##_printf ")\n", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3), arg4_type##_printfunc (arg4)); \
	fflush (stderr); \
	dlwrap_orig_4_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4);

#undef dlwrap_macro_5_nonvoid
#define dlwrap_macro_5_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5) \
	return_type##_decl return_code; \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ", " arg4_type##_printf ", " arg5_type##_printf ") = ", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3), arg4_type##_printfunc (arg4), arg5_type##_printfunc (arg5)); \
	fflush (stderr); \
	return_code = dlwrap_orig_5_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5); \
	fprintf (stderr, return_type##_printf "\n", return_type##_printfunc (return_code)); \
	fflush (stderr); \
	return return_code;

#undef dlwrap_macro_5_void
#define dlwrap_macro_5_void(return_type, name, arg1_type, arg1) \
	fprintf (stderr, "DLWRAP: " #name "(" arg1_type##_printf ", " arg2_type##_printf ", " arg3_type##_printf ", " arg4_type##_printf ", " arg5_type##_printf ")\n", \
		arg1_type##_printfunc (arg1), arg2_type##_printfunc (arg2), arg3_type##_printfunc (arg3), arg4_type##_printfunc (arg4), arg5_type##_printfunc (arg5)); \
	fflush (stderr); \
	dlwrap_orig_5_void(void, name, arg1, arg2, arg3, arg4, arg5);
