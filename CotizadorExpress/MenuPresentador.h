#pragma once
#include "MenuVista.h"
#include "Tienda.h"
#include "Vendedor.h"
#include "Camisa.h"
#include "Pantalon.h"

class MenuPresentador
{
public:
	MenuPresentador(MenuVista* vista, Tienda* tienda, Vendedor* vendedor);
	~MenuPresentador();
	void MenuPrincipal();						// Menu principal
	void HistorialCotizaciones(Vendedor* v);	// Menu principal. Opcion 1 
	void Cotizar();								// Menu principal. Opcion 2
private:
	MenuVista* vista;
	Tienda* tienda;
	Vendedor* vendedor;
	void RegresarAlMenu();
	void RegresarAlMenu(string* info);
	Cotizacion* SolicitarDatosCotizacion();
	TipoPrenda ElegirPrenda();		// Paso 1
	Manga ElegirManga();			// Paso 2 a
	Cuello ElegirCuello();			// Paso 2 b
	Ajuste ElegirAjuste();			// Paso 2
	CalidadPrenda ElegirCalidad();	// Paso 3
	int IngresarPrecio();			// Paso 4
	int IngresarCantidad(Prenda& p);// Paso 5
	Fecha IngresarFecha();			// Paso 6
	bool ConfirmarVolver();
};