#pragma once
#include "compras.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include "conexionBD.h"
using namespace std;
class productos : compras {
public:

	productos() {

	}

	productos(string pro, int id_marc, string desc, string img, float prec_c, float prec_v, int exist, string fh) : compras(pro, id_marc, desc, img, prec_c, prec_v, exist, fh) {

	}



	// METODOS

	//set (modificar)


	void setproductos(string pro) { producto = pro; }

	void setid_marca(int id_marc) { id_marca = id_marc; }

	void setdescripcion(string desc) { descripcion = desc; }

	void setimagen(string img) { imagen = img; }

	void setprecio_costo(float prec_c) { precio_costo = prec_c; }

	void setprecio_venta(float prec_v) { precio_venta = prec_v; }

	void setexistencia(int exist) { existencia = exist; }

	void setfecha_ingreso(string fh) { fecha_ingreso = fh; }



	//get (mostrar)


	string getproducto() { return producto; }

	int  getid_marca() { return id_marca; }

	string getdescripcion() { return descripcion; }

	string getimagen() { return imagen; }

	float getprecio_costo() { return precio_costo; }

	float getprecio_venta() { return precio_venta; }

	int getexistencia() { return existencia; }

	string getfecha_ingreso() { return fecha_ingreso; }





	// metodo
	void crear() {
		int q_estado;
		conexionBD cn = conexionBD();

		cn.abrir_conexion();
		string t = to_string(id_marca);
		string c = to_string(precio_costo);
		string d = to_string(precio_venta);
		string u = to_string(existencia);
		if (cn.getConectar()) {
			string  insertar = " INSERT INTO productos (producto,id_marca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES (' " + producto + " ',' " + t + " ',' " + descripcion + " ',' " + imagen + " ','  " + c + " ',' " + d + " ',' " + u + " ',' " + fecha_ingreso + " ')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void  leer() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << " ------------ Datos de productos ------------ " << endl;
			string consulta = " SELECT * FROM productos; ";
			const  char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar xxx " << endl;
			}

		}
		else {
			cout << " xxx Error en la conexión xxxx " << endl;
		}
		cn.cerrar_conexion();
	}
	void  modificar_producto(int pro) {
		
			int q_estado;
			conexionBD cn = conexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();

			if (cn.getConectar()) {
				string Id = to_string(pro);
				string pro,desc,imagen,fecha="now()";
				int idmarca=0, existencia=0;
				float precioc, preciov;
				
				string consulta = "select * from productos where id_producto= " + Id + "";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);

				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());

					while (fila = mysql_fetch_row(resultado)) {

						cout << "Id producto: " << fila[0] << endl;
						cout << "producto: " << fila[1] << endl;
						cout << "Id marca: " << fila[2] << endl;
						cout << "Descripcion: " << fila[3] << endl;
						cout << "Imagen: " << fila[4] << endl;
						cout << "precio costo: " << fila[5] << endl;
						cout << "precio venta " << fila[6] << endl;
						cout << "Existencia: " << fila[7] << endl;
						cout << "Fecha Ingreso: " << fila[8] << endl;

						cout << ("\n\nNuevo Producto: ") << fila[1] << endl;
						cin >> pro;

						cout << ("\n\n Nuevo id marca: ") << fila[2] << endl;
						cin >> idmarca;

						cout << ("\n\nNuevo decripcion: ") << fila[3] << endl;
						cin >> desc;
						
						cout << ("\n\nNuevo imagen: ") << fila[4] << endl;
						cin >> imagen;
						
						cout << ("\n\nNuevo precio costo: ") << fila[5] << endl;
						cin >> precioc;
						
						cout << ("\n\nNuevo precio venta: ") << fila[6] << endl;
						cin >> preciov;

						cout << ("\n\nNuevo existencia: ") << fila[7] << endl;
						cin >> existencia;

						cout << ("\n\nFecha: ") << fila[8] << endl;

						string q = to_string(idmarca);
						string w = to_string(existencia);
						string e = to_string(precioc);
						string r = to_string(preciov);

					
string consulta = "update productos set producto = '" + pro + "',id_marca = " + q + ", descripcion = '" + desc + "', imagen = '" + imagen + "', precio_costo = " +e + ", precio_venta = " + r + ", existencia = " + w + ", fecha_ingreso = " + fecha + "  where id_producto = " + Id + "";

							const char* c = consulta.c_str();
							q_estado = mysql_query(cn.getConectar(), c);
						
					}

				}
				else {
					cout << "\n\n--------- Error al modificar  ---------" << endl;
				}

			}
			else {
				cout << " \n\n---------  Error en la Conexion ---------" << endl;
			}
			cn.cerrar_conexion();
		}
	void eliminar_producto(int pro) {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		char m;
		if (cn.getConectar()) {
			string Id = to_string(pro);
		
			string consulta = "select * from productos where id_producto= " + Id + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id producto: " << fila[0] << endl;
					cout << "producto: " << fila[1] << endl;
					cout << "Id marca: " << fila[2] << endl;
					cout << "Descripcion: " << fila[3] << endl;
					cout << "Imagen: " << fila[4] << endl;
					cout << "precio costo: " << fila[5] << endl;
					cout << "precio venta " << fila[6] << endl;
					cout << "Existencia: " << fila[7] << endl;
					cout << "Fecha Ingreso: " << fila[8] << endl;
					cout << ("\n\nDesea eliminar  s/n: ");
					cin >> m;
					if (m=='s'){
					string consulta = "delete from productos where id_producto =" + Id + "";
						const char* c = consulta.c_str();
					q_estado = mysql_query(cn.getConectar(), c);
					cout<<("\n\nDatos Eliminados correctamente");
					}
				}

			}
			else {
				cout << "\n\n--------- Error al modificar  ---------" << endl;
			}

		}
		else {
			cout << " \n\n---------  Error en la Conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	
	}
	

};

