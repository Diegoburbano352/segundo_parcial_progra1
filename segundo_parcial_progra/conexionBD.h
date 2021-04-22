#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class conexionBD{
private : MYSQL* conectar;
public:
	void abrir_conexion() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_parcial_2", "P@rcial123", "bd_segundo_parcial", 3306, NULL, 0);
		}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}
};

