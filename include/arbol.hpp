#pragma once
#include <iostream>
#include <cmath>
#include <queue>
#include "../include/nodo.hpp"
#include "../include/DNI.hpp"


template <class dni>
class ABB_t{
    
  
    private:
    
        nodoBB_t<dni>* raiz_;
    
    public:
    
        // PARTE ESTADISTICA //
        int cont_max;
        int cont_min;
        int suma;
        float media;
  
  
        // OPERACIONES INICIALES
        ABB_t();
        ~ABB_t();
    
        void podar(nodoBB_t<dni>*& nodo);
        void mostrar();
    
        bool vacio(nodoBB_t<dni>* nodo){
            
            return nodo == NULL;
            
        }
        bool hoja(nodoBB_t<dni>* nodo){ 
            
            return !nodo->get_nodo_izquierdo() && !nodo->get_nodo_derecho();
            
        }
        
    
        // OPERACIONES //
    
        void insertar_rama(nodoBB_t<dni>*& nodo, dni_t x);
        void eliminar_rama(nodoBB_t<dni>*& nodo, dni_t x);
        void sustituye(nodoBB_t<dni>*& eliminado, nodoBB_t<dni>*& sust);
        nodoBB_t<dni>* buscar_rama(nodoBB_t<dni>* nodo, dni_t x);
    
        void insertar(dni_t x){ 
            
            insertar_rama(raiz_,x);
            
        }
        
        void eliminar(dni_t x){ 
            
            eliminar_rama(raiz_,x);
            
        }
        
        nodoBB_t<dni>* buscar(dni_t x){ 
            
            return buscar_rama(raiz_,x);
            
        }
  
        // PARTE ESTADISTICA //
        void inicializar_contadores();
        float resultado(int num_prueba);
        
        void podar_arbol(){
            
            podar(raiz_);
            
        }
    
    
};

    template<class dni>
    ABB_t<dni>::ABB_t():
        raiz_(NULL)
    {}

    template<class dni>
    ABB_t<dni>::~ABB_t(){
        podar(raiz_);
    }

    template<class dni>
    void ABB_t<dni>::podar(nodoBB_t<dni>* &nodo){
    
        if(nodo == NULL){
          
          return;
          
        } 
    
        podar(nodo -> get_nodo_izquierdo());
        podar(nodo -> get_nodo_derecho());
        delete nodo;
        nodo = NULL;
}

    template <class dni>
    void ABB_t<dni>::inicializar_contadores(){
        
        cont_max = 0;
        cont_min = 9999;
        suma = 0;
        media = 0;
        
    }

    template <class dni>
    float ABB_t<dni>::resultado(int num_prueba){
        
        media = suma/num_prueba;
        return media;
        
    }
    
    template<class dni>
    void ABB_t<dni>::insertar_rama(nodoBB_t<dni>*& nodo, dni_t x){
        
        if(nodo == NULL){
            
            nodo = new nodoBB_t<dni>(x, NULL, NULL);
            
        } else if(x < nodo -> get_nodo_valor()){
            
            insertar_rama(nodo -> get_nodo_izquierdo(), x);
            
        } else if (x > nodo -> get_nodo_valor()){
            
            insertar_rama( nodo -> get_nodo_derecho(), x);
        
        } else if (x == nodo -> get_nodo_valor()){
            
            
            nodo -> sumar_colision();
            
        }
    
    }

    template<class dni>
    void ABB_t<dni>::eliminar_rama(nodoBB_t<dni>*& nodo, dni_t x){
    
        if (nodo == NULL){
           
           return;
           
        }  
    
    if(x < nodo -> get_nodo_valor()){
        
        eliminar_rama(nodo -> get_nodo_izquierdo(), x);
        
    }else if(x > nodo -> get_nodo_valor()){
        
        eliminar_rama(nodo -> get_nodo_derecho(), x);
        
    }else{
        
        nodoBB_t<dni>* eliminado = nodo;
        
        if(nodo -> get_nodo_derecho() == NULL){
            
            nodo = nodo -> get_nodo_izquierdo();
            
        }else if(nodo -> get_nodo_izquierdo() == NULL){
           
            nodo = nodo -> get_nodo_derecho();
            
        }else{
            
            sustituye(eliminado, nodo -> get_nodo_izquierdo());
        }
        delete eliminado;
       
    }
    
}
    
    template<class dni>
    void ABB_t<dni>::sustituye(nodoBB_t<dni>*& eliminado, nodoBB_t<dni>*& sust)
    {
       if(sust -> get_nodo_derecho() != NULL){
           
           // cout << "SUSTITUIR 1 --> " << sust -> get_nodo_valor() << endl;
           sustituye(eliminado, sust -> get_nodo_derecho());
          
       } else{
            //cout << "SUSTITUIR 2 --> " << sust -> get_nodo_valor() << endl;
           eliminado -> get_nodo_valor() = sust -> get_nodo_valor();
         
           eliminado = sust;
           sust = sust -> get_nodo_izquierdo();
       } 
    }

    template<class dni>
    nodoBB_t<dni>* ABB_t<dni>::buscar_rama(nodoBB_t<dni>* nodo, dni_t x){
        // Si x es menor o igual que la raiz, la búsqueda prosigue de manera
        // recursiva por el subárbol izquierdo.
        
        // Si x es mayor que la raiz, la búsqueda prosigue de manera
        // recursiva por el subárbol derecho.
        
        // La búsqueda se termina cuando se encuentra el elemento o
        // cuando ya no quedan más nodos por visitar.
        
        if( nodo == NULL ){
            return NULL;
        }
        
        if(x == nodo -> get_nodo_valor()){
            return nodo;  
        } 
        
        if(x < nodo -> get_nodo_valor()){
            return buscar_rama(nodo -> get_nodo_izquierdo(), x);
        }
        
        return buscar_rama(nodo -> get_nodo_derecho(), x);
    }

    template<class dni>
    void ABB_t<dni>::mostrar(){
        
        queue<nodoBB_t<dni>*> cola;
        nodoBB_t<dni>* nodo_cola;
        nodoBB_t<dni>* aux = new nodoBB_t<dni>();
    
        int i = 0;
        int cont = 0;
        int meter_cola = 0;
        
        nodo_cola = raiz_;
        cola.push(nodo_cola);
        dni_t aux2;
        
        cout << "NIVEL [0]:" << endl;
        while(!cola.empty()){
            
            // Va mostrando los niveles
            if(cont == pow(2,i)){ // 2 elevado a i
                cout << endl;
                i++;
                cont = 0;
                cout << "NIVEL [" << i << "]:" << endl;
            }
            
            nodo_cola = cola.front();
            cola.pop();
            cont ++;
            if(nodo_cola != NULL){
                aux -> set_nodo_valor(nodo_cola -> get_nodo_valor());
                aux2 = aux -> get_nodo_valor();
                cout << "[" << aux2.get_dni() << "]";
            
            cola.push(nodo_cola -> get_nodo_izquierdo());
            cola.push(nodo_cola -> get_nodo_derecho());
            
            }else{
                cout << "[.]";
            }
            
        }
      cout << endl;
        
        
        
    }






