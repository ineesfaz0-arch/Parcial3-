#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Alumno {
	string nombre;
	string matricula;
	float calific[3];
};
int main() {
	Alumno nuevo;

	cout << "Ingresa el nombre del nuevo alumno: ";
	getline(cin, nuevo.nombre);
	cout << "Ingresa la matricula: ";
	cin >> nuevo.matricula;

	for (int a = 0; a < 3;a++) {
		cout << "Calificacion " << a + 1 << ": ";
		cin >> nuevo.calific[a];
	}
	ofstream archivo("alumno.txt", ios::app);
	if (archivo.is_open()) {
		archivo << nuevo.nombre << "|"
			<< nuevo.matricula << "|"
			<< nuevo.calific[0] << "|"
			<< nuevo.calific[1] << "|"
			<< nuevo.calific[2] << endl;
	
	}
	else {
		cout << "\nNo se pudo abrir el archivo para agregar\n";
			return 1;
	}

	archivo.close();
	cout << "Nuevo alumno agregado";
	return 0;

}