#ifndef PROJECT1_BINDMAP_H
#define PROJECT1_BINDMAP_H

#include <string>
#include<map>

using namespace std;
/**
* PathMap class
*/
class PathMap {
    //memmbers
    map<string,string> pathMap;
public:
     /**
    * constructors
    */
    PathMap(){}
    /**
     * add to the map
     * @param key the key to insert
     * @param value the value to add
     */
    void addToPathMap(string key, string value) {
        this->pathMap.insert(pair<string,string> (key,value));
    }

    map<string,string> getBindMap(){
        return this->pathMap;
    }
    ~PathMap(){};
};

#endif //PROJECT1_BINDMAP_H
