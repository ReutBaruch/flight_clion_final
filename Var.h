#ifndef PROJECT1_VAR_H
#define PROJECT1_VAR_H

#include <string>
#include "Expression.h"
#include "SymbolTable.h"
/**
* class Var
*/
class Var: public Expression {
    //memmbers
    string var;
    SymbolTable* symbols;
public:
    //constroctur
    Var(string v, SymbolTable* symbol);
    virtual double calculate(map<string, double> &assignment);

    double calculate();

    virtual ~Var(){};

};

#endif //PROJECT1_VAR_H
