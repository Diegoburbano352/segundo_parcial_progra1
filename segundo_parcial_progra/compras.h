#pragma once
#include <iostream>

using namespace std;
class compras{
	// atributos
protected: string producto, descripcion, fecha_ingreso, imagen;
		 int existencia = 0, id_marca = 0;
		 float precio_costo = 0 , precio_venta = 0;
		 // constructor
protected:
	compras(){
	}
	compras(string pro, int id_marc, string desc, string img, float prec_c, float prec_v, int exist, string fh) {
		producto = pro;
		id_marca = id_marc;
		descripcion = desc;
		imagen = img;
		precio_costo = prec_c;
		precio_venta = prec_v;
		existencia = exist;
		fecha_ingreso = fh;	
	}

};

