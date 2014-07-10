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

/* Declarations of types */
#define	void_decl			void
#define	char_pointer_decl		char *
#define	constant_char_pointer_decl	const char *
#define	void_pointer_decl		void *
#define size_t_decl			size_t
#define int_decl			int
#define long_int_decl			long int
#define unsigned_long_int_decl		unsigned long int

/* fprintf() formatting of types */
#undef	void_format
#define	char_pointer_format		"\"%s\""
#define	constant_char_pointer_format	"\"%s\""
#define	void_pointer_format		"%p"
#define	size_t_format			"%p"
#define	int_format			"%d"
#define	long_int_format			"%ld"
#define	unsigned_long_int_format	"%lu"

/* fprintf() argument processing of types */
#undef	void_func
#define	char_pointer_func
#define	constant_char_pointer_func
#define	void_pointer_func
#define	size_t_func
#define	int_func
#define	long_int_func
#define	unsigned_long_int_func

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
		arg1_type##_func (arg1));								\
	fflush (stderr);										\
	return_code = name##_orig (arg1);								\
	  fprintf (stderr, " = " return_type##_format "\n", return_type##_func (return_code));		\
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
		arg1_type##_func (arg1));								\
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
		arg1_type##_func (arg1), arg2_type##_func (arg2));					\
	fflush (stderr);										\
	return_code = name##_orig (arg1, arg2);								\
	fprintf (stderr, " = " return_type##_format "\n", return_type##_func (return_code));		\
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
		arg1_type##_func (arg1), arg2_type##_func (arg2));					\
	fflush (stderr);										\
	name##_orig (arg1, arg2);									\
}

#define install_wrap_on_end_3(return_type, name, arg1_type, arg2_type, arg3_type)			\
return_type##_decl name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3)		\
{													\
	static return_type##_decl (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,		\
		arg3_type##_decl arg3) = NULL;								\
	return_type##_decl return_code;									\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ")",								\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3));		\
	fflush (stderr);										\
	return_code = name##_orig (arg1, arg2, arg3);							\
	fprintf (stderr, " = " return_type##_format "\n", return_type##_func (return_code));		\
	fflush (stderr);										\
	return return_code;										\
}

#define install_wrap_on_end_3_voidreturn(name, arg1_type, arg2_type, arg3_type)				\
void name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3)				\
{													\
	static void (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,			\
		arg3_type##_decl arg3) = NULL;								\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ")\n",							\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3));		\
	fflush (stderr);										\
	name##_orig (arg1, arg2, arg3);									\
}

#define install_wrap_on_end_4(return_type, name, arg1_type, arg2_type, arg3_type, arg4_type)		\
return_type##_decl name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3,		\
		arg4_type##_decl arg4)									\
{													\
	static return_type##_decl (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,		\
		arg3_type##_decl arg3, arg4_type##_decl arg4) = NULL;					\
	return_type##_decl return_code;									\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ", " arg4_type##_format ")",					\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3),		\
			arg4_type##_func (arg4));							\
	fflush (stderr);										\
	return_code = name##_orig (arg1, arg2, arg3, arg4);						\
	fprintf (stderr, " = " return_type##_format "\n", return_type##_func (return_code));		\
	fflush (stderr);										\
	return return_code;										\
}

#define install_wrap_on_end_4_voidreturn(name, arg1_type, arg2_type, arg3_type, arg4_type)		\
void name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4)	\
{													\
	static void (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,			\
		arg3_type##_decl arg3, arg4_type##_decl arg4) = NULL;					\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ", " arg4_type##_format ")\n",				\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3),		\
			arg4_type##_func (arg4));							\
	fflush (stderr);										\
	name##_orig (arg1, arg2, arg3, arg4);								\
}

#define install_wrap_on_end_5(return_type, name, arg1_type, arg2_type, arg3_type, arg4_type, arg5_type)	\
return_type##_decl name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3,		\
		arg4_type##_decl arg4, arg5_type##_decl arg5)						\
{													\
	static return_type##_decl (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,		\
		arg3_type##_decl arg3, arg4_type##_decl arg4, arg5_type##_decl arg5) = NULL;		\
	return_type##_decl return_code;									\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ", " arg4_type##_format ", " arg5_type##_format ")",		\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3),		\
			arg4_type##_func (arg4), arg5_type##_func (arg5));				\
	fflush (stderr);										\
	return_code = name##_orig (arg1, arg2, arg3, arg4, arg5);					\
	fprintf (stderr, " = " return_type##_format "\n", return_type##_func (return_code));		\
	fflush (stderr);										\
	return return_code;										\
}

#define install_wrap_on_end_5_voidreturn(name, arg1_type, arg2_type, arg3_type, arg4_type, arg5_type)	\
void name (arg1_type##_decl arg1, arg2_type##_decl arg2, arg3_type##_decl arg3, arg4_type##_decl arg4)	\
{													\
	static void (*name##_orig) (arg1_type##_decl arg1, arg2_type##_decl arg2,			\
		arg3_type##_decl arg3, arg4_type##_decl arg4, arg5_type##_decl arg5) = NULL;		\
	if (!name##_orig)										\
		name##_orig = dl_wrap (#name);								\
	fprintf (stderr, "WRAP: " #name "(" arg1_type##_format ", " arg2_type##_format ", "		\
			arg3_type##_format ", " arg4_type##_format ", " arg5_type##_format ")\n",	\
		arg1_type##_func (arg1), arg2_type##_func (arg2), arg3_type##_func (arg3),		\
			arg4_type##_func (arg4), arg5_type##_func (arg5));				\
	fflush (stderr);										\
	name##_orig (arg1, arg2, arg3, arg4, arg5);							\
}
