/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <math.h>
#include <stdio.h>
#include "vector.h"

 __attribute__((const))
t_vector	vector_rotate_x(
				register const t_vector this,
				register const t_vector_rtype x
			)
{
	return (vector_rtoc((t_vector){.rdata = {
		this.c.x,
		this.c.y * vector_cos(x) -  this.c.z * vector_sin(x),
		this.c.y * vector_sin(x) + this.c.z * vector_cos(x),
		this.c.w
	}}));
}

 __attribute__((const))
t_vector	vector_rotate_y(
				register const t_vector this,
				register const t_vector_rtype y
			)
{
	return (vector_rtoc((t_vector){.rdata = {
		this.c.x * vector_cos(y) + this.c.z * vector_sin(y),
		this.c.y,
		this.c.z * vector_cos(y) - this.c.x * vector_sin(y),
		this.c.w
	}}));
}

 __attribute__((const))
t_vector	vector_rotate_z(
				register const t_vector this,
				register const t_vector_rtype z
			)
{
	return (vector_rtoc((t_vector){.rdata = {
		this.c.x * vector_cos(z) - this.c.y * vector_sin(z),
		this.c.x * vector_sin(z) + this.c.y * vector_cos(z),
		this.c.z,
		this.c.w
	}}));
}

 __attribute__((const))
t_vector	vector_rotate(
				register const t_vector this,
				register const t_vector rotate
			)
{
	t_vector_raxis		c;
	t_vector_raxis		s;
	
	c = (t_vector_raxis){
		vector_cos(rotate.r.x), vector_cos(rotate.r.y),
		vector_cos(rotate.r.z), 0};
	s = (t_vector_raxis){
		vector_sin(rotate.r.x), vector_sin(rotate.r.y),
		vector_sin(rotate.r.z), 0};
	return (vector_rtoc((t_vector){.rdata = {
		this.c.x * (c.z * c.y)
			+ this.c.y * (c.z * s.y * s.x - s.z * c.x)
			+ this.c.z * (c.z * s.y * c.x + s.z * s.x),
		this.c.x * (s.z * c.y)
			+ this.c.y * (s.z * s.y * s.x + c.z * c.x)
			+ this.c.z * (s.z * s.y * c.x - c.z * s.x),
		this.c.x * -s.y
			+ this.c.y * c.y * s.x
			+ this.c.z * c.y * c.x,
		this.c.w
	}}));
}