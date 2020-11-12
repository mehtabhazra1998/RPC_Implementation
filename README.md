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

   

### Contributors

- Mehtaab Singh
- Rahul Sajnani