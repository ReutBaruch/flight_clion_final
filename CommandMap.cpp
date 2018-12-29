#include "CommandMap.h"

/**
     * add a command to the map
     * @param key  the key to add to the map
     * @param command  the command to add to the map
     */
void CommandMap::addCommand(string key, Command *command) {
    this->commandMAp.insert(pair<string,Command*>(key,command));
}
map<string, Command*> CommandMap::getCommandMap(){
    return this->commandMAp;
}

/**
     * return the command according to the asked key
     * @param key the key from the map
     * @return the command according to the key
     */
Command* CommandMap::getCommand(string key) {
    //if the key is in the map
   if(this->commandMAp.count(key)){
       //return it
       return this->commandMAp.find(key)->second;
   } else{
       //if not- return error
       throw "ERROR: no such key";
   }
}

/**
     * return if the key is in the map
     * @param key the key to check
     * @return true if is in the map, false if not
     */
bool CommandMap::isInMap(string key) {
    return this->commandMAp.count(key);
}
