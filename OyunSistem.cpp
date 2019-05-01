#include "OyunSistem.h"

void OyunSistem::OyunYukle(const char * harita) const
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 36;j++)
		{
			cout << harita[k];
			k++;
		}
		
		cout << endl;
	}
}

void OyunSistem::konsolTemizle(const HANDLE & KonsolHWND) const
{
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
									 cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
									 the current buffer */

									 /* get the number of character cells in the current buffer */

	bSuccess = GetConsoleScreenBufferInfo(KonsolHWND, &csbi);
	//PERR(bSuccess, "GetConsoleScreenBufferInfo");
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */

	bSuccess = FillConsoleOutputCharacter(KonsolHWND, (TCHAR) ' ',
		dwConSize, coordScreen, &cCharsWritten);
	//PERR(bSuccess, "FillConsoleOutputCharacter");

	/* get the current text attribute */

	bSuccess = GetConsoleScreenBufferInfo(KonsolHWND, &csbi);
	//PERR(bSuccess, "ConsoleScreenBufferInfo");

	/* now set the buffer's attributes accordingly */

	bSuccess = FillConsoleOutputAttribute(KonsolHWND, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);
	//PERR(bSuccess, "FillConsoleOutputAttribute");

	/* put the cursor at (0, 0) */

	bSuccess = SetConsoleCursorPosition(KonsolHWND, coordScreen);
	//PERR(bSuccess, "SetConsoleCursorPosition");
	return;
}

void OyunSistem::KonsoleHandleAl(const HANDLE & kHandle)
{
	_KonsolHandle = kHandle;
}

void OyunSistem::OyunuYukle(const char * dosyaYeri, char *harita)const
{
	ifstream dosyaOku;
	dosyaOku.open(dosyaYeri);
	unsigned char Okunan[360];
	int j = 0;
	if (dosyaOku.is_open())
	{
		while (!dosyaOku.eof())
		{
			dosyaOku >> Okunan;

			for (int i = 0; i < 36; i++)
			{
				cout << Okunan[i];
				harita[i+j] = Okunan[i];
			}
			cout << endl;
			j += 36;
		}
	}
}

Koordinat OyunSistem::oyuncuBul(char *harita) const
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 36; j++)
		{
			if (harita[k] == '@')
			{
				Koordinat KOR{ j,i };
				return KOR;
			}
			k++;
		}

	}
	return Koordinat();
}


void OyunSistem::Oyna(Koordinat& oyuncuKoor, const Koordinat& Hareket, char *harita) const
{
	Koordinat yeniKoordinat = {oyuncuKoor.X + Hareket.X , oyuncuKoor.Y + Hareket.Y};
	int diziYeri = (yeniKoordinat.X ) + (yeniKoordinat.Y * 36);
	int oyuncuYeri = (oyuncuKoor.X )+ (oyuncuKoor.Y * 36);
	char a = harita[diziYeri];
	char b = harita[oyuncuYeri];
	switch(harita[ diziYeri ])
	{
	case '.':
		harita[diziYeri] = '@';
		harita[oyuncuYeri] = '.';
		konsolTemizle(_KonsolHandle);
		OyunYukle(harita);
		oyuncuKoor = yeniKoordinat;
		break;
	case '#':
		cout << "Duvar var" << endl;
		//MessageBoxA(NULL, "DUVAR VAR", "Dikkat!", MB_OK);
		break;
	}
}



