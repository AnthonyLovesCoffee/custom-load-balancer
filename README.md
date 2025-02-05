# Load Balancer Simulation System

A C++ implementation of a load balancer that distributes network requests across multiple web servers.

## System Components

- **Load Balancer**: Manages incoming request queue and distributes requests to web servers
- **Web Servers**: Process requests with simulated processing times
- **Request Generator**: Creates random IPv4 requests with source/destination addresses

## Technical Details

The system uses several key C++ components:
- Round-robin load distribution algorithm
- Random request generation with IPv4 address simulation
- Time-based request processing simulation

## Building and Running

1. Compile all source files:
```bash
g++ main.cpp -o loadbalancer
```

2. Run the executable:
```bash
./loadbalancer
```

## Simulation Notes

The system simulates:
- 10 web servers processing requests concurrently
- Request processing times between 0-499 units of time
- Random IPv4 address generation for request sources and destinations

## Output

The system outputs request processing information in the format:
```
At [timestamp] Server [ID] processed requested from: [source_ip] to [destination_ip]
```

## Architecture

```
                   ┌─────────────┐
                   │Load Balancer│
                   └─────┬───────┘
                         │
         ┌───────────────┼───────────────┐
         │               │               │
   ┌─────┴─────┐   ┌─────┴─────┐   ┌─────┴─────┐
   │WebServer A │   │WebServer B │   │WebServer C  ...│
   └───────────┘   └───────────┘   └───────────┘
```