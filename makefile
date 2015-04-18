UNAME := $(shell uname)
Compiler=g++ -std=c++11
SRC=Source/
OBJ=Objects/
EXE=Executable/
RSC=Resource/ 
EXEC=spaceRash.out
Files=*.o
#FOR LINUX
ifeq ($(UNAME), Linux)
LIBS= -lpthread -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lboost_serialization -lsfgui -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -lGLU
INCS=-I/usr/include/bullet

$(EXE)$(EXEC):  $(OBJ)message.o $(OBJ)userSettings.o  $(OBJ)skybox.o  $(OBJ)networkManager.o $(OBJ)weapon.o  $(OBJ)spaceObject_load.o $(OBJ)spaceObject_render.o $(OBJ)spaceObject_event.o $(OBJ)spaceObject_getsets.o $(OBJ)startJoinScreen.o $(OBJ)selectShipScreen.o $(OBJ)player.o $(OBJ)player_world.o $(OBJ)player_event.o $(OBJ)player_getsets.o $(OBJ)player_network.o $(OBJ)player_handle.o $(OBJ)main.o
	$(Compiler) $^ $(LIBS) -o $@ 

all:
	make $(EXE)$(EXEC)

$(OBJ)selectShipScreen.o: $(SRC)selectShipScreen.hpp $(SRC)selectShipScreen.cpp
	$(Compiler) -c $(SRC)selectShipScreen.cpp $(INCS)
	mv selectShipScreen.o $@

$(OBJ)startJoinScreen.o: $(SRC)startJoinScreen.hpp $(SRC)startJoinScreen.cpp
	$(Compiler) -c $(SRC)startJoinScreen.cpp $(INCS)
	mv startJoinScreen.o $@

$(OBJ)spaceObject_load.o: $(SRC)spaceObject_load.cpp
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_load.o $@

$(OBJ)spaceObject_render.o: $(SRC)spaceObject_render.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_render.o $@

$(OBJ)spaceObject_event.o: $(SRC)spaceObject_event.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_event.o $@

$(OBJ)spaceObject_getsets.o: $(SRC)spaceObject_getsets.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_getsets.o $@

$(OBJ)player.o: $(SRC)player.cpp
	$(Compiler) -c $^ $(INCS)
	mv player.o $@

$(OBJ)player_event.o: $(SRC)player_event.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_event.o $@

$(OBJ)player_world.o: $(SRC)player_world.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_world.o $@

$(OBJ)player_getsets.o: $(SRC)player_getsets.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_getsets.o $@

$(OBJ)player_network.o: $(SRC)player_network.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_network.o $@

$(OBJ)player_handle.o: $(SRC)player_handle.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_handle.o $@

$(OBJ)main.o: $(SRC)main.cpp
	$(Compiler) -c $< $(INCS)
	mv main.o $@

$(OBJ)skybox.o: $(SRC)skybox.cpp
	$(Compiler) -c $< $(INCS)
	mv skybox.o $@

$(OBJ)networkManager.o: $(SRC)networkManager.cpp
	$(Compiler) -c $< $(INCS)
	mv networkManager.o $@

$(OBJ)userSettings.o: $(SRC)userSettings.cpp
	$(Compiler) -c $^ $(INCS)
	mv userSettings.o $@

$(OBJ)weapon.o: $(SRC)weapon.cpp
	$(Compiler) -c $^ $(INCS)
	mv weapon.o $@

$(OBJ)message.o: $(SRC)message.cpp
	$(Compiler) -c $^ $(INCS)
	mv message.o $@

execute: $(EXE)$(EXEC)
	./$< $1 $2 $3

clean:
	rm $(EXE)$(EXEC) *.tang $(OBJ)*
cleanFiles:
	rm $(Files) 
endif

#FOR MAC
ifeq ($(UNAME), Darwin)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread-mt -lboost_serialization -lsfgui -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCS=-I /usr/local/Cellar/bullet/2.82/include/bullet/
FRAMEWORKS=-framework OpenGL -framework GLUT

$(EXE)$(EXEC):  $(OBJ)message.o $(OBJ)userSettings.o  $(OBJ)skybox.o  $(OBJ)networkManager.o $(OBJ)weapon.o  $(OBJ)spaceObject_load.o $(OBJ)spaceObject_render.o $(OBJ)spaceObject_event.o $(OBJ)spaceObject_getsets.o $(OBJ)selectShipScreen.o $(OBJ)startJoinScreen.o $(OBJ)player.o $(OBJ)player_world.o $(OBJ)player_event.o $(OBJ)player_getsets.o $(OBJ)player_network.o $(OBJ)player_handle.o $(OBJ)main.o
	$(Compiler) $^ $(LIBS) $(FRAMEWORKS) -o $@ 

all:
	make $(EXE)$(EXEC)

$(OBJ)selectShipScreen.o: $(SRC)selectShipScreen.hpp $(SRC)selectShipScreen.cpp
	$(Compiler) -c $(SRC)selectShipScreen.cpp $(INCS)
	mv selectShipScreen.o $@

$(OBJ)startJoinScreen.o: $(SRC)startJoinScreen.hpp $(SRC)startJoinScreen.cpp
	$(Compiler) -c $(SRC)startJoinScreen.cpp $(INCS)
	mv startJoinScreen.o $@

$(OBJ)spaceObject_load.o: $(SRC)spaceObject_load.cpp
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_load.o $@

$(OBJ)spaceObject_render.o: $(SRC)spaceObject_render.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_render.o $@

$(OBJ)spaceObject_event.o: $(SRC)spaceObject_event.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_event.o $@

$(OBJ)spaceObject_getsets.o: $(SRC)spaceObject_getsets.cpp 
	$(Compiler) -c $^ $(INCS)
	mv spaceObject_getsets.o $@

$(OBJ)player.o: $(SRC)player.cpp
	$(Compiler) -c $^ $(INCS)
	mv player.o $@

$(OBJ)player_event.o: $(SRC)player_event.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_event.o $@

$(OBJ)player_world.o: $(SRC)player_world.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_world.o $@

$(OBJ)player_getsets.o: $(SRC)player_getsets.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_getsets.o $@

$(OBJ)player_network.o: $(SRC)player_network.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_network.o $@

$(OBJ)player_handle.o: $(SRC)player_handle.cpp
	$(Compiler) -c $^ $(INCS)
	mv player_handle.o $@

$(OBJ)main.o: $(SRC)main.cpp
	$(Compiler) -c $< $(INCS)
	mv main.o $@

$(OBJ)skybox.o: $(SRC)skybox.cpp
	$(Compiler) -c $< $(INCS)
	mv skybox.o $@

$(OBJ)networkManager.o: $(SRC)networkManager.cpp
	$(Compiler) -c $< $(INCS)
	mv networkManager.o $@

$(OBJ)userSettings.o: $(SRC)userSettings.cpp
	$(Compiler) -c $^ $(INCS)
	mv userSettings.o $@

$(OBJ)weapon.o: $(SRC)weapon.cpp
	$(Compiler) -c $^ $(INCS)
	mv weapon.o $@

$(OBJ)message.o: $(SRC)message.cpp
	$(Compiler) -c $^ $(INCS)
	mv message.o $@

execute: $(EXE)$(EXEC)
	./$< $1 $2 $3

clean:
	rm $(EXE)$(EXEC) *.tang $(OBJ)*
cleanFiles:
	rm $(Files) 
endif