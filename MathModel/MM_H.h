#pragma once

double F_out;
double Delta_D;

double X0, //Null position scene
	   Y0, 
	   Z0;

double m2, //����� ��
	   m3, //����� ���
	   m4; //����� ��2

double X_TK, //Soyz CM position
       Y_TK,
       Z_TK;
//��������� �������� ��� ���������������� �������������
double czon[13];
double ctes[78];
double stes[78];

//////////////
// OUT DATA //
//////////////

//	��  //
double  r1x1;	//	������ ��������� �.�. �� � J2000
double  r1y1;
double  r1z1;
double  v1x1;	//	�������� �.�. �� � J2000
double  v1y1;
double  v1z1;
double  L0;    //	���������� ��������� ��� �� ������������ J2000 
double  L1;
double  L2;
double  L3;
double  om1x31;	//	������ ������� �������� �� ������������ J2000 � ��������� �� ��� �� 
double  om1y31;
double  om1z31;
double  cm1x;	//	���������� �.�. �� � ���/ ���
double  cm1y;
double  cm1z;

double TK_DATA_MASSIVE[15];
double DOS_DATA_MASSIVE[15];

///////////////////////
//  ORBITAL ELEMENTS //
///////////////////////

double Worb; //Orbital speed

/////////////////////////
//  ��������� �������  //
/////////////////////////
int hour_m;    //��� ������ ������
int min_m;     //������ ������ ������
int sec_m;     //������� ������ ������
int ddn;       //���� ������ ������
int mmn;       //����� ������ ������
int yyn;       //��� ������ ������

double p1;     //������� ������� ������ ��.
double e1;     //�������������� ������ ��.
double om1;    //������� ����������� ���� ������ ��.
double i1;     //���������� ������ ��.
double sig1;   //�������� ������ ������� ������ ��.
double fi1;    //�������� �������� ��.
double cb1;    //�������������� ����������� ��.
double massTK; //����� ��.

double h1;     //������ �.�. �� ��� ������������ �����.

double j_j1_mas[9]; //������ �������� ������� ��

double delta_r; //��������� �� �.�. ����� �� �.�. �������

/////////////
// M A T H //
/////////////

typedef double TVect3[3];
TVect3 TMatr33[3];


//////////////////////////
// ���������� ��������� //
//////////////////////////

//  ����� ���������� � �������� ����� �� �������.�������� �������� ��� 1

int X_e=0.0, //����. �.�. �����, ��� �� - ���� �����
	Y_e=0.0,
	Z_e=0.0;

	// EARTH PARAMETERS //
	const double f  = 6.67384e-11;   //���������� ����������
	const double Me = 5.972e-24;     //����� �����
	const double We = 0.00007292115; //������� �������� �������� �����
	double       u = f * Me;    	 //�������������� �������� ~398 600,441
	const int    Re = 6371;			 //������ �����
	const double a_e = 6378136;		 //������� ������� ����������� ����������

	//Epoch Parameters //
	const double JD2000  = 2451545.0;
	const double JulianC = 36525.0;   //1 ��������� ���


////////////////////
// �������������� //
////////////////////
double dt; //��� ��������������

/////////////
// M I S C //
/////////////
char CharSelF; //to select forces