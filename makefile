UNAME := $(shell uname)
Compiler=g++ -std=c++11
SRC=Source/
OBJ=Objects/
RSC=Resource/ 
ifeq ($(UNAME), Linux)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -lGLU
INCS=-I/usr/include/bullet
execute:$(SRC)a.out
	./$<
$(SRC)a.out:
	make all
all:
	$(Compiler) $(SRC)main.cpp $(LIBS) $(INCS) -o $(SRC)a.out
clean:
	rm $(SRC)a.out
endif

ifeq ($(UNAME), Darwin)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread-mt -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCS=-I /usr/local/Cellar/bullet/2.82/include/bullet/
FRAMEWORKS=-framework OpenGL -framework GLUT
execute: $(SRC)a.out
	./$<
$(SRC)a.out: 
	make all
all:
	$(Compiler) $(SRC)main.cpp $(LIBS) $(INCS) $(FRAMEWORKS) -o $(SRC)a.out
clean:
	rm $(SRC)a.out
endif