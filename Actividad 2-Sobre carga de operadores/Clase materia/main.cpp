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
    // Constructor
    Materia(int clave = 0, string nombre = "", string profesorTit = "", string libroTexto = "")
        : Clave(clave), Nombre(nombre), ProfesorTit(profesorTit), LibroTexto(libroTexto) {}

    // M�todos get y set
    int getClave() const { return Clave; }
    void setClave(int nuevaClave) { Clave = nuevaClave; }

    string getNombre() const { return Nombre; }
    void setNombre(const string& nuevoNombre) { Nombre = nuevoNombre; }

    string getProfesor() const { return ProfesorTit; }
    void setProfesor(const string& nuevoProfesor) { ProfesorTit = nuevoProfesor; }

    string getLibroTexto() const { return LibroTexto; }
    void setLibroTexto(const string& nuevoLibroTexto) { LibroTexto = nuevoLibroTexto; }

    // Imprime datos de la materia
    void imprime() const {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor Titular: " << ProfesorTit << endl;
        cout << "Libro de Texto: " << LibroTexto << endl;
    }

    // Cambia los datos de la materia
    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    // Cambia el nombre del profesor
    void Cambiaprofe(const string& nuevoProfesor) {
        ProfesorTit = nuevoProfesor;
    }

    // Sobrecarga de operadores
    bool operator==(const Materia& other) const {
        return Clave == other.Clave;
    }

    bool operator!=(const Materia& other) const {
        return !(*this == other);
    }

    bool operator<(const Materia& other) const {
        return Clave < other.Clave;
    }

    bool operator>(const Materia& other) const {
        return Clave > other.Clave;
    }

    Materia operator+(const Materia& other) const {
        return Materia(Clave, Nombre + " / " + other.Nombre, ProfesorTit + " / " + other.ProfesorTit, LibroTexto + " / " + other.LibroTexto);
    }

    // Sobrecarga del operador de salida <<
    friend ostream& operator<<(ostream& os, const Materia& m) {
        os << "Clave: " << m.Clave << "\n"
           << "Nombre: " << m.Nombre << "\n"
           << "Profesor Titular: " << m.ProfesorTit << "\n"
           << "Libro de Texto: " << m.LibroTexto;
        return os;
    }

    // Sobrecarga del operador de entrada >>
    friend istream& operator>>(istream& is, Materia& m) {
        cout << "Ingrese clave: ";
        is >> m.Clave;
        is.ignore(); // Limpiar el buffer de entrada

        cout << "Ingrese nombre: ";
        getline(is, m.Nombre);

        cout << "Ingrese profesor titular: ";
        getline(is, m.ProfesorTit);

        cout << "Ingrese libro de texto: ";
        getline(is, m.LibroTexto);

        return is;
    }
};

// N�mero m�ximo de materias
const int MAX_MATERIAS = 2;

// Funci�n para mostrar materias
void mostrarMaterias(const Materia materias[], int numMaterias) {
    for (int i = 0; i < numMaterias; ++i) {
        materias[i].imprime();
        cout << "------------------------------" << endl;
    }
}

// Funci�n para mostrar profesores
void mostrarProfesores(const Materia materias[], int numMaterias) {
    for (int i = 0; i < numMaterias; ++i) {
        cout << materias[i].getProfesor() << endl;
    }
}

int main() {
    // Crear arreglo est�tico de materias
    Materia materias[MAX_MATERIAS] = {
        Materia(42650, "Seminario de Programaci�n", "Jairo Cain Sanchez", "Ing. en informatica"),
        Materia(42499, "Bases de datos", "Ruben Ortega", "Ing. en informatica")
    };

    int opcion;
    do {
        cout << "\nMen� de opciones:\n";
        cout << "1. Mostrar materias.\n";
        cout << "2. Mostrar profesores.\n";
        cout << "3. Cambiar la clave de la materia Programaci�n.\n";
        cout << "4. Cambiar el nombre del maestro que imparte la materia BasesDatos.\n";
        cout << "5. Imprimir todos los datos de la materia BasesDatos.\n";
        cout << "6. Salir.\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << "****************************************************" << endl;

        switch (opcion) {
            case 1: {
                cout << "Materias:\n";
                mostrarMaterias(materias, MAX_MATERIAS);
                break;
            }
            case 2: {
                cout << "Profesores:\n";
                mostrarProfesores(materias, MAX_MATERIAS);
                break;
            }
            case 3: {
                int nuevaClave;
                cout << "Ingrese la nueva clave para Programaci�n: ";
                cin >> nuevaClave;
                materias[0].setClave(nuevaClave);
                cout << "Clave actualizada.\n";
                break;
            }
            case 4: {
                string nuevoProfesor;
                cout << "Ingrese el nuevo nombre del profesor para BasesDatos: ";
                cin.ignore();
                getline(cin, nuevoProfesor);
                materias[1].setProfesor(nuevoProfesor);
                cout << "Nombre del profesor actualizado.\n";
                break;
            }
            case 5: {
                cout << "Los datos de la materia BasesDatos son:\n" << endl;
                materias[1].imprime();
                cout << "****************************************************" << endl;
                break;
            }
            case 6: {
                cout << "Saliendo...\n";
                break;
            }
            default: {
                cout << "Opci�n no v�lida. Intente de nuevo.\n";
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}
