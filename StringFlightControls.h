#ifndef PROJECT1_STRINGFLIGHTCONTROLS_H
#define PROJECT1_STRINGFLIGHTCONTROLS_H

#include <string>
#include <list>

using namespace std;
/**
 * string to control the flight class
 */
class StringFlightControls {
    //memmbers
    list<string>controlCommand;
public:
    /**
     * constructor
     */
    StringFlightControls(){}

    /**
     * add a control
     * @param s contriol string
     */
    void setControl(string s){
        this->controlCommand.push_back(s);
    }

    /**
     * get a control from the list
     * @return control as a string
     */
    string getControl(){
        string control = this->controlCommand.front();
        this->controlCommand.pop_front();
        return control;
    }

    /**
     * if the list is empty
     * @return true if empty
     */
    bool isEmpty(){
        return this->controlCommand.empty();
    }
    /**
     * distructor
     */
    ~StringFlightControls(){};
};


#endif //PROJECT1_STRINGFLIGHTCONTROLS_H
