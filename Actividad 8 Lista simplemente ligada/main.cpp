#include <iostream>
#include <string>

template<class T>
class LSLSE;

template<class T>
class node {
private:
    T data;
    node<T>* sig;
public:
    node() : sig(nullptr) {}
    friend class LSLSE<T>;
};

template<class T>
class LSLSE {
private:
    node<T>* lista;
public:
    LSLSE() : lista(nullptr) {}
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;


    T& getData(node<T>* pos) const { return pos->data; }
    node<T>* getSig(node<T>* pos) const { return pos->sig; }
};


//IMPRIMIR
template<class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        std::cout << aux->data << " -> ";
        aux = aux->sig;
    }
    std::cout << "nullptr" << std::endl;
}
//ELIMINAR
template<class T>
bool LSLSE<T>::eliminar(node<T>* pos) {
    if (vacia() || pos == nullptr) {
        return false;
    }
    if (pos == lista) {
        lista = lista->sig;
    } else {
        anterior(pos)->sig = pos->sig;
    }
    delete pos;
    return true;
}


//INSERTAR
template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem) {
    node<T>* aux = new node<T>;
    aux->data = elem;
    if (pos == nullptr) {
        aux->sig = lista;
        lista = aux;
    } else {
        aux->sig = pos->sig;
        pos->sig = aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos) const {
    if (vacia() || pos == nullptr) {
        return nullptr;
    }
    node<T>* aux = lista;
    while (aux != nullptr && aux->sig != pos) {
        aux = aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero() const {
    return vacia() ? nullptr : lista;
}

template<class T>
node<T>* LSLSE<T>::ultimo() const {
    if (vacia()) {
        return nullptr;
    }
    node<T>* aux = lista;
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia() const {
    return lista == nullptr;
}

// Clase SocioClub
class SocioClub {
private:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;
    int AnoIngreso;

public:
    SocioClub(int num = 0, const std::string& nombre = "", const std::string& domicilio = "", int anio = 0)
        : NumeroSocio(num), NombreSocio(nombre), Domicilio(domicilio), AnoIngreso(anio) {}

    int getNumeroSocio() const { return NumeroSocio; }
    std::string getNombreSocio() const { return NombreSocio; }
    std::string getDomicilio() const { return Domicilio; }
    int getAnoIngreso() const { return AnoIngreso; }

    friend std::ostream& operator<<(std::ostream& os, const SocioClub& socio) {
        os << "Numero Socio: " << socio.NumeroSocio
           << ", Nombre: " << socio.NombreSocio
           << ", Domicilio: " << socio.Domicilio
           << ", Ingreso: " << socio.AnoIngreso;
        return os;
    }

    bool operator<(const SocioClub& other) const {
        return NumeroSocio < other.NumeroSocio;
    }
};

//FUNCIONES DE LA LISTA
class ListaSocios {
private:
    LSLSE<SocioClub> lista;

public:
    void agregarSocio(const SocioClub& socio) {
        node<SocioClub>* actual = lista.primero();
        node<SocioClub>* anterior = nullptr;

//VERIFICAR SI EXISTE O NO
        while (actual != nullptr) {
            if (lista.getData(actual).getNumeroSocio() == socio.getNumeroSocio()) {
                std::cout << "Error: Ya existe un socio con el mismo numero.\n";
                return;
            }
            if (lista.getData(actual).getNumeroSocio() > socio.getNumeroSocio()) {
                break;
            }
            anterior = actual;
            actual = lista.getSig(actual);
        }


        lista.insertar(anterior, socio);
        std::cout << "Socio registrado exitosamente.\n";
    }
//FUNCION ELIMINAR
    void eliminarSocio(int numeroSocio) {
        node<SocioClub>* actual = lista.primero();
        while (actual != nullptr) {
            if (lista.getData(actual).getNumeroSocio() == numeroSocio) {
                lista.eliminar(actual);
                std::cout << "Socio con numero " << numeroSocio << " eliminado exitosamente.\n";
                return;
            }
            actual = lista.getSig(actual);
        }
        std::cout << "Socio con numero " << numeroSocio << " no encontrado.\n";
    }

    void imprimirSocios() const {
        std::cout << "Lista de socios:\n";
        lista.imprimir();
    }

    int contarSocios() const {
        int count = 0;
        node<SocioClub>* actual = lista.primero();
        while (actual != nullptr) {
            count++;
            actual = lista.getSig(actual);
        }
        return count;
    }

    void buscarSocio(const std::string& nombre, const std::string& domicilio) const {
        node<SocioClub>* actual = lista.primero();
        while (actual != nullptr) {
            if (lista.getData(actual).getNombreSocio() == nombre && lista.getData(actual).getDomicilio() == domicilio) {
                std::cout << "Socio encontrado:\n" << lista.getData(actual) << std::endl;
                return;
            }
            actual = lista.getSig(actual);
        }
        std::cout << "Socio no encontrado.\n";
    }
};

int main() {
    ListaSocios listaSocios;
    int opcion;

    do {
        std::cout << "\nMenu de opciones:\n";
        std::cout << "1. Registrar nuevo socio\n";
        std::cout << "2. Dar de baja un socio\n";
        std::cout << "3. Generar reporte de socios\n";
        std::cout << "4. Buscar socio por nombre y domicilio\n";
        std::cout << "5. Calcular total de socios\n";
        std::cout << "0. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int numero, anio;
                std::string nombre, domicilio;
                std::cout << "Numero de socio: ";
                std::cin >> numero;
                std::cout << "Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Domicilio: ";
                std::getline(std::cin, domicilio);
                std::cout << "Anio de ingreso: ";
                std::cin >> anio;

                listaSocios.agregarSocio(SocioClub(numero, nombre, domicilio, anio));
                break;
            }
            case 2: {
                int numero;
                std::cout << "Numero de socio a dar de baja: ";
                std::cin >> numero;
                listaSocios.eliminarSocio(numero);
                break;
            }
            case 3:
                listaSocios.imprimirSocios();
                break;
            case 4: {
                std::string nombre, domicilio;
                std::cout << "Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Domicilio: ";
                std::getline(std::cin, domicilio);
                listaSocios.buscarSocio(nombre, domicilio);
                break;
            }
            case 5:
                std::cout << "Total de socios registrados: " << listaSocios.contarSocios() << std::endl;
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no valida. Intente nuevamente.\n";
        }
    } while (opcion != 0);

    return 0;
}
