/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tiles.h"
#include <cassert>

using namespace std;

// Private methods

void Tiles::allocate(int r, int c) {
    deallocate();
    
    rows = r;
    columns = c;
    
    cell = new char*[rows];
    cell[0] = new char[rows * columns];
    for (int i = 1; i < rows; ++i)
        cell[i] = cell[i - 1] + columns;

    
    
    for (int i = 0; i < r; i++ ){
        for (int j = 0; j < c; j++)
           set(i,j,EMPTY);
    }
}

void Tiles::deallocate() {
    if (cell != nullptr) {
        delete[] cell[0];
        delete[] cell;
        columns = 0;
        rows = 0;
        cell = nullptr;
    }
}

void Tiles::copy(const Tiles& t) {
    allocate(t.getHeight(), t.getWidth());
    
    for(int i = 0; i < getHeight(); i++){
        for (int j = 0; j < getWidth(); j++){
            set(i,j,t.get(i,j));
        }  
    }
}

// Public methods

Tiles::Tiles() {
    cell = nullptr;
    rows = 0;
    columns = 0;
}

Tiles::Tiles(int r, int c) {
    cell = nullptr;
    allocate(r, c);
}

Tiles::Tiles(const Tiles& orig) {
    cell = nullptr;
    copy(orig);
}

Tiles::~Tiles() {
    deallocate();
}

void Tiles::setSize(int r, int c) {
    deallocate();
    allocate(r, c);
}

Tiles& Tiles::operator=(const Tiles& orig) {
    if (this != &orig) {
        copy(orig);
    }

    return *this;
}

int Tiles::getWidth() const {
    return columns;
}

int Tiles::getHeight() const {
    return rows;
}

char Tiles::get(int r, int c) const {
    // Tenemos en cuenta que estamos contando
    // nuestra matriz desde la posicion 1 1

    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());

    return cell[r][c];
}

void Tiles::set(int r, int c, char l) {
    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());

    cell[r][c] = l;
}

void Tiles::add(const Move& m) {
    if(m.isHorizontal()){
        for(int i = 0; i<m.getLetters().size(); i++){
            if(m.getRow() >= 1 && m.getRow() <= getHeight())
                if(m.getCol()+i >= 1 && m.getCol()+i <= getWidth())
                    set(m.getRow()-1, m.getCol()+i-1, m.getLetters()[i]);
        }
    }
    if(!m.isHorizontal()){
        for(int i = 0; i<m.getLetters().size(); i++){
            if(m.getRow()+i >= 1 && m.getRow()+i <= getHeight())
                if(m.getCol() >= 1 && m.getCol() <= getWidth())
                    set(m.getRow()+i-1, m.getCol()-1, m.getLetters()[i]);
        }
    }
}

void Tiles::print(std::ostream & os) const{
    os << getHeight() << " " << getWidth() << endl;
   
    for (int i = 0; i < getHeight(); i++){
        for (int j = 0; j < getWidth(); j++){
            os << get(i,j) << " ";
        }
        
        os << endl; 
    }
    
    os << endl;
}

bool Tiles::read(std::istream& is){
    char caracter;
    int r,c;
    
    is >> r >> c;
    
    if (is.eof()||!is)
        return false;
    
    setSize(r,c);
    
    for (int i = 0; i < getHeight(); i++){
        for (int j = 0; j < getWidth(); j++){
            is >> caracter;
         
            if (is.eof())
                return false;
            
            set(i,j,caracter);
        }
    }
    
    return true;
}

std::istream& operator>>(std::istream& is, Tiles &t){
    t.read(is);
    return is;
}