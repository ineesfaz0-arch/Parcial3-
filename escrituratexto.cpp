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
	Alumno grupo[5];

	for (int i = 0; i < 5; i++) {

		cout << "Ingresa el nombre del alumno " << i + 1 << ": ";
		cin >> grupo[i].nombre;
		cout << "Ingresa la matricula del alumno " << i + 1 << ": ";
		cin >> grupo[i].matricula;
		float suma = 0;

		for (int j = 0; j < 3; j++) {
			cout << "Calificacion " << j + 1 << ": ";
			cin >> grupo[i].calific[j];
			suma += grupo[i].calific[j];
		}
		cout << "Alumno: " << grupo[i].nombre << ", Matricula: " << grupo[i].matricula << ", Promedio: " << suma / 3 << endl;
	}
	ofstream archivo("alumno.txt");

	if (archivo.is_open()) {
		for (int i = 0; i < 5; i++) {
			archivo << grupo[i].nombre << "|"
				<< grupo[i].matricula << "|"
				<< grupo[i].calific[0] << "|"
				<< grupo[i].calific[1] << "|"
				<< grupo[i].calific[2] << endl;

		}
		archivo.close();
		cout << "\nDatos guardados correctamente\n";
	}
	else {
		cout << "\nNo se guardaron los datos correctamente\n";
	}
	return 0;
}
