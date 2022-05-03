
#include "pch.h"
#include "Asignacion.hpp"



int logo[12][29]{
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     {0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},
     {0,0,0,1,0,1,0,1,0,1,1,0,0,1,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0},
     {0,0,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,0,1,1,1,0,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0},
     {0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0},
};
void guardarDatos(ListaPersonas* listaP) {


    ofstream archEsc("NombreUsuarios.txt");
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        archEsc << listaP->getpersona(i)->getNombre() << endl;
        archEsc << listaP->getpersona(i)->getApellido() << endl;
        archEsc << listaP->getpersona(i)->getEdad() << endl;
        archEsc << listaP->getpersona(i)->getGenero() << endl;
        archEsc << listaP->getpersona(i)->getid() << endl;
        archEsc << endl;
    }
    ifstream archLect("NombreUsuarios.txt");

    archLect.close();
}
void pintarLogo() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 29; j++) {

            if (logo[i][j] == 0) Console::BackgroundColor = ConsoleColor::Black;
            if (logo[i][j] == 1) Console::BackgroundColor = ConsoleColor::White;
            cout << " ";
            Console::BackgroundColor = ConsoleColor::Black;
        }
        cout << endl;
    }
    cout << endl;

}

void agregarPersona(ListaPersonas* ListaP) {
    int id;
    string Nombre;
    string Apellido;
    string genero;
    int edad;
    cout << "Ingrese su ID:" << endl;
    cin >> id;
    cin.ignore();
    cout << "Ingrese su nombre: ";
    getline(cin, Nombre); cout << endl;
    cout << "Ingrese su apellido: ";
    getline(cin, Apellido); cout << endl;
    cout << "Ingrese su genero (Masculino-Femenino-Otro): ";
    getline(cin, genero); cout << endl;
    cout << "Ingrese su edad: ";
    cin >> edad;
    ListaP->InsertarPersona(id, Nombre, Apellido, genero, edad);
    guardarDatos(ListaP);
}


void agregarTarea(ListaPersonas* ListaP, ListaTareas* ListaT) {
    string nombreTarea;
    string tipoUrgencia;
    string estado;
    string fechaCreacion;
    string auxPersona;
    int aux = 0;
    cout << "Ingrese el nombre de la tarea: ";
    cin.ignore();
    getline(cin, nombreTarea); cout << endl;
    cout << "Ingrese el tipo de urgencia(urgente-aplazable): ";
    getline(cin, tipoUrgencia); cout << endl;
    cout << "Ingrese su estado(completo, incompleto): ";
    getline(cin, estado); cout << endl;
    cout << "Ingrese la fecha de creacion: ";
    getline(cin, fechaCreacion); cout << endl;
    cout << "Ingrese su nombre: ";
    getline(cin, auxPersona); cout << endl;
    for (int i = 0; i < ListaP->getCantidad(); i++)
    {
        if (ListaP->getpersona(i)->getNombre() == auxPersona) {
            ListaT->InsertarTarea(nombreTarea, tipoUrgencia, estado, fechaCreacion, ListaP->getpersona(i));
            aux = 1;
        }
    }
    if (aux == 0) {
        cout << "Usted no ha sido registrado" << endl;
    }

}

auto ordenarNombrePersonas = [&](ListaPersonas* listaP) {
    int i, j, min;
    string aux, nombres[10];
    cout << "ORDENADO ALFABETICAMENTE:" << endl;
    for (i = 0; i < listaP->getCantidad(); i++)    //Primer bucle recorre todo el arreglo
    {
        nombres[i] = listaP->getpersona(i)->getNombre();
    }
    for (i = 0; i < listaP->getCantidad(); i++)
    {
        min = i;
        for (j = i + 1; j < listaP->getCantidad(); j++) {
            if (nombres[j] < nombres[min]) {
                min = j;
            }
        }
        aux = nombres[i];
        nombres[i] = nombres[min];
        nombres[min] = aux;
    }
    for (i = 0; i < listaP->getCantidad(); i++)
    {
        cout << nombres[i] << endl;
    }
    ofstream archEsc("NombreUsuariosOrdenados.txt");
    for (int i = 0; i < 10; i++)
    {
        archEsc << nombres[i] << endl;
        archEsc << endl;
    }
    ifstream archLect("NombreUsuariosOrdenados.txt");

    archLect.close();
};


