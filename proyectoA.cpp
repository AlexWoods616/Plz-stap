#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include "cliente.h"
#include "trabajador.h"
using namespace std;
enum  accion { ingresar=1,retirar}; // creas una numeracion de acciones
enum busqueda{ nom=1,apell}; // creas otra numeracion de opciones
int mon(string nm, string apl, int dnr) {
	int acc1;
	cout << nm << " " << apl << " " << dnr<< endl;
	cout << "que dese hacer?: \n 1.- ingresar dinero. \n 2.- retirar dinero. " << endl;
	cin >> acc1;
	switch (acc1) {
		int mov;
	case ingresar:
		cout << "cuanto desea ingresar?: ";
		cin >> mov;
		dnr += mov;
		return dnr;
		break;
	case retirar:
		cout << "cuanto desea retirar?: ";
		cin >> mov;
		dnr -= mov;
		return dnr;
		break;
	}
}

int main(){
	fstream prueba, aux;
	string nombre, apellido,linea, nombre2, apelli2,elec1;
	int dinero,elec , acc2,elec3;
	cout << "Cliente o Trabajador[1/2]: ";
	cin >> elec3;
	srand(time(NULL));
	if (elec3 == 1) {
		cliente a;
		prueba.open("Porfavor_funca.txt", ios::in);
		aux.open("help.txt", ios::out);
		cout << "eres \n 1.- Nuevo. \n 2.- Registrado. \n";
		cin >> elec;
		if (elec == 2) {
			cout << "como desea buscar?: \n 1.- nombre. \n 2.- apellido." << endl;
			cin >> acc2;
			switch (acc2) {
			case nom:
				cout << "ingresa el nombre que quieres buscar: ";
				cin >> nombre2;
				while (prueba >> nombre >> apellido >> dinero) { // mientras que el prueba tenga valores el while se ejecuta
					a.set_nombre(nombre); a.set_apellido(apellido); a.set_dinero(dinero);
					if (nombre2 == nombre) { //comparas el nombre con el que deseas buscar
						a.set_dinero(mon(a.get_nombre(), a.get_apellido(), a.get_dinero()));
					}
					aux << a.get_nombre() << " " << a.get_apellido() << " " << a.get_dinero() << endl; //escribes todo en el fichero auxiliar
				}
				prueba.close();
				aux.close();//cierras todos los ficheros
				remove("Porfavor_funca.txt");//eliminas el fichero antiguo
				if (rename("help.txt", "Porfavor_funca.txt") == 0) {} //renombras el fichero auxiliar
				else {
					cout << "nofunco";
				}
				ofstream("help.txt");
				break;
			case apell:
				cout << "ingresa el apellido que quieres buscar: ";
				cin >> apelli2;
				while (!prueba.eof()) {
					while (prueba >> nombre >> apellido >> dinero) {
						a.set_nombre(nombre); a.set_apellido(apellido); a.set_dinero(dinero);
						if (apelli2 == apellido) {
							a.set_dinero(mon(a.get_nombre(), a.get_apellido(), a.get_dinero()));
						}
						aux << a.get_nombre() << " " << a.get_apellido() << " " << a.get_dinero() << endl;
					}
				} // lo mismo que en la funcion anterior
				prueba.close();
				aux.close();
				remove("Porfavor_funca.txt");
				if (rename("help.txt", "Porfavor_funca.txt") == 0) {
					cout << "si funco";
				}
				else {
					cout << "nofunco";
				}
				break;
			}
		}
		if (elec == 1) {
			cout << "quieres unirte?[y/n]";
			cin >> elec1;
			if (elec1 == "y") {
				a.pedir_datos(nombre, apellido);
				cout << "Ingresa tu dinero: ";
				cin >> dinero;
				a.set_dinero(dinero);
				cout << a.get_nombre() << " " << a.get_apellido() << " " << a.get_dinero() << endl;
				aux << a.get_nombre() << " " << a.get_apellido() << " " << a.get_dinero() << endl;// escribe en el fichero auxiliar el nuevomen
				while (!prueba.eof()) {
					while (prueba >> nombre >> apellido >> dinero) {
						aux << nombre << " " << apellido << " " << dinero << endl;
					}
				}//aca escribe primero el cliente que se queire unir y despues los que ya estaban nuidos a la empresa
				prueba.close();
				aux.close();
				remove("Porfavor_funca.txt");
				if (rename("help.txt", "Porfavor_funca.txt") == 0)
					cout << "guardado";
				else
					cout << "hora de hacer la suicidacion Karen";
			}
			else {
				return 0;
			}//lo mismo cierras y renombras archivos
		}
	}
	if (elec3 == 2) {
		int elec4,id,id_aux,turnos_trab;
		trabajador me;
		cout << "Eres nuevo o ya trabajas aqui: [1/2]: ";
		cin >> elec4;
		if (elec4 == 1) {
			cout << "a que turno quieres ingresar? mañana,tarde,noche[1/2/3]: ";
			cin >> turnos_trab;
			if (turnos_trab == 1) {
				fstream coil;
				coil.open("trabajadores.txt", ios::in);
				fstream yawi;
				yawi.open("trabajador_aux.txt", ios::out);
				me.pedir_datos(nombre, apellido);
				id_aux = 1000000 + rand() % (10000000 - 1000000); // generas un numero aleatorio para los del turno de dia
				while (!coil.eof()) {
					while (coil >> id >> nombre >> apellido) {
						if (id_aux == id) {
							id_aux = 1000000 + rand() % (10000000 - 1000000);
							coil.seekg(0);
						}
						yawi << id << " " << nombre << " " << apellido << endl;
					}
				}
				cout << id_aux << endl;
				cout << id_aux << " " << me.get_nombre() << " " << me.get_apellido() << endl;
				yawi << id_aux << " " << me.get_nombre() << " " << me.get_apellido();
				coil.close();
				yawi.close();
				remove("trabajadores.txt");
				if (rename("trabajador_aux.txt", "trabajadores.txt") == 0)
					cout << "guardado";
				else
					cout << "hora de hacer la suicidacion Karen";
			}//lo mismo cierrsa y renombras
			if (turnos_trab == 2) {
				fstream tratar;
				tratar.open("Trab_tarde.txt", ios::in);
				fstream tratar_aux;
				tratar_aux.open("Trab_tarde_aux.txt", ios::out);
				me.pedir_datos(nombre, apellido);
				id_aux = 2000000 + rand() % (20000000 - 2000000);//generas un numero aleatorio para los de la tarde
				while (!tratar.eof()) {
					while (tratar >> id >> nombre >> apellido) {
						if (id_aux == id) {
							id_aux = 1000000 + rand() % (10000000 - 1000000);
							tratar.seekg(0);
						}
						tratar_aux << id << " " << nombre << " " << apellido << endl;
					}
				}//todo lo escribe en el auxiliar
				cout << id_aux << endl;
				cout << id_aux << " " << me.get_nombre() << " " << me.get_apellido() << endl;
				tratar_aux << id_aux << " " << me.get_nombre() << " " << me.get_apellido();
				tratar.close();
				tratar_aux.close();
				remove("Trab_tarde.txt");
				if (rename("Trab_tarde_aux.txt", "Trab_tarde.txt") == 0)
					cout << "guardado";
				else
					cout << "hora de hacer la suicidacion Karen";
			}//cierras y renombras archivos
			if (turnos_trab == 3) {
				fstream tranoch;
				tranoch.open("Trab_noche.txt", ios::in);
				fstream tranoch_aux;
				tranoch_aux.open("Trab_noche_aux.txt", ios::out);
				me.pedir_datos(nombre, apellido);
				id_aux = 2000000 + rand() % (20000000 - 2000000);//otro numero para los de la noche
				while (!tranoch.eof()) {
					while (tranoch >> id >> nombre >> apellido) {
						if (id_aux == id) {
							id_aux = 1000000 + rand() % (10000000 - 1000000);
							tranoch.seekg(0);
						}
						tranoch_aux << id << " " << nombre << " " << apellido << endl;
					}
				}//todo lo escribe en el auxiliar
				cout << id_aux << endl;
				cout << id_aux << " " << me.get_nombre() << " " << me.get_apellido() << endl;
				tranoch_aux << id_aux << " " << me.get_nombre() << " " << me.get_apellido();
				tranoch.close();
				tranoch_aux.close();
				remove("Trab_noche.txt");
				if (rename("Trab_noche_aux.txt", "Trab_noche.txt") == 0)
					cout << "guardado";
				else
					cout << "hora de hacer la suicidacion Karen";
			}
		}
		if (elec4 == 2) {
			fstream busqueda;
			int turn;
			cout << "que turno eres? dia,tarde,noche [1/2/3]: ";
			cin >> turn;
			if (turn == 1) {
				busqueda.open("trabajadores.txt", ios::in);
				cout << "ingresa tu id: " << endl;
				cin >> id_aux;
				while (busqueda >> id >> nombre >> apellido) {
					if (id == id_aux) {
						cout << "nombre: " << nombre << endl;
						cout << "apellido: " << apellido << endl;
						cout << "id: " << id << endl;
					}
				}
				busqueda.close();
			}
			if (turn == 2) {
				busqueda.open("Trab_tarde.txt", ios::in);
				cout << "ingresa tu id: ";
				cin >> id_aux;
				while (busqueda >> id >> nombre >> apellido) {
					if (id_aux == id) {
						cout << "nombre: " << nombre;
						cout << "apellido: " << apellido;
						cout << "id: " << id;
					}
				}
				busqueda.close();
			}
			if (turn == 3) {
				busqueda.open("Trab_noche.txt", ios::in);
				cout << "ingresa tu id: ";
				cin >> id_aux;
				while (busqueda >> id >> nombre >> apellido) {
					if (id_aux == id) {
						cout << "nombre: " << nombre;
						cout << "apellido: " << apellido;
						cout << "id: " << id;
					}
				}
				busqueda.close();
			}//son busquedas simples por favor.
		}
	}
		return 0;
}