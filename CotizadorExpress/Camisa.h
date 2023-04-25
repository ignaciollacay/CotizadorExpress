#pragma once
#include "Prenda.h"

class Camisa : public Prenda
{
public:
	Camisa(Manga manga, Cuello cuello);
	~Camisa();
	virtual string GetInfo() override;
	virtual int* GetIndex();
private:
	Manga manga;
	Cuello cuello;
	// Inherited via Prenda
	virtual double ReglaNegocioPrenda() override;
};
