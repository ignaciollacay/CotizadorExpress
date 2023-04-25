#include "Camisa.h"

Camisa::Camisa(Manga manga, Cuello cuello)
{
	tipo = TipoPrenda::camisa;
	this->manga = manga;
	this->cuello = cuello;
}

Camisa::~Camisa()
{
}
int* Camisa::GetIndex()
{
	int* index = new int[4];
	index[0] = tipo == TipoPrenda::camisa ? 0 : 1;
	index[1] = manga == Manga::corta ? 0 : 1;
	index[2] = cuello == Cuello::comun ? 0 : 1;
	index[3] = calidad == CalidadPrenda::standard ? 0 : 1;
	return index;
}
string Camisa::GetInfo()
{
	string info;
	info = Prenda::GetInfo();
	info.append(" - ");
	info += manga == Manga::corta ? "Manga Corta" : "Manga Larga";
	info.append(" - ");
	info += calidad == CalidadPrenda::standard ? "Standard" : "Premium";
	return info;
}

double Camisa::ReglaNegocioPrenda()
{
	double precioFinal = precio;
	// RN 1- Si es manga corta rebajar 10%
	if (manga == Manga::corta)
		precioFinal -= (precioFinal * 0.1);
	// RN 2- Si es cuello mao aumentar 3%
	if (cuello == Cuello::mao)
		precioFinal += (precioFinal * 0.03);
	// RN 3- Si es cuello mao y manga corta, aplican en orden
	return precioFinal;
}