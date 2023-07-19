# Minitalk

Is a comunication program between client and server using UNIX signals.</br>
SCREEEN
</br>

## Installing and running the project:

1- Clone the repo:
  
  ```sh
  git clone https://github.com/startaglia/minitalk.git minitalk
  ```

2- Enter in minitalk dir and compile the program with the `make` command
	
 ```
  cd minitalk
  make
 ```

It's a project written on Linux, to make it work on MAC you have to replace `intptr_t` with `uintptr_t` </br></br>

4- Run the server and copy its PID to the client, then write the message you want to send.

	./server
	./client <server_PID> <message>
    
### Makefile Available Targets:  
`make` or `make all` - Makes _client_ and _server_  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes the executables and all the resulting object files  
`make re` - fclean + all  
</br></br>

## Technologies Used:

- **Programming Language**: C
- **Operating System**: Linux
- **Compiler**: GCC (GNU Compiler Collection)
- **Build System**: GNU Make
- **C Standard Library**
- **Signal Handling**: Standard library functions from `signal.h`
- **Command Line Arguments Handling**: Techniques such as `argc`/`argv`

## Authors:

- **Simone Tartaglia**
  - Email: [startaglia89@gmail.com](mailto:startaglia89@gmail.com)
  - GitHub: [startaglia](https://github.com/startaglia)
  - LinkedIn: [Simone Tartaglia](https://www.linkedin.com/in/simone-tartaglia-134723248/)
