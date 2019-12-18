#include <math.h>
#include <cmath>

//////////////////////////////////////
// 2. Алгоритмы преобразования даты //
//////////////////////////////////////

// Вычисление модифицированной юлианской даты из текущего момента времени

int FromDatetoMJD(short int NDay,
	short int NMonth,
	short int NYear,
	short int NHour,
	short int NMinute,
	double Second)
{
	short int year;
	short int j1, m1, ij, iq;
	double t, q;
	double FDTM;
	/*-------------------------*/
	year = NYear;
	if (year < 85)year = 2000 + year;
	if (year < 100)year = 1900 + year;
	j1 = year - 1900;
	m1 = NMonth - 3;
	if (m1 < 0) {
		m1 = m1 + 12;
		j1 = j1 - 1;
	}
	q = 0.5 + 30.6 * m1;
	iq = trunc(q);
	ij = j1/4;
	q = iq + ij + NDay;
	t = t + (NHour + (NMinute + Second / 60.0) / 60.0) / 24.0 - 0.125;
	FDTM = t;
	return FDTM;
}

void TMJtoD (double Tmjd,double NDay,double NMonth, double NYear)