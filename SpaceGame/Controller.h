#pragma once
#include "Astronaut.h"
#include "Meteorite.h"
#include <vector>

using namespace std;

class Controller {
private:
	int time;
	Astronaut* astronaut;
	vector<Meteorite*> meteorites;

public:
	/**
	 * @brief Constructor del controlador, contiene la lógica del juego
	 * @param bmpAstronaut Bitmap del astronauta
	 * @param time El tiempo del juego
	*/
	Controller(Bitmap^ bmpAstronaut, int time) {
		this->time = time;
		astronaut = new Astronaut(bmpAstronaut->Width / 4, bmpAstronaut->Height / 4);
	}

	/**
	 * @brief Agrega un meteorito en el vector
	 * @param m El meteorito (objeto)
	*/
	void addMeteorite(Meteorite* m) {
		meteorites.push_back(m);
	}

	/**
	 * @brief Obtiene la cantidad de meteoritos que han aterrizado
	 * @return Meteoritos aterrizados
	*/
	int getLandeMeteorites() {
		int cont = 0;

		for (int i = 0; i < meteorites.size(); i++) {
			if (meteorites[i]->getLand()) {
				cont++;
			}
		}

		return cont;
	}

	/**
	 * @brief Dibuja todos los elementos en el canvas
	 * @param g El canvas
	 * @param bmpAstronaut El bitmap del astronauta
	 * @param bmpMeteorite El bitmap del meteorito
	*/
	void drawEverything(Graphics^ g, Bitmap^ bmpAstronaut, Bitmap^ bmpMeteorite) {
		astronaut->draw(g, bmpAstronaut);

		for each (Meteorite* m in meteorites) {
			m->draw(g, bmpMeteorite);
		}
	}

	/**
	 * @brief Mueve todos los elementos en el canvas (solo los que tienen movimiento automático)
	 * @param g El canvas
	*/
	void moveEverything(Graphics^ g) {
		for each (Meteorite* m in meteorites) {
			m->move(g);
		}
	}

	/**
	 * @brief Realiza la colisión de elementos en el canvas
	*/
	void collision() {
		//verifica si un meteorito choca con el astronauta
		for (int i = 0; i < meteorites.size(); i++) {
			//si choca
			if (astronaut->getRectangle().IntersectsWith(meteorites[i]->getRectangle())) {
				meteorites[i]->setVisible(false); //oculta el meteorito (desaparece del canvas)
				astronaut->decreaseHp(); //baja la vida del personaje
			}
		}

		//eliminación
		for (int i = 0; i < meteorites.size(); i++) {
			if (!meteorites[i]->getVisible()) { //si el meteorito está oculto (visible = false)
				meteorites.erase(meteorites.begin() + i); //borra los elementos del canvas
			}
		}
	}

	/**
	 * @brief Obtiene al personaje
	 * @return El astronauta
	*/
	Astronaut* getAstronaut() { return astronaut; }

	/**
	 * @brief Para obtener el tiempo (del archivo)
	 * @return El tiempo en segundos
	*/
	int getTime() { return time; }

	/**
	 * @brief Decrementa el tiempo en 1
	*/
	void decreaseTime() { time--; }
};
