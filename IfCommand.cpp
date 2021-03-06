#include "IfCommand.h"
/**
 * if the condition true- do the next.
 * @param script the iterator
 * @return 0 when finish
 */
int IfCommand::execute(vector<string>::iterator &vectorIt) {
    //if the condition is true
    if (this->boolExpression->calculateBool(this->symbolTable->getSymbols())) {
        list<CommandExpression *>::iterator tempIt;

        for (tempIt = this->commandExpressions.begin();
             tempIt != this->commandExpressions.end(); tempIt++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*tempIt)->calculate(symbolMap);
        }
    }
    return 0;
}
