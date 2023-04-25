#pragma once
#include "Fecha.h"
#include "Prenda.h"

class Cotizacion
{
public:
	Cotizacion(); // Constructor predeterminado necesario para obtener el historial.
	Cotizacion(Fecha fecha, string codigo, Prenda* prenda, int precio, int cantidad);
	~Cotizacion();
	float CalcularPrecioFinal();
	void SetID(int contador);
	int GetCantidad();
	int GetPrecioFinal();

	string* GetInfo();
private:
	string id; // Contador de transacciones. Set by ListaCotizaciones
	Fecha fecha;
	string codigoVendedor;
	Prenda* prenda;
	int precio; 
	int cantidad; // cantidad de unidades solicitadas (debe ser menor a disponibilidad)
	float precioFinal;
};