<img src="../image/code.png" align="right" width="300">

# Project zombie 001# :zombie:

In short, the way of criating a zombie process is starting a child process with a fork() and, through a condition ( if ( pid == 0 ) ),making this child process exit ( exit(0) ) thus resulting in the zombie process. finally, to leave the code running for or for more than 10 seconds, just complement the code with a repetition structure while(), that will runs the code until the given time.

## How to use ? :gear:
<img src="../image/C-logo-editado.png" align="right" width="300">

Some of the requirements to run and compile this process on your machine :

* Have a development environment for C language
    * GCC
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

Other way of compiling and running the code in your machine is using the Makefile <br>
(Which currently provides an option to compile, run the executable, and delete the executable to not take up space)

For compiling :
```bash

make         " gcc 'NOME DO ARQUIVO'.c -o 'NOME DO EXECUTAVEL'" 

```
For run the executable
```bash

make run     "./'NOME DO EXECUTAVEL'"

```
For remove the executable from the directory
```bash

make clean   "rm 'NOME DO EXECUTAVEL'"

```
And thats it`s :wink: any questions send me a msg on slack!!
