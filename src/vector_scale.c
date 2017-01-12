/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"


__attribute__((const))
t_vector	vector_scale_x(
				register const t_vector this,
				register const t_vector_ctype x)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.x = this.c.x * x;
	return (tmp);
}

__attribute__((const))
t_vector	vector_scale_y(
				register const t_vector this,
				register const t_vector_ctype y)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.y = this.c.y * y;
	return (tmp);
}

__attribute__((const))
t_vector	vector_scale_z(
				register const t_vector this,
				register const t_vector_ctype z)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata;
	tmp.c.z = this.c.z * z;
	return (tmp);
}

__attribute__((const))
t_vector	vector_scale(
				register const t_vector this,
				register const t_vector scale)
{
	register t_vector	tmp;

	tmp.cdata = this.cdata * scale.cdata;
	return (tmp);
}