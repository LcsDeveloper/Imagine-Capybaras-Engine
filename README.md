# IMAGINE CAPYBARAS ENGINE
## What's that?
Imagine Capybaras Engine is a open source game engine developed as part of activities from book "Learn OpenGL - Graphics Programming". Implemented exclusive in C using OpenGl, an open source graphics library.

## How to use?
To use the engine it is necessary to install the dependencies
```
sudo apt-get update
sudo apt-get install cmake pkg-config
sudo apt-get install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt-get install libglew-dev libglfw3-dev libglm-dev
sudo apt-get install libao-dev libmpg123-dev
```
Before adding the directory ``/includes`` and ``/lib`` to your project. For convenience, the file ``ImCapy.h`` inclued all headers implemented, but you'll still need the files ``/include/glad.h``, ``/include/glfw.h``, ``/include/gltext.h``, ``/include/khrplataform.h``, ``/include/stb_image.h``.
To compile use
```
g++ [main file] [reference to lib] -lglfw -I [includes] -o [bin]
```
## Example game developed with engine
[The Rooms](https://yo-lyo.itch.io/the-rooms)
