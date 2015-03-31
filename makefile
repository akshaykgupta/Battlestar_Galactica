#this is a comment.
CC= g++ -std=c++11
CFLAGS= -Wall
LIBS= -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system -lGL
INCS= -I/usr/include/bullet
SRC=Source/
OBJ=Objects/
RSC=Resource/
EXEC=bg
all: $(EXEC)
bg: $(OBJ)main.o $(OBJ)cuboid.o
	$(CC) $(OBJ)main.o $(OBJ)cuboid.o -o $(EXEC)

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) -c $(SRC)main.cpp
	mv main.o $(OBJ)main.o

$(OBJ)cuboid.o: $(SRC)cuboid.h $(SRC)cuboid.cpp
	$(CC) -c $(SRC)cuboid.cpp
	mv cuboid.o $(OBJ)cuboid.o

clean:
	rm $(OBJ)*.o
	rm $(EXEC)