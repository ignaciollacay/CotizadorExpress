#include "MenuVista.h"
#include <string>

int MenuVista::GetInput()
{
	int input;
	cin >> input;
	return input;
}
void MenuVista::MenuPrincipal(string* tienda, string* vendedor)
{
	system("CLS");
	cout << app + " - MENU PRINCIPAL" << endl << linea << endl
		<< tienda[0] << " | " << tienda[1] << endl << linea << endl
		<< vendedor[0] << " | " << vendedor[1] << endl << linea << endl
		<< "SELECCIONE UNA OPCION DEL MENU:" << endl
		<< "1) Historial de Cotizaciones" << endl
		<< "2) Realizar Cotizacion" << endl
		<< "3) Salir" << endl << linea << endl;
}

void MenuVista::MostrarHeaderHistorial()
{
	system("CLS");
	cout << app + " - HISTORIAL DE COTIZACIONES" << endl;
	MostrarVolver();
}
// Esto anda
void MenuVista::MostrarCotizacion(string* info)
{
	cout << "Numero de identificacion: " << info[0] << endl
		<< "Fecha y hora de la cotizacion: " << info[1] << endl
		<< "Codigo del vendedor: " << info[2] << endl
		<< "Prenda cotizada: " << info[3] << endl
		<< "Precio unitario: $" << fixed << setprecision(2) << stof(info[4]) << endl // fixed y set precision(2) para formato. stof convierte string a float. 
		<< "Cantidad de unidades cotizadas: " << info[5] << endl
		<< "Precio final: $" << fixed << setprecision(2) << stof(info[6]) << endl; // fixed y set precision(2) para formato. stof convierte string a float. 
}

void MenuVista::MostrarPrendas()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 1: Selecciona la prenda a cotizar: " << endl
		<< "1) Camisa" << endl
		<< "2) Pantalon" << endl 
		<< linea << endl;
}
void MenuVista::MostrarMangas()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 2.a: Selecciona el tipo de manga de la camisa: " << endl
		<< "1) Manga corta" << endl
		<< "2) Manga larga" << endl 
		<< linea << endl;
}
void MenuVista::MostrarCuellos()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 2.b: Selecciona el tipo de cuello de la camisa: " << endl
		<< "1) Cuello normal" << endl
		<< "2) Cuello mao" << endl 
		<< linea << endl;
}
void MenuVista::MostrarAjustes()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 2: Selecciona el tipo de ajuste del pantalon: " << endl
		<< "1) Normal" << endl
		<< "2) Chupin" << endl 
		<< linea << endl;
}
void MenuVista::MostrarCalidades()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 3: Selecciona la calidad de la prenda: " << endl
		<< "1) Standard" << endl
		<< "2) Premium" << endl 
		<< linea << endl;
}
void MenuVista::SolicitarPrecio()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar: ";
}
void MenuVista::SolicitarCantidad(int stock)
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "INFORMACION:" << endl << "EXISTE " << stock << " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << endl << "\n"
		<< "PASO 5: Ingrese la cantidad de unidades a cotizar: ";
}
void MenuVista::SolicitarFecha()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "PASO 6: Ingrese la fecha y hora de la cotizacion: ";
}
void MenuVista::Imprimir(string x)
{
	cout << x;
}
void MenuVista::MostrarResultado(string* info)
{
	system("CLS");
	MostrarHeaderCotizar();
	MostrarCotizacion(info);
	MostrarVolver();
}
void MenuVista::MostrarHeaderCotizar()
{
	cout << app + " - COTIZAR" + '\n';
	MostrarVolver();
}
void MenuVista::MostrarVolver()
{
	cout << linea << endl << "Presiona 3 para volver al menu principal" << endl << linea << endl;
}
void MenuVista::ConfirmarVolver()
{
	system("CLS");
	MostrarHeaderCotizar();
	cout << "Desea continuar o volver al menu principal? " << endl
		<< "1) Continuar con el valor de 3" << endl
		<< "2) Volver al menu principal" << endl
		<< linea << endl;
}
void MenuVista::MostrarSalir()
{
	system("CLS");
	cout << "Saliendo del programa..." << endl << linea << endl;
}
void MenuVista::MensajeIncorrecto()
{
	cout << "Opcion invalida. Por favor, ingrese una de las opciones indicadas." << endl;
}