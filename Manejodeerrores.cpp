#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream archivo("no_existe.txt");

	if (!archivo.is_open()) {
		cout << "Error: el archivo 'no_existe.txt' no existe o no se pudo abrir\n";
		cout << "Verifica el nombre o la ubicacion del archivo\n";
	}
	else {
		string linea;
		while (getline(archivo, linea))
			cout << linea << endl;
		archivo.close();
	}

	cout << "\nEl programa continua y termina correctamente\n";
	return 0;
}
