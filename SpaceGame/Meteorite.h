#pragma once
#include "Character.h"

class Meteorite : public Character {
private:
	bool land; //para verificar si el meteorito aterrizo

public:
	/**
	 * @brief Constructor de la clase, inicializa y renderiza el elemento
	 * @param width El ancho del bitmap
	 * @param height El alto del bitmap
	*/
	Meteorite(int width, int height) : Character(width, height) {
		x = rand() % 400;
		y = 5;
		dx = dy = 10;
		land = false;
	}

	~Meteorite() { }

	/**
	 * @brief Mueve el meteorito en el canvas del formulario, valida que no salga del canvas
	 * @param g El canvas
	*/
	void move(Graphics^ g) {
		if (y + height * 1.5 < g->VisibleClipBounds.Height) { //si el elemento no choca abajo
			y += dy; //el meteorito se desplaza hacia abajo (y aumenta)
			idy++; //avanza 1 fotograma del sprite (para la animacion)

			if (idy > 7) idy = 0; //si alcanza el máximo de fotogramas, que se reinicie (animacion bucle)
		}
		else { //si choca abajo
			land = true; //establece el meteorito como aterrizado
		}
	}

	/**
	 * @brief Verifica si el meteorito ha aterrizado
	 * @return Si el meteorito ha aterrizado o no (true/false)
	*/
	bool getLand() { return land; }
};
