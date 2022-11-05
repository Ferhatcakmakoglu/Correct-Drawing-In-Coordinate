#include<iostream>
#include <list>
#include <iterator>
using namespace std;

class Draw
{
public:
	list<int> sayilar;
	list<int> sayilarIslenmis;
	int sinirX, sinirY;
	int pJ;
	void koordinatCiz(const int x, const int y,int pX,int pY)
	{
		int xx,yy ;
		int count = 0;
		//koordinat düzlemi çizilmesi için döngüyü 1 fazla döndürüyorum
		for(int i=y;i>-y-1;i--)
		{
			//koordinat çizgisine geldimi gelmedimi kontrol
			if(i != 0)
			{
				for (int j = -x; j < x + 1; j++)
				{
					if(kontol(j,i))
					{
						cout << ".";
					}
					else
					{
						if (j != 0)
							cout << " ";
						else
							cout << "*";
					}
				}
			}
			else
			{
				for(int h=-x;h<x+1;h++)
				{
					if (h == 0)
					{
						cout << "#";
					}
					else
					{
						cout << "*";
					}
					
				}
			}
			cout << "\n";
		}
	}

	void sinirBelirle(const int x, const int y, const int ax, const int b)
	{
		int koordinatKucukDegeri,koordinatBuyukDeger;

		//b nin - olma durumu
		koordinatKucukDegeri = -1 * x;
		koordinatBuyukDeger = x;

		//denklemin alt ve üst limiti bulundu
		if(ax == 1)
		{
			koordinatKucukDegeri -= b;
			koordinatBuyukDeger -= b;
		}else if(ax > 1)
		{
			koordinatKucukDegeri -= b;
			koordinatBuyukDeger -= b;
			koordinatKucukDegeri /= ax;
			koordinatBuyukDeger /= ax;
		}else if(ax == -1)
		{
			koordinatKucukDegeri -= b;
			koordinatBuyukDeger -= b;
			int temp = koordinatBuyukDeger;
			koordinatBuyukDeger = koordinatKucukDegeri * -1;
			koordinatKucukDegeri = temp * -1;
		}else
		{
			koordinatKucukDegeri -= b;
			koordinatBuyukDeger -= b;
			koordinatKucukDegeri /= ax;
			koordinatBuyukDeger /= ax;
			int temp = koordinatBuyukDeger;
			koordinatBuyukDeger = koordinatKucukDegeri;
			koordinatKucukDegeri = temp;
		}
		int size = 2 * x;
		int negatifX = -x;
		int sayac;
		
		//x -x ve kucukKoor. buyukKoor. arasýndaki ortak alaný buldum
		//bulunan x degerleri sayilar a atýldý
		if(koordinatKucukDegeri< negatifX)
		{
			negatifX = koordinatKucukDegeri;
			koordinatKucukDegeri = -x;
		}
		int k;
		int cc = 0;
		for(int i=0;i<size;i++)
		{
			if(negatifX == koordinatKucukDegeri)
			{
				sayac = i;
				while (true)
				{
					if(negatifX != koordinatBuyukDeger && negatifX != x)
					{
						sayilar.push_back(negatifX);
						k = printX(sayilar, cc);
						sayilarIslenmis.push_back((ax * k) + b);
						cc++;
					}else
					{
						break;
					}
					negatifX++;
					i++;
				}
			}
			negatifX++;
		}
	}
	bool kontol(int i,int j)
	{
		int boolOne =0;
		int boolTwo=0;
		int index = 0;
		int indexOne = 0;
		int indexTwo = 0;
		for(auto sayi:sayilar)
		{
			if(sayi == i)
			{
				indexOne = index;
				boolOne = 1;
			}
			index++;
		}
		index = 0;
		for(auto sayiDiger:sayilarIslenmis)
		{
			if(sayiDiger == j)
			{
				indexTwo = index;
				boolTwo = 1;
			}
			index++;
		}
		if(boolOne == 1 && boolTwo == 1 && indexOne == indexTwo)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int printX(list<int> a , int i)
	{
		list<int>::iterator it = a.begin();
		advance(it, i);
		return *it;
	}
	int printY(list<int> a, int i)
	{
		list<int>::iterator it2 = a.begin();
		advance(it2, i);
		return *it2;
	}
};