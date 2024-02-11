INCLUDE = ./include
SRC = ./src
OBJ = ./obj
LIB = ./lib
CXX = g++

FLAGS = -O3 -Wall -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

all: include

include:\
	$(OBJ)/glad.o \
	$(OBJ)/stb_image.o \
	$(OBJ)/square.o \
	$(OBJ)/window_manager.o \
	$(OBJ)/shaders.o \
	$(OBJ)/texture.o \
	$(OBJ)/cam.o \
	$(OBJ)/animation.o \
	$(OBJ)/text.o \
	$(OBJ)/transform.o \
	$(OBJ)/color.o \
	$(OBJ)/collision.o \
	$(OBJ)/time.o
	ar -rcs $(LIB)/libImCapy.a $(OBJ)/*.o

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CXX) -c $< -Wall -I $(INCLUDE) -o $@
	
clean:
	rm -rf $(LIB)/* $(OBJ)/*


