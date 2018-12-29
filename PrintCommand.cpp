#include "PrintCommand.h"
/**
 * 
 * @param vectorIt the iterator
 * @return 0 when done
 */
int PrintCommand::execute(vector<string>::iterator &vectorIt) {
    string toPrint = "";
    //if its a word
    if((*vectorIt)[0] != '\"'){
        toPrint = (*vectorIt);
        //its a variable
    } else {
        while ((*vectorIt) != ";") {
            toPrint += (*vectorIt);
            vectorIt++;
        }
        toPrint = toPrint.substr(1, (toPrint.length()) - 2);
    }
    vectorIt++;
//print
    cout << toPrint << endl;
    return 0;
}
