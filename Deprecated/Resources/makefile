LIBS=`sdl-config --cflags --libs` -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FRAMEWORKS=-framework OpenGL -framework GLUT -I/usr/local/Cellar/sdl_image/1.2.12_1/include -L/usr/local/Cellar/sdl_image/1.2.12_1/lib/
all:
	g++ tempRender.cpp -o tempRender.o $(LIBS) $(FRAMEWORKS)
execute: tempRender.o
	./$<
tempRender.o:
	make all