//
// Created by vinicius on 4/25/18.
//

#ifndef PROJECT_ROSCPP_EXAMPLE_BASE_H
#define PROJECT_ROSCPP_EXAMPLE_BASE_H

#include <string>
#include <sstream>

using namespace std;

class Echoer {
protected:
    int nEchos;
    string inMsg;
    string outMsg;

public:
    explicit Echoer(int n = 3, string in = "...", string out = "...");
    void setNEchos(int n);
    void listen(const string &msg);
    string shout();
    void makeEcho();
};

#endif //PROJECT_ROSCPP_EXAMPLE_BASE_H
