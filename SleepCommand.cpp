#include <unistd.h>
#include <iostream>
#include "SleepCommand.h"


    /**
     * sleep
     * @param vectorIt vector to run on
     * @return nothing
     */
int SleepCommand::execute(vector<string>::iterator &vectorIt){
    int num = atoi((*vectorIt).c_str());
    sleep(num);
    vectorIt += 2;
    return 0;
}
