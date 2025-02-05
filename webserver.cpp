// webserver.cpp
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webserver {
    public:
        webserver() {
            requestStartTime = 0;
            serverName = ' ';
        }

        webserver(char serverString) {
            serverName = serverString;
            requestStartTime = 0;
        }

        void addRequest(request req, int currTime) {
            r = req;
            requestStartTime = currTime;
        }

        request getRequest() {
                return r;
            }

        char getServerName() {
                return serverName;
            }

        bool isRequestFinished(int currTime) {
                return (currTime > (requestStartTime + r.processTime));
            }

    private:
        request r;
        int requestStartTime;
        char serverName;
};