/* dlwrap/dlwrap.h -- macros for easy definitions of dynamic library wrappers

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

#ifndef _DLWRAP_DLWRAP_H
#define _DLWRAP_DLWRAP_H


#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>


/* Declarations of types allow to define different behavior of wrappers depending on the function prototype */

/* The type string with added "_decl" defines the type string for purpose of the declaration.
 * Other macros can use the string with different added string for its own purposes (e. g. proper formatting of the output */

#define	void_decl			void
#define	char_pointer_decl		char *
#define	constant_char_pointer_decl	const char *
#define	void_pointer_decl		void *
#define size_t_decl			size_t
#define int_decl			int
#define long_int_decl			long int
#define unsigned_long_int_decl		unsigned long int


/* void switches */

/* Many parts ot the wrapper (and possibly also wrap function) are different for void return functions.
 * These macros allow to expand macros differently for void return functions */

#define	void_voidsw(ifvoid,ifnonvoid)			ifvoid
#define	char_pointer_voidsw(ifvoid,ifnonvoid)		ifnonvoid
#define	constant_char_pointer_voidsw(ifvoid,ifnonvoid)	ifnonvoid
#define	void_pointer_voidsw(ifvoid,ifnonvoid)		ifnonvoid
#define size_t_voidsw(ifvoid,ifnonvoid)			ifnonvoid
#define int_voidsw(ifvoid,ifnonvoid)			ifnonvoid
#define long_int_voidsw(ifvoid,ifnonvoid)		ifnonvoid
#define unsigned_long_int_voidsw(ifvoid,ifnonvoid)	ifnonvoid


/* Wrapped functions */

/* Definitions of wrap macros allow to completely change behavior of the wrapper. */

/* Define, what wrappers will do in addition or instead of call of the original function.
 * The default is the call of respective void or nonvoid macros. */

/* Number represents number of arguments */

/* Note: It is possible to define all these macros without arg?, as these runtime values are directly inherited from the calling macro. */

#ifndef dlwrap_macro_0
#define dlwrap_macro_0 dlwrap_macro_0_voidsw
#endif
#define dlwrap_macro_0_voidsw(return_type, name)	\
	return_type##_voidsw (dlwrap_macro_1_void, dlwrap_macro_1_nonvoid) \
		(return_type, name)
#ifndef dlwrap_macro_1
#define dlwrap_macro_1 dlwrap_macro_1_voidsw
#endif
#define dlwrap_macro_1_voidsw(return_type, name, arg1_type, arg1)	\
	return_type##_voidsw (dlwrap_macro_1_void, dlwrap_macro_1_nonvoid) \
		(return_type, name, arg1_type, arg1)
#ifndef dlwrap_macro_2
#define dlwrap_macro_2 dlwrap_macro_2_voidsw
#endif
#define dlwrap_macro_2_voidsw(return_type, name, arg1_type, arg1, arg2_type, arg2) \
	return_type##_voidsw (dlwrap_macro_2_void, dlwrap_macro_2_nonvoid) \
		(return_type, name, arg1_type, arg1, arg2_type, arg2)
#ifndef dlwrap_macro_3
#define dlwrap_macro_3 dlwrap_macro_3_voidsw
#endif
#define dlwrap_macro_3_voidsw(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
	return_type##_voidsw (dlwrap_macro_3_void, dlwrap_macro_3_nonvoid) \
		(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3)
#ifndef dlwrap_macro_4
#define dlwrap_macro_4 dlwrap_macro_4_voidsw
#endif
#define dlwrap_macro_4_voidsw(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
	return_type##_voidsw (dlwrap_macro_4_void, dlwrap_macro_4_nonvoid) \
		(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4)
#ifndef dlwrap_macro_5
#define dlwrap_macro_5 dlwrap_macro_5_voidsw
#endif
#define dlwrap_macro_5_voidsw(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5) \
	return_type##_voidsw (dlwrap_macro_5_void, dlwrap_macro_5_nonvoid) \
		(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5)

/* void/nonvoid wrap macros. In mose cases, these are real wrapper macros.
 * The default is the call of the wrapped function without any modification.
 * Note: void variants define return_type as argument 1 for just for simplification. It is always "void" and you can ignore it.
 * If you need, you can redefine dlwrap_macro_* as a macro with arguments.
 */

#ifndef dlwrap_macro_0_void
#define dlwrap_macro_0_void dlwrap_orig_0_void;
#endif
#define dlwrap_orig_0_void(return_type, name) \
	name##_dlwrap_orig ()
#ifndef dlwrap_macro_0_nonvoid
#define dlwrap_macro_0_nonvoid return dlwrap_orig_0_nonvoid;
#endif
#define dlwrap_orig_0_nonvoid(return_type, name) \
	name##_dlwrap_orig ()
