#pragma once
/////////////
// M I S C //
/////////////

double F_out;
double Delta_D;
double m2, //TK Mass
m3, //����� ���
m4; //����� ��2
extern char CharSelF; //to select forces

double X_TK, //Soyz CM position
Y_TK,
Z_TK;

//////////////
// OUT DATA // MODEL->M&C
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

	double WxTK, WyTK, WzTK;

	double TK_DATA_MAS[15];
	double DOS_DATA_MAS[15];

	double lmu_tk[3]; //�������� ���������� ���������
	double wmu_tk[3]; //������� ���������� ���������
	double evsJ[3]; //��������� ������ �� ������ J2000 �� ������ � ��������� �� J2000

///////////////////////
//  ORBITAL ELEMENTS //
///////////////////////
	double Worb; //Orbital speed

////////////////////////
// PROCESS DATA ARRAY //
//   ���������������  //
////////////////////////

	bool START; //"START" command from M&C
	int qcn[3]; //���������

/////////////////////////
//  ��������� �������  // M&C -> MODEL
/////////////////////////
	int hour_m;    //��� ������ ������
	int min_m;     //������ ������ ������
	int sec_m;     //������� ������ ������
	int ddn;       //���� ������ ������
	int mmn;       //����� ������ ������
	int yyn;       //��� ������ ������
	int NU_DT_MAS[6];

	double p1;     //������� ������� ������ ��.
	double e1;     //�������������� ������ ��.
	double om1;    //������� ����������� ���� ������ ��.
	double i1;     //���������� ������ ��.
	double sig1;   //�������� ����������.
	double fi1;    //�������� �������� ��.
	double cb1;    //�������������� ����������� ��.
	double massTK; //����� ��.

	char sktk; //�� �� ���������� ��:0-������.����.; 1-���; 2-���; 3-���
	double dtgk1; //���� ���-�1 (0.00 - 100.00)
	double dtgk2; //���� ���-�2 (0.00 - 100.00)
	double tkfz;			//	����� ������� �� (� ��)

	double nu_cm1x; //���������� �.�. �� � ������. �� ��.
	double nu_cm1y; //���������� �.�. �� � ������. �� ��.
	double nu_cm1z; //���������� �.�. �� � ������. �� ��.

	double wx_tk; //������� �������� ��
	double wy_tk; //������� �������� ��
	double wz_tk; //������� �������� ��

	double pitch_tk; //������ ��
	double yaw_tk; //Yaw 
	double roll_tk; //Roll
	double h1;     //������ �.�. �� ��� ������������ �����.

	double j_j1_mas[9]; //������ �������� ������� ��

	double os_vx; //������ �������� ���
	double os_vy; //������ �������� ���
	double os_vz; //������ �������� ���
	double os_vpx; //������ ��������� ���
	double os_vpy; //������ ��������� ���
	double os_vpz; //������ ��������� ���

	double PACK_DATA_FROM_TXT[36];


	double delta_r; //��������� �� �.�. ����� �� �.�. �������
/////////////
// M A T H //
/////////////

typedef double TVect3[3]; //��� ������ - ������ X Y Z
extern TVect3 TMatr33[3];


///////////////////
// PHYSICS CONST //
///////////////////
	//  ����� ���������� � �������� ����� �� �������.�������� �������� ��� 1

	int X_e = 0.0, //����. �.�. �����, ��� �� - ���� �����
		Y_e = 0.0,
		Z_e = 0.0;

	// EARTH PARAMETERS //
	const double f = 6.67384e-11;   //���������� ����������
	const double Me = 5.972e-24;     //����� �����
	const double We = 0.00007292115; //������� �������� �������� �����
	double       u = f * Me;    	 //�������������� �������� ~398 600,441
	const int    Re = 6371;			 //������ �����
	const double a_e = 6378136;		 //������� ������� ����������� ����������

	//Epoch Parameters //
	const double JD2000 = 2451545.0;
	const double JulianC = 36525.0;   //1 ��������� ���


////////////////////
// �������������� //
////////////////////
double dt; //��� ��������������

