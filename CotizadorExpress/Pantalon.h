#pragma once
#include "Prenda.h"

class Pantalon : public Prenda
{
public:
	Pantalon(Ajuste ajuste);
	~Pantalon();
	virtual int* GetIndex();
	virtual string GetInfo() override;
private:
	virtual double ReglaNegocioPrenda() override;
	Ajuste ajuste;
};