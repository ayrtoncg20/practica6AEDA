#include "../include/colision.hpp"


colision_t::colision_t():

    colision_(0)
    {}
    
colision_t::~colision_t(){
    
}

void colision_t::suma_colision(){
    
    colision_ ++;
    cout << "COLISION -> " << colision_ << endl;
}