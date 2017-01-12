/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"

__attribute__((const))
t_vector	rvector(
				register const t_vector_rtype x,
				register const t_vector_rtype y,
				register const t_vector_rtype z,
				register const t_vector_rtype w)
{
	return ((t_vector){.rdata = {x, y, z, w}});
}

__attribute__((const))
t_vector	cvector(
				register const t_vector_ctype x,
				register const t_vector_ctype y,
				register const t_vector_ctype z,
				register const t_vector_ctype w)
{
	return ((t_vector){.cdata = {x, y, z, w}});
}

__attribute__((const))
t_vector	vector(
				register const t_vector_ctype x,
				register const t_vector_ctype y,
				register const t_vector_ctype z,
				register const t_vector_ctype w)
{
	return ((t_vector){.cdata = {x, y, z, w}});
}
