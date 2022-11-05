#include<iostream>
#include "Draw.h"
using namespace std;

int main()
{
	Draw draw = Draw();
	int koordinatX, koordinatY,kX;
	int katsayiX,katsayiS;
	cout << "koordinat olusturunuz --> (x,y) turunde" << endl;
	cout << "orn: x = 2 --> -2,2 arasinda" << endl;
	cout << "x: ";
	cin >>koordinatX;
	cout << "y: ";
	cin >> koordinatY;
	cout << "y = ax + b formatinda fonksiyon giriniz" << endl;
	cout << "a = ";
	cin >> katsayiX;
	cout << "b = ";
	cin >> katsayiS;
	cout << "FONKSIYON -->  y = " << katsayiX << "x + " << katsayiS << endl;
	draw.sinirBelirle(koordinatX, koordinatY, katsayiX, katsayiS);
	draw.koordinatCiz(koordinatX, koordinatY, katsayiX, katsayiS);
	return 0;
}