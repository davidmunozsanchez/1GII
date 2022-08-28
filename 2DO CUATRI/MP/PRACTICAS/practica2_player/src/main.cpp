/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <string>
#include <iostream>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "wordlist.h"
///@warning complete missing #includes

using namespace std;
/**
 * @brief Shows final data
 * @param l Language
 * @param random Random seed
 * @param b Final bag
 * @param p Final player
 * @param nwords Number of words found
 * @param score Number of letters found
 * @param result Aggregation of all valid words found
 */
void HallOfFame(const Language &l, int random, const Bag &b, const Player &p, 
        int nwords, int score, const string &result);

/**
 * @brief Main function. 
 * @return 
 */
int main() {
    int Id;             /// To be used in bag.setRandom())
    Bag bag;            /// Bag of letters
    Player player;      /// Player set of letters
    Language language;  /// Language to be loaded from disk
    string result = "";      /// String that contains all the words found
    int nletters = 0,          /// Number of letters found
        nwords = 0;          /// Number of words found
    string lang_aux;    /// To set the language
    string word;        /// Word given
    
    /// @warning; complete code
    
    //1. Leer un string con el ID del lenguaje, según el estándar ISO639-
    cout << "Select a language (ES, FR, EN): ";
    cin  >> lang_aux;
    
    /*2. Crear una instancia de la clase Language con el anterior ID y
    mostrar el conjunto de caracteres permitido para ese lenguaje.*/
    language.setLanguage(toISO(lang_aux));
    cout << toUTF(language.getLetterSet());
    
    /*3. Pedir un número entero, si este número es mayor o igual a ce-
    ro, iniciar el generador de números aleatorios con el número
    anterior con el método setRandom(), en otro caso, no se llama 
    a setRadndom() para dejar deja una inicialización aleato-
    ria. Definir el contenido de bag en base al lenguaje que se ha
    declarado anteriormente (método define()).*/
    
    cout << endl << "Enter a positive number to mess the bag up: ";
    cin  >> Id;
    
    if (Id >= 0)
        bag.setRandom(Id);
    
    bag.define(toISO(lang_aux));
    
    /*4. Crear una instancia de la clase Player y llenarla por comple-
    to con caracteres de la bolsa. Este objeto player deberá estar
    siempre ordenado de la A a la Z.*/
    player.add(bag.extract(7));
    
    cout << endl << toUTF(bag.to_string());
    
    /*5. Pedir una palabra por teclado (en letras mayúsculas). Si esta
    palabra no es una tirada válida según el contenido de player se
    debe indicar como "INVALID!" . Si, por el contrario, la palabra
    leı́da es compatible con el contenido de player, se debe extraer
    de player de forma definitiva y volver a rellenar player con más
    letras de bag. En este caso, si esta palabra está en el diccio-
    nario elegido, indicarlo como "FOUND!" en otro caso, indicarlo
    como "NOT REGISTERED!"*/
    do{
        cout << endl << "PLAYER: " << toUTF(player.to_string()) << "  BAG (" << bag.size() << ")" << endl;
        cout << "INPUT A WORD: ";
        cin >> word;
        
        word = toISO(word);
        
        if (player.isValid(word)){
            if (language.query(word)){
                cout << endl << toUTF(word) << " FOUND!" << endl;
                result = result + toUTF(word) + " - ";
                nwords += 1;
                nletters += word.length();
            }
                
            else
                cout << endl << toUTF(word) << " NOT REGISTERED!" << endl;
            
            player.extract(word);
            player.add(bag.extract(word.length()));
        }
        
        else
            cout << endl << toUTF(word) << " INVALID!" << endl;
    }while(word.length() >= 2 && player.to_string().length() > 0);
    
    
    
    HallOfFame(language,Id,bag,player, nwords, nletters, result);
    return 0;
}

void HallOfFame(const Language &l, int random, const Bag &b, const Player &p, 
        int nwords, int score, const string &result) {
    cout << endl << "%%%OUTPUT" << endl << "LANGUAGE: "<<l.getLanguage()<< " ID: " << random << endl;
    cout << "BAG ("<<b.size()<<"): " << toUTF(b.to_string()) << endl;
    cout << "PLAYER (" <<p.size() << "): " << toUTF(p.to_string())<<endl;
    cout << nwords << " words and " << score << " letters found"<<endl << 
            toUTF(result) << endl;    
}


