#include <iostream>
#include <string>

using namespace std;

class Materia {
private:
    int Clave;
    string Nombre;
    string ProfesorTit;
    string LibroTexto;

public:
    //SE INICIALIZA EL CONSTRUCTOR
    Materia(int clave, string nombre, string profesorTit, string libroTexto)
        : Clave(clave), Nombre(nombre), ProfesorTit(profesorTit), LibroTexto(libroTexto) {}

    // IMPRIMIR LOS DATOS
    void imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor Titular: " << ProfesorTit << endl;
        cout << "Libro de Texto: " << LibroTexto << endl;
    }

    //CAMBIAR CLAVE MATERIA
    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    // CAMBIAR NOMRE DEL PROFESOR
    void Cambiaprofe(string nuevoProfesor) {
        ProfesorTit = nuevoProfesor;
    }
};

int main() {
    Materia Programacion(42650, "Seminario de Programación", "Jairo Cain Sanchez", "Ing. en informatica");
    Materia BasesDatos(42499, "Bases de datos", "Ruben Ortega", "Ing. en informatica");

    int opcion;
    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Cambiar la clave de la materia.\n";
        cout << "2. Cambiar el nombre del maestro que imparte la materia BasesDatos.\n";
        cout << "3. Imprimir todos los datos de la materia BasesDatos.\n";
        cout << "4. Salir.\n";
        cout << "Seleccione una opcion: "<<endl;
        cin >> opcion;
        cout<<endl;
        cout << "****************************************************"<<endl;

        switch (opcion) {
            case 1: {
                int nuevaClave;
                cout << "Ingrese la nueva clave para Programación: ";
                cin >> nuevaClave;
                Programacion.CambiaClave(nuevaClave);
                cout << "Clave actualizada.\n";
                break;
            }
            case 2: {
                string nuevoProfesor;
                cout << "Ingrese el nuevo nombre del profesor para BasesDatos: ";
                cin.ignore();
                getline(cin, nuevoProfesor);
                BasesDatos.Cambiaprofe(nuevoProfesor);
                cout << "Nombre del profesor actualizado.\n";
                break;
            }
            case 3: {
                cout << "Los datos de la materia base de datos son:\n"<<endl;
                BasesDatos.imprime();
                cout << "****************************************************"<<endl;


                break;
            }
            case 4: {
                cout << "Saliendo...\n";
                break;
            }
            default: {
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}
