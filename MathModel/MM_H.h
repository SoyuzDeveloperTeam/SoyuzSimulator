#pragma once
/////////////
// M I S C //
/////////////

double F_out;
double Delta_D;
double m2, //TK Mass
m3, //Масса МКС
m4; //Масса ТК2
extern char CharSelF; //to select forces

double X_TK, //Soyz CM position
Y_TK,
Z_TK;

//////////////
// OUT DATA // MODEL->M&C
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

	double WxTK, WyTK, WzTK;

	double TK_DATA_MAS[15];
	double DOS_DATA_MAS[15];

	double lmu_tk[3]; //Линейное мгновенное ускорение
	double wmu_tk[3]; //Угловое мгновенное ускорение
	double evsJ[3]; //Единичный вектор из центра J2000 на Солнце в проекциях на J2000

///////////////////////
//  ORBITAL ELEMENTS //
///////////////////////
	double Worb; //Orbital speed

////////////////////////
// PROCESS DATA ARRAY //
//   ТЕХНОЛОГИЧЕСКИЕ  //
////////////////////////

	bool START; //"START" command from M&C
	int qcn[3]; //Квитанции

/////////////////////////
//  НАЧАЛЬНЫЕ УСЛОВИЯ  // M&C -> MODEL
/////////////////////////
	int hour_m;    //час начала режима
	int min_m;     //минуты начала режима
	int sec_m;     //секунды начала режима
	int ddn;       //день начала режима
	int mmn;       //месяц начала режима
	int yyn;       //год начала режима
	int NU_DT_MAS[6];

	double p1;     //Большая полуось орбиты ТК.
	double e1;     //Эксцентриситет орбиты ТК.
	double om1;    //Долгота восходящего узла орбиты ТК.
	double i1;     //Наклонение орбиты ТК.
	double sig1;   //Аргумент перицентра.
	double fi1;    //Истинная аномалия ТК.
	double cb1;    //баллистический коэффициент ТК.
	double massTK; //масса ТК.

	char sktk; //СК НУ ориентации ТК:0-состык.сост.; 1-ИСК; 2-ОСК; 3-ВСК
	double dtgk1; //Тяга ДПО-К1 (0.00 - 100.00)
	double dtgk2; //Тяга ДПО-К2 (0.00 - 100.00)
	double tkfz;			//	запас топлива ТК (в кг)

	double nu_cm1x; //координата ц.м. ТК в строит. СК ТК.
	double nu_cm1y; //координата ц.м. ТК в строит. СК ТК.
	double nu_cm1z; //координата ц.м. ТК в строит. СК ТК.

	double wx_tk; //Угловая скорость ТК
	double wy_tk; //Угловая скорость ТК
	double wz_tk; //Угловая скорость ТК

	double pitch_tk; //Тангаж ТК
	double yaw_tk; //Yaw 
	double roll_tk; //Roll
	double h1;     //Высота ц.м. ТК над поверхностью Земли.

	double j_j1_mas[9]; //Массив моментов инерции ТК

	double os_vx; //Вектор скорости МКС
	double os_vy; //Вектор скорости МКС
	double os_vz; //Вектор скорости МКС
	double os_vpx; //Вектор положения МКС
	double os_vpy; //Вектор положения МКС
	double os_vpz; //Вектор положения МКС

	double PACK_DATA_FROM_TXT[36];


	double delta_r; //Расстоние от Ц.М. земли до Ц.М. объекта
/////////////
// M A T H //
/////////////

typedef double TVect3[3]; //Тип данных - вектор X Y Z
extern TVect3 TMatr33[3];


///////////////////
// PHYSICS CONST //
///////////////////
	//  Имена переменных и констант взяты из Дубошин.Небесная Механика ТОМ 1

	int X_e = 0.0, //Коор. Ц.М. Земли, они же - нуль сцены
		Y_e = 0.0,
		Z_e = 0.0;

	// EARTH PARAMETERS //
	const double f = 6.67384e-11;   //Постоянная притяжения
	const double Me = 5.972e-24;     //Масса Земли
	const double We = 0.00007292115; //Угловая скорость вращения земли
	double       u = f * Me;    	 //Гравитационный параметр ~398 600,441
	const int    Re = 6371;			 //Радиус Земли
	const double a_e = 6378136;		 //Большая полуось общеземного эллипсоида

	//Epoch Parameters //
	const double JD2000 = 2451545.0;
	const double JulianC = 36525.0;   //1 юлианский век


////////////////////
// ИНТЕГРИРОВАНИЕ //
////////////////////
double dt; //Шаг интегрирования

