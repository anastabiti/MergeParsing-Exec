# Minishell  : This project is about creating a simple shell (bash as reference)




## This project was done in collaboration with my partner [Mohamed Karim](https://github.com/skeet1)
![image](https://user-images.githubusercontent.com/79755743/179492355-c12a875e-6f33-4ee8-be13-2fd24588de67.png)

### Our shell is support the following :
##### ◦ echo with option -n
##### ◦ cd with only a relative or absolute path
##### ◦ pwd with no options
##### ◦ export with no options
##### ◦ unset with no options
##### ◦ env with no options or arguments
##### ◦ Have a working history
##### ◦ Search and launch the right executable 
##### ◦ Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
##### ◦ Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
##### ◦  redirections:  < and > and  << and >>
##### ◦ pipes 
##### ◦ Handle environment variables
##### ◦ Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
##### ◦ Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash




## MANUAL
| Functions     | description           |   
| ------------- |:-------------:|
| readline()      |    readline will read a line from the terminal and return it, using prompt as a prompt.  If prompt is NULL or the empty string, no prompt is issued.  The line returned is allocated with malloc(3); the caller must free it when finished.  The line returned has the final newline removed, so only the text of the line remains.
| ------------- |:-------------:|
| execve()       |    executes the program referred to by pathname.  This  causes the program that is currently being run by the calling  process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments.
| ------------- |:-------------:|
| void rl_clear_history (void)     |    Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list
| ------------- |:-------------:|
|  int rl_on_new_line (void)	     |   Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
| ------------- |:-------------:|
|  void rl_replace_line (const char *text, int clear_undo)    |   Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.
| ------------- |:-------------:|
| void rl_redisplay (void)     |    Change what's displayed on the screen to reflect the current contents of rl_line_buffer.
| ------------- |:-------------:|
|  add_history()      |    to save the line away in a history list of such lines.
| ------------- |:-------------:|
|int access(const char *pathname, int mode)     |   access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.
| ------------- |:-------------:|
| fork()   |     creates a new process by duplicating the calling process. The new process is referred to as the child process.  The calling process is referred to as the parent process.
| ------------- |:-------------:|
| Getcwd()     |    get_current_dir_name - get current working directory
| ------------- |:-------------:|
| chdir()    |    changes the current working directory of the calling process to the directory specified in path.
| ------------- |:-------------:|
| dup2     |    The dup2() system call performs the same task as dup(), but instead of using the lowest-numbered unused file descriptor, it uses the file descriptor number specified in newfd.  In other  words, the file descriptor newfd is adjusted so that it now refers to the same open file description as oldfd.

# REFERENCES
### BEST : https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
### https://www.gnu.org/software/bash/manual/html_node/
### http://www.ulixos.org/publications/ulix-cyron-pipes.pdf
### https://www.geeksforgeeks.org/exit-codes-in-c-c-with-examples/
### https://tldp.org/LDP/abs/html/exit-status.html
### https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10
### https://www.computernetworkingnotes.com/linux-tutorials/differences-between-absolute-path-and-relative-path-in-linux.html
### https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
### https://askubuntu.com/questions/678915/whats-the-difference-between-and-in-bash
### https://www.cs.cornell.edu/courses/cs414/2004su/homework/shell/parse.html
### https://medium.com/dev-genius/lets-build-a-linux-shell-part-i-954c95911501
### https://stackoverflow.com/questions/9449241/where-is-path-max-defined-in-linux
### https://www.scs.stanford.edu/nyu/04fa/sched/readings/rc.pdf
### https://chmodcommand.com/chmod-700/
### https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/getopt.html
### https://app.pluralsight.com/course-player?clipId=cf6cbd74-1491-4350-9ea8-b5894b2e8cbd

