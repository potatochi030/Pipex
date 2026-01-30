*This project has been created as part of the 42 curriculum by aoqdeh.*

# Pipex

## Description

Pipex is a system programming project that aims to recreate the behavior of UNIX
pipes using low-level system calls in C.

The program takes an input file, two commands, and an output file as arguments,
then executes the commands in a way that redirects the output of the first command
to the input of the second command, exactly like the shell pipe ( `|` ) operator.

This project focuses on:
- Process creation and management
- Inter-process communication using pipes
- File descriptor manipulation
- Understanding UNIX system calls and error handling

## Instructions

### Compilation

The project is compiled using the provided Makefile. Ensure that the `libft`
library is present in the project directory, then compile the program using:

```bash
make
```
This will generate the `pipex` executable.

### Execution

Run the program using the following format:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

This behaves the same as the shell command:

```bash
< infile cmd1 | cmd2 > outfile
```
The program executes the commands and writes the final output to the specified
output file.
## Resources 

### References

 - [Pipex the 42 project “Understanding Pipelines in C” ~ _PP](https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103) 
 
 - [Unix Processes in C ~ CodeVault](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=SmvlRl-wLfFfVOk6) 
 
 ### AI Usage 
 
 AI tools were used to assist with testing and to explain certain concepts related to the project. AI assistance was limited to clarification and validation purposes. 
 
 All code was written without the use of AI.