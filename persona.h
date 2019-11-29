#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;
class persona {
	string nombre;
	string apellido;
public:
	void set_nombre(string nom);
	void set_apellido(string ape);
	string get_nombre();
	string get_apellido();
	virtual void pedir_datos(string a,string b) = 0;
};
void persona::set_nombre(string nom) {
	nombre = nom;
}
void persona::set_apellido(string ape) {
	apellido = ape;
}
string persona::get_nombre() {
	return nombre;
}
string persona::get_apellido() {
	return apellido;
}