#include <iostream>
#include <math.h>
#include <string>
using namespace std;

/* Section 3.5 of datasheet. */
short AC1 = 408, AC2 = -72, AC3= -14383;
unsigned short AC4 = 32741, AC5 = 32757, AC6 = 23153;
short B1 = 6190, B2 = 4, MB = -32768, MC = -8711, MD = 2868;
int oss = 0;
long ut = 27898;
long up = 23843;

void verify(void){
	cout << "ut: " << ut << endl;
	cout << "up: " << up << endl;
	long x1 = (ut - AC6) * AC5 / pow(2, 15);
	cout << "x1: " << x1 << endl;
	long x2 = (MC * pow(2, 11)) / (x1 + MD);
	cout << "x2: " << x2 << endl;
	long b5 = x1 + x2;
	cout << "b5: " << b5 << endl;
	long b6 = b5 - 4000;
	cout << "b6: " << b6 << endl;
	x1 = (B2 * (b6 * b6 / pow(2, 12))) / pow(2, 11);
	cout << "x1: " << x1 << endl;
	x2 = AC2 * b6 / pow(2, 11);
	cout << "x2: " << x2 << endl;
	long x3 = x1 + x2;
	cout << "x3: " << x3 << endl;
	long b3 = (((AC1 * 4 + x3) << oss) + 2) / 4;
	cout << "b3: " << b3 << endl;
	x1 = AC3 * b6 / pow(2, 13);
	cout << "x1: " << x1 << endl;
	x2 = (B1 * (b6 * b6 / pow(2, 12))) / pow(2, 16);
	cout << "x2: " << x2 << endl;
	x3 = ((x1 + x2) + 2) / 4;
	cout << "x3: " << x3 << endl;
	unsigned long b4 = AC4 * (unsigned long) (x3 + 32768) / pow(2, 15);
	cout << "b4: " << b4 << endl;
	unsigned long b7 = ((unsigned long) up - b3) * (50000 >> oss);
	cout << "b7: " << b7 << endl;
	long p;
	if (b7 < 0x80000000)
		p = (b7 * 2) / b4;
	else
		p = (b7 / b4) * 2;
		cout << "p: " << p << endl;
	x1 = (p / pow(2, 8)) * (p / pow(2, 8));
	cout << "x1: " << x1 << endl;
	x1 = (x1 * 3038) / pow(2, 16);
	cout << "x1: " << x1 << endl;
	x2 = (-7357 * p) / pow(2, 16);
	cout << "x2: " << x2 << endl;
	p = p + (x1 + x2 + 3791) / pow(2, 4);
	cout << "p: " << p << endl;
}

int main(int argc, char** argv) {
	verify();
	return 0;
}
