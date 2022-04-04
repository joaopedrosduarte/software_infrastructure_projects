# Pipe Process 002#

This process is based on starting to create the variables and writing the pipe message all in the parent process, right after creating the child process and reading into it. In my case the message was just an integer: 9.

## How to use ? :gear:
<img src="./image/C-logo-editado.png" align="right" width="300">

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

~$ gcc "FILE NAME".c -o "EXECUTABLE NAME"

```

And after the compilation you just have to run the executable that was created by compiling

```bash

~$ ./"EXECUTABLE NAME"

```

Other way of compiling and running the code in your machine is using the Makefile <br>
(Which currently provides an option to compile, run the executable, and delete the executable to not take up space)

For compiling :
```bash

make         " gcc 'FILE NAME'.c -o 'EXECUTABLE NAME'" 

```
For run the executable
```bash

make run     "./'EXECUTABLE NAME'"

```
For remove the executable from the directory
```bash

make clean   "rm 'EXECUTABLE NAME'"

```
And thats it`s :wink: any questions send me a msg on slack!!
