/**
 * @file bag.cpp
 * @author DECSAI
 * @note To be implemented by students except function shuffle()
 */
#include <cassert>
#include <random>
#include <algorithm>
#include <string>
#include "bag.h"
#include "language.h"

///@warning Fill missing #include

using namespace std;

/**
 * @brief Randomly reorders a vector of char
 * @param s Vector of char
 * @param n Number of char in the vector
 * @author DECSAI
 */
void shuffleVector(char *s, int n, int id);

/**
 * @brief Removes a position from a vector and compacts the remaining positions, 
 * thus reducing its size
 * @param s Vector of char
 * @param n Number of chars
 * @param p Position to remove
 * @warning TO BE FULLY IMPLEMENTED. 
 * @warning Check parameters const/&/* and their types
 */
void removeVector(char s [], int &n, int p);


// Main methods

Bag::Bag() {
    nletters = 0;
    id = time(NULL);
}

char Bag::get(int p) const{
    return letters[p];
}

void Bag::set(int p, char c){
    letters[p] = c;
}

void Bag::setRandom(int p){
    id = p;
}

void Bag::define(const Language &l){
    string available;
    int contador = 0;
    
    available = l.getLetterSet();
    
    for (int i = 0; i < available.length(); i++){
        for (int j = contador; j < contador + l.getFrequency(available[i]); j++){
            set(j, available[i]);
        } 
        contador += l.getFrequency(available[i]);
    }
    nletters = contador;
    
    shuffleVector(letters, nletters, id);
}

int Bag::size()const {
    return nletters;
}

string Bag::to_string()const{
    string auxi = "", s="A";
    
    for (int i = 0; i < size(); i++){
        s[0] = get(i);
        auxi += s;
    }
    
    return auxi;
}

void Bag::set(string s){
    for (int i = 0; i < s.size(); i++){
        set(i, s[i]);
    }
    
    nletters = s.length();
}

string Bag::extract(int n){
    string devolver = "";
    int tope;
    
    if (nletters < n)
        tope = nletters;
    else if(n <= nletters)
        tope = n;
    
    for (int i = 0; i < tope; i++)
        devolver.push_back(get(i));
        
    for (int i = 0; i < tope; i++)
        removeVector(letters, nletters, 0);
    
    return devolver;
}

///@warning Implement all the methods

// Auxiliary functions 

void shuffleVector(char *s, int n, int id) {
    vector <char> aux(s, s+n);
    unsigned seed = id;
    std::shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));
    for (int i=0; i<n; i++)
        s[i] = aux[i];    
}

void removeVector(char *s, int &n, int p){
    for (int i = p; i < n-1; i++){
        s[i] = s[i+1];
    }
    n--;
}


