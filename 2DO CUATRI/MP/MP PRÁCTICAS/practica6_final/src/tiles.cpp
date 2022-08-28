/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tiles.h"
#include <cassert>
#include <list>

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



    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            set(i, j, EMPTY);
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

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            set(i, j, t.get(i, j));
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
    int contador1 = 0;
    int contador2 = 0;
    int contador_char1 = 0;
    int contador_char2 = 0;
    bool continue1 = true;
    bool continue2 = true;

    // Revisar

    if (m.isHorizontal()) {
        while (continue1 && contador_char1 < m.getLetters().size()) {
            if (m.getRow() >= 1 && m.getRow() <= getHeight())
                if (m.getCol() + contador1 >= 1 && m.getCol() + contador1 <= getWidth()) {

                    while (get(m.getRow() - 1, m.getCol() + contador1 - 1) != EMPTY)
                        contador1 += 1;

                    set(m.getRow() - 1, m.getCol() + contador1 - 1, m.getLetters()[contador_char1]);
                    contador1 += 1;
                    contador_char1 += 1;
                } else {
                    continue1 = false;
                }

        }
    }
    if (!m.isHorizontal()) {
        while (continue2 && contador_char2 < m.getLetters().size()) {
            if (m.getRow() + contador2 >= 1 && m.getRow() + contador2 <= getHeight())
                if (m.getCol() >= 1 && m.getCol() <= getWidth()) {

                    while (get(m.getRow() + contador2 - 1, m.getCol() - 1) != EMPTY)
                        contador2 += 1;

                    set(m.getRow() + contador2 - 1, m.getCol() - 1, m.getLetters()[contador_char2]);
                    contador2 += 1;
                    contador_char2 += 1;
                } else {
                    continue2 = false;
                }

        }
    }
}

void Tiles::print(std::ostream & os) const {
    os << getHeight() << " " << getWidth() << endl;

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            os << toUTF(get(i, j)) << " ";
        }

        os << endl;
    }

    os << endl;
}

bool Tiles::read(std::istream& is) {
    char caracter;
    int r, c;

    is >> r >> c;

    if (is.eof() || !is)
        return false;

    setSize(r, c);

    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++) {
            is >> caracter;

            if (is.eof())
                return false;

            set(i, j, caracter);
        }
    }

    return true;
}

std::istream& operator>>(std::istream& is, Tiles &t) {
    t.read(is);
    return is;
}

Move Tiles::findMaxWord(int r, int c, bool hrz) const {
    assert(r >= 0 && r < getHeight());
    assert(c >= 0 && c < getWidth());

    int start = 0;
    int end = 0;
    string word;
    bool vacio = false;

    Move move;

    if (hrz == true) {
        end = getWidth();

        // Comprobamos hacia la izquierda

        for (int i = c; i >= 0 && vacio == false; i--) {
            if (get(r, i) == EMPTY) {
                start = i + 1;
                vacio = true;
                ;
            }
        }

        vacio = false;
        // Comprobamos hacia la derecha
        for (int i = c; i < getWidth() && vacio == false; i++) {
            if (get(r, i) == EMPTY) {
                end = i;
                vacio = true;

            }
        }

        // Rellenamos el string
        for (int i = start; i < end; i++) {
            word.push_back(get(r, i));
        }

        move.set(r + 1, start + 1, 'h', word);
    } else {
        end = getHeight();

        // Comprobamos hacia arriba
        for (int i = r; i >= 0 && vacio == false; i--) {
            if (get(i, c) == EMPTY) {
                start = i + 1;
                vacio = true;
            }
        }
        vacio = false;

        // Comprobamos hacia abajo
        for (int i = r; i < getHeight() && vacio == false; i++) {
            if (get(i, c) == EMPTY) {
                end = i;
                vacio = true;
            }
        }

        //Rellenamos el string
        for (int i = start; i < end; i++) {
            word.push_back(get(i, c));
        }

        move.set(start + 1, c + 1, 'v', word);
    }

    return move;
}

