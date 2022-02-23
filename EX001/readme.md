<img src="../image/code.png" align="right" width="300">

# Project zombie 001# :zombie:

In short, the way of criating a zombie process is starting a child process with a fork() and, through a condition ( if ( pid == 0 ) ),making this child process exit ( exit(0) ) thus resulting in the zombie process. finally, to leave the code running for or for more than 10 seconds, just complement the code with a repetition structure while(), that will runs the code until the given time.

## How to use ? :gear:

Some of the requirements to run and compile this process on your machine :

* Have a development environment for C language
    * Gcc 
    * Makefile
    * Vscode
* If you want to contribute 
    * GitHub
    * A Linux operating system 

Talking more about running and compiling this code on your machine, you have the option of compiling in Terminal 

    ```bash

        ~$ gcc "Nome do arquivo".c -o "Nome do execultavel"

    ```

And after the compilation you just have to run the executable that was created by compiling

    ```bash

        ~$ ./"Nome do execultavel"

    ```