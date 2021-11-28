#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite; //para escribir dentro del archivo
	ifstream fileRead; //para leer u obtener datos del archivo
	string text; //el texto a escribir

	int secondsMeteorites; //cada cuantos segundos caerá un meteorito
	int time; //tiempo de juego

public:
	File() { }

	/**
	 * @brief Método para leer los datos del archivo
	*/
	void readData() {
		fileRead.open("config.txt", ios::in); //busca el archivo y lo abre

		if (fileRead.fail()) { //si ha fallado la apertura del archivo
			fileRead.close(); //cierra

			fileWrite.open("config.txt", ios::out); //crea un nuevo archivo
			fileWrite << "2" << endl; //cada 2 seg caerá un meterito
			fileWrite << "60" << endl; //escribe el tiempo x defecto
			fileWrite.close();

			fileRead.open("config.txt", ios::in); //abre el archivo creado
		}

		getline(fileRead, text); //obtiene la 1ra linea del txt y asigna el valor a text
		secondsMeteorites = atoi(text.c_str()); //transforma el texto a int y le asigna a la variable
		getline(fileRead, text); 
		time = atoi(text.c_str());

		fileRead.close();
	}

	/**
	 * @brief Obtiene el tiempo en el que caerá un meteorito
	 * @return 
	*/
	int getSecondsMeteorites() { return secondsMeteorites; }

	/**
	 * @brief Obtiene el tiempo que se definió en el archivo
	 * @return El tiempo definido
	*/
	int getTime() { return time; }
};