Movelist Tiles::findCrosswords(const Move& m, const Language& l) const {
    Movelist lista;
    Tiles copia(*this);
    Move move = m;
    string word;
    Move aniade;
    Move auxiliar;
    bool not_cross = true;
    int col = 0;
    int row = 0;
    int contador = 0;
    bool overflow = false;
    int score;
    int comparador = 0;
    bool aniadida = false;

    // Voy a comentar brevemente el caso en el que el move sea horizontal, el vertical es analogo

    // Comprobamos si las coordenadas que nos introducen encajan en la matriz
    if (move.getRow() > getWidth() || move.getCol() > getHeight() || move.getRow() < 1 || move.getCol() < 1) {
        move.setScore(BOARD_OVERFLOW);
        lista.add(move);
        return lista;

        // Si la posición de comienzo no esta vacia, devuelve un error
    } else if (copia.get(m.getRow() - 1, m.getCol() - 1) != EMPTY) {
        move.setScore(NOT_FREE);
        lista.add(move);
        return lista;

    } else {
        // Si es horizontal
        if (move.isHorizontal()) {

            /* Con este bucle vamos haciendo el set letra por letra y saltando posiciones ocupadas,
               ademas tratamos con distintos contadores y booleanos que nos serviran para el board overflow
               y missing crosswords
             */
            col = move.getCol() - 1;
            while (contador < move.getLetters().size() && !overflow) {
                overflow = (col >= getWidth());
                while (!overflow && copia.get(move.getRow() - 1, col) != EMPTY) {
                    col += 1;
                    comparador += 1;
                    overflow = (col >= getWidth());
                }

                if (!overflow) {
                    copia.set(move.getRow() - 1, col, move.getLetters()[contador]);

                    //Tiradas en direccion contraria a la principal
                    aniade = copia.findMaxWord(move.getRow() - 1, col, false);

                    if (aniade.getLetters().size() > 1) {
                        if (l.query(aniade.getLetters())) {
                            score = aniade.findScore(l);
                            aniade.setScore(score);
                            lista.add(aniade);
                        } else {
                            aniade.setScore(NONEXISTENT_WORD);
                            lista.add(aniade);

                        }
                        aniadida = true;
                    }

                    contador += 1;
                    col += 1;
                    comparador += 1;
                }

            }
            //Tirada principal
            auxiliar = copia.findMaxWord(move.getRow() - 1, move.getCol() - 1, move.isHorizontal());

            // Si tenemos overflow, vaciamos la lista y devolvemos auxiliar con la puntuacion correspondiente
            if (overflow) {
                lista.clear();
                auxiliar.setScore(BOARD_OVERFLOW);
                lista.add(auxiliar);
                return lista;
            }

            // Si auxiliar tiene tamanio mayor a 1, vemos si existe o no
            if (auxiliar.getLetters().size() > 1) {
                if (l.query(auxiliar.getLetters())) {

                    score = auxiliar.findScore(l);
                    auxiliar.setScore(score);
                    lista.add(auxiliar);

                } else {
                    auxiliar.setScore(NONEXISTENT_WORD);
                    lista.add(auxiliar);

                    return lista;
                }
            }

            // Condicion para ver si hay un missing crosswords:
            // el contador tiene que ser igual al tamaño de la palabra del move
            // la lista puede tener tamanio menor o igual a 1
            // el tamanio de las letras de la tirada principal tiene que coincidir con el tamanio de las letras del move
            // la matriz no puede estar vacia (consideramos primera tirada)
            // y no se han añadido posibles palabras cruzadas (por no tener dimension mayor que 1)
            if (comparador == move.getLetters().size() && lista.size() <= 1 && auxiliar.getLetters().size() == move.getLetters().size() && clear() == false && !aniadida) {
                lista.clear();
                auxiliar.setScore(MISSING_CROSSWORDS);
                lista.add(auxiliar);
                return lista;

            }

            // Condicion para despreciar si el usuario introduce una sola letra en la primera tirada
            if (clear()) {
                if (auxiliar.getLetters().size() == 1)
                    if (!l.query(auxiliar.getLetters())) {
                        auxiliar.setScore(NONEXISTENT_WORD);
                        lista.add(auxiliar);
                        return lista;
                    }
            }


            return lista;

        } else {

            row = move.getRow() - 1;
            while (contador < move.getLetters().size() && !overflow) {
                overflow = (row >= getHeight());
                while (!overflow && copia.get(row, move.getCol() - 1) != EMPTY) {
                    row += 1;
                    comparador += 1;
                    overflow = (row >= getHeight());
                }
                if (!overflow) {
                    copia.set(row, move.getCol() - 1, move.getLetters()[contador]);
                    aniade = copia.findMaxWord(row, move.getCol() - 1, true);
                    if (aniade.getLetters().size() > 1) {
                        if (l.query(aniade.getLetters())) {
                            score = aniade.findScore(l);
                            aniade.setScore(score);
                            lista.add(aniade);
                        } else {
                            aniade.setScore(NONEXISTENT_WORD);
                            lista.add(aniade);
                        }

                        aniadida = true;
                    }
                    row += 1;
                    comparador += 1;
                    contador += 1;
                }

            }
            auxiliar = copia.findMaxWord(move.getRow() - 1, move.getCol() - 1, move.isHorizontal());

            if (overflow) {
                lista.clear();
                auxiliar.setScore(BOARD_OVERFLOW);
                lista.add(auxiliar);
                return lista;
            }

            if (auxiliar.getLetters().size() > 1) {
                if (l.query(auxiliar.getLetters())) {
                    score = auxiliar.findScore(l);
                    auxiliar.setScore(score);
                    lista.add(auxiliar);

                } else {
                    auxiliar.setScore(NONEXISTENT_WORD);
                    lista.add(auxiliar);
                    return lista;

                }
            }

            if (comparador == move.getLetters().size() && lista.size() <= 1 && auxiliar.getLetters().size() == move.getLetters().size() && clear() == false && !aniadida) {
                lista.clear();
                auxiliar.setScore(MISSING_CROSSWORDS);
                lista.add(auxiliar);
                return lista;

            }
            if (clear()) {
                if (auxiliar.getLetters().size() == 1)
                    if (!l.query(auxiliar.getLetters())) {
                        auxiliar.setScore(NONEXISTENT_WORD);
                        lista.add(auxiliar);
                        return lista;
                    }
            }

            return lista;
        }
    }
}

// Para comprobar si la matriz esta vacia 

bool Tiles::clear() const {
    for (int i = 0; i < getWidth(); i++) {
        for (int j = 0; j < getHeight(); j++) {
            if (get(i, j) != EMPTY) {
                return false;
            }
        }
    }
    return true;
}

