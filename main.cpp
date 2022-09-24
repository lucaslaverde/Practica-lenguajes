
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
 
using namespace std;
 
typedef struct nodo
{
    int info;
    struct nodo *sig;
} nodoL;

// Alias para lista
typedef nodoL * lista;

void crearUsuario();

void buscar();

void mostrar();

void borrar();


int main () {
    
   //Se declara y asigna una la variable paraa controlar la opción selecionada en el menú.
    int op=-1;
    //Se declara una lista.
    lista milista=NULL;
    
    //Mientras op se distinto de 0 (Cuando es op=0 finaliza el programa.
    while(op)
    {
        
        system("cls"); //Borrar la pantalla.
        //Mostrar en pantalla las opciones del menú.
        cout << "\t\t<-----BIENVENIDO----->" << endl << endl << "\tSeleccione una opcion" << endl << endl <<"\t-1. Agregar un usuario"<<endl <<"\t-2. buscar en la lista"<<endl <<"\t-3. Borrar un elemento"<<endl <<"\t-4. mostrar lista" << endl <<"\t-0. Salir" << endl;
        cin >> op; //Captura el numero opción seleccionada.
        switch(op) //Ir a la opción indicada por el usuario.
        {
        //Ingresar un valor al comienzo de la lista.
        case 1:
        {  
             
             crearUsuario();

            system("pause"); //Esperar que el usuario presione una tecla.
            break;
        }
        //Mostrar la lista por pantalla.
        case 2:
        {
            system("cls");//Borrar la pantalla.
            //Mostrar en pantalla un titulo.
            cout << "que usuario desea buscar: " << endl;

            buscar();
            
            


            system("pause");
            break;
        }
        //Eliminar un número de la lista.
        case 3:
        {
           
            system("cls");//Borrar la pantalla.

            borrar();
           
            system("pause"); //Esperar que el usuario presione una tecla.
            break;
        }
        case 4:
        {
            system("cls");//Borrar la pantalla.
            //Mostrar en pantalla un titulo.
            cout << "Los usuarios cargados en la lista:" << endl << endl;
            
            mostrar();


            system("pause");
            break;
        }
        
        }
    }

    
}

void crearUsuario(){
     ofstream archivo;
    string nombre;
    
    archivo.open("usuarios.txt", ios::out);
    
    if(archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    
    cout << "Escribe usuario y pwd: "<<endl;
    cout << "asi:  usuario:pwd "<<endl;
    cin >> nombre;
   
    while(nombre.compare("salir") != 0) {
        archivo << nombre << endl;
        cout << "Escribe usuario y pwd: "<<endl;
        cout << "si no desea mas escribe ---> salir "<<endl;
        cin >> nombre;
        

        
    }
    
    archivo.close();
    
    
    
}

void buscar(){

    ifstream archivo;
    string buscar, texto;
    int contador = 0;
 
    archivo.open("usuarios.txt", ios::in); //Abrimos el archivo en modo lectura
 
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
 
    cout << "Ingrese lo que desea buscar en el archivo: "<<endl;
    cin >> buscar;
 
    while (!archivo.eof()) //Mientras no sea el final del archivo
    {
        getline(archivo, texto); //Obtenemos una línea del archivo
 
        if (texto.find(buscar) != string::npos) //Si encontramos la palabra
        {
            cout << "bienvenido " << buscar << endl;
    
        }
        
 
        contador++;
    }
 
    archivo.close(); //Cerramos el archivo
 


}



void mostrar(){
    ifstream archivo;
    string texto;

    archivo.open("usuarios.txt",ios::in);//archivo abierto en modo lectura

    while(!archivo.eof()){//mientras no sea el final del archivo
    getline(archivo,texto);
    cout<<texto<<endl;

}

archivo.close();//cerramos el archivo

}


    
void borrar()
 {

    {
    ifstream archivoIn("usuarios.txt");
    ofstream archivoOut("usuarios.txt");
    string palabra;
    vector<string> lista;
    while (archivoIn >> palabra)
    {
        lista.push_back(palabra);
    }
    bool encontrado = false;
    string palabraBorrar;
    cout << "Introduce la palabra que deseas borrar: "<<endl;
    cin >> palabraBorrar;
    for (int i = 0; i < lista.size(); i++)
    {
        if (lista[i] == palabraBorrar)
        {
            encontrado = true;
            lista.erase(lista.begin()+i);
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Palabra no encontrada";
    }
    for (int i = 0; i < lista.size(); i++)
    {
        archivoOut << lista[i] << " ";
    }

}
   
}
  




