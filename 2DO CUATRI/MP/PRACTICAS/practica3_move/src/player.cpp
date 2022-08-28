/**
 * @file player.cpp
 * @author DECSAI
 * @note To be implemented by students
 */
#include <iostream>
#include <cstring>
#include "player.h"
#include <string>
///@warning complete missing #includes
/// See http://www.cplusplus.com/reference/cstring/ for details about cstrings
using namespace std;



/**
 * @brief Removes a position from a cstring
 * @param cstr The cstring
 * @param pos The position
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void removeCString(char *cstr, int pos);

/**
 * @brief Sort a cstring from A to Z
 * @param cstr The cstring
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void sortCString(char *cstr);

Player::Player(){
    clear();
}

int Player::size() const{
    return strlen(letters);
}

string Player::to_string() const{
    string dev = letters;
    return dev; 
}

void Player::clear(){
    letters[0] = '\0';
}

bool Player::isValid(const std::string s)const{
    char s2[MAXPLAYER + 1];
    bool auxiliary_vector[MAXPLAYER] = {false};
    bool dev = true, exists;
    
    if(s.length()>MAXPLAYER){
        return false;
    }
    strcpy(s2, s.c_str());
    
    if(strlen(s2) <= this->size()){
        for(int i = 0; i < strlen(s2); i++){
            exists = false;
            
            for (int j = 0; j < this->size() && !exists; j++){
                if(auxiliary_vector[j] != true && letters[j] == s2[i]){
                    exists = true;
                    auxiliary_vector[j] = true;
                }
            }
            
            if (!exists)
                dev = false;
        }
    }
    
    return dev;
    
}

bool Player::extract(const std::string s){
    char s2[MAXPLAYER + 1];
    bool valid = false;
    bool one_time = true;
    if(isValid(s)){
        strcpy(s2, s.c_str());
        
        for (int i = 0; i < strlen(s2); i++){
            for(int j= 0; j < this->size() && one_time; j++){
                if(s2[i] == letters[j]){
                    removeCString(letters, j);
                    one_time = false;
                }
            
            }
        one_time = true;
        }
    valid = true;
    }
    sortCString(letters);
    return valid;
    
}

void Player::add(std::string frombag){
    if((this->size() + strlen(frombag.c_str())) <= MAXPLAYER){
        strcat(letters, frombag.c_str());
        sortCString(letters);
    }
    
       
}
void removeCString(char *cstr, int pos){
    for (int i = pos; i < strlen(cstr); i++){
        cstr[i] = cstr[i+1];
    }
}

void sortCString(char *cstr){
    char minimo, change;
    int posicion_minimo;
    
    for (int izda = 0 ; izda < strlen(cstr); izda++){
        minimo = cstr[izda];
        posicion_minimo = izda;
        
        for (int i = izda + 1; i < strlen(cstr); i++){
            if(cstr[i] < minimo){
                minimo = cstr[i];
                posicion_minimo = i;
            }
        }
        
        change = cstr[izda];
        cstr[izda] = cstr[posicion_minimo];
        cstr[posicion_minimo] = change;
        
        
    }
}

