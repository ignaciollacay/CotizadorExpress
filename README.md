# CotizadorExpress
Programa para que un vendedor de una tienda de ropa mayorista pueda realizar cotizaciones de sus productos.

## Uso
1. Descargar el archivo ejecutable "CotizadorExpress.exe" que se encuentra en la carpeta Debug.
2. Abrir el archivo ejecutable.

## Diagrama de Clases UML:
![CotizadorExpressUML](https://user-images.githubusercontent.com/37609021/235043815-5396062d-e033-4036-9f8d-ffd9f0293f1e.png)
(Quedó un poco desactualizado respecto los cambios que surgieron durante el desarrollo)

## Acerca de
Desarrollado con C++.
Desafío Final del Curso de C++ de Quark Academy.
Conceptos aplicados: C++, POO, UML, Git, Patrón de Diseño Modelo-Vista-Presentador (MVP)

## Desafío final
Parte A
1. Realizar un diagrama de clases que modele la entidad Vendedor. El usuario del programa será el vendedor de una tienda de ropa mayorista.
En principio, un vendedor posee Nombre, Apellido y Código de Vendedor.
2. El vendedor, podrá realizar distintas Cotizaciones antes de llevar a cabo una Venta. Las cotizaciones se deberán almacenar en un historial del vendedor.
Una Cotización se compone de los siguientes atributos:
• Número de identificación
• Fecha y Hora de la cotización
• Código del Vendedor que realiza la cotización
• Prenda cotizada
• Cantidad de unidades cotizadas
• Resultado del cálculo de la cotización.
3. Implementar las clases creando los miembros necesarios.

Parte B
1. Modelar las entidades especificadas a continuación y relacionarlas según corresponda.
El Vendedor trabaja en una Tienda de ropa. Esta última posee un Nombre, Dirección y un listado de distintas Prendas para vender.
Una prenda tiene algunas propiedades como: calidad de prenda (standard o Premium), precio unitario de la prenda y cantidad de unidades en stock.
2. Implementar las clases creando los atributos necesarios.

Parte C
1. Además, existen dos tipos de prendas: Pantalones y Camisas.
- Las camisas pueden ser de manga corta o manga larga.
- Además, las camisas pueden tener cuello mao o cuello común.
- Los pantalones pueden ser comunes o chupines.
2. Completar el modelo de clases.
3. Es necesario que el programa permita marcar si el tipo de camisa es de manga corta o manga larga, cuello mao o cuello común, ya que cada tipo de camisa tiene un precio diferente a los demás. Lo mismo para los pantalones chupines, que tienen un precio diferente a los pantalones normales.
4. El precio final que calcula el programa (cotización) responderá a las siguientes reglas de negocio:
Tipo de prenda:
RN 1- Si la camisa es de tipo manga corta, el precio se rebaja en un 10%.
RN 2- Si la camisa tiene cuello mao, el precio aumenta en un 3%.
RN 3- Si la camisa es de manga corta y cuello mao, deben aplicarse las dos reglas anteriores (en el orden establecido).
RN 4- Si el pantalón es chupín, el precio se rebaja en un 12%.
Calidad de prenda:
RN 5- Si la calidad de la prenda es Standard: el precio no se modifica.
RN 6- Si la calidad de la prenda es Premium: el precio aumenta en un 30%.
☛ Importante: las reglas de negocio se deben aplicar de forma incremental, aplicando primero las de Tipo de prenda, y al resultado, aplicar si corresponde, las reglas de Calidad.
5. Modificar la implementación contemplando los nuevos cambios.

Parte E
1. Al iniciar el programa, deberá crearse el objeto Tienda con datos ficticios, al igual que el objeto Vendedor, también con datos ficticios.
Además, también habrá un número fijo de prendas en stock, siendo:
- 1000 camisas en total, de las cuales:
  - 500 de manga corta, de las cuales:
    - 200 son de cuello mao, de las cuales: 100 son de calidad Standard
    - 100 son de calidad Premium
- 300 son de cuello común, de las cuales: 
  - 150 son de calidad Standard
  - 150 son de calidad Premium
- 500 de manga larga, de las cuales:
  - 150 son de cuello mao, de las cuales:
    - 75 son de calidad Standard ⚫ 
    - 75 son de calidad Premium 
  - 350 son de cuello común, de las cuales:
    - 175 son de calidad Standard
    - 175 son de calidad Premium
- 2000 pantalones en total, de los cuales:
  - 1500 son chupines, de los cuales: 
    - 750 son de calidad Standard
    - 750 son de calidad Premium
  -  500 son comunes, de los cuales
    - 250 son de calidad Standard
    - 250 son de calidad Premium
Restricción: si el usuario intenta cotizar sobre una cantidad de stock no disponible, el sistema emitirá un mensaje de error indicando que no se puede realizar una cotización sobre una cantidad de stock no disponible.
2. Se deberá poder consultar el Historial de Cotizaciones en cualquier momento de la ejecución del programa.

Parte F
1. Finalmente, se desea poder imprimir tanto la cotización actual como el historial completo de cotizaciones del vendedor. ¿Cómo se podría establecer a estos objetos como "imprimibles"?.
2. Modificar el diagrama de clases correspondiente.
Aclaración: habiendo planteado la solución en el diagrama de clases, no es necesario implementar la funcionalidad de impresión en el programa.

Parte G
A este punto ya deberías tener un conjunto de clases implementado en código C++ con el diagrama UML correspondiente. Te sugerimos que revises el diagrama para chequear que no te falta modelar ninguna relación, atributo o método.
Importante: en el diagrama sólo debes incluir las clases del dominio, es decir, aquellas que contienen la lógica de negocio de tu aplicación. No incluyas clases de la vista o aquellas que correspondan a patrones de arquitectura MVC, MVP u otro.
