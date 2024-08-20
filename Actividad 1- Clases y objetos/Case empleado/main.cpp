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
    // Constructor
    Empleado(int clave, string nombre, string domicilio, float sueldo, string reportaA)
        : claveEmpleado(clave), nombre(nombre), domicilio(domicilio), sueldo(sueldo), reportaA(reportaA) {}

    // Métodos
    void imprime() const {
        cout << "Clave Empleado: " << claveEmpleado << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Reporta A: " << reportaA << endl;
    }

    void CambiaDomic(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void CambiaReportaA(string nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    void ActualSueldo(float nuevoSueldo) {
        sueldo = nuevoSueldo;
    }

    int getClaveEmpleado() const {
        return claveEmpleado;
    }
};


//FIN DE LA CLASE

/*---------------------------------------------------------------------------------------------------------------------------- */

//ALGORITMO PARA BUSCAR AL EMPLEADO POR CLAVE
Empleado* buscarEmpleadoPorClave(Empleado empleados[], int numEmpleados, int clave) {
    for (int i = 0;
    i < numEmpleados; i++) {
        if (empleados[i].getClaveEmpleado() == clave) {
            return &empleados[i];
        }
    }
    return 0;
}

//ALGORITMO PARA MOSTRAR EMPLEADOS
void mostrarEmpleados(Empleado empleados[], int numEmpleados) {
    for (int i = 0; i < numEmpleados; i++) {
        empleados[i].imprime();
        cout << "---------------------" << endl;
    }
}

//MENU DE OPCIONES
void menu(Empleado empleados[], int numEmpleados) {
    int opcion;


    do {
        cout << "\n   BIENVENIDO AL MENU DE OPCIONES" << endl;
        cout << "**************************************"<< endl;
        cout << endl;
        cout << "1. Mostrar todos los empleados" << endl;
        cout << "2. Imprimir los datos de un empleado" << endl;
        cout << "3. Actualizar el sueldo de un empleado" << endl;
        cout << "4. Cambiar el nombre de la persona a quien reporta un empleado" << endl;
        cout << "5. Cambiar el domicilio de un empleado" << endl;
        cout << "6. Salir" << endl;
        cout <<endl;
        cout << "SELECCIONE UNA OPERACION: ";
        cin >> opcion;
        system("cls");  // Comando para Windows



        int clave;
        Empleado* empleado;

        switch (opcion) {
            case 1:

                cout<<"      LISTA DE EMPLEADOS:"<<endl;
                cout<<"****************************"<<endl;
                mostrarEmpleados(empleados, numEmpleados);

                break;

            case 2:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                empleado = buscarEmpleadoPorClave(empleados, numEmpleados, clave);
                if (empleado != nullptr) {
                    empleado->imprime();
                } else {
                    cout << "Empleado no encontrado." << endl;
                }
                break;

            case 3:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                empleado = buscarEmpleadoPorClave(empleados, numEmpleados, clave);
                if (empleado != nullptr) {
                    float nuevoSueldo;
                    cout << "Ingrese el nuevo sueldo: ";
                    cin >> nuevoSueldo;
                    empleado->ActualSueldo(nuevoSueldo);
                    cout<<endl;
                    cout << "Sueldo actualizado con exito!." << endl;
                } else {
                    cout << "Este numero de empleado no existe." << endl;
                }

                break;

            case 4:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                empleado = buscarEmpleadoPorClave(empleados, numEmpleados, clave);
                if (empleado != nullptr) {
                    string nuevoReportaA;
                    cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, nuevoReportaA);
                    empleado->CambiaReportaA(nuevoReportaA);
                    cout << "Nombre de persona a quien reporta actualizado." << endl;
                } else {
                    cout << "Empleado no encontrado." << endl;
                }
                break;

            case 5:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                empleado = buscarEmpleadoPorClave(empleados, numEmpleados, clave);
                if (empleado != nullptr) {
                    string nuevoDomicilio;
                    cout << "Ingrese el nuevo domicilio: ";
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, nuevoDomicilio);
                    empleado->CambiaDomic(nuevoDomicilio);
                    cout << "Domicilio actualizado." << endl;
                } else {
                    cout << "Empleado no encontrado." << endl;
                }



                break;

            case 6:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor, intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

}

int main() {
    // Declaración de los objetosdu JefePlanta y JefePersonal
    Empleado jefePlanta(3314761, "Rubi Duran", "Elm Street #2340", 50000.0, "DIRECTOR");
    Empleado jefePersonal(331208, "Francisco Garcia", "Hacienda el lencero #4285", 35000.0, "SUBDIRECTOR");

    Empleado empleados[] = {jefePlanta, jefePersonal};
    int numEmpleados = 2;

    // Ejecutar el menú
    menu(empleados, numEmpleados);

    return 0;
}
