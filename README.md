# 3D Vector Library (v0.1)

## Build
```bash
git clone https://github.com/godefroyponsinet/libv3d.git

./bin/configure.sh VECTOR_FLOAT
# OR
./bin/configure.sh VECTOR_INT
make -C libv3d
gcc  [ file.c, ... ] -L libv3d -lv3d -I libv3d -lm
```

## Declaration and Instantiation

All following examples will use integer coordinate vectors.
Rotation vectors are always float.

```c
#include <vector.h>

[...]

t_vector cv, rv;
int x = 0, y = 0, z = 0, w = 1;
float rx = 90, ry = 90, rz = 90, rw = 1;

/*
** Coordinate Vector
*/
cv = vector(x, y, z, w);
cv = cvector(x, y, z, w);

/*
** Rotation Vector
*/
rv = rvector(rx, ry, rz, rw);

[...]
```

## Transformations

### Translation
```c
t_vector translation = vector(0, 0, 0, 1);

v = vector_translate(v, translation);
/*
** OR
*/
v = vector_translate_x(v, 0);
v = vector_translate_y(v, 0);
v = vector_translate_z(v, 0);
```

### Rotation
```c
t_vector rotation = rvector(90, 90, 90, 1);

v = vector_rotate(v, rotation);
/*
** OR
*/
v = vector_rotate_x(v, 90);
v = vector_rotate_y(v, 90);
v = vector_rotate_z(v, 90);
```

### Scale
```c
t_vector scale = vector(0, 0, 0, 1);

v = vector_scale(v, scale);
/*
** OR
*/
v = vector_scale_x(v, 0);
v = vector_scale_y(v, 0);
v = vector_scale_z(v, 0);
```

### Perspective (not implemented)
/!\ The projection do not compute angle distortion.
It return a vector with x and y projection and z base value. (useful for z-buffer)
```c
t_vector v = vector(21, 42, 84, 1), vp;

vp = vector_perspective(v, 1280, 720); // = {320, 360, 84, 1}
```


## Arithmetic

### Basic Operations
```c
t_vector va = vector(3, 2, 1, 1), vb = vector(1, 2, 3, 1), vc;

vc = vector_add(va, vb); // = {4, 4, 4, 1}
vc = vector_sub(va, vb); // = {2, 0, -2, 1}
vc = vector_mul(va, vb); // = {3, 4, 3, 1}
vc = vector_div(va, vb); // = {3, 1, 0, 1}
vc = vector_mod(va, vb); // = {0, 0, 3, 0}
```

### Sum
```c
t_vector v = vector(2, 3, 4, 1), rv = rvector(90, 90, 90, 1);
int res;
float fres;

res = vector_sum(v); // = 10
fres = vector_rsum(rv); // = 180
```

## Others

### Length
```c
t_vector v = vector(1, 1, 1, 1);
int len;

len = vector_length(v); // axis { x, y, z}
len = vector_length_x(v); // axis { y, z }
len = vector_length_y(v); // axis { x, z }
len = vector_length_z(v); // axis { x, y }
```

### Get Min or Max
```c
t_vector v = vector(5, 2, 3, 1);
int res;

res = vector_min(v); // = 2
res = vector_min_x(v); // = 2
res = vector_min_y(v); // = 3
res = vector_min_z(v); // = 2

res = vector_max(v); // = 5
res = vector_max_x(v); // = 3
res = vector_max_y(v); // = 5
res = vector_max_z(v); // = 5
```

## License

MIT
