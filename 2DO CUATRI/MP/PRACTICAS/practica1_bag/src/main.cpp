/**
 * @file main.cpp
 * @author @warning Fill in your full name
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <iostream>
#include "bag.h"
#include "language.h"
#include "wordlist.h"
///@warning Fill missing #include

using namespace std;


/**
 * @brief Shows final data in a form detectable by autovalidation scripts
 * @param l Language
 * @param random Random seed
 * @param b Final bag
 * @param nwords Number of words found
 ** @param result Aggregation of all valid words found
 */
void HallOfFame(const Language &l, int random, const Bag &b,
        int nwords, const string &result);

/**
 * @brief Main function. 
 * @return 
 */
int main() {
    const int MAXIMO = 100;
    Language language;
    Bag bag;
    string word, lang, result= "", lang_aux, allowed;
    string mostrar;
    int random, count = 0;
    bool exist;
    
    
    /// @warning Read language
    cout << "Select a language(ES, FR, EN): ";
    cin >> lang_aux;
    
    lang = toISO(lang_aux);
    
    /// @warning Show allowed letters
    language.setLanguage(lang);
    
    allowed = language.getLetterSet();
    
    cout << toUTF(allowed) << endl;
        
    /// @warning Read random and define bag
    cout << "Enter a positive number to mess the bag up: ";
    cin  >> random;

    if (random > 0)
        bag.setRandom(random);
    
    bag.define(lang);
    /// @warning Extract a 5-letter word from the bag
    /// check whether it is in the dictionary or not
    /// if it is, count a new word, and aggregate the 
    /// word to result ... result = result + word +" - ";
    while(bag.size() != 0){
            word = bag.extract(5);
            exist = language.query(word);
            
            if(exist){
                cout << toUTF(word) << " *" << endl;
                result = result + word + " - ";
                count += 1;
            }
            else
                cout << toUTF(word) << endl;
                
     }
       
    
    /// @warning Finish when the bag is empty and show results
    /// thru HallOfFame(...))
    HallOfFame(language,random, bag,count,result);
    return 0;
    
}

void HallOfFame(const Language &l, int random, const Bag &b,  
        int nwords, const string &result) {
    cout << endl <<"%%%OUTPUT" << endl << "LANGUAGE: "<<l.getLanguage()<< " ID: " << random << endl;
    cout << "BAG ("<<b.size()<<"): " << toUTF(b.to_string()) << endl;
    cout << nwords << " words found "<<endl << 
            toUTF(result) << endl;    
}


