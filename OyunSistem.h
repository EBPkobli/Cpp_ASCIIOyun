#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Koordinat.h"
#include <Windows.h>
using namespace std;


class OyunSistem
{
private:
	void OyunYukle(const char *harita)const;
	HANDLE _KonsolHandle;
	void konsolTemizle(const HANDLE& KonsolHWND)const;

public:
	void KonsoleHandleAl(const HANDLE& kHandle);
	void OyunuYukle(const char * dosyaYeri, char *harita) const;
	Koordinat oyuncuBul(char *harita)const;
	void Oyna(Koordinat& oyuncuKoor,const Koordinat& Hareket,char *harita)const;

};

