/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"

__attribute__((const))
t_vector	vector_translate_x(
				register const t_vector this,
				register const t_vector_ctype x)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.x = this.c.x + (x * this.c.w);
	return (tmp);
}

__attribute__((const))
t_vector	vector_translate_y(
				register const t_vector this,
				register const t_vector_ctype y)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.y = this.c.y + (y * this.c.w);
	return (tmp);
}

__attribute__((const))
t_vector	vector_translate_z(
				register const t_vector this,
				register const t_vector_ctype z)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.z = this.c.z + (z * this.c.w);
	return (tmp);
}

__attribute__((const))
t_vector	vector_translate(
				register const t_vector this,
				register const t_vector translate)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata + (translate.cdata * this.c.w);
	tmp.c.w = this.c.w * translate.c.w;
	return (tmp);
}