#include <iostream>
#include <sstream>
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
	int n = 0;
	string linea;


	ifstream archivo("alumno.txt");

	if (!archivo.is_open()) {
		cout << "\nNo se pudo abrir el archivo para leer\n";
		return 0;

		}
	while (n < 5 && getline(archivo, linea)) {
		stringstream ss(linea);
		string c1, c2, c3;
		getline(ss, grupo[n].nombre, '|');
		getline(ss, grupo[n].matricula, '|');
		getline(ss, c1, '|');
		getline(ss, c2, '|');
		getline(ss, c3, '|');

		grupo[n].calific[0] = stof(c1);
		grupo[n].calific[1] = stof(c2);
		grupo[n].calific[2] = stof(c3);

		n++;
	}
	archivo.close();

	cout << "\nDatos leidos del archivo (" << n << " alumnos)\n";
	for (int i = 0; i < n; i++) {
		float suma = grupo[i].calific[0] + grupo[i].calific[1] + grupo[i].calific[2];
		cout << "Alumno: " << grupo[i].nombre
			<< ", Matricula: " << grupo[i].matricula
			<< ", Calificaciones: " << grupo[i].calific[0] << ", "
			<< grupo[i].calific[1] << ", " << grupo[i].calific[2]
			<< ", Promedio: " << suma / 3 << endl;
	}
	return 0;
}
