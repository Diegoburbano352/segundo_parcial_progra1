// segundo_parcial_progra.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <windows.h>
#include <iostream>
#include "productos.h"
#include <string>
using namespace std;
void modificar();
void eliminar();

int main()
{
	while (1)
	{
		int opc;
		cout << "----------------------------------------menu CRUD--------------------------------------" << endl << endl;
		cout << "1) menu CRUD productos" << endl;
		cin >> opc;
		cin.ignore();
		system("CLS");

		switch (opc)
		{
		case 1:
			int opciones;
			cout << "1) Insert tabla productos " << endl;
			cout << "2) Select tabla productos " << endl;
			cout << "3) Update tabla productos " << endl;
			cout << "4) Delete tabla productos  " << endl;
			cout << "5) Salir " << endl;
			cin >> opciones;
			cin.ignore();
			switch (opciones)
			{
			   case 1:
			   {
				   string producto, descripcion, fecha_ingreso, imagen;
				   int existencia = 0, id_marca = 0;
				   float precio_costo = 0, precio_venta = 0;

				   cout << "Ingrese el producto:\n";
				   getline(cin, producto);
				   cout << "ingrese el id_marca:\n";
				   cin >> id_marca;
				   cin.ignore();
				   cout << "Ingrese la descripcion:\n";
				   getline(cin, descripcion);
				   cout << "Ingrese la imagen: \n";
				   getline(cin, imagen);
				   cout << "Ingrese el precio costo:\n";
				   cin >> precio_costo;
				   cin.ignore();
				   cout << " Ingrese el precio venta:\n";
				   cin >> precio_venta;
				   cin.ignore();
				   cout << "Ingrese la existencia:\n";
				   cin >> existencia;
				   cin.ignore();
				   cout << "Ingrese la fecha de ingreso:\n";
				   getline(cin, fecha_ingreso);

				   productos p = productos(producto, id_marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);

				   p.crear();
				   break;
			   }
			   case 2:
			   {
				   string producto, descripcion, fecha_ingreso, imagen;
				   int existencia = 0, id_marca = 0;
				   float precio_costo = 0, precio_venta = 0;
				   productos p = productos(producto, id_marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
				   p.leer();
				   system("pause");
				   break;
			   }
			   case 3:
			   {
				   int opciones;
				   cout << "1) Update productos" << endl;
				   cout << "5) Salir " << endl;
				   cin >> opciones;
				   cin.ignore();
				   switch (opciones) {
				   case 1:
				   {
					   modificar();
					   break;
				   }

				   }
			   }
			   case 4:system("cls");
				   eliminar();
				   break;
			   case 5:
				   exit(0);

			}
		}
	}

		system("pause");
		return 0;

}
void modificar() {
	int pro;
	cout << ("Ingrese Id a modificar: ");
	cin >> pro;
	productos p = productos();
	p.modificar_producto(pro);
	system("pause");

}

void eliminar() {
	int pro;
	cout << ("Ingrese Id a eliminar: ");
	cin >> pro;
	productos p = productos();
	p.eliminar_producto(pro);
	system("pause");
}