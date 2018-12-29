#include "BoolExpression.h"

/**
 * the function gets a condition in string and makes it to expression.
 * @param boolCondition the condition
 */
void BoolExpression::createBoolExpression(string conditionToCheck) {

    this->createExpression = new CreateExpression(this->symbols);

    string expression = "";
    this->action = "";
    int strLen = 0;

    int size = conditionToCheck.size();
    
    //get the first expression and put it into expression, char by char
    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '!') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '>')) {
        expression += conditionToCheck[strLen];
        strLen++;
        //if we got to the end of the string and there no condition
        if(strLen == (size - 1)){
            // throw error
            throw ("ERROR: invalid condition");
        }
    }
    
     //from string to expression
    this->leftArgument = createExpression->convertToExpression(expression);
    //get the condition and put it into action
    while ((conditionToCheck[strLen] == '<') || (conditionToCheck[strLen] == '>') ||
           (conditionToCheck[strLen] == '=') || (conditionToCheck[strLen] == '!')) {
        action += conditionToCheck[strLen];
        strLen++;
    }
    expression = "";
    //get the second expression by the same way
    int conLen = conditionToCheck.length();
    while ((conditionToCheck[strLen] != '<') && (conditionToCheck[strLen] != '>') &&
           (conditionToCheck[strLen] != '=') && (conditionToCheck[strLen] != '!') &&
           (strLen < conLen)) {
        expression += conditionToCheck[strLen];
        strLen++;
    }
     //get the right expression
    this->rightArgument = createExpression->convertToExpression(expression);
}


/**
 * the function calculate the condition and returns the answer
 * @param symbolMap the symbol map
 * @return true / false according to the condition
 */
bool BoolExpression::calculateBool(map<string, double> symbolMap) {
    //if the condition is <
    if (this->action == "<") {
        //calculate according to the condition < and return the answer
        return ((leftArgument->calculate(symbolMap)) <
                rightArgument->calculate(symbolMap));
         //if the condition is >
    } else if (this->action == ">") {
        //calculate according to the condition > and return the answer
        return ((leftArgument->calculate(symbolMap)) >
                rightArgument->calculate(symbolMap));
         //if the condition is <=
    } else if (this->action == "<=") {
        //calculate according to the condition <= and return the answer
        return ((leftArgument->calculate(symbolMap)) <=
                rightArgument->calculate(symbolMap));
         //if the condition is >=
    } else if (this->action == ">=") {
        //calculate according to the condition >= and return the answer
        return ((leftArgument->calculate(symbolMap)) >=
                rightArgument->calculate(symbolMap));
         //if the condition is ==
    } else if (this->action == "==") {
        //calculate according to the condition == and return the answer
        return ((leftArgument->calculate(symbolMap)) ==
                rightArgument->calculate(symbolMap));
         //if the condition is !=
    } else if (this->action == "!=") {
        //calculate according to the condition != and return the answer
        return ((leftArgument->calculate(symbolMap)) !=
                rightArgument->calculate(symbolMap));
    } else {
        //if there no such argument
        throw "ERROR: no such argument";
    }
}
