#include "MAIN.h"

int main()
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	char *harita = new char();
	OyunSistem OS;
	OS.OyunuYukle("harita.txt",harita);
	unsigned char gHarf;
	Koordinat oyuncuKoor = { 0,0 };
	Koordinat hoyuncuKoor = { 0,0 };
	hoyuncuKoor = OS.oyuncuBul(harita);
	Oyuncu *Gamer = new Oyuncu();
	//Gamer->SetKoor(hoyuncuKoor);
	OS.KonsoleHandleAl(hCon);
	while (true)
	{
		gHarf = _getch();
		switch (gHarf)
		{
		case 'w':
			oyuncuKoor = { 0,-1 };
			break;
		case 's':
			oyuncuKoor = { 0,1 };
			break;
		case 'a':
			oyuncuKoor = { -1,0 };
			break;
		case 'd':
			oyuncuKoor = { 1,0 };
			break;
		}
		OS.Oyna(hoyuncuKoor, oyuncuKoor, harita);
	}
	system("pause");
    return 0;
}

