# pipex
This project is about handling pipes

## Mandatory part
the program `pipex` should be executed as follows:
```
 $> ./pipex file1 cmd1 cmd2 file2
```
It must behave exactly the same as the shell command below:
```
 $> < file1 cmd1 | cmd2 > file2
```
All errors like: wrong commands, permission to files and etc, need be handle.

## Bonus part
`pipex`'s program should handle multiple pipes:
```
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
it must behave like :
```
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
and support `«` and `»` when the first parameter is "here_doc":
```
$> ./pipex here_doc LIMITER cmd cmd1 file
```
should behave like:
```
cmd << LIMITER | cmd1 >> file
```
## Ressources
- [Unix Processes in C](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)
- [Process management](https://www.youtube.com/watch?v=OrM7nZcxXZU&list=PLBlnK6fEyqRgKl0MbI6kbI5ffNt7BF8Fn)
- [Unix Pipeline (Brian Kernighan) - Computerphile](https://www.youtube.com/watch?v=bKzonnwoR2I)
