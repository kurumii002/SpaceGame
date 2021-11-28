#pragma once
#include <ctime>
#include <iostream>
#include "Controller.h"
#include "File.h"

namespace SpaceGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			
			//carga del buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//carga de bitmaps
			bmpAstronaut = gcnew Bitmap("astronauta.png");
			bmpMap = gcnew Bitmap("marte.png");
			bmpMeteorite = gcnew Bitmap("meteoritos.png");

			//leer datos del archivo
			file = new File();
			file->readData();

			//empezar el juego
			controller = new Controller(bmpAstronaut, file->getTime());
		}

	private:
		//instancias para el buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//instancia para el controlador
		Controller* controller;

		//instancias para los bitmaps
		Bitmap^ bmpAstronaut;
		Bitmap^ bmpMap;
		Bitmap^ bmpMeteorite;

		//instancia para el archivo
		File* file;

	private: System::Windows::Forms::Timer^ timerMeteorites;
	private: System::Windows::Forms::Label^ lblMeteorites;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblHp;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timerTiempo;

		

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblMeteorites = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblHp = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerMeteorites = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTiempo = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblMeteorites);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->lblHp);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(686, 472);
			this->panel1->TabIndex = 0;
			// 
			// lblMeteorites
			// 
			this->lblMeteorites->AutoSize = true;
			this->lblMeteorites->Location = System::Drawing::Point(118, 46);
			this->lblMeteorites->Name = L"lblMeteorites";
			this->lblMeteorites->Size = System::Drawing::Size(13, 13);
			this->lblMeteorites->TabIndex = 5;
			this->lblMeteorites->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 46);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Landed Meteorites:";
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(53, 29);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(13, 13);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Time:";
			// 
			// lblHp
			// 
			this->lblHp->AutoSize = true;
			this->lblHp->Location = System::Drawing::Point(45, 12);
			this->lblHp->Name = L"lblHp";
			this->lblHp->Size = System::Drawing::Size(13, 13);
			this->lblHp->TabIndex = 1;
			this->lblHp->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"HP:";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// timerMeteorites
			// 
			this->timerMeteorites->Interval = 2000;
			this->timerMeteorites->Tick += gcnew System::EventHandler(this, &FrmMain::timerMeteorites_Tick);
			// 
			// timerTiempo
			// 
			this->timerTiempo->Enabled = true;
			this->timerTiempo->Interval = 1000;
			this->timerTiempo->Tick += gcnew System::EventHandler(this, &FrmMain::timerTiempo_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 474);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//CLEAR
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//COLLISION
		controller->collision();

		//MOVE
		controller->moveEverything(buffer->Graphics);

		//DRAW
		lblHp->Text = "" + controller->getAstronaut()->getHp();
		lblMeteorites->Text = "" + controller->getLandeMeteorites();
		lblTime->Text = "" + controller->getTime();

		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		controller->drawEverything(buffer->Graphics, bmpAstronaut, bmpMeteorite);

		//CONDITION (RENDER)
		if (controller->getAstronaut()->getHp() == 0) { //si el personaje no tiene vidas
			timerMain->Enabled = false; //detiene el timer
			MessageBox::Show("Game Over"); //game over
			this->Close(); //cerrar el formulario
		}
		else if (controller->getTime() == 0) { //si el tiempo llega a 0
			timerMain->Enabled = false; //detiene el timer
			MessageBox::Show("You Win"); //you win
			this->Close(); //cerrar el formulario
		}
		else {
			//RENDER
			buffer->Render(g);
		}
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::A:
			controller->getAstronaut()->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			controller->getAstronaut()->move(buffer->Graphics, 'D'); break;
		case Keys::W:
			controller->getAstronaut()->move(buffer->Graphics, 'W'); break;
		case Keys::S:
			controller->getAstronaut()->move(buffer->Graphics, 'S'); break;
		}
	}
	private: System::Void timerMeteorites_Tick(System::Object^ sender, System::EventArgs^ e) {
		Meteorite* m = new Meteorite(bmpMeteorite->Width / 8, bmpMeteorite->Height / 8);
		controller->addMeteorite(m);
	}
	private: System::Void timerTiempo_Tick(System::Object^ sender, System::EventArgs^ e) {
		controller->decreaseTime();
	}
	private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
		timerMeteorites->Interval = 1000 * file->getSecondsMeteorites();
		timerMeteorites->Enabled = true;
	}
};
}
