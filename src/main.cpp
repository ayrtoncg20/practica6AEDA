#include <iostream>
#include <cstdlib> //rand()
#include <ctime>
#include "../include/DNI.hpp"
#include "../include/nodo.hpp"
#include "../include/arbol.hpp"
#include <ctime>
#include <iomanip>

using namespace std;


int main (void){
    
    ABB_t<dni_t> arbol;
    int opcion;
    int opcion1;
    int opcion2;
    
    do {
        cout << endl;
        cout << "-------------------MENU-----------------" << endl;
        cout << "- INTRODUCE UN 1 PARA EL MODO DEMOSTRACION" << endl;
        cout << "- INTRODUCE UN 2 PARA EL MODO ESTADISTICA" << endl;
        cout << "- INTRODUCE UN 0 PARA SALIR" << endl;
        cout << "- OPCION -> ";
        cin >> opcion;
        cout << endl;
        
        switch(opcion){
            
            case 1: do {
                        cout << endl;
                        cout << "-------------------MENU-----------------" << endl;
                        cout << "- INTRODUCE UN 1 PARA INSERTAR CLAVE" << endl;
                        cout << "- INTRODUCE UN 2 PARA ELIMINAR CLAVE" << endl;
                        cout << "- INTRODUCE UN 3 PARA SALIR" << endl;
                        cout << "- OPCION -> ";
                        cin >> opcion1;
                        cout << endl;
                        
                        switch(opcion1){
                            
                            case 1: {
                                        dni_t D;
                                        int dni;
                                        cout << "INTRODUZCA UN DNI -> ";
                                        cin >> dni;
                                        cout << endl;
                                        D.set_dni(dni);
                                        arbol.insertar(D);
                                        arbol.mostrar();
                                    }
                                    break;
                            case 2: {
                                        dni_t D;
                                        int dni;
                                        cout << "INTRODUZCA EL DNI QUE DESEAR ELIMINAR -> ";
                                        cin >> dni;
                                        cout << endl;
                                        D.set_dni(dni);
                                        // buscar el elemento antes de eliminar, si no esta no se elimina
                                        arbol.eliminar(D);
                                        arbol.mostrar();
                                    }
                                    break;
                			}
                    }while(opcion1 != 3);
                    break;
            case 2: {
                        ABB_t<dni_t> valores_dni;
                        int size_arbol;
                        int numero_de_pruebas;
                        
                        cout << "INTRODUZCA EL TAMAÑO DEL ÁRBOL -> ";
                        cin >> size_arbol;
                        cout << endl;
                        
                        cout << "INTRODUZCA EL NUMERO DE PRUEBAS A REALIZAR -> ";
                        cin >> numero_de_pruebas;
                        
                        dni_t* banco_dni = new dni_t[2*size_arbol]; // VECTOR -> BANCO DE PRUEBAS DE LOS DNI 
                        
                        dni_t D; // crea las matriculas aleatoriamente
                        dni_t* aux;
                        aux = D.crear_dni_aleatorios(2*size_arbol);
                        
                        // insertar valores generados en el banco de pruebas
                        for(int i = 0; i < 2*size_arbol; i++){
                            banco_dni[i] = aux[i]; 
                        }
                        // insertar elementos en el árbol
                        for(int i = 0; i < size_arbol; i++){
                            valores_dni.insertar(banco_dni[i]);
                        }
                        
                       
                      //----------------------------------- BUSQUEDA ---------------------------------- //
                        valores_dni.inicializar_contadores();
                                    
                        for(int i = 0; i < numero_de_pruebas; i++){
                            int pos1 = rand()% size_arbol;
                            D.reiniciar_contador();
                                            
                            // busqueda uno de los elementos de los primos N elementos del banco de pruebas
                            valores_dni.buscar(banco_dni[pos1]);
                                    
                            if (D.contador_ > valores_dni.cont_max){
                                valores_dni.cont_max = D.contador_;   
                            } 
                        	if (D.contador_ < valores_dni.cont_min){
                        		valores_dni.cont_min = D.contador_;          
                        	}
                        	valores_dni.suma = valores_dni.suma + D.contador_;
                        }
             
                        float media1 =  valores_dni.resultado(numero_de_pruebas);   
                        cout << setw(33) << "NUMERO DE COMPARACIONES" << endl;
                        cout << setw(16) << "NUMERO" << setw(10) << "PRUEBAS" << setw(10) << "MINIMO" << setw(10) << "MEDIA" << setw(10) << "MAXIMO" << endl;
                        cout << "BUSQUEDA" << setw(6) << size_arbol << setw(9) << numero_de_pruebas << setw(10) << valores_dni.cont_min << setw(11) << media1 << setw(10) << valores_dni.cont_max << endl;
                    
                        // Podar el árbol
                        valores_dni.podar_arbol();
                    
            	        //-----------------------------------INSERCIÓN----------------------------------------//  
                    
                        // insertar N primeros elementos en el árbol
                        for(int i = size_arbol; i < 2*size_arbol ; i++){
                                    valores_dni.insertar(banco_dni[i]);
                        }
                        //valores_.mostrar();
                    
                        valores_dni.inicializar_contadores();
                        
                        for(int i = 0; i < numero_de_pruebas; i++){
                             
                            int pos = (rand() % size_arbol) + size_arbol;
                            D.reiniciar_contador();
                                
                            // insertar(buscar) N ultimos elementos en el árbol
                            valores_dni.buscar(banco_dni[i]);
                                
                            if (D.contador_ > valores_dni.cont_max){
                                valores_dni.cont_max = D.contador_; 
                            } 
            		        if (D.contador_ < valores_dni.cont_min){
            		            valores_dni.cont_min = D.contador_;  
            		        } 
                        
                            valores_dni.suma = valores_dni.suma + D.contador_;
                                
                         }
                         
                        float media2 =  valores_dni.resultado(numero_de_pruebas);   
                        cout << "INSERCION" << setw(5) << size_arbol << setw(9) << numero_de_pruebas << setw(10) << valores_dni.cont_min << setw(11) << media2 << setw(10) << valores_dni.cont_max << endl;
                
                    }
                    break;
			}
    }while(opcion != 0);
    
}