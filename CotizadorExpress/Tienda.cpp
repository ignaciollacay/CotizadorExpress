#include "Tienda.h"


Tienda::Tienda(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;

	SetCamisas(0, 0, 0, CAMISA_CORTA_COMUN_STANDARD);
	SetCamisas(0, 0, 1, CAMISA_CORTA_COMUN_PREMIUM);
	SetCamisas(0, 1, 0, CAMISA_CORTA_MAO_STANDARD);
	SetCamisas(0, 1, 1, CAMISA_CORTA_MAO_PREMIUM);

	SetCamisas(1, 0, 0, CAMISA_LARGA_COMUN_STANDARD);
	SetCamisas(1, 0, 1, CAMISA_LARGA_COMUN_PREMIUM);
	SetCamisas(1, 1, 0, CAMISA_LARGA_MAO_STANDARD);
	SetCamisas(1, 1, 1, CAMISA_LARGA_MAO_PREMIUM);

	SetPantalones(0, 0, PANTALON_COMUN_STANDARD);
	SetPantalones(0, 1, PANTALON_COMUN_PREMIUM);
	SetPantalones(1, 0, PANTALON_CHUPIN_STANDARD);
	SetPantalones(1, 1, PANTALON_CHUPIN_PREMIUM);
}

Tienda::~Tienda()
{
}

string Tienda::GetNombre()
{
	return nombre;
}

string Tienda::GetDireccion()
{
	return direccion;
}

string* Tienda::GetInfo()
{
	string* info = new string[2];
	info[0] = nombre;
	info[1] = direccion;
	return info;
}

int Tienda::GetCamisas(int manga, int cuello, int calidad)
{
	return camisas[manga][cuello][calidad];
}

int Tienda::GetPantalones(int ajuste, int calidad)
{
	return pantalones[ajuste][calidad];
}

void Tienda::SetCamisas(int manga, int cuello, int calidad, int cantidad)
{
	camisas[manga][cuello][calidad] = cantidad;
}

void Tienda::SetPantalones(int ajuste, int calidad, int cantidad)
{
	pantalones[ajuste][calidad] = cantidad;
}
