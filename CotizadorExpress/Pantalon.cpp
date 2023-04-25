#include "Pantalon.h"

Pantalon::Pantalon(Ajuste ajuste)
{
	tipo = TipoPrenda::pantalon;
	this->ajuste = ajuste;
	precio = 0;
	calidad = CalidadPrenda::standard;
}

Pantalon::~Pantalon()
{
}
int* Pantalon::GetIndex()
{
	int* index = new int[3];
	index[0] = tipo == TipoPrenda::camisa ? 0 : 1;
	index[1] = ajuste == Ajuste::comun ? 0 : 1;
	index[2] = calidad == CalidadPrenda::standard ? 0 : 1;
	return index;
}
string Pantalon::GetInfo()
{
	string info;
	info = Prenda::GetInfo();
	info.append(" - ");
	info += ajuste == Ajuste::comun ? "Comun" : "Chupin";
	return info;
}

double Pantalon::ReglaNegocioPrenda()
{
	double precioFinal = precio;

	// RN 4- Si el pantalon es chupin, el precio se rebaja un 12%
	if (ajuste == Ajuste::chupin)
		precioFinal -= (precioFinal * 0.12);

	return precioFinal;
}