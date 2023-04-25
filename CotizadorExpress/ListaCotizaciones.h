#pragma once
#include "Cotizacion.h"\

class ListaCotizaciones
{
public:
	ListaCotizaciones();
	~ListaCotizaciones();
	void Agregar(Cotizacion c);
	Cotizacion* GetCotizaciones(); // obtener array cotizaciones en un puntero para imprimir el historial.
	int GetCantidad();
private:
	class Nodo
	{
	public:
		Nodo();
		~Nodo();
		Cotizacion info;
		Nodo* sig;
	};
	Nodo* raiz;
	int cantidad;
};