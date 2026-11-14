#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calific[3];
};

int main() {
    Alumno a[3];

    for (int i = 0; i < 3; i++) {
        cout << "Alumno " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, a[i].nombre);

        cout << "Matricula: ";
        getline(cin, a[i].matricula);

        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> a[i].calific[j];
        }
        cin.ignore(1000, '\n');   
    }

    ofstream txt("alumnos.txt");
    if (!txt) {
        cout << "Error al crear archivo de texto.";
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        txt << a[i].nombre << "|" << a[i].matricula << "|"
            << a[i].calific[0] << "|" << a[i].calific[1] << "|" << a[i].calific[2] << endl;
    }
    txt.close();

    ofstream bin("alumnos.dat", ios::binary);
    if (!bin) {
        cout << "Error al crear archivo binario";
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        unsigned int tam = a[i].nombre.size();
        bin.write((char*)&tam, sizeof(tam));
        bin.write(a[i].nombre.c_str(), tam);

        tam = a[i].matricula.size();
        bin.write((char*)&tam, sizeof(tam));
        bin.write(a[i].matricula.c_str(), tam);

        bin.write((char*)a[i].calific, sizeof(a[i].calific));
    }
    bin.close();

    ifstream texto("alumnos.txt", ios::binary | ios::ate);
    ifstream archivo("alumnos.dat", ios::binary | ios::ate);

    if (texto && archivo) {
        cout << "\nArchivo de texto: " << texto.tellg() << " bytes";
        cout << "\nArchivo binario: " << archivo.tellg() << " bytes\n";
    }
    else {
        cout << "\nNo se pudieron comparar los archivos\n";
    }
    texto.close();
    archivo.close();

    ifstream rb("alumnos.dat", ios::binary);
    Alumno b;
    cout << "\n--- Datos leidos del binario ---\n";
    for (int i = 0; i < 3; i++) {
        unsigned int tam;

        rb.read((char*)&tam, sizeof(tam));
        b.nombre.resize(tam);
        rb.read(&b.nombre[0], tam);

        rb.read((char*)&tam, sizeof(tam));
        b.matricula.resize(tam);
        rb.read(&b.matricula[0], tam);

        rb.read((char*)b.calific, sizeof(b.calific));

        cout << b.nombre << " |" << b.matricula << "|"
            << b.calific[0] << "|" << b.calific[1] << "|" << b.calific[2] << endl;
    }
    rb.close();

    return 0;
}
