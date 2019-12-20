#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "MM_H.h"
#include <chrono>
#include <functional>
#include <fstream>
#include <cstring>
using namespace std;

int LANG;

void SELECT_LANG(){
	char chek;
	cout << "SELECT LANGUAGE  -  ВЫБЕРИТЕ ЯЗЫК\n";
	cout << "1. ENG" << "\n" << "2. RUS \n" << "->";
	cin >> chek;
	if (chek == '1') {
		LANG = 1;
	}
	if (chek == '2') {
		LANG = 2;
	}
}

//#include "MM_MD.cpp"

#define DEBUG_MODE  //Debug mode only for developers
//#define RELEASE_MODE

#ifdef RELEASE_MODE
#define UDP_CONNECT //Обмен по Ethernet
#endif // RELEASE_MODE

extern double Delta_D, m2, m3, u;

////////////////////////
// УРАВНЕНИЯ ДВИЖЕНИЯ //
////////////////////////

// 1. Алгоритмы операций с матрицами и векторами //
// 1.1. Вычисление матриц поворота //
void ForRotMatr(int iaxis, double angle, TVect3 Matr) {
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
		Matr[1, 1] = +c;
		Matr[1, 3] = -s;
		Matr[3, 1] = +s;
		Matr[3, 3] = +c;
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
	pr = sqrt(u / pow(h + Re, 3));
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

//////////////////////

#ifdef DEBUG_MODE

void change_model_type() {
	setlocale(LC_ALL, "Russian");
	system("cls");
	std::cout << "Выберете режим работы: ";
}
	const char* arr_data_nameE[]{ 
	"Hour                  ","Minutes               ","Seconds               ","Day                   ",
	"Month                 ","Year                  ","Semimajor axis        ","Eccentricity          ",
	"Long. of asc. node    ","Inclination           ","Pericenter argument   ","True anomaly          ",
	"Ballistic coefficient ","TK mass               ","Orientation           ","ДПО-К1 thrust         ",
	"ДПО-К2 thrust         ","Fuel                  ","Coordinate C.M. X     ","Coordinate C.M. Y     ",
	"Coordinate C.M. Z     ","Angular velocity X    ","Angular velocity Y    ","Angular velocity Z    ",
	"Pitch                 ","Yaw                   ","Roll                  ","Jxx                   ",
	"Jyy                   ","Jzz                   ","Jxy                   ","Jyz                   ",
	"Jzx                   ","Jzy                   ","Jxz                   ","Jyz                   " };
	const char* arr_data_nameR[]{
	"Час                   ","Минуты                ","Секунды               ","День                  ",
	"Месяц                 ","Год                   ","Большая полуось       ","Эксцентриситет        ",
	"Долгота восх. узла    ","Наклонение            ","Аргумент перицентра   ","Истинная аномалия     ",
	"Балл. коэффициент     ","Масса ТК              ","СК ориентации         ","Тяга ДПО-К1           ",
	"Тяга ДПО-К2           ","Топливо               ","Координата Ц.М. X     ","Координата Ц.М. Y     ",
	"Координата Ц.М. Z     ","Угловая скорость X    ","Угловая скорость Y    ","Угловая скорость Z    ",
	"Тангаж                ","Рыскание              ","Крен                  ","Jxx                   ",
	"Jyy                   ","Jzz                   ","Jxy                   ","Jyz                   ",
	"Jzx                   ","Jzy                   ","Jxz                   ","Jyz                   " };

void ControlDyn() {
	setlocale(LC_ALL, "Russian");
    // Отображение инструкорского формата 
}

#endif // DEBUG_MODE

//\\//\\//\\//\\//\\
//  MODEL PROCESS //
//\\//\\//\\//\\//\\

void StartModel() {
	system("cls");
	cout << "Model Process... ";
}

//\\//\\//\\//\\//\\

void Connect() { // Установка соединения с МиУ
	setlocale(LC_ALL, "Russian");
	if (LANG == 1)
		cout << "Connect to M&C...";
	else
	{
		cout << "Установка соеденения с МиУ... ";
	}
	// коннектимся к МиУ, посылаем квитанцию, если ответ верный, то
	cout << "OK\n";
}

void UNPACK_FF(void) {
	hour_m      = PACK_DATA_FROM_TXT[0];
	min_m		= PACK_DATA_FROM_TXT[1];
	sec_m		= PACK_DATA_FROM_TXT[2];
	ddn			= PACK_DATA_FROM_TXT[3];
	mmn			= PACK_DATA_FROM_TXT[4];
	yyn		    = PACK_DATA_FROM_TXT[5];
	p1		    = PACK_DATA_FROM_TXT[6];
	e1		    = PACK_DATA_FROM_TXT[7];
	om1         = PACK_DATA_FROM_TXT[8];
	i1          = PACK_DATA_FROM_TXT[9];
	sig1        = PACK_DATA_FROM_TXT[10];
	fi1         = PACK_DATA_FROM_TXT[11];
	cb1         = PACK_DATA_FROM_TXT[12];
	massTK      = PACK_DATA_FROM_TXT[13];
	sktk        = PACK_DATA_FROM_TXT[14];
	dtgk1       = PACK_DATA_FROM_TXT[15];
	dtgk2       = PACK_DATA_FROM_TXT[16];
	tkfz        = PACK_DATA_FROM_TXT[17];
	nu_cm1x     = PACK_DATA_FROM_TXT[18];
	nu_cm1y     = PACK_DATA_FROM_TXT[19];
	nu_cm1z     = PACK_DATA_FROM_TXT[20];
	wx_tk       = PACK_DATA_FROM_TXT[21];
	wy_tk       = PACK_DATA_FROM_TXT[22];
	wz_tk       = PACK_DATA_FROM_TXT[23];
	pitch_tk    = PACK_DATA_FROM_TXT[24];
	yaw_tk      = PACK_DATA_FROM_TXT[25];
	roll_tk     = PACK_DATA_FROM_TXT[26];
	j_j1_mas[0] = PACK_DATA_FROM_TXT[27];
	j_j1_mas[1] = PACK_DATA_FROM_TXT[28];
	j_j1_mas[2] = PACK_DATA_FROM_TXT[29];
	j_j1_mas[3] = PACK_DATA_FROM_TXT[30];
	j_j1_mas[4] = PACK_DATA_FROM_TXT[31];
	j_j1_mas[5] = PACK_DATA_FROM_TXT[32];
	j_j1_mas[6] = PACK_DATA_FROM_TXT[33];
	j_j1_mas[7] = PACK_DATA_FROM_TXT[34];
	j_j1_mas[8] = PACK_DATA_FROM_TXT[35];
}

//// MAIN ////
int main() 
{
	setlocale(LC_ALL, "Russian");
	system("cls");
#ifdef DEBUG_MODE
	char chek[2];
	SELECT_LANG(); //Выбор языка
	system("cls");
	if (LANG == 1)
		std::cout << "Load data from file \n";
	else
	{
		std::cout << "Зарузка данных из файла \n";
	}
	    std::cout << "-----------------------\n";


	char ff[10];
	double test;
	int br;
	int i;
	std::ifstream FNU; //Переменная файла НУ
	FNU.open("C:\\input_data.nuf", std::ifstream::in);
	if (!FNU) { 
		if (LANG == 1)
			std::cout << "File not found!";
		else
		{
			std::cout << "Файл отсутствует!";
		}
		return 1;
	}
	else
	{
		for (int i = 0; i < 36; i++) {
			FNU >> PACK_DATA_FROM_TXT[i];	//Присваиваем FNU TO ARRAY
		}
		for (i = 0; i < 36; i++)
			if(LANG==1)
			std::cout << arr_data_nameE[i] << std::setw(8) << PACK_DATA_FROM_TXT[i] << "\n";
			else
			{
			std::cout << arr_data_nameR[i] << std::setw(8) << PACK_DATA_FROM_TXT[i] << "\n";
			}
		if (LANG == 1)
			std::cout << "Data is correct?";
		else {
			std::cout << "Данные верны?";
		}
		std::cout << " Y/N \n" << "->";
		std::cin >> chek[0];
		if (chek[0] == 'Y' or 'y') {
			UNPACK_FF(); //Присваиваем из массива
			std::cout << "ddd";
		}
		if (chek[0] == 'N' or 'n') {
			return 0;
		}

	}
	std::cout << "sss";
#endif // DEBUG_MODE
	Connect();
}
