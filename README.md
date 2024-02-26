# fdf
42's fdf task (macos edition). makes funny 3d wireframes from a 2d map of heights of the following type:
```
1 2 3
4 1 1
2 3 1
```
or you can add color (selectively) with a comma and a hex number like that:
```
1 2 3
4 1,0xFF 1
2 3 1,0xff00
```
the capitalization doesn't matter, neither should the leading zeroes. the 0x does matter.

this is NOT a project about parsing maps. we assume that you don't screw them up.

file format: *mapname*.fdf

to build, just run
```
make
```
if on linux, use the [fdf_real_linux branch](https://github.com/DISN-kolo/fdf/tree/fdf_real_linux/)
# must see before coding
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

# anything else?
ft printf does so to strerr because i use it only for error printing and it's much much easier like that

W to make the vertical scale smaller, S to make the total scale smaller. Q and A respectively to do the reverse. arrow keys to pan.

this project is NOT optimized for big maps with custom colors. beware.
# project structure
...dictated by *norminette*. sorry. sources are in src, the libraries are elsewhere in their own folders.
