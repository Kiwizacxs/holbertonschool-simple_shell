<h1 align ="center">
<img src="https://holbertonschool.uy/wp-content/themes/holberton/assets/img/logo.png" height="60%" width="50%">
</h1>

### `C - Simple Shell`
Write a simple UNIX command interpreter.

## Decription:
Simple_shell is a standard command interpreter for the system.
In this Readme file we will browse the different main part of this challenge,
which was been the creation of this program.

### `General`

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?


### `List of allowed functions and system calls`

|                                           Commands                                             |
|:-------------------------------|:---------------------------:|--------------------------------:|
| access (man 2 access)          | chdir (man 2 chdir)         |close (man 2 close)              |
| closedir (man 3 closedir)      | execve (man 2 execve)       | exit (man 3 exit)               |
| exit (man 2 _ exit)            | fflush (man 3 fflush)       | fork (man 2 fork)               |
| free (man 3 free)              | getcwd (man 3 getcwd)       | getline (man 3 getline)         |
| getpid (man 2 getpid)          | isatty (man 3 isatty)       | kill (man 2 kill)               |
| malloc (man 3 malloc)          | open (man 2 open)           | opendir (man 3 opendir)         |
| perror (man 3 perror)          | read (man 2 read)           | readdir (man 3 readdir)         |
| signal (man 2 signal)          | stat ( _ xstat) (man 2 stat)| lstat ( __ lxstat) (man 2 lstat)|
| fstat (_ _fxstat) (man 2 fstat)| strtok (man 3 strtok)       | wait (man 2 wait)               |
| waitpid (man 2 waitpid)        | wait3 (man 2 wait3)         | wait4 (man 2 wait4)             |
| write (man 2 write)            | printf                      | fprintf                         |
| vfprintf                       | putchar                     | sprintf

###  `TASKS`

0. README, man, AUTHORS
1. Betty would be proud : a beautiful code that passes the Betty checks
2. Simple shell 0.1 : a UNIX command line interpreter.
3. Simple shell 0.2 : Handle command lines with arguments
4. Simple shell 0.3 : Handle the PATH  /  fork must not be called if the command doesn’t exist
5. Simple shell 0.4 : Implement the exit built-in, that exits the shell / Usage: exit
6. Simple shell 1.0 : Implement the env built-in, that prints the current environment

### `Compilation`

```
* gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

* This fucntion has no return value

```
### Examples of execution:

$ ls -l *.c
. -rw-rw-r-- 1 bilo bilo  319 déc.   5 23:03 _getline.c
. -rw-rw-r-- 1 bilo bilo   89 déc.   2 14:44 logo.c
. -rw-rw-r-- 1 bilo bilo 1464 nov.  10 10:11 print_int.c

### Comande to run man page:

man ./man_1_simple_shell


## Authors
| [<img src="https://avatars.githubusercontent.com/u/135631203?v=4" width=115><br><sub> Franco Doldan </sub>](https://github.com/FrancoDoldan0) |  [<img src="https://avatars.githubusercontent.com/u/124705981?v=4/u/135638564?v=4" width=115><br><sub>Brian de Leon </sub>](https://github.com/Kiwizacxs) |
| :---: | :---: |