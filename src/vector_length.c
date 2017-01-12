/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <math.h>
#include "vector.h"

__attribute__((const))
t_vector_ctype	vector_length_x(register const t_vector this)
{
	return ((t_vector_ctype)sqrt((double)(
		this.c.y * this.c.y	+ this.c.z * this.c.z
	)));
}

__attribute__((const))
t_vector_ctype	vector_length_y(register const t_vector this)
{
	return ((t_vector_ctype)sqrt((double)(
		this.c.x * this.c.x + this.c.z * this.c.z
	)));
}

__attribute__((const))
t_vector_ctype	vector_length_z(register const t_vector this)
{
	return ((t_vector_ctype)sqrt((double)(
		this.c.x * this.c.x + this.c.y * this.c.y
	)));
}

__attribute__((const))
t_vector_ctype	vector_length(register const t_vector this)
{
	return ((t_vector_ctype)sqrt((double)vector_sum(vector_mul(this, this))));
}