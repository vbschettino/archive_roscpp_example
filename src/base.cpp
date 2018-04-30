//
// Created by vinicius on 4/25/18.
//

#include "roscpp_example/base.h"

// Constructor
Echoer::Echoer(int n, string in, string out) : nEchos(n), inMsg(in), outMsg(out) {}

// Setters and getters
void Echoer::setNEchos(int n) {
    Echoer::nEchos = n;
}

void Echoer::listen(const string &msg) {
    Echoer::inMsg = msg;
}

string Echoer::shout() {
    return Echoer::outMsg;
}

// Actual work
void Echoer::makeEcho() {
    stringstream ss;
    for (int i = 0; i < Echoer::nEchos; ++i) {
        ss << Echoer::inMsg << "...";
    }
    Echoer::outMsg = ss.str();
}
