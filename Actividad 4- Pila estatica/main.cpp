#include <iostream>
#include <string>

using namespace std;

class Empleado {

private:
int claveEmpleado;
string nombre;
string domicilio;
float sueldo;
string reportaA;

public:
    Empleado(int clave = 0, const string& nombre = "", const string& domicilio = "", float sueldo = 0.0, const string& reportaA = "")
        : claveEmpleado(clave), nombre(nombre), domicilio(domicilio), sueldo(sueldo), reportaA(reportaA) {}

    void CambiaDomic(string nuevoDomicilio) { domicilio = nuevoDomicilio; }
    void CambiaReportaA(string nuevoReportaA) { reportaA = nuevoReportaA; }
    void ActualSueldo(float nuevoSueldo) { sueldo = nuevoSueldo; }

    int getClaveEmpleado() const { return claveEmpleado; }
    float getSueldo() const { return sueldo; }
    const string& getNombre() const { return nombre; }

    void imprime() const {
        cout << "Clave Empleado: " << claveEmpleado << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta A: " << reportaA << endl;
    }


//SOBRE CARGA

    friend ostream& operator<<(ostream& o, const Empleado& e) {
        o << "Clave Empleado: " << e.claveEmpleado << endl;
        o << "Nombre: " << e.nombre << endl;
        o << "Domicilio: " << e.domicilio << endl;
        o << "Sueldo: " << e.sueldo << endl;
        o << "Reporta A: " << e.reportaA << endl;
        return o;
    }

    friend istream& operator>>(istream& i, Empleado& e) {
        cout << "Ingrese la clave del empleado: ";
        i >> e.claveEmpleado;
        i.ignore();
        cout << "Ingrese el nombre: ";
        getline(i, e.nombre);
        cout << "Ingrese el domicilio: ";
        getline(i, e.domicilio);
        cout << "Ingrese el sueldo: ";
        i >> e.sueldo;
        i.ignore();
        cout << "Ingrese a quien reporta: ";
        getline(i, e.reportaA);
        return i;
    }
};


//DECLARACION DE LA PILA
template <typename T, int MAX>
class PilaEstatica {
private:
T datos[MAX];
int tope;

public:
PilaEstatica() : tope(-1) {}

//PUSH
void push(const T& elem) {
if (Llena()) {
cout << "No puedes agregar mas empleados la pila esta llena." << endl;
            return;
        }
        datos[++tope] = elem;
    }
//PPOP
void pop() {
        if (Vacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        --tope;
    }

//TOP
T top() const {
        if (Vacia()) {
            throw runtime_error("La pila está vacia.");
        }
        return datos[tope];
    }

    bool Vacia() const {
        return tope == -1;
    }

    bool Llena() const {
        return tope >= MAX - 1;
    }
};


//MENU DE OPCIOONES
void menu(PilaEstatica<Empleado, 10>& pila) {
    int opcion;
    do {
        cout << "\n   MENU DE OPCIONES" << endl;
        cout << "***********************" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        cout<< endl;

        Empleado e;

        switch (opcion) {
            case 1: {
                if (pila.Llena()) {
                    cout << " No puedes agregar más empleados. Espacio lleno." << endl;
                    break;
                }
                cout << "Ingrese los datos del nuevo empleado:" << endl;
                cout <<endl;
                cin >> e;
                pila.push(e);
                cout << "Se agrego un empleado!" << endl;
                break;
            }
            case 2: {
                if (pila.Vacia()) {
                    cout << "No hay nada que eliminar" << endl;
                    break;
                }
                pila.pop();
                cout << "Este empleado fue eliminado." << endl;
                break;
            }
            case 3: {
                if (pila.Vacia()) {
                    cout << "No hay informacion para mostrar" << endl;
                    break;
                }
                cout << "El empleado TOP es:" << endl;
                cout << pila.top();
                break;
            }
            case 4: {
                cout << "Salir con exito." << endl;
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
    PilaEstatica<Empleado, 10> pila;
    menu(pila);
    return 0;
}
