#! /bin/bash
OBJ=objects
rm $OBJ/*.o
rm bin/run
g++ -c src/Vector3.cpp        -o $OBJ/Vector3.o
g++ -c src/ParticleSystem.cpp -o $OBJ/ParticleSystem.o
g++ -c src/main.cpp           -o $OBJ/main.o
g++ -Wall -o bin/run $OBJ/main.o $OBJ/ParticleSystem.o $OBJ/Vector3.o 