void mostrarPersonas(ListaPersonas* listaP) {
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        cout << listaP->getpersona(i)->getNombre() << endl;
    }
}

void mostrarTareas(ListaPersonas* listaP, ListaTareas* ListaT) {
    for (int i = 0; i < listaP->getCantidad(); i++)
    {
        cout << listaP->getpersona(i)->getNombre() << ":" << endl;

        for (int j = 0; j < ListaT->getCantidad(); j++)
        {
            if (listaP->getpersona(i)->getNombre() == ListaT->getTarea(j)->getPersona()->getNombre()) {
                cout << j + 1 << ".-" << ListaT->getTarea(j)->getNombrTarea() << "\t" << "Estado: " << ListaT->getTarea(j)->getEstado() << endl;
            }
        }
    }

}
void mostrarTareasTerminadas(ListaTareas* ListaT) {
    for (int i = 0; i < ListaT->getCantidad(); i++)
    {
        cout << "Usuario: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
        if (ListaT->getTarea(i)->getEstado() == "completo") {
            for (int i = 0; i < ListaT->getCantidad(); i++) {
                cout << "Tareas terminadas de: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
                cout << i + 1 << ListaT->getTarea(i)->getNombrTarea() << endl;
            }
        }
    }
}

void cambiarEstadoTarea(ListaTareas* ListaT) {
    string auxUsuario;
    string auxTarea;
    cout << "Ingrese un nombre de usuario registrado: " << endl;
    cin.ignore();
    getline(cin, auxUsuario); cout << endl;
    for (int i = 0; i < ListaT->getCantidad(); i++)
    {
        if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
            cout << "Ingrese la tarea para cambiar su estado: " << endl;
            for (int i = 0; i < ListaT->getCantidad(); i++)
            {
                if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
                    cout << i + 1 << ".-" << ListaT->getTarea(i)->getNombrTarea() << endl;
                }
            }
            getline(cin, auxTarea); cout << endl;
            if (ListaT->getTarea(i)->getNombrTarea() == auxTarea) {
                ListaT->getTarea(i)->setEst("completo");
            }
        }
        else {
            cout << "El nombre puesto no es de un usuario registrado, intentelo nuevamente" << endl; break;
        }
    }
}
void mostrarTareasIncompletas(ListaTareas* listaT) {
    for (int i = 0; i < listaT->getCantidad(); i++)
    {
        if (listaT->getTarea(i)->getEstado() == "incompleto") {
            cout << "Tareas incompletas:" << endl;
            cout << listaT->getTarea(i)->getNombrTarea() << " -> " << listaT->getTarea(i)->getPersona()->getNombre() << endl;
        }
    }
}
void OrdInsercion(ListaPersonas* lp) { //Tiempo Asintotico = O(n^2)
    int edad[20];//1
    int pos, aux;

    for (int i = 0; i < lp->getCantidad(); i++) {
        edad[i] = lp->getpersona(i)->getEdad();
        pos = i;
        aux = edad[i];

        while ((pos > 0) && (edad[pos - 1] > aux)) {

            edad[pos] = edad[pos - 1];
            pos--;
        }
        edad[pos] = aux;

    }

    cout << "\nLista de personas ordenadas" << endl;
    cout << "\tEDAD \t\t NOMBRE" << endl;

    for (int i = 0; i < lp->getCantidad(); i++) {
        for (int j = 0; j < lp->getCantidad(); j++) {
            int x = lp->getpersona(j)->getEdad();
            if (edad[i] == x)
                cout << "\n " << x << "\t-\t" << lp->getpersona(j)->getNombre() << endl;
        }
    }

}
void ordenaroNombres(ListaPersonas* listaP, ListaTareas* listaT) {// tiempo asintotico = o(n^2)


    string auxN;
    string auxA;
    string auxG;
    int auxE;
    int auxID;

    for (int i = 0; i < listaP->getCantidad() - 1; i++)//1+n(1+...+2)
    {
        for (int j = 0; j < listaP->getCantidad() - 1; j++)//1+n(2+..+2)
        {
            if (tolower(listaP->getpersona(j)->getNombre()[0]) > tolower(listaP->getpersona(j + 1)->getNombre()[0])) {//1

                auxN = listaP->getpersona(j)->getNombre();//2
                auxE = listaP->getpersona(j)->getEdad();//2
                auxA = listaP->getpersona(j)->getApellido();//2
                auxID = listaP->getpersona(j)->getid();//2
                auxG = listaP->getpersona(j)->getGenero();//2

                listaP->getpersona(j)->setNombre(listaP->getpersona(j + 1)->getNombre());//3
                listaP->getpersona(j)->setedad(listaP->getpersona(j + 1)->getEdad());//3
                listaP->getpersona(j)->setApellido(listaP->getpersona(j + 1)->getApellido());//3
                listaP->getpersona(j)->setId(listaP->getpersona(j + 1)->getid());//3
                listaP->getpersona(j)->setgenero(listaP->getpersona(j + 1)->getGenero());//3

                listaP->getpersona(j + 1)->setNombre(auxN);//2
                listaP->getpersona(j + 1)->setedad(auxE);//2
                listaP->getpersona(j + 1)->setApellido(auxA);//2
                listaP->getpersona(j + 1)->setId(auxID);//2
                listaP->getpersona(j + 1)->setgenero(auxG);//2
            }
        }
    }   //1+n(3+n(29))= 29n^2+3n+1
    cout << "Datos de usuarios ordenados por el nombre" << endl;//2
    for (int i = 0; i < listaP->getCantidad(); i++)//1+n(1+...+2)
    {
        cout << listaP->getpersona(i)->getNombre() << " " << listaP->getpersona(i)->getApellido() << endl;//4
        cout << listaP->getpersona(i)->getEdad() << " " << listaP->getpersona(i)->getGenero() << " " << listaP->getpersona(i)->getid() << endl << endl;//6

    }//1+n(13)
    _getch();
}// tiempo detallado = 29n^2 + 15n + 6



