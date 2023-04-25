#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Fecha
{
public:
	Fecha();
	Fecha(int dia, int mes, int ano, int hora, int min);
	static Fecha TiempoActual();
	static bool Validar(int& dia, int& mes, int& ano, int& hora, int& min);
	string GetInfo();
private:
	int dia, mes, ano, hora, min;
	static bool ValidarAno(int ano);
	static bool ValidarMes(int& mes);
	static bool ValidarDia(int& dia, int& mes, int& ano);
	static bool Bisiestro(int& ano);
	static bool ValidarHora(int& hora);
	static bool ValidarMinutos(int& min);
	string IntToString(int x);
};