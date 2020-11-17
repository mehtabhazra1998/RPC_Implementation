# Remote Procedure Calls

Remote Procedure Calls for Operating systems and Algorithms course



### Code preparation

1. Install rpcbind

   ```bash
   sudo apt-get install rpcbind
   ```

   

2. Use the make file to make the code

   ```bash
   # Change directory
   cd src/RPC/
   # Make file
   make -f Makefile.cmd
   ```



### Running the code



1. Run the client and server

   ```bash
   # Run server
   ./cmd_server
   # Run client in a different terminal
   ./cmd_client <host> # replace <host> with localhost to check within the same pc
   ```

# Remote Procedure Calls Using Sockets

##Open atleast two terminals for one server and multiple clients .
### Running the code
#### For server:-
 ```bash
 1. cd src/sockets/
 2. gcc server.c -o server
 3. ./server
 ```

#### For client:-
 ```bash
 1. cd src/sockets/
 2. gcc client.c -o client 
 3. ./client
 ```
   

### Contributors

- Mehtaab Singh
- Rahul Sajnani
