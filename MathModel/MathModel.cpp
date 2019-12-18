#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "MM_H.h"

#define DEBUG_MODE  //Debug mode only for developers
#define UDP_CONNECT //Обмен по Ethernet

extern double Delta_D, m2, m3, u;

////////////////////////
// УРАВНЕНИЯ ДВИЖЕНИЯ //
////////////////////////

// 1. Алгоритмы операций с матрицами и векторами //
// 1.1. Вычисление матриц поворота //
void ForRotMatr(int iaxis,double angle,TVect3 Matr) {
	int i, j;
	double s, c;
	c = cos(angle);
	s = sin(angle);
	for (i = 1; i < 4; i++)
		for (j = 1; j < 4; j++)
			if (i = j)
				Matr[i, j] = 1, 0;
			else
			{
				Matr[i, j] = 0, 0;
			}
	switch (iaxis)
	{
	case 1: //rotate around OX axis
		Matr[2, 2] = +c;
		Matr[2, 3] = +s;
		Matr[3, 2] = -s;
		Matr[3, 3] = +c;
	case 2: //rotate around OY axis
		Matr[1,1] = +c;
		Matr[1,3] = -s;
		Matr[3,1] = +s;
		Matr[3,3] = +c;
	case 3: //rotate around OZ axis
		Matr[1, 1] = +c;
		Matr[1, 2] = +s;
		Matr[2, 1] = -s;
		Matr[2, 2] = +c;
	default:
		break;
	}
}

// 1.2. Преобразование сферических координат к прямоугольным //
void DFSC(double Azt, //Азимут
	      double Alt, //Высота
	      double  Ro, //Ro
	       TVect3 PD  //PosDescart - 
) {
	double cb;
	cb = cos(Alt);
	PD[1] = Ro * cos(Azt) * cb; // X
	PD[2] = Ro * sin(Azt) * cb; // Y
	PD[3] = Ro * sin(Alt);      // Z
}




/////
//+//
/////

void OEOM() {

}

void OrbSpeed(int h) {
	double pr;
	pr = sqrt(u/pow(h+Re,3));
	Worb = floor(pr);
}

void XYZ_from(double i, //Наклонение
		      double a, //Большая полуось
			  double e, //Эксцентриситет
			  double W, //Долгота восходящего узла
			  double _w //Аргумент широты перигея
) {
	double x, y, z;
}

void kgpt(double gam, double psi, double tet, double* c0, double* c1, double* c2, double* c3)
{
	double sp, cp, st, ct, sg, cg;

	sp = sin(psi / 2.0);
	cp = cos(psi / 2.0);
	st = sin(tet / 2.0);
	ct = cos(tet / 2.0);
	sg = sin(gam / 2.0);
	cg = cos(gam / 2.0);
	*c0 = cg * cp * ct - sg * sp * st;
	*c1 = sg * cp * ct + cg * sp * st;
	*c2 = cg * sp * ct - sg * cp * st;
	*c3 = sg * sp * ct + cg * cp * st;
}

// Закон притяжения
void _F(double m1, double m2, double D) {
	F_out = f * m1 * m2 / (D * D);
}

// Расстояние между Ц.М. М1(х) и М2(_х)
void deltaa(double x, double y, double z, double _x, double _y, double _z) {
	Delta_D = sqrt(pow((x - _x), 2) + pow((y - _y), 2) + pow((z - _z), 2));
}

void ncos(double alpha, double betta, double gamma, double x, double y, double z, double _x, double _y, double _z) {
	alpha = (x - _x) / Delta_D;
	betta = (y - _y) / Delta_D;
	gamma = (z - _z) / Delta_D;
}

///////////////////////////////////////////////
///////////////////////////////////////////////

#ifdef DEBUG_MODE

void EnterNU() {
	setlocale(LC_ALL, "Russian");
	std::cout << "ВВОД НУ ВРУЧНУЮ\n";
	std::cout << "Большая полуось ";
	std::cin >> p1;
	std::cout << "Эксцентриситет ";
	std::cin >> e1;
	std::cout << "Долгота восх. узла ";
	std::cin >> om1;
	std::cout << "Наклонение ";
	std::cin >> i1;
	std::cout << "Аргумент перицентра ";
	std::cin >> sig1;
	std::cout << "Истиная аномалия ";
	std::cin >> fi1;
	std::cout << "Баллистический коэффециент ";
	std::cin >> cb1;
	std::cout << "Масса корабля ";
	std::cin >> massTK;
	std::cout << "Час начала режима ";
	std::cin >> hour_m;
	std::cout << "Минуты начала режима ";
	std::cin >> min_m;
	std::cout << "Секунды начала режима ";
	std::cin >> sec_m;
	std::cout << "День ";
	std::cin >> ddn;
	std::cout << "Месяц ";
	std::cin >> mmn;
	std::cout << "Год ";
	std::cin >> yyn;

}



void ControlDyn() {
	setlocale(LC_ALL, "Russian");
    // Отображение инструкорского формата 
}

#endif // DEBUG_MODE

//|//|//|//|//|//|// 
//  MODEL PROCESS //
//|//|//|//|//|//|//

void StartModel() {
	system("cls");
	std::cout << "Model Process... ";
}

// // // // // // // // // // // 

void StartM() { // Запуск моделирования
	int v;
	system("cls");
	std::cout << "1 - ПУСК моделирования\n";
	std::cout << "2 - Повторить ввод НУ\n";
	std::cout << "3 - Выход\n";
	std::cin >> v;
	if (v = 1) {
		StartModel();
	}
}


void intro()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Математическая Модель Движения\n";
	std::cout << "------------------------------\n";
	std::cout << "Введите m1\n";
	std::cin >> massTK;
	std::cout << "Введите m2\n";
	std::cin >> m2;
	std::cout << "Введите расстоние\n";
	std::cin >> delta_r;
	_F(massTK, m2, delta_r);
	system("cls");
	std::cout << "F = " << F_out;
	std::cout << "\n";
}

void Connect() {
	setlocale(LC_ALL, "Russian");
	std::cout << "БММ - SS";
	std::cout << "Установка соеденения... ";
	// конектимся к МиУ, посылаем квитанцию, если ответ верный, то
	std::cout << "OK";
}

int main()
{
	system("cls");
#ifdef DEBUG_MODE
	EnterNU(); //Вводим НУ
	StartM();
#endif // DEBUG_MODE
	return EXIT_SUCCESS;
}
