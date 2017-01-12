/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <math.h>
#include "vector.h"

__attribute__((const))
t_vector	vector_rtoc(register const t_vector this)
{
#ifndef VECTOR_INT
	return (this);
#else
	return ((t_vector){.cdata = {
		round(this.r.x),
		round(this.r.y),
		round(this.r.z),
		round(this.r.w)
	}});
#endif
}