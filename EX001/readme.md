#Project zombie 001
In short, the way of criating a zombie process is starting a child process with a fork()<br>
and, through a condition ( if(pid == 0) ),making this child process exit ( exit(0) ) <img src="../image/code.png" alt="imagem do codigo">