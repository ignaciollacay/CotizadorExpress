#include "Prenda.h"

string Prenda::GetInfo()
{
	return tipo == TipoPrenda::camisa ? "Camisa" : "Pantalon";;
}

void Prenda::SetCalidad(CalidadPrenda c)
{ 
	calidad = c;
}

void Prenda::SetPrecio(int p) 
{ 
	precio = p; 
}


int* Prenda::GetIndex()
{
	return nullptr;
}


double Prenda::AplicarReglaNegocio()
{
	double precioFinal = precio;
	precioFinal = ReglaNegocioPrenda();
	precioFinal = ReglaNegocioCalidad(precioFinal);
	return precioFinal;
}


// Inherited via IReglasNegocio
double Prenda::ReglaNegocioPrenda() 
{ 
	return 0; 
}

double Prenda::ReglaNegocioCalidad(double precio)
{
	switch (calidad)
	{
	case CalidadPrenda::standard: 
		// RN 5- Si la calidad es Standard el precio no se modifica
		return precio; // Aplican reglas de prenda.
		//return this->precio;  // No aplican reglas de prenda.
	case CalidadPrenda::premium:
		// RN 6- Si la calidad es Premium el precio aumenta 30%
		return precio + (precio * 0.3);
	}
}