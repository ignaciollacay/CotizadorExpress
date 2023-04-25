	#pragma once
#include <string>
#include "Prenda.h"

#define CAMISA_CORTA_COMUN_STANDARD 150
#define CAMISA_CORTA_COMUN_PREMIUM 150
#define CAMISA_CORTA_MAO_STANDARD 100
#define CAMISA_CORTA_MAO_PREMIUM 100

#define CAMISA_LARGA_COMUN_STANDARD 175
#define CAMISA_LARGA_COMUN_PREMIUM 175
#define CAMISA_LARGA_MAO_STANDARD 75
#define CAMISA_LARGA_MAO_PREMIUM 75

#define PANTALON_COMUN_STANDARD 250
#define PANTALON_COMUN_PREMIUM 250
#define PANTALON_CHUPIN_STANDARD 750
#define PANTALON_CHUPIN_PREMIUM 750

using namespace std;

class Tienda
{
public:
	Tienda(string nombre, string direccion);
	~Tienda();
	string GetNombre();
	string GetDireccion();
	string* GetInfo();

	int GetCamisas(int manga, int cuello, int calidad);
	int GetPantalones(int ajuste, int calidad);
	void SetCamisas(int manga, int cuello, int calidad, int cantidad);
	void SetPantalones(int ajuste, int calidad, int cantidad);
private:
	string nombre;
	string direccion;
	// Cantidad de Camisas en stock
	int camisas[2][2][2];

	// Stock de Pantalones en stock
	int pantalones[2][2];

	// Lista de vendedores. Agregar vendedor le asigna la id.
};