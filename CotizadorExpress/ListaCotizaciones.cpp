#include "ListaCotizaciones.h"

ListaCotizaciones::Nodo::Nodo()
{
	sig = nullptr;
}

ListaCotizaciones::Nodo::~Nodo()
{
	delete sig;
}

ListaCotizaciones::ListaCotizaciones()
{
	raiz = NULL;
	cantidad = 0;
}

ListaCotizaciones::~ListaCotizaciones()
{
	Nodo* reco = raiz;
	Nodo* bor;
	while (reco != NULL)
	{
		bor = reco;
		reco = reco->sig;
		delete bor;
	}
}

void ListaCotizaciones::Agregar(Cotizacion c)
{
	Nodo* nuevo = new Nodo();
	nuevo->info = c;
	if (raiz == NULL)
	{
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
	cantidad++;
	nuevo->info.SetID(cantidad);
}

Cotizacion* ListaCotizaciones::GetCotizaciones()
{
	// Crear un array de cotizaciones y lo apunto a un puntero 
	// para poder retornar el array de cotizaciones que contiene la lista
	Cotizacion* cotizaciones = new Cotizacion[cantidad];

	Nodo* reco = raiz;
	for (int i = 0; i < cantidad; i++)
	{
		cotizaciones[i] = reco->info;
		reco = reco->sig;
	}
	return cotizaciones;
}

int ListaCotizaciones::GetCantidad()
{
	return cantidad;
}
