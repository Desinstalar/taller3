#include <iostream>
#include <cstdlib>  
using namespace std;

struct nodo {
    int datocola;    
    nodo* sgt;
};

void eliminarcola(nodo*& frente, nodo*& final, int& n);
void mostrarcola(nodo* frente);
void ingresarcola(nodo*& frente, nodo*& final, int n);  

int main() {
    nodo* final = NULL;
    nodo* frente = NULL;
    int x, opcion;
    do {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Ingresar pila" << endl;
        cout << "2. Ingresar cola" << endl;
        cout << "3. Mostrar pila" << endl;
        cout << "4. Mostrar cola" << endl;
        cout << "5. Eliminar pila" << endl;
        cout << "6. Eliminar cola" << endl;
        cout << "7. SALIR" << endl;
        cin >> opcion;

        switch (opcion) {
            case 2:
                cout << "Ingrese el número: ";
                cin >> x;
                ingresarcola(frente, final, x);  
                cout << "\n";
                system("pause");
                break;
            case 4:
                mostrarcola(frente);
                cout << "\n";
                system("pause");
                break;
            case 6:
                eliminarcola(frente, final, x);
                break;
        }
        system("cls");
    } while (opcion != 7);
}

void ingresarcola(nodo*& frente, nodo*& final, int n) {
    nodo* aux = new nodo();
    aux->datocola = n;  
    aux->sgt = NULL;
    if (frente == NULL) {
        frente = aux;
        final = aux;
    } else {
        final->sgt = aux;
        final = aux;
    }
}

void eliminarcola(nodo*& frente, nodo*& final, int& n) {
    if (frente == NULL) {
        cout << "La cola está vacía." << endl;
        return;
    }
    nodo* aux = frente;
    n = aux->datocola;  
    frente = frente->sgt;
    delete aux;
}

void mostrarcola(nodo* frente) {
    nodo* actual = frente;
    while (actual != NULL) {
        cout << "   " << actual->datocola;  
        actual = actual->sgt;
    }
}
