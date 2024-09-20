#include <iostream>
#include <string>

using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string solicitud;

public:
    Alumno(int id = 0, const string& nombre = "", const string& solicitud = "")
        : id(id), nombre(nombre), solicitud(solicitud) {}

    void imprime() const {
        cout << "ID Alumno: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Solicitud: " << solicitud << endl;
    }

    friend ostream& operator<<(ostream& o, const Alumno& a) {
        o << "ID Alumno: " << a.id << ", Nombre: " << a.nombre << ", Solicitud: " << a.solicitud;
        return o;
    }

    friend istream& operator>>(istream& i, Alumno& a) {
        cout << "Ingrese el ID del alumno: ";
        i >> a.id;
        i.ignore();
        cout << "Ingrese el nombre: ";
        getline(i, a.nombre);
        cout << "Ingrese la solicitud: ";
        getline(i, a.solicitud);
        return i;
    }
};

// Declaración de la cola
template <typename T, int MAX>
class ColaEstatica {
private:
    T datos[MAX];
    int frente, fondo;

public:
    ColaEstatica() : frente(0), fondo(0) {}

    void enqueue(const T& elem) {
        if (llena()) {
            cout << "No se puede agregar más solicitudes, la cola está llena." << endl;
            return;
        }
        datos[fondo] = elem;
        fondo = (fondo + 1) % MAX;
    }

    void dequeue() {
        if (vacia()) {
            cout << "No hay solicitudes para atender." << endl;
            return;
        }
        frente = (frente + 1) % MAX;
    }

    T front() const {
        if (vacia()) {
            throw runtime_error("La cola está vacía.");
        }
        return datos[frente];
    }

    bool vacia() const {
        return frente == fondo;
    }

    bool llena() const {
        return (fondo + 1) % MAX == frente;
    }

    void mostrar() const {
        if (vacia()) {
            cout << "No hay solicitudes en la cola." << endl;
            return;
        }
        cout << "Solicitudes en la cola:" << endl;
        int i = frente;
        while (i != fondo) {
            cout << datos[i] << endl;
            i = (i + 1) % MAX;
        }
    }
};

// Menú de opciones
void menu(ColaEstatica<Alumno, 10>& cola) {
    int opcion;
    Alumno a;

    do {
        cout << "\n   MENU DE OPCIONES" << endl;
        cout << "*" << endl;
        cout << "1. Dar de alta solicitud de un alumno" << endl;
        cout << "2. Elaborar constancia" << endl;
        cout << "3. Mostrar alumnos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                cout << "Ingrese los datos del nuevo alumno:" << endl;
                cin >> a;
                cola.enqueue(a);
                cout << "Solicitud de alumno encolada." << endl;
                break;
            }
            case 2: {
                if (cola.vacia()) {
                    cout << "No hay solicitudes para atender." << endl;
                    break;
                }
                a = cola.front();
                cout << "Elaborando constancia para:" << endl;
                cout << a << endl;
                cola.dequeue();
                cout << "Constancia elaborada y solicitud atendida." << endl;
                break;
            }
            case 3: {
                cola.mostrar();
                break;
            }
            case 4: {
                cout << "Salir con éxito." << endl;
                break;
            }
            default: {
                cout << "Opción no válida." << endl;
                break;
            }
        }
    } while (opcion != 4);
}

int main() {
    ColaEstatica<Alumno, 10> cola;
    menu(cola);
    return 0;
}