#ifndef dlwrap_macro_1_void
#define dlwrap_macro_1_void dlwrap_orig_1_void;
#endif
#define dlwrap_orig_1_void(return_type, name, arg1_type, arg1) \
	name##_dlwrap_orig (arg1)
#ifndef dlwrap_macro_1_nonvoid
#define dlwrap_macro_1_nonvoid return dlwrap_orig_1_nonvoid;
#endif
#define dlwrap_orig_1_nonvoid(return_type, name, arg1_type, arg1) \
	name##_dlwrap_orig (arg1)
#ifndef dlwrap_macro_2_void
#define dlwrap_macro_2_void dlwrap_orig_2_void;
#endif
#define dlwrap_orig_2_void(return_type, name, arg1_type, arg1, arg2_type, arg2) \
	name##_dlwrap_orig (arg1, arg2)
#ifndef dlwrap_macro_2_nonvoid
#define dlwrap_macro_2_nonvoid return dlwrap_orig_2_nonvoid;
#endif
#define dlwrap_orig_2_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2) \
	name##_dlwrap_orig (arg1, arg2)
#ifndef dlwrap_macro_3_void
#define dlwrap_macro_3_void dlwrap_orig_3_void;
#endif
#define dlwrap_orig_3_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
	name##_dlwrap_orig (arg1, arg2, arg3)
#ifndef dlwrap_macro_3_nonvoid
#define dlwrap_macro_3_nonvoid return dlwrap_orig_3_nonvoid;
#endif
#define dlwrap_orig_3_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
	name##_dlwrap_orig (arg1, arg2, arg3)
#ifndef dlwrap_macro_4_void
#define dlwrap_macro_4_void dlwrap_orig_4_void;
#endif
#define dlwrap_orig_4_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
	name##_dlwrap_orig (arg1, arg2, arg3, arg4)
#ifndef dlwrap_macro_4_nonvoid
#define dlwrap_macro_4_nonvoid return dlwrap_orig_4_nonvoid;
#endif
#define dlwrap_orig_4_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
	name##_dlwrap_orig (arg1, arg2, arg3, arg4)
#ifndef dlwrap_macro_5_void
#define dlwrap_macro_5_void dlwrap_orig_5_void;
#endif
#define dlwrap_orig_5_void(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5) \
	name##_dlwrap_orig (arg1, arg2, arg3, arg4, arg5)
#ifndef dlwrap_macro_5_nonvoid
#define dlwrap_macro_5_nonvoid return dlwrap_orig_5_nonvoid;
#endif
#define dlwrap_orig_5_nonvoid(return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5) \
	name##_dlwrap_orig (arg1, arg2, arg3, arg4, arg5)


/* The wrapper installation itself. */

static void
*dlwrap_install(const char *symbol) {
	void *address;
	if (!(address = dlsym (RTLD_NEXT, symbol))) {
		printf ("dlsym(%s) failed: %s. Aborting!\n",
			symbol, dlerror());
		abort();
	}
        return address;
}


/* Install wrapper for function with no arguments */
#define dlwrap_install_0(return_type, name) \
return_type##_decl \
name () \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (void) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_0 (return_type, name) \
}

/* Install wrapper for function with 1 argument */
#define dlwrap_install_1(return_type, name, arg1_type) \
return_type##_decl \
name (arg1_type##_decl arg1) \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (arg1_type##_decl arg1) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_1 (return_type, name, arg1_type, arg1) \
}

/* Install wrapper for function with 2 arguments */
#define dlwrap_install_2(return_type, name, arg1_type, arg2_type) \
return_type##_decl \
name (arg1_type##_decl arg1, arg2_type##_decl arg2) \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_2 (return_type, name, arg1_type, arg1, arg2_type, arg2) \
}

/* Install wrapper for function with 3 arguments */
#define dlwrap_install_3(return_type, name, arg1_type, arg2_type, arg3_type) \
return_type##_decl \
name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3) \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_3 (return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3) \
}

/* Install wrapper for function with 4 arguments */
#define dlwrap_install_4(return_type, name, arg1_type, arg2_type, arg3_type, arg4_type) \
return_type##_decl \
name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4) \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_4 (return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4) \
}

/* Install wrapper for function with 5 arguments */
#define dlwrap_install_5(return_type, name, arg1_type, arg2_type, arg3_type, arg4_type, arg5_type) \
return_type##_decl \
name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4, arg5_type##_decl arg5) \
{ \
	static return_type##_decl (*name##_dlwrap_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4, arg5_type##_decl arg5) = NULL; \
	if (!name##_dlwrap_orig) \
		name##_dlwrap_orig = dlwrap_install (#name); \
	dlwrap_macro_5 (return_type, name, arg1_type, arg1, arg2_type, arg2, arg3_type, arg3, arg4_type, arg4, arg5_type, arg5) \
}


#endif
