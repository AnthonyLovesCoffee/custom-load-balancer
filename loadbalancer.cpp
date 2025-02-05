// loadbalancer.cpp

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif
#include <queue>
using namespace std;

int loadbalancer::getTime() {
    return systemTime;
}

void loadbalancer::incTime() {
    systemTime++;
}

void loadbalancer::addRequest(request r) {
    requestQ.push(r);
    incTime();
}

request loadbalancer::getRequest() {
    incTime();
    if (!requestQ.empty()) {
        request r = requestQ.front();
        requestQ.pop();
        return r;
    }
}

bool loadbalancer::isRequestQEmpty() {
    return requestQ.empty();
}


