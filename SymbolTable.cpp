#include "SymbolTable.h"

/**
 * add to symbol table
 * @param key variable
 * @param value value
 */
void SymbolTable::addPairSymbol(string key, string value) {
    this->bindMap->addToPathMap(key, value);
    //if the path in the plan xml
    if (this->flightValues->getFlightVauleMap().count(value)) {
        this->symbols.insert(pair<string, double>(key, this->flightValues->getFlightVauleMap()
        .find(value)->second));
        this->bindMap->addToPathMap(key, value);
        //if its in our symbol map
    } else if(this->symbols.count(value)) {
        double tempValue = this->getValue(value);
        this->symbols.insert(pair<string, double>(key,tempValue));
        this->bindedSymbols.insert(pair<string, string>(key, value));
        this->bindedSymbols.insert(pair<string, string>(value, key));
        //not exists yet
    } else {
        this->symbols.insert(pair<string, double>(key, 0));
        this->bindMap->addToPathMap(key, value);
    }
}

/**
 * returns the path of a variable
 * @param key a variable
 * @return its path
 */
string SymbolTable::getPath(string key){
    if (bindMap->getBindMap().count(key)){
        return bindMap->getBindMap().find(key)->second;
    } else if (this->bindedSymbols.count(key)){
        return bindMap->getBindMap().find(this->bindedSymbols.find(key)->second)->second;
    } else {
        throw ("Path not found\n");
    }
}

/**
 * sets the value of a variable
 * @param key a variable
 * @param num value
 */
void SymbolTable::setSymbol(string key, double num){
    if(this->bindedSymbols.count(key)){
        string tempBind = this->bindedSymbols.find(key)->second;
        symbols.find(key)->second = num;
        symbols.find(tempBind)->second = num;
    } else if (this->bindMap->getBindMap().count(key)){
        symbols.find(key)->second = num;
    }
}

/**
 * adds a symbol to the map
 * @param s a variable
 * @param num value
 */
void SymbolTable::addSymbol(string s, double num){
    symbols.insert(std::pair<string, double>(s, num));
}


/**
 * returns the symbol map
 * @return symbol map
 */
map<string, double> SymbolTable::getSymbols(){
    return this->symbols;
}

/**
 * if the symbol is in the map - return true; false otherwise
 * @param str variable
 * @return true or false
 */
bool SymbolTable::isInSymbol(string str){
    return this->symbols.count(str);
}

/**
 * retrns the value of a a variable
 * @param s a variable
 * @return its value
 */
double SymbolTable::getValue(string s){
    if(this->symbols.count(s)){
        if(this->bindMap->getBindMap().count(s)){
            string fromBindMap = this->bindMap->getBindMap().find(s)->second;
            if(this->flightValues->getFlightVauleMap().count(fromBindMap)){
                double temp = this->flightValues->getFlightVauleMap().find(fromBindMap)->second;
                this->setSymbol(s, temp);
                return this->symbols.find(s)->second;
            }
        } else {
            return this->symbols.find(s)->second;
        }
    } else {
        throw ("Symbol not found.\n");
    }
    return this->symbols.find(s)->second;
}
