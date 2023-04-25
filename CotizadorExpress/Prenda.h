#pragma once
#include <string>
#include "IReglasNegocio.h"
#include "IStockable.h"
#include "Tienda.h"

using namespace std;

enum class CalidadPrenda { standard, premium };
enum class TipoPrenda { pantalon, camisa };
enum class Ajuste { comun, chupin };
enum class Manga { corta, larga };
enum class Cuello { comun, mao };

class Prenda : IReglasNegocio
{
public:
	void SetCalidad(CalidadPrenda c);
	void SetPrecio(int p);
	virtual string GetInfo();

	virtual int* GetIndex();
	virtual double AplicarReglaNegocio();
protected:
	TipoPrenda tipo;
	CalidadPrenda calidad;
	int precio;

	// Inherited via IReglasNegocio
	virtual double ReglaNegocioPrenda();
	virtual double ReglaNegocioCalidad(double precio) override;
};




