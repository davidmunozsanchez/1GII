/**
 * @file move.cpp
 * @author DECSAI
 * @note To be implemented by students
 */

#include <string>
#include "move.h"


using namespace std;

Move::Move(){
    set(0,0,'v',"");
    setScore(0);
}

void Move::set(int r, int c, char h, const std::string& l){
    h = toupper(h);
    if (h=='H' || h=='V'){
        row = r;
        column = c;
        ishorizontal = (h== 'H');
        letters = normalizeWord(l);
    }
}

void Move::setRow(int r){
    row = r;
}

void Move::setCol(int c){
    column = c;
}

void Move::setHorizontal(char h){
    h = toupper(h);
    ishorizontal = (h =='H');
}

void Move::setLetters(const std::string& l){
    letters = normalizeWord(l);
}

void Move::setScore(int s){
    score = s;
}

int Move::getScore() const{
    return score;
}

int Move::getRow() const{
    return row;
}

int Move::getCol() const{
    return column;
}

bool Move::isHorizontal() const{
    return ishorizontal;
}

string Move::getLetters() const{
    return letters;
}

void Move::print(std::ostream& os)const{
    char orientation;
    
    if (isHorizontal())
        orientation = 'H';
    else 
        orientation = 'V';
    
    os << orientation << " " << getRow() << " " << getCol() << " " << toUTF(getLetters());
}

void Move::read(std::istream& is){
    char orientation;
    int row2, column2;
    string letters2;
    
    is >> orientation >> row2 >> column2 >> letters2;
    
    set(row2, column2, orientation, letters2);
}

int Move::findScore(const Language& l){
    int devolver = -1;
    char auxi;
    
    if(l.query(getLetters())){
        devolver = 0;
        for (int i = 0; i < getLetters().length(); i++){
            auxi = getLetters()[i];
            devolver += l.getScore(auxi);
        }
    }
    
    return devolver;
        
}