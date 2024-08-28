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
    Empleado(int clave = 0, string nombre = "", string domicilio = "", float sueldo = 0.0, string reportaA = "")
        : claveEmpleado(clave), nombre(nombre), domicilio(domicilio), sueldo(sueldo), reportaA(reportaA) {}

//IMPRIME DATOS DEL EMPLEADO

    void imprime() const {
        cout << "Clave Empleado: " << claveEmpleado << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta A: " << reportaA << endl;
    }

//ACTUALIZA LOS DATOS DEL EMPLEADO.
    void CambiaDomic(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;}

        void CambiaReportaA(string nuevoReportaA) {
        reportaA = nuevoReportaA;}

        void ActualSueldo(float porcentajeIncremento) {
        sueldo += sueldo * (porcentajeIncremento / 100.0);}

//DEVUELVE LA CLAVE DEL EMPLEADO
int getClaveEmpleado() const {
        return claveEmpleado;}



//SE INICIA SOBRECARGA DE OPERADORES
    bool operator==(const Empleado& other) const {
        return claveEmpleado == other.claveEmpleado;}

    bool operator!=(const Empleado& other) const {
        return !(*this == other);}

    bool operator<(const Empleado& other) const {
        return sueldo < other.sueldo;}

    bool operator>(const Empleado& other) const {
        return sueldo > other.sueldo;}

    Empleado operator+(const Empleado& other) const {
        return Empleado(-1, nombre + " & " + other.nombre, domicilio + " / " + other.domicilio, sueldo + other.sueldo, reportaA + " / " + other.reportaA);}

    friend ostream& operator<<(ostream& os, const Empleado& e);
    friend istream& operator>>(istream& is, Empleado& e);
};

//OPERADOR DE SALIDA
ostream& operator<<(ostream& os, const Empleado& e) {os
<< "Clave Empleado: " << e.claveEmpleado << "\n"
<< "Nombre: " << e.nombre << "\n"
<< "Domicilio: " << e.domicilio << "\n"
<< "Sueldo: " << e.sueldo << "\n"
<< "Reporta A: " << e.reportaA;
return os;
}

//OPERADOR DE ENTRADA
istream& operator>>(istream& is, Empleado& e) {
cout << "Ingrese clave del empleado: ";
    is >> e.claveEmpleado;
    is.ignore();
cout << "Ingrese nombre: ";
    getline(is, e.nombre);
cout << "Ingrese domicilio: ";
    getline(is, e.domicilio);
cout << "Ingrese sueldo: ";
    is >> e.sueldo;
    is.ignore();
cout << "Ingrese a quien reporta: ";
    getline(is, e.reportaA);

    return is;
}


//MUESTRA EMPLEADOS
void mostrarEmpleados(const Empleado empleados[], int numEmpleados) {
    for (int i = 0; i < numEmpleados; ++i) {
        empleados[i].imprime();
        cout << "---------------------" << endl;
    }
}

//CAMBIA EL DOMICILIO
void cambiarDomicilio(Empleado empleados[], int numEmpleados) {
    int clave;
    string nuevoDomicilio;
    cout << "Ingrese la clave del empleado: ";
    cin >> clave;
    cin.ignore();
    cout << "Ingrese el nuevo domicilio: ";
    getline(cin, nuevoDomicilio);

    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].getClaveEmpleado() == clave) {
            empleados[i].CambiaDomic(nuevoDomicilio);
            cout << "Domicilio actualizado correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}


//ACTUALIZA EL SUELDO
void actualizarSueldo(Empleado empleados[], int numEmpleados) {
    int clave;
    float porcentaje;
    cout << "Ingrese la clave del empleado: ";
    cin >> clave;
    cout << "Ingrese el porcentaje de incremento: ";
    cin >> porcentaje;

    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].getClaveEmpleado() == clave) {
            empleados[i].ActualSueldo(porcentaje);
            cout << "Sueldo actualizado correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

//IMPRIME EMPLEADO
void imprimirEmpleado(const Empleado empleados[], int numEmpleados) {
    int clave;
    cout << "Ingrese la clave del empleado: ";
    cin >> clave;

    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].getClaveEmpleado() == clave) {
            empleados[i].imprime();
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}


//CAMBIA PATRON
void cambiarReportaA(Empleado empleados[], int numEmpleados) {
    int clave;
string nuevoReportaA;
cout << "Ingrese la clave del empleado: ";
cin >> clave;
cin.ignore();
cout << "Ingrese el nuevo nombre de quien reporta: ";
getline(cin, nuevoReportaA);

    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].getClaveEmpleado() == clave) {
            empleados[i].CambiaReportaA(nuevoReportaA);
            cout << "Nombre de quien reporta actualizado correctamente." << endl;
            return;
        }
    }
    cout << "Empleado no encontrado." << endl;
}

int main()

{


    Empleado jefePlanta(3314761, "Rubi Duran", "Elm Street #2340", 50000.0, "DIRECTOR");
    Empleado jefePersonal(331208, "Francisco Garcia", "Hacienda el lencero #4285", 35000.0, "SUBDIRECTOR");

    Empleado empleados[] = {jefePlanta, jefePersonal};
    int numEmpleados = 2;

    int opcion;

    do {
        cout << "\n   MENU DE OPCIONES" << endl;
        cout << endl;
        cout << "1. Mostrar todos los empleados" << endl;
        cout << "2. Cambiar domicilio de un empleado" << endl;
        cout << "3. Actualizar sueldo de un empleado" << endl;
        cout << "4. Imprimir datos de un empleado" << endl;
        cout << "5. Cambiar nombre de quien reporta" << endl;
        cout << "6. Salir" << endl;
        cout << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
        cout << endl;
        cout << "_____________________________________" << endl;
        cout << endl;
        cin.ignore();

        switch (opcion) {
            case 1: {
                cout << "LISTA DE EMPLEADOS:" << endl;
                cout << endl;
                mostrarEmpleados(empleados, numEmpleados);
                break;
            }

            case 2: {
                cambiarDomicilio(empleados, numEmpleados);
                break;
            }

            case 3: {
                actualizarSueldo(empleados, numEmpleados);
                break;
            }

            case 4: {
                imprimirEmpleado(empleados, numEmpleados);
                break;
            }

            case 5: {
                cambiarReportaA(empleados, numEmpleados);
                break;
            }

            case 6:
                cout << "Usted esta saliendo." << endl;
                break;

            default:
                cout << "La informacion es incorrecta." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
