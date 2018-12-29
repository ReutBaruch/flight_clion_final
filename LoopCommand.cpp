#include "LoopCommand.h"

/**
 * execute
 * @param script  the iterator
 * @return 0 when finish
 */
int LoopCommand::execute(vector<string>::iterator &vectorIt) {
    list<CommandExpression*> tempList;
    //check the condition
    while (this->boolExpression->calculateBool(
            this->symbolTable->getSymbols())) {
        tempList = this->commandExpressions;
        list<CommandExpression *>::iterator itr;
        for (itr = tempList.begin();
             itr !=tempList.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*itr)->calculate(symbolMap);
        }
    }
    return 0;
}
