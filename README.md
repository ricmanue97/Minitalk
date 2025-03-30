# Minitalk

## Overview
Minitalk is a small data exchange program using UNIX signals to facilitate communication between a client and a server.

## Features
- Implements inter-process communication (IPC) using UNIX signals.
- Consists of two executables: `client` and `server`.
- The server receives messages from multiple clients without restarting.
- Communication is handled via `SIGUSR1` and `SIGUSR2` signals.

## Installation
Clone the repository and compile the project using the provided Makefile:
```sh
make
```

## Usage
### Running the Server
Start the server first. It will print its Process ID (PID):
```sh
./server
```
### Sending Messages via Client
Use the client to send a message to the server:
```sh
./client <server_pid> "Your message here"
```
Replace `<server_pid>` with the PID of the running server.

## Allowed Functions
The project permits the use of the following system calls:
- `write`
- `ft_printf` (or a self-implemented equivalent)
- `signal`, `sigemptyset`, `sigaddset`, `sigaction`
- `kill`, `getpid`
- `malloc`, `free`
- `pause`, `sleep`, `usleep`, `exit`

## Bonus Features
- Server acknowledges receipt of messages by sending a signal back to the client.
- Unicode character support for extended message encoding.

## Evaluation Criteria
To be graded, the project must meet all mandatory requirements:
- No segmentation faults, bus errors, or memory leaks.
- Efficient signal transmission without excessive delay.
- Proper error handling.

The bonus features will only be evaluated if the mandatory part is implemented perfectly.

## Submission
Submit your work via the assigned Git repository. Only the contents within the repository will be evaluated.

