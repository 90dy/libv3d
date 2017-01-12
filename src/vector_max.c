/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "vector.h"

__attribute__((const))
t_vector_ctype	vector_max_x(register const t_vector this)
{
	if (this.c.y > this.c.z)
		return (this.c.y);
	return (this.c.z);
}

__attribute__((const))
t_vector_ctype	vector_max_y(register const t_vector this)
{
	if (this.c.x > this.c.z)
		return (this.c.x);
	return (this.c.z);
}

__attribute__((const))
t_vector_ctype	vector_max_z(register const t_vector this)
{
	if (this.c.x > this.c.y)
		return (this.c.z);
	return (this.c.y);
}

__attribute__((const))
t_vector_ctype	vector_max(register const t_vector this)
{
	if (this.c.x > this.c.y)
		if (this.c.x > this.c.z)
			return (this.c.x);
		else
			return (this.c.z);
	else
		if (this.c.y > this.c.z)
			return (this.c.y);
		else	
			return (this.c.z);
	return (0);
}