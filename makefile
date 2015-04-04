UNAME := $(shell uname)
Compiler=g++ -std=c++11
SRC=Source/
OBJ=Objects/
RSC=Resource/ 
EXEC=spaceRash.out
ifeq ($(UNAME), Linux)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -lGLU
INCS=-I/usr/include/bullet
execute:$(EXEC)
	./$<
$(EXEC):
	make all
all:
	$(Compiler) $(SRC)main.cpp $(LIBS) $(INCS) -o $(EXEC)
clean:
	rm $(EXEC)
endif

ifeq ($(UNAME), Darwin)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread-mt -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCS=-I /usr/local/Cellar/bullet/2.82/include/bullet/
FRAMEWORKS=-framework OpenGL -framework GLUT
execute: $(EXEC)
	./$<
$(EXEC): 
	make all
all:
	$(Compiler) $(SRC)main.cpp $(LIBS) $(INCS) $(FRAMEWORKS) -o $(EXEC)
clean:
	rm $(EXEC)
endif