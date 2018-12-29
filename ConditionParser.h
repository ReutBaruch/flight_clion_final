#include "Command.h"
#include <list>
#include "BoolExpression.h"
#include <map>
#include "SymbolTable.h"
#include "CommandExpression.h"
#include "CommandMap.h"
#ifndef PROJECTNUM1_CONDITIONPARSER_H
#define PROJECTNUM1_CONDITIONPARSER_H


/**
 * ConditionParser inheritors Command
 */
class ConditionParser : public Command {
    //members
    list<CommandExpression*> expressionCommandList;
    CommandMap* commandMap;
    BoolExpression* boolExpression;
    SymbolTable* symbolTable;
    list<Command*> toDelete;
    list<CommandExpression*> toDeleteCommExp;
    CreateExpression* createExpression;

public:

   /**
    * constructor
    */
    ConditionParser(CommandMap* commandMap,SymbolTable* symbolMap, CreateExpression* createExp);

     /**
     * parser the condition
     * @param script iterator
     * @return 0 when finish
     */
    virtual int execute(vector<string>::iterator &vectorIt);
     /**
     * create new command
     * @param vectorIt the iterator
     */
    void createCommand(vector<string>::iterator &vectorIt);

        /**
    *distructor
    */
    virtual ~ConditionParser(){
        list<Command*>::iterator itr;
        for(itr = toDelete.begin(); itr != toDelete.end(); itr++){
            delete (*itr);
        }

        list<CommandExpression*>::iterator itCom;
        for(itCom = toDeleteCommExp.begin(); itCom != toDeleteCommExp.end(); itCom++){
            delete (*itCom);
        }
    };
};


#endif //PROJECTNUM1_CONDITIONPARSER_H
