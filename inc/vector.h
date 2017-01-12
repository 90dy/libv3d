/**
 * Copyright (c) 2017 <godefroy.ponsinet@outlook.com>
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef VECTOR_H
# define VECTOR_H

# define VECTOR_PI		3.14159265358979323846

# define VECTOR_ANGLE	360000
# define VECTOR_ANGLE_I	360
# define VECTOR_ANGLE_D	1000

# ifdef VECTOR_INT
typedef int				t_vector_ctype;
typedef float			t_vector_rtype;
# else
typedef float			t_vector_ctype;
typedef float			t_vector_rtype;
# endif

typedef t_vector_ctype	t_vector_cdata __attribute__((vector_size(sizeof(t_vector_ctype) * 4)));
typedef t_vector_rtype	t_vector_rdata __attribute__((vector_size(sizeof(t_vector_rtype) * 4)));

typedef struct			s_vector_caxis
{
	t_vector_ctype		x;
	t_vector_ctype		y;
	t_vector_ctype		z;
	t_vector_ctype		w;
}						t_vector_caxis;

typedef struct			s_vector_raxis
{
	t_vector_rtype		x;
	t_vector_rtype		y;
	t_vector_rtype		z;
	t_vector_rtype		w;
}						t_vector_raxis;

typedef union			u_cvector
{
	t_vector_cdata		cdata;
	t_vector_caxis		c;
	t_vector_ctype		cvalue[4];
}						t_cvector;

typedef union			u_rvector
{
	t_vector_rdata		rdata;
	t_vector_raxis		r;
	t_vector_rtype		rvalue[4];
}						t_rvector;

typedef union			u_vector
{
	t_vector_cdata		cdata;
	t_vector_caxis		c;
	t_vector_ctype		cvalue[4];
	t_vector_rdata		rdata;
	t_vector_raxis		r;
	t_vector_rtype		rvalue[4];
}						t_vector;

t_vector				vector(
							register const t_vector_ctype x,
							register const t_vector_ctype y,
							register const t_vector_ctype z,
							register const t_vector_ctype w
						) __attribute__((const));
t_vector				cvector(
							register const t_vector_ctype x,
							register const t_vector_ctype y,
							register const t_vector_ctype z,
							register const t_vector_ctype w
						) __attribute__((const));
t_vector				rvector(
							register const t_vector_rtype x,
							register const t_vector_rtype y,
							register const t_vector_rtype z,
							register const t_vector_rtype w
						) __attribute__((const));

t_vector				vector_rtoc(register const t_vector this
						) __attribute__((const));

t_vector_rtype			vector_cos(register const t_vector_rtype a
						) __attribute__((const));
t_vector_rtype			vector_sin(register const t_vector_rtype a
						) __attribute__((const));

t_vector_ctype			vector_length(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_length_x(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_length_y(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_length_z(register const t_vector this
						) __attribute__((const));

t_vector_ctype			vector_max(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_max_x(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_max_y(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_max_z(register const t_vector this
						) __attribute__((const));

t_vector_ctype			vector_min(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_min_x(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_min_y(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_min_z(register const t_vector this
						) __attribute__((const));

t_vector_ctype			vector_sum(register const t_vector this
						) __attribute__((const));
t_vector_ctype			vector_csum(register const t_vector this
						) __attribute__((const));
t_vector_rtype			vector_rsum(register const t_vector this
						)__attribute__((const));

t_vector				vector_add(
							register const t_vector this,
							register const t_vector rhs
						) __attribute__((const));
t_vector				vector_sub(
							register const t_vector this,
							register const t_vector rhs
						) __attribute__((const));
t_vector				vector_mul(
							register const t_vector this,
							register const t_vector rhs
						) __attribute__((const));
t_vector				vector_div(
							register const t_vector this,
							register const t_vector rhs
						) __attribute__((const));
t_vector				vector_mod(
							register const t_vector this,
							register const t_vector rhs
						) __attribute__((const));

t_vector				vector_translate(
							register const t_vector this,
							register const t_vector t
						) __attribute__((const));
t_vector				vector_translate_x(
							register const t_vector this,
							register const t_vector_ctype x
						) __attribute__((const));
t_vector				vector_translate_y(
							register const t_vector this, 
							register const t_vector_ctype y
						) __attribute__((const));
t_vector				vector_translate_z(
							register const t_vector this,
							register const t_vector_ctype z
						) __attribute__((const));

t_vector				vector_rotate(
							register const t_vector this,
							register const t_vector rotate
						) __attribute__((const));
t_vector				vector_rotate_x(
							register const t_vector this,
							register const t_vector_rtype t
						) __attribute__((const));
t_vector				vector_rotate_y(
							register const t_vector this,
							register const t_vector_rtype t
						) __attribute__((const));
t_vector				vector_rotate_z(
							register const t_vector this,
							register const t_vector_rtype t
						) __attribute__((const));

t_vector				vector_scale(
							register const t_vector this,
							register const t_vector s
						) __attribute__((const));
t_vector				vector_scale_x(
							register const t_vector this,
							register const t_vector_ctype x
						) __attribute__((const));
t_vector				vector_scale_y(
							register const t_vector this,
							register const t_vector_ctype y
						) __attribute__((const));
t_vector				vector_scale_z(
							register const t_vector this,
							register const t_vector_ctype z
						) __attribute__((const));

t_vector				vector_project(
							register const t_vector this
						) __attribute__((const));

#endif