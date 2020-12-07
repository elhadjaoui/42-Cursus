# miniRT

### Library used
> -lmlx -framework OpenGL -framework AppKit

 &&
 
> minilibx_mms/libmlx.dylib

### how to run 
##### macOS
> $ make re && ./miniRT Scene/.._rt [--save]
##### linux
> make a little change on Makefile.
> change " -lmlx -framework OpenGL -framework AppKit libmlx.dylib " 

by

> " gcc -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit".

and dont forget the mlx_get_screen_size(...) (available only in minilibx_mms/libmlx.dylib)

### Norme 
> $ make norme

#

<p align="center">
  <img src="../images/cylinder.bmp" alt="cylinder" title="Screenshot">
</p>

<p align="center">
  <img src="../images/first.bmp" alt="first" title="Screenshot">
</p>

<p align="center">
  <img src="../images/miniRT copy 2.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/wolf.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/miniRT.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/scene.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/second.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/square.bmp" alt="first" title="Screenshot">
</p>
<p align="center">
  <img src="../images/view.bmp" alt="first" title="Screenshot">
</p>
