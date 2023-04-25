#include "MenuPresentador.h"

MenuPresentador::MenuPresentador(MenuVista* vista, Tienda* tienda, Vendedor* vendedor)
{
	this->vista = vista;
	this->tienda = tienda;
	this->vendedor = vendedor;
}

MenuPresentador::~MenuPresentador()
{
	delete vista;
	delete tienda;
	delete vendedor;
}

void MenuPresentador::MenuPrincipal()
{
	string* infoTienda = tienda->GetInfo(), *infoVendedor = vendedor->GetInfo();
	vista->MenuPrincipal(infoTienda, infoVendedor);
	delete[] infoTienda; delete[] infoVendedor;
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			HistorialCotizaciones(vendedor);
			break;
		}
		else if (input == 2)
		{
			Cotizar();
			break;
		}
		else if (input == 3)
		{
			vista->MostrarSalir();
			exit(0);
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (true);
}

void MenuPresentador::Cotizar()
{
	Cotizacion* cotizacion = SolicitarDatosCotizacion(); // FIXME: Memory release?

	vendedor->GetHistorial()->Agregar(*cotizacion); // Agregar al historial
	string* info = cotizacion->GetInfo();
	vista->MostrarResultado(info);
	delete cotizacion;
	delete[] info;
	RegresarAlMenu();
}
Cotizacion* MenuPresentador::SolicitarDatosCotizacion()
{
	Prenda* prenda;

	// Paso 1
	TipoPrenda tipo = ElegirPrenda();
	if (tipo == TipoPrenda::camisa)
	{
		// Paso 2 a
		Manga manga = ElegirManga();

		// Paso 2 b
		Cuello cuello = ElegirCuello();
		prenda = new Camisa(manga, cuello);
	}
	else
	{
		// Paso 2
		Ajuste ajuste = ElegirAjuste();
		prenda = new Pantalon(ajuste);
	}

	// Paso 3
	CalidadPrenda calidad = ElegirCalidad();
	prenda->SetCalidad(calidad);

	// Paso 4
	int precio = IngresarPrecio();
	prenda->SetPrecio(precio);

	// Paso 5
	int cantidad = IngresarCantidad(*prenda);

	// Paso 6
	string codigoVendedor = vendedor->GetCodigo();

	// Obtener fecha y hora actual de manera automatica 
	Fecha fecha = Fecha::TiempoActual(); 
	// Obtener fecha y hora de manera manual.
	//Fecha fecha = IngresarFecha(); // Se descarta la opcion de ingreso manual de fecha a fin de seguir la consigna
	
	// Generar cotizacion con los datos ingresados
	Cotizacion* cotizacion = new Cotizacion(fecha, codigoVendedor, prenda, precio, cantidad);

	return cotizacion;
}

// Muestra el historial del vendedor y retorna al menu principal cuando presiona 3.
void MenuPresentador::HistorialCotizaciones(Vendedor* v)
{
	vista->MostrarHeaderHistorial();
	int cotizaciones = v->GetHistorial()->GetCantidad();
	if (cotizaciones > 0)
	{
		for (int i = 0; i < cotizaciones; i++)
		{
			string* info = v->GetHistorial()->GetCotizaciones()[i].GetInfo();
			vista->MostrarCotizacion(info);
			if (i != cotizaciones -1)
				vista->Imprimir("\n \n");
			delete[] info;
		}
	}
	else
	{
		vista->Imprimir("\nNo hay cotizaciones para mostar.\n\n");
	}
	vista->MostrarVolver();
	RegresarAlMenu();
}
void MenuPresentador::RegresarAlMenu()
{
	int input;
	do
	{
		input = vista->GetInput();
		if (input != 3)
			vista->MensajeIncorrecto();
	} while (input != 3);

	MenuPrincipal();
}
TipoPrenda MenuPresentador::ElegirPrenda()
{
	// Cotizar 1
	vista->MostrarPrendas();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return TipoPrenda::camisa;
		}
		else if (input == 2)
		{
			return TipoPrenda::pantalon;
		}
		else if (input == 3)
		{
			MenuPrincipal();
			break;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 3);
}
Manga MenuPresentador::ElegirManga()
{
	// Paso 2.a
	vista->MostrarMangas();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return Manga::corta;
		}
		else if (input == 2)
		{
			return Manga::larga;
		}
		else if (input == 3)
		{
			MenuPrincipal();
			break;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 3);
}
Cuello MenuPresentador::ElegirCuello()
{
	// Paso 2.b
	vista->MostrarCuellos();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return Cuello::comun;
		}
		else if (input == 2)
		{
			return Cuello::mao;
		}
		else if (input == 3)
		{
			MenuPrincipal();
			break;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 3);
}
Ajuste MenuPresentador::ElegirAjuste()
{
	// Paso 2
	vista->MostrarAjustes();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return Ajuste::comun;
		}
		else if (input == 2)
		{
			return Ajuste::chupin;
		}
		else if (input == 3)
		{
			MenuPrincipal();
			break;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 3);
}
CalidadPrenda MenuPresentador::ElegirCalidad()
{
	// Paso 3
	vista->MostrarCalidades();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return CalidadPrenda::standard;
		}
		if (input == 2)
		{
			return CalidadPrenda::premium;
		}
		if (input == 3)
		{
			MenuPrincipal();
			break;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 3);
}
int MenuPresentador::IngresarPrecio()
{
	// Paso 4
	vista->SolicitarPrecio();
	int input = vista->GetInput();

	if (input == 3 && ConfirmarVolver())
		MenuPrincipal();

	return input;
}
int MenuPresentador::IngresarCantidad(Prenda& p)
{
	// Paso 5
	int stock;
	int* index = p.GetIndex();
	if (index[0] == 0) // camisa
		stock = tienda->GetCamisas(index[1], index[2], index[3]);
	else
		stock = tienda->GetPantalones(index[1], index[2]);

	vista->SolicitarCantidad(stock);

	int input;
	do
	{
		input = vista->GetInput();
		if (input > stock)
			vista->Imprimir("No se puede realizar una cotizacion sobre una cantidad de stock no disponible.\n");
	} while (input > stock);

	delete[] index;
	if (input == 3 && ConfirmarVolver())
		MenuPrincipal();
	return input;
}

bool MenuPresentador::ConfirmarVolver()
{
	vista->ConfirmarVolver();
	int input;
	do
	{
		input = vista->GetInput();
		if (input == 1)
		{
			return false;
		}
		else if (input == 2)
		{
			return true;
		}
		else
		{
			vista->MensajeIncorrecto();
		}
	} while (input > 2);
}

// Permite ingresar manualmente la fecha.
Fecha MenuPresentador::IngresarFecha()
{
	bool valid = false;
	do
	{
		vista->SolicitarFecha();

		int dia, mes, ano, hora, min;
		vista->Imprimir("Dia: ");
		cin >> dia;
		vista->Imprimir("Mes: ");
		cin >> mes;
		vista->Imprimir("Ano: ");
		cin >> ano;
		vista->Imprimir("Hora: ");
		cin >> hora;
		vista->Imprimir("Minutos: ");
		cin >> min;
		if (Fecha::Validar(dia, mes, ano, hora, min))
		{
			valid = true;
			return Fecha(dia, mes, ano, hora, min);
		}
		else
		{
			cout << "fecha invalida" << endl;
		}
	} while (!valid);
}