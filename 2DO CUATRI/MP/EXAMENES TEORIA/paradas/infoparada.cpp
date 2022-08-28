
#include "infoparada.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
friend istream& operator>>(istream& flujo, InfoParada &parada){
    string letra;
    
    flujo >> parada.indice_parada;
  
    flujo >> letra;
    
    if (letra == "S"){
        parada.activa = true;
    }
    
    if (letra == "N"){
        parada.activa == false;
    }
    
    return flujo;
}
