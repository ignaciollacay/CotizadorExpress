#pragma once

class IReglasNegocio
{
	virtual double AplicarReglaNegocio() = 0;
	virtual double ReglaNegocioPrenda() = 0;
	virtual double ReglaNegocioCalidad(double precio) = 0;
};