void limpiarPantalla() {
    system("cls");
    system("cls");

}

void mostrarMenu() {
    pintarLogo();
    cout << "Ingrese una opcion" << endl;
    cout << "1.- Agregar un usuario" << endl;
    cout << "2.- Agregar una tarea" << endl;
    cout << "3.- Ver lista de tareas" << endl;
    cout << "4.- Mostrar tareas terminadas" << endl;
    cout << "5.-Cambiar estado de una tarea" << endl;
    cout << "6.- Mostrar tareas incompletas" << endl;
    cout << "7.- Mostrar  y Guardar por Nombres (Ordenamiento de seleccion)" << endl;
    cout << "8.- OrdenarDatos (Metodo burbuja)" << endl;
    cout << "9.- Ordenar edades (Ordenamiento de insercion)" << endl;
    cout << "10.- Limpiar consola" << endl;
    cout << "0.- Salir" << endl;
}


void main() {

    ListaPersonas* listaP = new ListaPersonas();
    ListaTareas* listaT = new ListaTareas();
    int opcion;
    while (true)
    {

        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1: agregarPersona(listaP); break;
        case 2: agregarTarea(listaP, listaT); break;
        case 3: mostrarTareas(listaP, listaT); break;
        case 4: mostrarTareasTerminadas(listaT); break;
        case 5: cambiarEstadoTarea(listaT); break;
        case 6: mostrarTareasIncompletas(listaT); break;
        case 7:ordenarNombrePersonas(listaP); break;
        case 8:ordenaroNombres(listaP, listaT); break;
        case 9:OrdInsercion(listaP);
        case 10:limpiarPantalla(); break;
        case 0:return;


        default:
            break;
        }
    }
    delete listaP;
    delete listaT;

    _getch();
}
