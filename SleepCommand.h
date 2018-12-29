#ifndef PROJECT1_SLEEPCOMMMAND_H
#define PROJECT1_SLEEPCOMMMAND_H

#include "Command.h"

/**
 * sleep class
 */
class SleepCommand: public Command {

public:
    /**
     * sleep
     * @param vectorIt vector to run on
     * @return nothing
     */
    virtual int execute(vector<string>::iterator &vectorIt);
    /**
     * distructor
     */
    virtual ~SleepCommand(){};

};


#endif //PROJECT1_SLEEPCOMMMAND_H
