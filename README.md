# 42cursus-Minitalk
## :books: About the project
The purpose of this project is to code a small data exchange program using UNIX signals.

## Score
![score](https://user-images.githubusercontent.com/106436743/223189938-c045383f-4b8b-4608-8a96-1c39acb86bf4.jpg)

## :warning: Mandatory
* You must create a communication program in the form of a client and a server.
* The server must be started first. After its launch, it has to print its PID.
* The client takes two parameters:
  - The server PID.
  - The string to send.
* The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
* The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.

## :dart: Bonus 
* The server acknowledges every message received by sending back a signal to the client.
* Unicode characters support!

## :computer: Compiling the project
The library is written in C language and thus needs the -cc compiler and some standard C libraries to run.

**Instruction**
1. Compiling the project

         $ make

2. Execute the program

         $ ./server
         $ ./client "Your message here!"         
         
3. Compiling bonus part

         $ make bonus
         
4. Execute the program

         $ ./server
         $ ./client "Your message here!"   
