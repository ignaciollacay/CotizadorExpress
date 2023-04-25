#pragma once
#include <string>
using namespace std;

class IVista
{
	virtual int GetInput() = 0;
	virtual void MenuPrincipal(string* tienda, string* vendedor) = 0;
	virtual void MostrarCotizacion(string* info) = 0;
	virtual void MostrarPrendas() = 0;
	virtual void MostrarMangas() = 0;
	virtual void MostrarCuellos() = 0;
	virtual void MostrarAjustes() = 0;
	virtual void MostrarCalidades() = 0;
	virtual void SolicitarPrecio() = 0;
	virtual void SolicitarCantidad(int stock) = 0;
	virtual void Imprimir(string x) = 0;
	virtual void MostrarResultado(string* info) = 0;
	virtual void MostrarVolver() = 0;
	virtual void ConfirmarVolver() = 0;
	virtual void MostrarSalir() = 0;
	virtual void MensajeIncorrecto() = 0;
	virtual void MostrarHeaderCotizar() = 0;
};