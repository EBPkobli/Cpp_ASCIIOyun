#pragma once

#include "Koordinat.h"

class Oyuncu
{
private:
	char* _Adi;
	unsigned short _can;
	unsigned short _zirh;
	unsigned short _level;
	Koordinat _Koor;

public:
	unsigned short getCan()const;
	unsigned short getZirh() const;
	unsigned short getLevel()const;
	Koordinat getKoor()const;
	void SetKoor(const Koordinat& Koordinat);


};
