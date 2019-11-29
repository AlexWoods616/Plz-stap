#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include "persona.h"
using namespace std;
class trabajador :public persona {
	int id;
public:
	void set_id(int d);
	int get_id();
	virtual void pedir_datos(string a, string b) override;
};

void trabajador::set_id(int i) {
	id = i;
}
int trabajador::get_id() {
	return id;
}
void trabajador::pedir_datos(string a, string b) {
	cout << "ingresa tu nombre: ";
	cin >> a;
	cout << "ingresar apellido: ";
	cin >> b;
	set_nombre(a);
	set_apellido(b);
	cout << "aqui esta el codigo: ";
}