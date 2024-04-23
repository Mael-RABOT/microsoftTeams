# Microsoft Team

## Description

This project aim to create a Microsoft Team clone in C.<br>
This project does not have any graphical interface, it is a command line project.<br>

## Goals

- [x] Create a server that can handle multiple clients
- [x] Manage multiple teams, channels, threads and replies
- [x] Make a client that can connect to the server
- [x] Create a custom protocol to communicate between the server and the client

## Getting Started

To get started, you need to clone the repository and compile the server and the client.<br>

```bash
make
```

## Usage

### Server

To start the server, you need to run the following command:

```bash
./myteams_server [port]
```

### Client

To start the client, you need to run the following command:

```bash
./myteams_cli [ip] [port]
```

## Logs

All the commands are using a custom `libmyteams.so` file that logs all the commands.<br>
This library will print on the stderr.<br>
 
## Authors

- [**Mathieu Borel**](mathieu.borel@epitech.eu)
- [**Yohann Mangenot**](yohann.mangenot@epitech.eu)
- [**Maël RABOT**](mael.rabot@epitech.eu)
