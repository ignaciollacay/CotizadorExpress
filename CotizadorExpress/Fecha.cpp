#include "Fecha.h"
#include <string>
Fecha::Fecha() { }
Fecha::Fecha(int dia, int mes, int ano, int hora, int min)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->hora = hora;
	this->min = min;
}
// Crea una fecha con la hora actual del sistema. Evita ingresar manualmente los datos
Fecha Fecha::TiempoActual()
{
	// Obtener la hora actual del sistema
	time_t t = time(NULL);
	// Convertir la hora actual a la estructura tm (contiene fecha y hora)
	struct tm tm;
	localtime_s(&tm, &t);
	// Obtener valores de la estructura tm
	int dia = tm.tm_mday;
	int mes = tm.tm_mon + 1; // tm_mes devuelve valor 0 para enero
	int ano = tm.tm_year + 1900; // tm_year devuelve los años desde 1900 hasta la fecha actual
	int hora = tm.tm_hour;
	int min = tm.tm_min;

	return Fecha(dia, mes, ano, hora, min);
}

// Convierte la fecha a una cadena de caracteres
string Fecha::GetInfo()
{
	string info = IntToString(dia) + '/' + IntToString(mes) + '/' + to_string(ano) + ' ' + IntToString(hora) + ':' + IntToString(min);
	return info;
}

string Fecha::IntToString(int x)
{
	string s = to_string(x);

	// agregar ceros a la izquierda si es necesario
	while (s.length() < 2) {
		s = "0" + s;
	}

	return s;
}

// Validacion de fecha en caso de ser ingresada manualmente
bool Fecha::Validar(int& dia, int& mes, int& ano, int& hora, int& min)
{
	if (ValidarAno(ano) && ValidarMes(mes) && ValidarDia(dia, mes, ano) && ValidarHora(hora) && ValidarMinutos(min))
		return true;
	else
		return false;
}

bool Fecha::ValidarAno(int ano)
{
	if (ano >= 2000)
		return true;
	else
		return false;
}

bool Fecha::ValidarMes(int& mes)
{
	if ((mes >= 1) && (mes <= 12))
		return true;
	else
		return false;
}

bool Fecha::ValidarDia(int& dia, int& mes, int& ano)
{
	if (dia<1)
		return false;

	if (mes % 2 == 0)
	{
		if (Bisiestro(ano))
		{
			if (dia <= 28)
				return true;
			else
				return false;
		}
		else
		{
			if (dia <= 30)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (dia <= 31)
			return true;
		else
			return false;
	}
}

bool Fecha::Bisiestro(int& ano)
{
	if (ano % 4 == 0)
		return true;
	else
		return false;
}

bool Fecha::ValidarHora(int& hora)
{
	if ((hora >= 0) && (hora <= 24))
		return true;
	else
		return false;
}

bool Fecha::ValidarMinutos(int& min)
{
	if ((min >= 0) && (min <= 60))
		return true;
	else
		return false;
}
