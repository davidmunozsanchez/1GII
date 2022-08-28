/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <string>
#include <cassert>
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "window.h"
#include "AnsiTerminal.h"
using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
#define GENERAL_ERROR 4
#define PASSWORD "MPALABRADOS-V1"


/**
 * @brief Reports an important error and exits the program
 * @param errorcode An integer representing the error detected, which is represented
 * by several symbolic constants: ERROR_ARGUMENTS, ERROR_OPEN y ERROR_DATA
 * @param errorinfo Additional information regarding the error: "" (empty string) for 
 * errors parsing the arguments to main() and, for the case of errors opening or 
 * reading/writing data, the name of the file thas has failed.
 */
void errorBreak(int errorcode, const string & errorinfo);

ostream & operator<<(ostream & os, const Game &game);
istream & operator>>(istream & is, Game &game);

bool goodCross(const Game & game);

/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    Move move;
    Game game;
    int w = -1, h = -1, wait = 0;
    string lang = "", ifilematch = "", ofilematch = "", word;
    ifstream ifile;
    ofstream ofile;
    bool end = false;
    bool langu = false, width = false, height = false, prefile = false, nueva_partida = false;
    int random = -1;


    /// Check arguments

    int arg = 1;
    string str_arg;
    while (arg < nargs) {
        str_arg = args[arg];
        if (str_arg == "-l") {
            arg++;
            if (arg >= nargs) //MISMA CONDICION PARA TODOS LOS ERRORES
                errorBreak(ERROR_ARGUMENTS, "");
            langu = true;
            lang = args[arg++];
        } else if (str_arg == "-w") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            width = true;
            w = atoi(args[arg++]);
        } else if (str_arg == "-h") {
            arg++;

            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            height = true;
            h = atoi(args[arg++]);
        } else if (str_arg == "-r") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            random = atoi(args[arg++]);
        } else if (str_arg == "-save") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            ofilematch = args[arg++];
        } else if (str_arg == "-open") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            prefile = true;
            ifilematch = args[arg++];
        } else {
            errorBreak(ERROR_ARGUMENTS, "");
        }

    }

    // Process arguments
    if (prefile && (langu || width || height))
        errorBreak(ERROR_ARGUMENTS, "");
    if ((!langu || !width || !height) && !prefile)
        errorBreak(ERROR_ARGUMENTS, "");
    if (langu)
        nueva_partida = true;

    /// load data from file, if asked to in arguments
    if (nueva_partida) {
        game.language.setLanguage(lang);
        if (random >= 0)
            game.bag.setRandom(random);
        game.bag.define(game.language);
        game.player.add(toISO(game.bag.extract(7)));
        game.tiles.setSize(h, w);
        game.score = 0;
    } else {
        ifile.open(ifilematch);
        if (ifile.fail())
            errorBreak(ERROR_OPEN, ifilematch);
        ifile >> game;
        if (ifile.eof())
            errorBreak(ERROR_DATA, ifilematch);
    }

    // Game's main loop 
    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles
    game.setWindowSize();
    game.doPaint();
    game.wait = wait;

    while (!end) {
        
        // 2) Given the inner data members, it pretty-prints the screen
        game.doPaint();
        setCursorOn();
        // 3) Reads the movement from cin
        cin >> move;
        setCursorOff();
        word = toISO(move.getLetters());
        if (word == "_") {
            end = true;
        }//Comprobamos si la palabra es valida con respecto a nuestro player
        else if (game.player.isValid(word)) {

            
            // Checks whether the movement is valid accoring to the letters in player    
            // Finds all the crosswords produced by move and inform about the reasons of rejection
            game.crosswords = game.tiles.findCrosswords(move, game.language);
            //Checks that the crosswords are valid, that is either has a positive score
            //      or produces at least a cross with other existin letters
            
            // Once a valid move is detected, the user is asked to confirm
            // call doConfirmCrosswords()
            if (goodCross(game)) {
                if (game.doConfirmCrosswords("ACCEPT MOVEMENT?")) {
                    move.setScore(game.crosswords.getScore());
                    game.acceptedmovements.add(move);
                    game.tiles.add(move);
                    game.score = game.score + move.getScore();
                    game.player.extract(word);
                    game.player.add(toISO(game.bag.extract(7 - game.player.size())));
                }


                //     the movement. If he/she does (by pressing Y o y) then the movement
                //     is inserted in tiles and its score is caLculated,
                //     otherwise, the move is just ignored
                // If valid and accepted, computes the score and adds it

                // Show crosswords found
                // If it is a bad crosswords

                // call doBadCrosswords()
            } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == BOARD_OVERFLOW) {
                game.doBadCrosswords("BOARD OVERFLOW");
                move.setScore(BOARD_OVERFLOW);
                game.rejectedmovements.add(move);
            } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NOT_FREE) {
                game.doBadCrosswords("NOT FREE");
                move.setScore(NOT_FREE);
                game.rejectedmovements.add(move);
            } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == NONEXISTENT_WORD) {
                game.doBadCrosswords("NON EXISTENT WORD");
                move.setScore(NONEXISTENT_WORD);
                game.rejectedmovements.add(move);
            } else if (game.crosswords.size() == 1 && game.crosswords.get(0).getScore() == MISSING_CROSSWORDS) {

                game.doBadCrosswords("MISSING CROSSWORDS");
                move.setScore(MISSING_CROSSWORDS);
                game.rejectedmovements.add(move);


            } else {
                game.doBadCrosswords("BAD CROSSWORDS FOUND!");
                game.rejectedmovements.add(move);
            }

            // If not valid w.r.t. player
            // call doBadCrosswords()

        } else {
            move.setScore(INFEASIBLE_WORD);
            //Lo aniadimos a crosswords, ya que en crosswords no tratamos este error
            game.crosswords.clear();
            game.crosswords.add(move);
            game.doBadCrosswords("INFEASIBLE WORD");
            game.rejectedmovements.add(move);
        }
    }
    // End of game
    // Save file or print screen
    if (ofilematch == "") {
        cout << endl << "%%%OUTPUT" << endl;
        cout << game;
    } else {

        ofile.open(ofilematch);
        ofile << PASSWORD << endl;
        ofile << game;
    }


    return 0;


}

