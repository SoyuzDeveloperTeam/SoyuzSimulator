#pragma once

double F_out;
double Delta_D;

double X0, //Null position scene
	   Y0, 
	   Z0;

double m2, //Масса ТК
	   m3, //Масса МКС
	   m4; //Масса ТК2

double X_TK, //Soyz CM position
       Y_TK,
       Z_TK;
//начальные значения для геопотенциальных коэффициентов
double czon[13];
double ctes[78];
double stes[78];

//////////////
// OUT DATA //
//////////////

//	ТК  //
double  r1x1;	//	Вектор положения ц.м. ТК в J2000
double  r1y1;
double  r1z1;
double  v1x1;	//	Скорость ц.м. ТК в J2000
double  v1y1;
double  v1z1;
double  L0;    //	кватернион разворота ССК ТК относительно J2000 
double  L1;
double  L2;
double  L3;
double  om1x31;	//	Вектор угловой скорости ТК относительно J2000 в проекциях на ССК ТК 
double  om1y31;
double  om1z31;
double  cm1x;	//	Координаты ц.м. ТК в ТГК/ ТПК
double  cm1y;
double  cm1z;

double TK_DATA_MASSIVE[15];
double DOS_DATA_MASSIVE[15];

///////////////////////
//  ORBITAL ELEMENTS //
///////////////////////

double Worb; //Orbital speed

/////////////////////////
//  НАЧАЛЬНЫЕ УСЛОВИЯ  //
/////////////////////////
int hour_m;    //час начала режима
int min_m;     //минуты начала режима
int sec_m;     //секунды начала режима
int ddn;       //день начала режима
int mmn;       //месяц начала режима
int yyn;       //год начала режима

double p1;     //Большая полуось орбиты ТК.
double e1;     //Эксцентриситет орбиты ТК.
double om1;    //Долгота восходящего узла орбиты ТК.
double i1;     //Наклонение орбиты ТК.
double sig1;   //Аргумент широты перигея орбиты ТК.
double fi1;    //Истинная аномалия ТК.
double cb1;    //баллистический коеффициент ТК.
double massTK; //масса ТК.

double h1;     //Высота ц.м. ТК над поверхностью Земли.

double j_j1_mas[9]; //Массив моментов инерции ТК

double delta_r; //Расстоние от Ц.М. земли до Ц.М. объекта

/////////////
// M A T H //
/////////////

typedef double TVect3[3];
TVect3 TMatr33[3];


//////////////////////////
// ФИЗИЧЕСКИЕ КОНСТАНТЫ //
//////////////////////////

//  Имена переменных и констант взяты из Дубошин.Небесная Механика ТОМ 1

int X_e=0.0, //Коор. Ц.М. Земли, они же - нуль сцены
	Y_e=0.0,
	Z_e=0.0;

	// EARTH PARAMETERS //
	const double f  = 6.67384e-11;   //Постоянная притяжения
	const double Me = 5.972e-24;     //Масса Земли
	const double We = 0.00007292115; //Угловая скорость вращения земли
	double       u = f * Me;    	 //Гравитационный параметр ~398 600,441
	const int    Re = 6371;			 //Радиус Земли
	const double a_e = 6378136;		 //Большая полуось общеземного эллипсоида

	//Epoch Parameters //
	const double JD2000  = 2451545.0;
	const double JulianC = 36525.0;   //1 юлианский век


////////////////////
// ИНТЕГРИРОВАНИЕ //
////////////////////
double dt; //Шаг интегрирования

/////////////
// M I S C //
/////////////
char CharSelF; //to select forces