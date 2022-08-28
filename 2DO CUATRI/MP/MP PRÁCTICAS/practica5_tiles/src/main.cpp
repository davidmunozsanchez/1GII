/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */


#include <iostream>
#include <fstream>
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "language.h"

using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
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

/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    // Declarations, in a similar way as older versions
    bool langu, width, height, play;
    langu = width = height = play = false;
    bool prefile = false;;
    int w, h;
    string playfile = "", language = "";
    int random = -1;
    string match_file, save_file="";
    Language lang;
    Bag bag;
    Player player;
    Move move;
    Movelist original, accepted, rejected, legal;
    Tiles tiles;
    bool nueva_partida = false;
    ifstream match;
    ifstream play_in;
    ofstream out;
    string codigo;
    int score;
    string non_use, current_play, current_bag;
    ostream *output;
    /*
    * 1) El main() recibe múltiples parámetros de entrada, distinguiendo
    entre dos modos de funcionamiento.

     * a) Empezar una partida nueva. Para ello los parámetros de
    llamada serán
    -l <lang> -w <int> -h <int> -p <pfile> [-r <int>
     *  -save <matchfile>]
    especificando el diccionario, el ancho y alto del tablero de
    juego, el fichero de movimientos registrados y, opcional-
    mente, el número aleatorio y la posibilidad de salvar la la
    jugada en un fichero con extensión .match con la opción
    -save . En caso de que no se indique esta última opción,
    entonces deberá mostrar el estado final de la partida con el
    mismo formato (ver Sección ??).

     * b) Continuar una partida existente. Para ello los parámetros
    de llamada serán
    5Metodologı́a de la Programación
    MPALABRADOS (tiles-1)
    -open <matchfile> -p <playfile> [-save <matchfile>]
    indicando la apertura de un fichero .match desde el que
    se restaura el estado anterior de la partida, y un fichero
    de movimientos. Opcionalmente, se podrá grabar la partida
    final si se indica el parámetro -save comentado antes.*/
    
    // Evaluamos todos los parametros del main
    int arg = 1;
    string str_arg;
    while (arg < nargs) {
        str_arg = args[arg];
        if (str_arg == "-l") {
            arg++;
            if (arg >= nargs) //MISMA CONDICION PARA TODOS LOS ERRORES
                errorBreak(ERROR_ARGUMENTS, "");
            langu = true;
            language = args[arg++];
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
        } else if (str_arg == "-p") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            play = true;
            playfile = args[arg++];
        } else if (str_arg == "-r") {
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            random = atoi(args[arg++]);
        } else if (str_arg == "-save"){
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            save_file = args[arg++];
        } else if (str_arg == "-open"){
            arg++;
            if (arg >= nargs)
                errorBreak(ERROR_ARGUMENTS, "");
            prefile = true;
            match_file = args[arg++];
        }
        else{
            errorBreak(ERROR_ARGUMENTS,"");
        }

    }
    // Vamos a determinar posibles errores en la lectura de argumentos
    if (prefile && (langu || width || height || !play ))
        errorBreak(ERROR_ARGUMENTS, "");
    if ((!langu || !width || !height || !play) && !prefile)
        errorBreak(ERROR_ARGUMENTS, "");
    if (langu)
        nueva_partida = true;
    
    
     
    /*
     * 2. Crear una instancia de la clase Language con el ID indicado.

     * 3. Crear una instancia de la clase Bag, si es una partida nueva,
    inicializar la bolsa, en otro caso, cargarla directamente desde el
    fichero .match

     * 4. Crear una instancia de la clase Player y inicializarla por com-
    pleto con caracteres de la bolsa o bien leerla del fichero .match.

     * 5. Crear una instancia de la clase Tiles y dimensionarla según
    los parámetros leı́dos, bien desde la lı́nea de comandos, bien
    desde el fichero .match.

     * 6. Crear una instancia de la clase bf Movelist llamada original
    y leer todos los movimientos desde el fichero indicado en el
    parámetro -p usando operador sobrecargado >>*/
                
    if (nueva_partida){
        lang.setLanguage(language);
        if (random >= 0)
            bag.setRandom(random);
        bag.define(lang);
        player.add(bag.extract(7));
        tiles.setSize(h,w);
    }    
    
    else{
        match.open(match_file);
        if (match.fail())
            errorBreak(ERROR_OPEN,match_file);
        match >> codigo;
        if (codigo != PASSWORD)
            errorBreak(ERROR_DATA,"");
        match >> score;
        match >> language;
        if(match.eof())
            errorBreak(ERROR_DATA,"");
        lang.setLanguage(language);
        
        match >> tiles;
        match >> non_use >> current_play;
        if(match.eof())
            errorBreak(ERROR_DATA,"");
        player.add(toISO(current_play));
        
        match >> non_use >> current_bag;
        if(match.eof())
            errorBreak(ERROR_DATA,"");
        bag.set(current_bag);
    }
    
    
    
    /*


     * 7. Crear una instancia de Movelist llamada legal que contenga
    sólo los movimientos de original que están en el diccionario
    del lenguaje elegido. Usar, para ello, el método zip(...)

     * 8. Crear dos instancias adicionales de Movelist y llamarlas accepted
    y rejected
     * 9. Recorrer toda la lista de movimientos leı́da y, por cada uno de
    ellos.

     * a) Si el movimiento está en el diccionario, añadir la palabra a
    la lista accepted , calcular su puntuación, según el idioma
    y acumularla. A continuación, se deberá colocar cada mo-
    vimiento en su posición correspondiente en la instancia de
    Tiles creada anteriormente, ignorando aquellos caracteres
    que caigan fuera de las dimensiones permitidas y sobrees-
    cribiendo los caracteres que se crucen.

     * b) En otro caso añadirla a la lista rejected .

    
     */
    play_in.open(playfile);
    if (play_in.fail())
        errorBreak(ERROR_OPEN, playfile);
    play_in >> original;
    if (play_in.eof())
        errorBreak(ERROR_DATA,playfile);
    
    
    legal = original;
    
    legal.zip(lang);
    
    for (int i = 0; i < legal.size(); i++) {
        move = legal.get(i);

        string word = move.getLetters();

        if (player.isValid(word)) {
            move.setScore(move.findScore(lang));
            accepted.add(move);
            player.extract(word);
            player.add(bag.extract(word.length()));
            tiles.add(move);
        } else 
            rejected.add(move);
    }
    
    if (nueva_partida)
        score = accepted.getScore();
    
    else
        score += accepted.getScore();
    
    /*
      * 10. Terminar mostrando el estado de la partida en pantalla o guardándo-
    lo en disco según la presencia o no de -save .
    11. Si en cualquier momento se presenta un error en los argumen-
    tos, en la apertura de ficheros o en la lectura de datos del fiche-
    ro, se debe usar la función errorBreak(...) para notificar el error
    y parar el programa 
     
     
     */
    
    if (save_file == ""){
        output = &cout;
        *output << "%%%OUTPUT" << endl;
    }
       
    else{
        out.open(save_file);
        output = &out;
        *output << PASSWORD << endl;
    }
    
    *output << score << endl;
    *output << language << endl;
    tiles.print(*output);
    *output << player.size() << " " << toUTF(player.to_string()) << endl;
    *output << bag.size() << " " << toUTF(bag.to_string()) << endl;
    
    
    return 0;
}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cerr << "Error in call. Please use either:" << endl;
            cerr << "-l <language> -w <width> -h <height> -p <playfile> [-r <randomnumber> -save <matchfile>]" << endl;
            cerr << "-open <matchfile> -p <playfile> [-save <matchfile>]" << endl;
            break;
        case ERROR_OPEN:
            cerr << "Error opening file " << errordata << endl;
            break;
        case ERROR_DATA:
            cerr << "Data error in file " << errordata << endl;
            break;
    }
    std::exit(1);
}

