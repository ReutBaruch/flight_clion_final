#include "CreateExpression.h"

/**
 * shunting yard
 * @param str the string to make expression
 * @return
 */
Expression *CreateExpression::convertToExpression(string string1) {

    string operatorString = "";
    stack<string> operators;
    stack<Expression *> expressions;

    int stringLength = 0;
    int resultLength = 0;
    
    int str1Len = string1.length();

    //go on all the string 
    while (stringLength < str1Len) {
        //if there is a (, put in the stack
        if (string1[stringLength] == '(') {
            operators.push("(");
             // if there is a )
        } else if (string1[stringLength] == ')') {
            string temp;
            operatorString += ",";
            //until the ( is in the top og the stack
            while (operators.top() != "(") {
                temp = operators.top();
                operatorString += temp;
                operators.pop();
            }
            //out of the stack
            operators.pop();
            //if there is a operators: +-*/
        } else if (string1[stringLength] != '+' && string1[stringLength] != '-' &&
                   string1[stringLength] != '*' && string1[stringLength] != '/') {

            operatorString += string1[stringLength];
        } else {
            string operatorPush = "";
            if ((stringLength == 0) && (string1[stringLength] == '-')) {
                operatorPush = "^";
            } else {
                 //check the current char and the previous char
                char previousChar = string1[stringLength - 1];
                char currentChar = string1[stringLength];
                if ((currentChar == '-') &&
                    ((previousChar == '*') || (previousChar == '+') ||
                     (previousChar == '/') || (previousChar == '-'))) {
                    operatorPush = "^";
                } else {
                    operatorPush = string(1, string1[stringLength]);
                    operatorString +=",";

                }
            }
            //add the operator to the stack
            operators.push(operatorPush);
        }
        stringLength++;
    }

     //until the end
    while (!operators.empty()) {
        operatorString += operators.top();
        operators.pop();
    }
    int operLen = operatorString.length();
    //until there are operators in the list
    while (resultLength < operLen) {
        Expression* newExpression;
        Expression* rightExpression;
        Expression* leftExpression;
        if (operatorString[resultLength] != ' ') {
            //if the operator is +
            if (operatorString[resultLength] == '+') {
                //set the first expression
                rightExpression = expressions.top();
                 //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                 //new plus expression
                newExpression = new Plus(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
                //if the operator is *
            } else if (operatorString[resultLength] == '*') {
                //set the first expression
                rightExpression = expressions.top();
                 //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                //new mul expression
                newExpression = new Mul(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
                //if the operator is /
            } else if (operatorString[resultLength] == '/') {
                 //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                resultLength++;
                //new Div expression
                newExpression = new Div(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
                //if the operator is -
            } else if (operatorString[resultLength] == '-') {
                 //set the first expression
                rightExpression = expressions.top();
                //out from stack
                expressions.pop();
                //set the second expression
                leftExpression = expressions.top();
                //out from stack
                expressions.pop();
                //new minus expression
                newExpression = new Minus(leftExpression, rightExpression);
                this->toDelete.push_back(newExpression);
                resultLength++;
            } else if (operatorString[resultLength] == '^') {
                //new neg expression
                newExpression = new Neg(expressions.top());
                this->toDelete.push_back(newExpression);
                //out from stack
                expressions.pop();
                resultLength++;
            } else if (isdigit(operatorString[resultLength])) {
                string num = "";
                while (((operatorString[resultLength]) != ',') && (isdigit(operatorString[resultLength]))) {
                    string s = string(1, operatorString[resultLength]);
                    num = num + s;
                    resultLength++;
                }
                double d = atof(num.c_str());
                newExpression = new Num(d);
                this->toDelete.push_back(newExpression);
            } else if (operatorString[resultLength] != ' ') {
                string tempVar = "";
                while (((operatorString[resultLength] != ',') || (isdigit(operatorString[resultLength])) ||
                       (isalpha(operatorString[resultLength]))) && (resultLength < operLen)){
                    string s = string(1, operatorString[resultLength]);
                    tempVar = tempVar + s;
                    resultLength++;
                }
                newExpression = new Var(tempVar, this->symbols);
                this->toDelete.push_back(newExpression);
            }
            expressions.push(newExpression);
            if(operatorString[resultLength] == ',') {
                resultLength++;
            }
        } else {
            resultLength++;
        }
    }
    //return the expression
    return expressions.top();
}
