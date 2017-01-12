/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"

__attribute__((const))
t_vector	vector_add(
				register const t_vector this,
				register const t_vector rhs)
{
	return ((t_vector){.cdata = this.cdata + rhs.cdata});
}

__attribute__((const))
t_vector	vector_sub(
				register const t_vector this,
				register const t_vector rhs)
{
	return ((t_vector){.cdata = this.cdata - rhs.cdata});
}

__attribute__((const))
t_vector	vector_mul(
				register const t_vector this,
				register const t_vector rhs)
{
	return ((t_vector){.cdata = this.cdata * rhs.cdata});
}

__attribute__((const))
t_vector	vector_div(
				register const t_vector this,
				register const t_vector rhs)
{
	return ((t_vector){.cdata = this.cdata / rhs.cdata});
}

__attribute__((const))
t_vector	vector_mod(
				register const t_vector this,
				register const t_vector rhs)
{
#ifdef VECTOR_INT
	return ((t_vector){.cdata = this.cdata / rhs.cdata});
#endif
	(void)this;
	(void)rhs;
	return ((t_vector){.cdata = {0, 0, 0, 1}});
}