ostream & operator<<(ostream & os, const Game & game) {

    os << game.score << "\n" << game.language.getLanguage() << "\n";
    game.tiles.print(os);
    os << game.player.size() << " " << toUTF(game.player.to_string()) << "\n";
    os << game.bag.size() << " " << toUTF(game.bag.to_string()) << endl;
    return os;

}

istream & operator>>(istream & is, Game &game) {
    string codigo = "", non_use = "", lang = "", current_play = "", current_bag = "";
    

    is >> codigo;
    if (codigo != PASSWORD)
        errorBreak(ERROR_DATA, "");
    is >> game.score;
    is >> lang;
    if (is.eof())
        return is;
    game.language.setLanguage(lang);

    is >> game.tiles;
    is >> non_use >> current_play;
    if (is.eof())
        return is;
    game.player.add(toISO(current_play));

    is >> non_use >> current_bag;

    if (is.eof())
        return is;
    game.bag.set(toISO(current_bag));

    return is;

}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cerr << "Error in call. Please use either:" << endl;
            cerr << "-l <language> -w <width> -h <height> [-r <randomnumber> -save <matchfile>]" << endl;
            cerr << "-open <matchfile> [-save <matchfile>]" << endl;
            break;
        case ERROR_OPEN:
            cerr << "Error opening file " << errordata << endl;
            break;
        case ERROR_DATA:
            cerr << "Data error in file " << errordata << endl;
            break;
        case GENERAL_ERROR:
            cerr << "Error: " << errordata << endl;
            break;
    }
    std::exit(1);
}


// Funcion para ver si hay alguna negativa
bool goodCross(const Game & game){
    for (int i = 0; i < game.crosswords.size(); i++){
        if (game.crosswords.get(i).getScore() < 0){
            return false;
        }
    }
    return true;
}

