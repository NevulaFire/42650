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

//AQUI ESTA LO DE LA CARGA DE OPERADORES

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

    bool operator<(const Empleado& e) const {
        return sueldo < e.sueldo;
    }
};

//FIN DE LA CARGA DE LOS OP



template <typename T, int MAX>
class ListaEstatica {
private:
T datos[MAX];
int tam;

public:
ListaEstatica() : tam(0) {}

//FORMULA PARA INCERTAR ELEMENTOS EN LA LISTA
int Inserta(const T& elem, int pos) {
    if (pos < 0 || pos > tam || tam >= MAX) return -1;
    for (int i = tam; i > pos; --i) {
    datos[i] = datos[i - 1];
    }
    datos[pos] = elem;
    tam++;
    return 0;
    }

//FORMULA PARA INCERTAR ELEMENTOS AL FINAL DE LA LISTA
    int Agrega(const T& elem) {
    if (tam >= MAX) return -1;
    datos[tam++] = elem;
    return 0;
    }

//BUSCAR POR ID EMPLEADO
    int Busca(const T& elem) const {
    for (int i = 0; i < tam; ++i) {
    if (datos[i].getClaveEmpleado() == elem.getClaveEmpleado()) {
    return i;  //SE ENCONTRO EL DDTO
            }
        }
        return -1;
    }

 //ELIMINAR ELEMENTO DE LA LISTA
    int Elimina(int pos) {
    if (pos < 0 || pos >= tam) return -1;
    for (int i = pos; i < tam - 1; ++i) {
    datos[i] = datos[i + 1];
    }
    tam--;
    return 0;
    }

 //VERIFICAR SI ESTA VACIA
    int Vacia() const {
    return tam == 0 ? 1 : 0;
    }

//VERIFICAR SU ESTA LLENA
    int Llena() const {
    return tam >= MAX ? 1 : 0;
    }
//MOSTRAR TODOS LOS ELEMENTOS DE LA LISTA
    int Muestra() const {
    if (Vacia()) {
            cout << "Lista vacía." << endl;
            return -1;
        }
        for (int i = 0; i < tam; ++i) {
            cout << datos[i];
            cout << "---------------------" << endl;
        }
        return 0;
    }
};

void menu(ListaEstatica<Empleado, 10>& lista) {
    int opcion;
    do {
        cout << "\n   MENU DE OPCIONES" << endl;
        cout << "***********************" << endl;
        cout << "1. Agregar un empleado" << endl;
        cout << "2. Buscar un empleado" << endl;
        cout << "3. Eliminar un empleado" << endl;
        cout << "4. Insertar un empleado" << endl;
        cout << "5. Mostrar todos los empleados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        Empleado e;
        int pos;

        switch (opcion) {
            case 1: {
                if (lista.Llena()) {
                    cout << "La lista esta llena. No se puede agregar mas empleados." << endl;
                    break;
                }
                cout << "Ingrese los datos del nuevo empleado:" << endl;
                cin >> e;
                lista.Agrega(e);
                cout << "Empleado insertado con exito." << endl;
                break;
            }
            case 2: {
                if (lista.Vacia()) {
                    cout << "La lista está vacía. No se puede buscar empleados." << endl;
                    break;
                }
                cout << "Ingrese la clave del empleado a buscar: ";
                cin >> e;
                int index = lista.Busca(e);
                if (index != -1) {
                    cout << "Empleado encontrado en la posicion: " << index << endl;
                    cout << "Datos del empleado: " << endl;
                    cout << lista.Muestra();
                } else {
                    cout << "Empleado no encontrado." << endl;
                }
                break;
            }
            case 3: {
                if (lista.Vacia()) {
                    cout << "La lista esta vacia. No se puede eliminar empleados." << endl;
                    break;
                }
                cout << "Ingrese la clave del empleado a eliminar: ";
                cin >> e;
                int index = lista.Busca(e);
                if (index != -1) {
                    lista.Elimina(index);
                    cout << "Empleado eliminado con exito." << endl;
                } else {
                    cout << "Empleado no encontrado." << endl;
                }
                break;
            }
            case 4: {
                if (lista.Llena()) {
                    cout << "La lista esta llena. No se puede insertar mas empleados." << endl;
                    break;
                }
                cout << "Ingrese los datos del empleado a insertar:" << endl;
                cin >> e;
                cout << "Ingrese la posicion donde insertar el empleado: ";
                cin >> pos;
                if (lista.Inserta(e, pos) == 0) {
                    cout << "Empleado insertado con exito en la posicion " << pos << "." << endl;
                } else {
                    cout << "No se pudo insertar el empleado. Verifique la posicion." << endl;
                }
                break;
            }
            case 5: {
                cout << "Lista de empleados:" << endl;
                lista.Muestra();
                break;
            }
            case 6: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                break;
            }
        }
    } while (opcion != 6);
}

int main() {
   //LO MAS DIFICL CREAR
    ListaEstatica<Empleado, 10> lista;


    menu(lista);

    return 0;
}
