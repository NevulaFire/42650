#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Alumno {
private:
    int id;
    string nombre;
    string solicitud;
    string carrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    Alumno(int id = 0, const string& nombre = "", const string& solicitud = "", const string& carrera = "",
           int materiasAprobadas = 0, float promedioGeneral = 0.0)
        : id(id), nombre(nombre), solicitud(solicitud), carrera(carrera),
          materiasAprobadas(materiasAprobadas), promedioGeneral(promedioGeneral) {}

    void imprime() const {
        cout << "ID Alumno:\n " << id << endl;
        cout << "Nombre: \n" << nombre << endl;
        cout << "Solicitud: \n" << solicitud << endl;
        cout << "Carrera: \n" << carrera << endl;
        cout << "Materias Aprobadas: \n" << materiasAprobadas << endl;
        cout << "Promedio General: \n" << promedioGeneral << endl;
    }

    friend ostream& operator<<(ostream& o, const Alumno& a) {
        o << "ID Alumno: " << a.id << endl
          << "Nombre: " << a.nombre << endl
          << "Solicitud: " << a.solicitud << endl
          << "Carrera: " << a.carrera << endl
          << "Materias Aprobadas: " << a.materiasAprobadas << endl
          << "Promedio General: " << a.promedioGeneral << endl;
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
        cout << "Ingrese la carrera: ";
        getline(i, a.carrera);
        cout << "Ingrese el total de materias aprobadas: ";
        i >> a.materiasAprobadas;
        cout << "Ingrese el promedio general: ";
        i >> a.promedioGeneral;
        i.ignore();
        return i;
    }

    int getId() const {
        return id;
    }

    bool operator<(const Alumno& other) const {
        return id < other.id;
    }
};

// INICIA LA COLA
template <typename T, int MAX>
class ColaEstatica {
private:
    T datos[MAX];
    int frente, fondo;

public:
    ColaEstatica() : frente(0), fondo(0) {}

    void enqueue(const T& elem) {
        if (llena()) {
            cout << "La cola esta llena!.\a" << endl;
            return;
        }
        datos[fondo] = elem;
        fondo = (fondo + 1) % MAX;
    }

    void dequeue() {
        if (vacia()) {
            cout << "Informacion no encontrada.\a" << endl;
            return;
        }
        frente = (frente + 1) % MAX;
    }

    T front() const {
        if (vacia()) {
            throw runtime_error("La cola esta vacia!.\a");
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
            cout << "no hay informacion \a." << endl;
            return;
        }
        cout << "Solicitudes en la cola:" << endl;
        int i = frente;
        while (i != fondo) {
            cout << datos[i] << endl;
            i = (i + 1) % MAX;
        }
    }


    int busquedaLineal(int elem, Alumno arr[], int ultind) const {
        int i = 0;
        while (i <= ultind) {
            if (arr[i].getId() == elem) {
                return i;
            }
            i++;
        }
        return -1;
    }

//BUSQUEDA BINARIA
    int busquedaBinaria(int elem, Alumno arr[], int ultind) const {
        int i = 0, j = ultind;
        while (i <= j) {
            int medio = (i + j) / 2;
            if (arr[medio].getId() == elem) {
                return medio;
            }
            if (elem < arr[medio].getId()) {
                j = medio - 1;
            } else {
                i = medio + 1;
            }
        }
        return -1;
    }

//ORDENAR
    void obtenerDatosOrdenados(Alumno arr[], int& count) const {
        count = 0;
        int i = frente;
        while (i != fondo) {
            arr[count++] = datos[i];
            i = (i + 1) % MAX;
        }
        sort(arr, arr + count);
    }
};

//MENU DE OPCIONES
void menu(ColaEstatica<Alumno, 10>& cola) {
    int opcion;
    Alumno a;

    do {
        cout << "\n       MENU DE OPCIONES:" << endl;
        cout << "*****************************" << endl;
        cout << "1. Dar de alta al alumno" << endl;
        cout << "2. Crear constancia" << endl;
        cout << "3. Mostrar alumnos" << endl;
        cout << "4. Busqueda lineal" << endl;
        cout << "5. Busqueda binaria" << endl;
        cout << "6. Salir" << endl;
        cout << "\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        cout << "*****************************\n" << endl;

        switch (opcion) {
            case 1: {
                cout << "-------------------------" << endl;
                cout << "\n    Agregar alumnos:" << endl;
                cout << "-------------------------" << endl;
                cout << "Ingrese los datos del alumno nuevo:\n" << endl;
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
                cout << "-------------------------" << endl;
                cout << "\n    Crear constancia:" << endl;
                cout << "-------------------------" << endl;
                cout << "Contancia para:\n" << endl;
                cout << a << endl;
                cola.dequeue();
                cout << "La constancia se creo con exito." << endl;
                break;
            }
            case 3: {
                cola.mostrar();
                break;
            }
            case 4: {
                cout << "Ingrese el ID del alumno a buscar de forma lineal: ";
                int idBuscado;
                cin >> idBuscado;
                cout << "-----------------------------------------------------" << endl;
                Alumno arr[10];
                int count;
                cola.obtenerDatosOrdenados(arr, count);

                int posicion = cola.busquedaLineal(idBuscado, arr, count - 1);
                if (posicion == -1) {
                    cout << "Esta informacion no existe!.\a" << endl;
                } else {
                    cout << "La informacion del alumno se encuentra en la posicion:\n " <<endl <<posicion << endl;
                     cout << "-----------------------------------------------------" << endl;
                    cout <<endl;
                    cout << "Informacion del alumno:\n" <<endl<< arr[posicion] << endl;
                    cout << "-----------------------------------------------------" << endl;
                }
                break;
            }
            case 5: {
                cout << "Ingrese el ID del alumno a buscar de forma binaria: ";
                int idBuscado;
                cin >> idBuscado;
                 cout << "-----------------------------------------------------" << endl;

                Alumno arr[10];
                int count;
                cola.obtenerDatosOrdenados(arr, count);

                int posicion = cola.busquedaBinaria(idBuscado, arr, count - 1);
                if (posicion == -1) {
                    cout << "Esta informacion no existe!.\a" << endl;
                } else {
                    cout << "La informacion del alumno se encuentra en la posicion:\n " <<endl << posicion<< endl;
                    cout <<endl;
                    cout << "Informacion del alumno:\n" <<endl<< arr[posicion] << endl;
                    cout << "-----------------------------------------------------" << endl;
                }
                break;
            }
            case 6: {
                cout << "Salir con exito." << endl;
                break;
            }
            default: {
                cout << "Esta opcion no existe!\a" << endl;
                break;
            }
        }
    } while (opcion != 6);
}

int main() {
    ColaEstatica<Alumno, 10> cola;
    menu(cola);
    return 0;
}

