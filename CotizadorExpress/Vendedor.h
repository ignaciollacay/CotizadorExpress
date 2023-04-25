#pragma once
#include <string>
#include "ListaCotizaciones.h"
using namespace std;

class Vendedor
{
public:
	Vendedor(string nombre, string apellido, string codigo);
	ListaCotizaciones* GetHistorial();
	string GetCodigo();
	string* GetInfo();
private:
	string nombre;
	string apellido;
	string codigo; // Debería ser definido por la tienda al agregar vendedor, segun la cantidad de vendedores. Pero queda out of scope para la consigna.
	ListaCotizaciones* historial;
};