#define LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class loadbalancer {
    public:
        loadbalancer() {
            systemTime = 0;
        }
        int getTime();
        void incTime();
        void addRequest(request r);
        request getRequest();
        bool isRequestQEmpty();

    private:
    int systemTime;
    queue<request> requestQ;
};
