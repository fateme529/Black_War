all: compile link 

compile:
	g++ -Isfml/include -c src/main.cpp src/app.cpp src/shoot.cpp src/heli.cpp

link:
	g++ main.o app.o heli.o shoot.o 