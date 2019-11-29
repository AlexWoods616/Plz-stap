#pragma once
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include "persona.h"
using namespace std;
class cliente :public persona {
	public:
		int dinero;
		void set_dinero(int d);
		int get_dinero();
		virtual void pedir_datos(string a, string b) override;
};
void cliente::set_dinero(int d) {
	dinero = d;
}
int cliente::get_dinero() {
	return dinero;
}
void cliente::pedir_datos(string a,string b) {
	cout << "ingresa tu nombre: ";
	cin >> a;
	cout << "ingresar apellido: ";
	cin >> b;
	set_nombre(a);
	set_apellido(b);
	cout << "listo solo falta el monto a ingresar." << endl;
}