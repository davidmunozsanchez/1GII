/**
 * @file movelist.cpp
 * @author DECSAI
 * @note To be implemented by students
 * @warning Complete the code
 *  */
#include <iostream>
#include <fstream>
#include <cassert>

#include "movelist.h"

using namespace std;

Movelist::Movelist() {
    nMove = 0;
    moves = 0;
}

Movelist::Movelist(const Movelist& orig) {
    moves = 0;
    nMove = 0;
    copy(orig);
}

Movelist::Movelist(int nmov) {
    moves = 0;
    allocate(nmov);
}

Movelist::~Movelist() {
    deallocate();
}

Movelist& Movelist::operator =(const Movelist& orig) {
    if (this != &orig) {
        copy(orig);
    }

    return *this;
}

Move Movelist::get(int p) const {
    assert(0 <= p && p < size());
    return moves[p];
}

void Movelist::set(int p, Move m) {
    assert(0 <= p && p < size());
    moves[p] = m;
}

int Movelist::find(Move mov) const {
    int position = -1;

    for (int i = 0; i < size(); i++) {
        if (compare(get(i), mov) && position == -1)
            position = i;
    }

    return position;
}

void Movelist::add(Move mov) {
    redimension(1);
    set(size() - 1, mov);

}

void Movelist::remove(Move mov) {
    int position = find(mov);
    assert(position != -1);

    int tope = size() - 1;

    for (int i = position; i < tope; i++)
        set(i,get(i+1));

    redimension(-1);

}

void Movelist::remove(int p) {
    assert(0 <= p && p < size());
    remove(get(p));
}

void Movelist::zip(Language l) {
    for (int i = 0; i < size();) {
        string word = get(i).getLetters();
        if (word.length() < 2 || (!l.query(word))) {
            remove(get(i));
        }
        else
            i++;
    }
}

void Movelist::clear() {
    deallocate();
}

int Movelist::getScore() const {
    int whole_score = 0;
    bool do_it = true;
    int value;

    for (int i = 0; i < size() && do_it; i++) {
        value = get(i).getScore();
        if (value == -1) {
            do_it = false;
            whole_score = -1;
        }

        else
            whole_score += value;
    }

    return whole_score;
}

bool Movelist::print(std::ostream &os, bool scores) const {
    bool res = true;
    for (int i = 0; i < size() && res; i++) {
        get(i).print(os);
        if (scores)
            os << " (" << get(i).getScore() << ") - ";
        else
            os << " - ";
        if (os.bad())
            res = false;
    }
    return res;
}

bool Movelist::read(std::istream &is) {
    char orientation;
    int row2, column2;
    string letters2;
    Move move;
    bool read=true;
    
    do{
        is >> orientation >> row2 >> column2 >> letters2;
        if ((is.eof()) || (!is))
            read = false;
        if (letters2 != "@" && read == true){
            move.set(row2, column2, orientation, letters2);
            add(move);
        }
    }while (letters2 != "@" && read == true);
    
    return read;
}

void Movelist::allocate(int n) {
    if (moves != 0)
        deallocate();
    moves = new Move[n];
    nMove = n;
}

void Movelist::deallocate() {
    if (moves != 0) {
        delete [] moves;
        moves = 0;
        nMove = 0;
    }
    



}

void Movelist::copy(const Movelist& ml) {
    if (size() != ml.size()) {
        deallocate();
        allocate(ml.size());
        nMove = ml.size();
    }

    for (int i = 0; i < nMove; i++)
        set(i, ml.get(i));
}

void Movelist::redimension(int increment) {
    assert(size() + increment >= 0);
    if(size() + increment > 0){
        int new_size = size() + increment;
        Move *moves_increment = new Move[new_size];

        for (int i = 0; (i < size()) && (i < size() + increment); i++)
            moves_increment[i] = moves[i];

        deallocate();
        moves = moves_increment;
        this->nMove = new_size;
    }
    
    else if(size() + increment == 0){
        deallocate();
    }
    
    
}

bool compare(Move first, Move second) {
    bool comparison = true;

    bool evaluate_string = (first.getCol() == first.getCol()) &&
            (first.getRow() == second.getRow()) &&
            (first.getScore() == second.getScore())&&
            (first.isHorizontal() == second.isHorizontal())&&
            (first.getLetters() == second.getLetters());

    if (!evaluate_string)
        comparison = false;

    return comparison;
}

std::istream & operator>>(std::istream & is, Movelist & i){
    i.read(is);
    return is;
}
std::ostream & operator<<(std::ostream & os, const Movelist & i){
    i.print(os);
    return os;
}