#pragma once
#include <iostream>
#include "../include/DNI.hpp"
#include "../include/colision.hpp"

using namespace std;

template <class dni>
class nodoBB_t{
    
    public:
    
        nodoBB_t<dni>* nodo_izquierdo_; // nodo izquierdo
        nodoBB_t<dni>* nodo_derecho_; //nodo derecho
        colision_t colision_;
        dni dni_; // valor del dni
        int nivel;
    
        nodoBB_t();
        ~nodoBB_t();
        nodoBB_t(dni_t dato, nodoBB_t<dni>* izquierdo = NULL, nodoBB_t<dni>* derecho = NULL):
            dni_(dato),
            nodo_derecho_(derecho),
            nodo_izquierdo_(izquierdo),
            nivel(0)
        {}
    
        void set_colision(nodoBB_t<dni>*& colision){
            
            colision_ = colision;
            
        }
        
        colision_t sumar_colision(){
            
            colision_.suma_colision();
            
        }
        void set_nodo_izquierdo(nodoBB_t<dni>*& izquierdo){ 
            
            nodo_izquierdo_ = izquierdo; 
        }
        
        void set_nodo_derecho(nodoBB_t<dni>*& derecho){ 
            
            nodo_derecho_ = derecho; 
        }
        
        nodoBB_t<dni>*& get_nodo_izquierdo() {
            
            return nodo_izquierdo_;
        }
        
        nodoBB_t<dni>*& get_nodo_derecho() {
            
            return nodo_derecho_;
        }
      
        dni& get_nodo_valor() { 
            
            return dni_; 
        } 
        void set_nodo_valor(dni dni1) { 
            
            dni_ = dni1; 
        }
            
        int get_nivel(){ 
            
            return nivel;
            
        }
        void set_nivel(int nivel_){ 
            
            nivel = nivel_;
            
        }
        

};
    template <class dni>
    nodoBB_t<dni>::nodoBB_t():
        nodo_izquierdo_(NULL),
        nodo_derecho_(NULL),
        dni_()
    {}

    template <class dni>
    nodoBB_t<dni>::~nodoBB_t(){
        delete nodo_izquierdo_;
        delete nodo_derecho_;
        nodo_izquierdo_ = NULL;
        nodo_derecho_ = NULL;
    }
