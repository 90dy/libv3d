/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <math.h>
#include <stdlib.h>
#include "vector.h"

static __attribute__((const))
t_vector_rtype	*vector_sin_compute(void)
{
	static t_vector_rtype	sinus[VECTOR_ANGLE];
	unsigned long	i;

	i = 0;
	while (i < VECTOR_ANGLE)
	{
		sinus[i] = sin(
			((t_vector_rtype)i / (t_vector_rtype)(VECTOR_ANGLE))
			* (VECTOR_PI * 2.0)
		);
		++i;
	}
	return (sinus);
}

static __attribute__((const))
t_vector_rtype	*vector_cos_compute(void)
{
	static t_vector_rtype	cosinus[VECTOR_ANGLE];
	unsigned long	i;

	i = 0;
	while (i < VECTOR_ANGLE)
	{
		cosinus[i] = cos(
			((t_vector_rtype)i / (t_vector_rtype)(VECTOR_ANGLE))
			* (VECTOR_PI * 2.0)
		);
		++i;
	}
	return (cosinus);
}

__attribute__((const))
t_vector_rtype	vector_sin(register t_vector_rtype a)
{
	static t_vector_rtype	*sinus = 0;

	if (!sinus)
		sinus = vector_sin_compute();
	if (a >= 0)
		return (sinus[abs(a * VECTOR_ANGLE_D) % VECTOR_ANGLE]);
	return (-sinus[abs(a * VECTOR_ANGLE_D) % VECTOR_ANGLE]);
}

__attribute__((const))
t_vector_rtype	vector_cos(register t_vector_rtype a)
{
	static t_vector_rtype	*cosinus = 0;

	if (!cosinus)
		cosinus = vector_cos_compute();
	return (cosinus[abs(a * VECTOR_ANGLE_D) % VECTOR_ANGLE]);
}
