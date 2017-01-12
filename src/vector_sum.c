/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"

__attribute__((const))
t_vector_rtype	vector_rsum(register const t_vector this)
{
	return (this.r.x + this.r.y + this.r.z + this.r.w);
}

__attribute__((const))
t_vector_ctype	vector_csum(register const t_vector this)
{
	return (this.c.x + this.c.y + this.c.z + this.c.w);
}

__attribute__((const))
t_vector_ctype	vector_sum(register const t_vector this)
{
	return (this.c.x + this.c.y + this.c.z + this.c.w);
}