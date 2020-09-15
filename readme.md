**NOTE: The folder where my a.out file(executable) is present,that directory will be home of my shell.So execute my a.out file from that directory only.**


**Steps to run my code:**

Execute these commands on terminal and not changing directory
1. make
2. ./a.out
3. Now execute commands on my shell

**Explaining different functions(here files) of my shell**

1. **main.c file**
	contains basic I/O func and calls find_func to execute input functions.

2. **find_func**
	This functions basically takes input string completely and divide it into substrings with delimiter ";" with help of function **strtok**.Thus,each substrings is now a one line linux command.Thus,every command is identified and its repective function is called now. 

3. **pwd_func:**
	This function finds the present working directory.

4. **ls_func**
	Contains 2 functions:
	1. f_one for ls,ls -a, ls /path/
	2. f_two for ls -l,ls -al,ls -la

5. **cd_func**
	This function firstly identifies whether the parh given is relative(ex: ~/a/b)
	or absolute.Now,with help of **chdir() function** current directory is changed.


6. **echo_func**
	This functoin handles both cases when input is given as:
	1. echo "bhavesh    shukla" or
	2. echo bhavesh      shukla or
	3. echo "bhavesh"    shukla s 

7. **pinfo_func**
	Simply data from proc/pid/status and proc/pid/exe is retrieved.
	Size,pid,state from proc/pid/status and path from proc/pid/exe.

8. **location_func**
	This function give pwd in relative form to add in form of ~/abc/def/ to match display requirements,whereas pwd_func function prints absolute path of cwd and then gives cwd in realtive form.


9. **relative_path_function**
	Takes any path and converts it into relative path wrt new_home.

10. **prompt func**
	This function finds username,system_name.Then concatenates them to print prompt.

11. **history_func**
	This function prints last 10 given commands.

12. **add_to_history func**
	This function is actually a database that stores latest 20 given commands.

13. **syscmnds_func**
	This function handles background and foreground queries using functions execvp,fork and wait. 

14. **handler func** in main
	This functoin is actually signal_handler function for sigchld signal.
	It prints the recently termainated child process and its pid no.

15. **Makefile**
	To auto compile program.
