# Basic Load Balancer
This project is an implementation of a load balancer serving to multiple webservers. 

## What do we need?
**Requests**: The request is going to contain an ingoing address (IP in) and an outgoing address (IP out) 
and a timestamp, in this implementation we just used ints for time measurement. 
In this basic implementation, these reuqests are going to be basic fields/structs of data.

**Web Server**: The web server will take a request from the load balancer, process the request and ask for another request from the load balancer.

**Load Balancer**: This will essentially be a simple queue of requests and it will keep track of time. This is so it can track how long each requests takes to process.