#pragma once
#include "IVista.h"
#include <iostream>
#include <stdlib.h> // necesario para limpiar la consola
#include <iomanip> // necesario para mostrar precios con dos decimales

using namespace std;

class MenuVista : IVista
{
public:
	int GetInput();
	void MenuPrincipal(string* tienda, string* vendedor);
	void MostrarHeaderHistorial();
	void MostrarCotizacion(string* info);
	void MostrarPrendas();
	void MostrarMangas();
	void MostrarCuellos();
	void MostrarAjustes();
	void MostrarCalidades();
	void SolicitarPrecio();
	void SolicitarCantidad(int stock);
	void SolicitarFecha();
	void Imprimir(string x);
	void MostrarResultado(string* info);
	void MostrarVolver();
	void ConfirmarVolver();
	void MostrarSalir();
	void MensajeIncorrecto();
	void MostrarHeaderCotizar();
private:
	const string linea = "------------------------------------------------";
	const string app = "COTIZADOR EXPRESS";
};