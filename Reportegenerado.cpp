#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Alumno {
	string nombre;
	string matricula;
	float calific[3];
	float promedio;
};

int main() {
	ifstream entrada("alumnos.txt");
	if (!entrada.is_open()) {
		cout << "Error: no se pudo abrir alumnos.txt\n";
		return 0;
	}

	Alumno lista[100];
	int n = 0;
	string linea;
	while (n < 100 && getline(entrada, linea)) {
		for (char& ch : linea)
			if (ch == '|') ch = ' ';

		stringstream ss(linea);
		ss >> lista[n].nombre >> lista[n].matricula
			>> lista[n].calific[0] >> lista[n].calific[1] >> lista[n].calific[2];

		lista[n].promedio = (lista[n].calific[0] + lista[n].calific[1] + lista[n].calific[2]) / 3;
		n++;
	}
	entrada.close();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (lista[j].promedio < lista[j + 1].promedio) {
				Alumno temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}

	ofstream reporte("reporte.txt");
	if (!reporte.is_open()) {
		cout << "Error: no se pudo crear reporte.txt\n";
		return 0;
	}

	reporte << "REPORTE: ALUMNOS POR PROMEDIO (de mayor a menor)\n";
	reporte << "------------------------------------------------\n";
	for (int i = 0; i < n; i++) {
		reporte << i + 1 << ". " << lista[i].nombre
			<< " | Matricula: " << lista[i].matricula
			<< " | Promedio: " << lista[i].promedio << endl;
	}
	reporte.close();

	cout << "Reporte generado en reporte.txt\n\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << lista[i].nombre
			<< " | Matricula: " << lista[i].matricula
			<< " | Promedio: " << lista[i].promedio << endl;
	}

	return 0;
}