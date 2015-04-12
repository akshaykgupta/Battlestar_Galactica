UNAME := $(shell uname)
Compiler=g++ -std=c++11
SRC=Source/
OBJ=Objects/
EXE=Executable/
RSC=Resource/ 
EXEC=spaceRash.out

#FOR LINUX
ifeq ($(UNAME), Linux)
LIBS= -lpthread -lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lboost_serialization -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL -lGLU
INCS=-I/usr/include/bullet


execute: $(EXE)$(EXEC)
	./$<

$(EXE)$(EXEC): $(OBJ)player.o $(OBJ)spaceObject_load.o $(OBJ)laser.o $(OBJ)player_event.o $(OBJ)spaceObject_render.o $(OBJ)main.o $(OBJ)player_getsets.o  $(OBJ)message_to_game.o $(OBJ)skybox.o $(OBJ)networkIntegration.o $(OBJ)spaceObject_event.o $(OBJ)networkManager.o $(OBJ)spaceObject_getsets.o
	$(Compiler) $^ $(LIBS) -o $@ 

all:
	make $(EXE)$(EXEC)

$(OBJ)player.o: $(SRC)player.cpp
	$(Compiler) -c $< $(INCS)
	mv player.o $@

$(OBJ)spaceObject_load.o: $(SRC)spaceObject_load.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_load.o $@

$(OBJ)laser.o: $(SRC)laser.cpp
	$(Compiler) -c $< $(INCS)
	mv laser.o $@

$(OBJ)player_event.o: $(SRC)player_event.cpp
	$(Compiler) -c $< $(INCS)
	mv player_event.o $@

$(OBJ)spaceObject_render.o: $(SRC)spaceObject_render.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_render.o $@

$(OBJ)main.o: $(SRC)main.cpp
	$(Compiler) -c $< $(INCS)
	mv main.o $@

$(OBJ)player_getsets.o: $(SRC)player_getsets.cpp
	$(Compiler) -c $< $(INCS)
	mv player_getsets.o $@

$(OBJ)message_to_game.o: $(SRC)message_to_game.cpp
	$(Compiler) -c $< $(INCS)
	mv message_to_game.o $@

$(OBJ)skybox.o: $(SRC)skybox.cpp
	$(Compiler) -c $< $(INCS)
	mv skybox.o $@

$(OBJ)networkIntegration.o: $(SRC)networkIntegration.cpp
	$(Compiler) -c $< $(INCS)
	mv networkIntegration.o $@

$(OBJ)spaceObject_event.o: $(SRC)spaceObject_event.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_event.o $@

$(OBJ)networkManager.o: $(SRC)networkManager.cpp
	$(Compiler) -c $< $(INCS)
	mv networkManager.o $@

$(OBJ)spaceObject_getsets.o: $(SRC)spaceObject_getsets.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_getsets.o $@

clean:
	rm $(EXE)$(EXEC) *.tang $(OBJ)*

endif

#FOR MAC
ifeq ($(UNAME), Darwin)
LIBS=-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread-mt -lboost_serialization -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCS=-I /usr/local/Cellar/bullet/2.82/include/bullet/
FRAMEWORKS=-framework OpenGL -framework GLUT

execute: $(EXE)$(EXEC)
	./$<
$(EXE)$(EXEC): $(OBJ)player.o $(OBJ)spaceObject_load.o $(OBJ)laser.o $(OBJ)player_event.o $(OBJ)spaceObject_render.o $(OBJ)main.o $(OBJ)player_getsets.o $(OBJ)startup.o $(OBJ)message_to_game.o $(OBJ)skybox.o $(OBJ)timers.o $(OBJ)networkIntegration.o $(OBJ)spaceObject_event.o $(OBJ)networkManager.o $(OBJ)spaceObject_getsets.o
	$(Compiler) $^ $(LIBS) $(FRAMEWORKS) -o $@ 
all:
	make $(EXE)$(EXEC)

$(OBJ)player.o: $(SRC)player.cpp
	$(Compiler) -c $< $(INCS)
	mv player.o $@

$(OBJ)spaceObject_load.o: $(SRC)spaceObject_load.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_load.o $@

$(OBJ)laser.o: $(SRC)laser.cpp
	$(Compiler) -c $< $(INCS)
	mv laser.o $@

$(OBJ)player_event.o: $(SRC)player_event.cpp
	$(Compiler) -c $< $(INCS)
	mv player_event.o $@

$(OBJ)spaceObject_render.o: $(SRC)spaceObject_render.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_render.o $@

$(OBJ)main.o: $(SRC)main.cpp
	$(Compiler) -c $< $(INCS)
	mv main.o $@

$(OBJ)player_getsets.o: $(SRC)player_getsets.cpp
	$(Compiler) -c $< $(INCS)
	mv player_getsets.o $@

$(OBJ)startup.o: $(SRC)startup.cpp
	$(Compiler) -c $< $(INCS)
	mv startup.o $@

$(OBJ)message_to_game.o: $(SRC)message_to_game.cpp
	$(Compiler) -c $< $(INCS)
	mv message_to_game.o $@

$(OBJ)skybox.o: $(SRC)skybox.cpp
	$(Compiler) -c $< $(INCS)
	mv skybox.o $@

$(OBJ)timers.o: $(SRC)timers.cpp
	$(Compiler) -c $< $(INCS)
	mv timers.o $@

$(OBJ)networkIntegration.o: $(SRC)networkIntegration.cpp
	$(Compiler) -c $< $(INCS)
	mv networkIntegration.o $@

$(OBJ)spaceObject_event.o: $(SRC)spaceObject_event.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_event.o $@

$(OBJ)networkManager.o: $(SRC)networkManager.cpp
	$(Compiler) -c $< $(INCS)
	mv networkManager.o $@

$(OBJ)spaceObject_getsets.o: $(SRC)spaceObject_getsets.cpp
	$(Compiler) -c $< $(INCS)
	mv spaceObject_getsets.o $@


clean:
	rm $(EXE)$(EXEC) *.tang $(OBJ)*
endif


