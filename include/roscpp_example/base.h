//
// Created by vinicius on 4/25/18.
//

#ifndef PROJECT_ROSCPP_EXAMPLE_BASE_H
#define PROJECT_ROSCPP_EXAMPLE_BASE_H

#include <string>
#include <sstream>

class Echoer {
protected:
    int nEchos;
    std::string inMsg;
    std::string outMsg;

public:
    explicit Echoer(int n = 3, std::string in = "...", std::string out = "...");
    void setNEchos(int n);
    void listen(const std::string &msg);
    std::string shout();
    void makeEcho();
};

#endif //PROJECT_ROSCPP_EXAMPLE_BASE_H
