#include "MenuPresentador.h"
using namespace std;

int main()
{
	Tienda* tienda = new Tienda("Tienda Mayorista de Ropa", "Esmeralda 1000");
	Vendedor* vendedor = new Vendedor("Ignacio", "Llacay", "001");
	MenuVista* vista = new MenuVista();
	MenuPresentador* presentador = new MenuPresentador(vista, tienda, vendedor);
	presentador->MenuPrincipal();

	return 0;
}