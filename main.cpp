#include "request.cpp"
#include "webserver.cpp"
#include "loadbalancer.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <random>


using namespace std;

const int NUM_SERVERS = 10;

// creating our requests
request createRandomRequest() {
    stringstream ip_source, ip_dest;
    request r;

    ip_source.str("");
    ip_source.clear();
    ip_dest.str("");
    ip_dest.clear();

    // ipv4 is octet of 256 possible numbers
    ip_source << (rand() % 256) << "." << (rand() % 256) << "." <<(rand() % 256) << "." << (rand() % 256);
    ip_dest << (rand() % 256) << "." << (rand() % 256) << "." <<(rand() % 256) << "." << (rand() % 256);

    r.source = ip_source.str();
    r.destination = ip_dest.str();
    r.processTime = rand() % 500;

    return r;
}

int main() {
    srand(time(0));
    loadbalancer lb; // creating our load balancer

    // starting full q
    for (int i = 0; i < 10; i++) {
        request r = (createRandomRequest());
        lb.addRequest(r);
    }

    webserver webArray[NUM_SERVERS];
    for (int i = 0; i < NUM_SERVERS; i++) {
        webserver w((char)(i + 65)); // casting Unicode to char to name each server
        webArray[i] = w;
        webArray[i].addRequest(lb.getRequest(), lb.getTime());
    }

    while (lb.getTime() < 10000) {
        // check if each webserver is done
        int currTime = lb.getTime();
        if (webArray[currTime % NUM_SERVERS].isRequestFinished(currTime)) {
            request r = webArray[currTime % NUM_SERVERS].getRequest();
            cout << "At " << currTime << " Server " << webArray[currTime % NUM_SERVERS].getServerName() << " processed requested from: " << r.source << " to " << r.destination << endl;

            webArray[currTime % NUM_SERVERS].addRequest(lb.getRequest(), currTime); // giving a new request when web server is finished processing
        }

        if (rand() % 10 == 0) {
            request r = (createRandomRequest());
            lb.addRequest(r);
        }
        lb.getTime();
    }
}