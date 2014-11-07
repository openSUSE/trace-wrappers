/* wrap-alloc.c -- allocation functions wrapper

   Copyright (C) SUSE Linux
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

#include <dlwrap/dlwrap.h>
#include <dlwrap/printf.h>

dlwrap_install_1 (void_pointer, malloc, size_t);
dlwrap_install_1 (void, free, void_pointer);
dlwrap_install_2 (void_pointer, realloc, void_pointer, size_t);
