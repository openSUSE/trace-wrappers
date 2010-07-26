/* wrap.h -- dynamic library wrapper macros

   Copyright (C) Novell, Inc.
   Written by Stanislav Brabec, 2010

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

#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

#define	char_pointer_decl		char *
#define	constant_char_pointer_decl	const char *
#define	void_decl			void
#define	void_pointer_decl		void *
#define size_t_decl			size_t

#define	char_pointer_format		"%s"
#define	constant_char_pointer_format	"%s"
#undef	void_format
#define	void_pointer_format		"%p"
#define	size_t_format			"%p"

void *dl_wrap(const char *symbol) {
	void *address;
	if (!(address = dlsym (RTLD_NEXT, symbol))) {
		printf ("dlsym(%s) failed: %s. Aborting!\n",
			symbol, dlerror());
		abort();
	}
        return address;
}

#define install_wrap_on_end_1(return_type, name, arg1_type)						\
return_type##_decl name (arg1_type##_decl arg1)								\
{													\
	static return_type##_decl (*name##_orig) (arg1_type##_decl arg1) = NULL;			\
	return_type##_decl return_code;									\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ")",					\
		arg1);											\
	fflush (stderr);										\
	return_code = name##_orig (arg1);								\
	fprintf (stderr, " = " return_type##_format "\n", return_code);					\
	fflush (stderr);										\
	return return_code;										\
}

#define install_wrap_on_end_1_voidreturn(name, arg1_type)						\
void name (arg1_type##_decl arg1)									\
{													\
	static void (*name##_orig) (arg1_type##_decl arg1) = NULL;					\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ")\n",					\
		arg1);											\
	fflush (stderr);										\
	name##_orig (arg1);										\
}

#define install_wrap_on_end_2(return_type, name, arg1_type, arg2_type)					\
return_type##_decl name (arg1_type##_decl arg1, arg2_type##_decl arg2)					\
{													\
	static return_type##_decl (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2) = NULL;	\
	return_type##_decl return_code;									\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ")",		\
		arg1, arg2);										\
	fflush (stderr);										\
	return_code = name##_orig (arg1, arg2);								\
	fprintf (stderr, " = " return_type##_format "\n", return_code);					\
	fflush (stderr);										\
	return return_code;										\
}

#define install_wrap_on_end_2_voidreturn(name, arg1_type, arg2_type)					\
void name (arg1_type##_decl arg1, arg2_type##_decl arg2)						\
{													\
	static void (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2) = NULL;		\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ")\n",		\
		arg1, arg2);										\
	fflush (stderr);										\
	name##_orig (arg1, arg2);									\
}
