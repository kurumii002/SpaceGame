#pragma once
#include "Character.h"

class Astronaut : public Character { //hereda de Character
private:
	int hp;

public:
	/**
	 * @brief Constructor de la clase, inicializa y renderiza el elemento
	 * @param width El ancho del bitmap
	 * @param height El alto del bitmap
	*/
	Astronaut(int width, int height) : Character(width, height) { //constructor del padre
		x = y = 200;
		dx = dy = 15;
		hp = rand() % 6 + 5;
	}

	~Astronaut() { }

	/**
	 * @brief Mueve el astronauta en el canvas del formulario mediante teclas, valida que no salga del canvas
	 * @param g El canvas
	 * @param i La tecla presionada
	*/
	void move(Graphics^ g, char i) {
		switch (i) {
		case 'A':
			if (x > 0) { //si la coordenada X del elemento es > a 0 (no choca a la izq)
				x -= dx; //disminuye la coordenada X (desplazamento a la izq)
				idy = 1; //sprite de caminar a la izq
			}
			break;
		case 'D':
			if (x + width * 1.5 < g->VisibleClipBounds.Width) { //si la coordenada X del elemento es < al limite derecho (no choca a la der)
				x += dx; //aumenta la coordenada X (desplazamento a la der)
				idy = 2; //sprite de caminar a la der
			}
			break;
		case 'W':
			if (y > 0) { //si la coordenada Y del elemento es > a 0 (no choca a la parte superior)
				y -= dy; //disminuye la coordenada Y (desplazamento hacia arriba)
				idy = 3; //sprite de caminar arriba
			}
			break;
		case 'S':
			if (y + height * 1.5 < g->VisibleClipBounds.Height) {  //si la coordenada Y del elemento es < al limite inferior (no choca abajo)
				y += dy; //aumenta la coordenada Y (desplazamento hacia abajo)
				idy = 0; //sprite de caminar abajo
			}
			break;
		}

		idx++; //avanza 1 fotograma del sprite
		if (idx > 3)idx = 0; //si llega al 3er fotograma, que regrese al 1ro (bucle)
	}

	/**
	 * @brief Método que decrementa 1 vida del personaje
	*/
	void decreaseHp() { hp--; }

	/**
	 * @brief Método getter que retorna la cantidad de vida del personaje
	 * @return Vidas que le quedan
	*/
	int getHp() { return hp; }
};
