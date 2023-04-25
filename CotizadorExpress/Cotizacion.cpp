#include "Cotizacion.h"
#include <iomanip> // necesario para std::setprecision
#include <sstream> // necesario para std::ostringstream

Cotizacion::Cotizacion()
{
	fecha = Fecha(0,0,0,0,0);
	prenda = nullptr;
	id = "";
	precio = 0;
	cantidad = 0;
	precioFinal = 0;
}

Cotizacion::Cotizacion(Fecha fecha, string codigo, Prenda* prenda, int precio, int cantidad)
{
	id = "";
	this->fecha = fecha;
	codigoVendedor = codigo;
	this->prenda = prenda;
	this->precio = precio;
	this->cantidad = cantidad;
	this->precioFinal = CalcularPrecioFinal();
}

Cotizacion::~Cotizacion()
{
	// liberacion de memoria de prenda en presentador. creo.
}

float Cotizacion::CalcularPrecioFinal()
{
	double precioFinal = prenda->AplicarReglaNegocio();
	return precioFinal * cantidad;
}

void Cotizacion::SetID(int contador)
{ 
	string id = to_string(contador);

	// agregar ceros a la izquierda si es necesario
	while (id.length() < 3) {
		id = "0" + id;
	}

	this->id = id; 
}

int Cotizacion::GetCantidad() 
{ 
	return cantidad; 
}

int Cotizacion::GetPrecioFinal() 
{ 
	return precioFinal; 
}

string* Cotizacion::GetInfo()
{
	string* info = new string[7];
	info[0] = id;
	info[1] = fecha.GetInfo();
	info[2] = codigoVendedor;
	info[3] = prenda->GetInfo();
	info[4] = to_string(precio);
	info[5] = to_string(cantidad);
	info[6] = to_string(precioFinal);
	return info;
}
