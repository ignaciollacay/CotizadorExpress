#include "Vendedor.h"

Vendedor::Vendedor(string nombre, string apellido, string codigo)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->codigo = codigo;
	historial = new ListaCotizaciones();
}

ListaCotizaciones* Vendedor::GetHistorial()
{
	return historial;
}

string Vendedor::GetCodigo()
{
	return codigo;
}

string* Vendedor::GetInfo()
{
	string* info = new string[2];
	info[0] = nombre + ", " + apellido;
	info[1] = codigo;
	return info;
}
