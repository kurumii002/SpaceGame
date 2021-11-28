#pragma once
#include <iostream>

using namespace System::Drawing;

class Character {
protected:
	int x, y; //coordenadas
	int dx, dy; //velocidad de desplazamiento en x & y
	int width, height;
	int idx, idy; //indices (para los sprites)
	bool visible; //ocultar o mostrar el elemento

public:
	/**
	 * @brief Constructor de la clase padre, inicializa y renderiza el elemento
	 * @param width El ancho del bitmap
	 * @param height El alto del bitmap
	*/
	Character(int width, int height) {
		this->width = width;
		this->height = height;
		idx = idy = 0;
		visible = true;
	}

	~Character() { }

	/**
	 * @brief Mueve el elemento en el canvas del formulario (este método se implementará en las clases hijas)
	*/
	virtual void move() { }
	
	/**
	 * @brief Dibuja el elemento en el canvas del formulario
	 * @param g El canvas
	 * @param bmp El bitmap(imagen)
	*/
	void draw(Graphics^ g, Bitmap^ bmp) {
		//delimita cada fotograma del sprite segun el indice Y o X
		Rectangle sectionShown = Rectangle(idx * width, idy * height, width, height);

		//el zoom es para ampliar la imagen(* 1.0 = 100% de zoom, si es < 1 = encojer)
		Rectangle zoom = Rectangle(x, y, width * 1.5, height * 1.5); 

		//dibuja el elemento con el zoom y limite especificado
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	/**
	 * @brief Método para obtener el rectágulo (hitbox) del elemento
	 * @return La hitbox del elemento
	*/
	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.5, height * 1.5);
	}

	/**
	 * @brief Método setter que setea la visibilidad del elemento
	 * @param v True: visible, False: oculto
	*/
	void setVisible(bool v) { visible = v; }

	/**
	 * @brief Método getter que retorna si el elemento está o no visible
	 * @return Visibilidad del elemento (true/false)
	*/
	int getVisible() { return visible; }
};
