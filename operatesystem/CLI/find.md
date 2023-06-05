# find command
## 1. What does find command do ? 
- search for files in a directory hierarchy  
## 2. Synopsis
### 2.1 Syntax
```
find [-H] [-L] [-P] [-D debugopts] [-Olevel] [starting-point...] [expression]
```
### 2.2 Description
- This manual page documents the GNU version of find  
- GNU find searches each directory tree rooted at each given starting-point by  
    evaluating the given expression from left to right, according to the rules of  
    precedence, until the outcome is know(the left hand side is false for and operation,  
    true for or), at which point `find` moves on to the next file name.  
- If no starting-point is specified, '.' is assumed.  
### 2.3 Options
- The `-H, -L and -P` control the treatment of symbolic links. Command-line arguments following  
    these are token to be names of files or directories to be examined, up to the first argument  
    that begins with '-', or the argument '(' or '!'. That argument and following arguments are  
    token to be the expression describing what is to be searched for.  
- If no paths are given, the current directory is used.  
- If no expression is given, the expression `-print` is used(but you should probably consider using  
    `-print0` instead, anyway)  
- `-P` : never follow symblic links  
- `-L` : follow symblic links  
- `-H` : don't follow symblic links, except while process command line arguments  
- `-D debugopts` : print diagnostic information  
- `-Olevel` : enable query optimisation  
### 2.4 Expression
- The part of the command line after the list of starting points is the *expression*.  
- This is kind of query specification describing how we match files and what we do  
    with the file that were matched  
- An expression is composed of a sequence of things :  
    - Tests  
        - Tests return a true or false value, usaully on the basis of some property of  
            a file we are considering. The `-empty` test for example is true only when  
            current file is empty  
    - Actions  
        - Actions have side effects(such as printing something on the standard output) and  
            return either true or false, usually based on whether or not they are successful.  
            The `-print` action for example prints the name of the current file on the standard ouput.  
    - Global options  
        - Global options affect the operation of tests and actions specified on any part of the  
            command line. Global options always return true. The `-depth` option for example makes  
            `find` traverse the file system in depth-first order.  
    - Positional options  
        - Positional options affect only tests and actions which following them. Positional options  
            always return true. The `-regextype` option for example is positional, specifying the  
            regular expression dialect for regular expressions occurring later on the command line.   
    - Operators  
        - Operators join together the other items within the expression. They include for example `-o`  
            (meaning logical OR) and `-a`(meaning logical AND). Where an operator is missing, `-a` is  
            assumed.  
- The `-print` action is preformed on all files for which the whole expression is true, unless it contains  
    an action other than `-prune` or `-quit`.  
#### 2.4.1 Positional options
Position always return true. They affect only tests occurring later on the command line  
- -daystart  
    - Measure times(for `-amin`, `-atime`, `-cmin`, `-ctime`, `-mmin`, and `-mtime`) from  
        the beginning of today rather than from 24 hours ago.  
- -warn, -nowarn  
    - Turn warning message on or off.  
#### 2.4.2 Global options 
Global options always return true. To prevent confusion, global options should be specified on  
the command-line after the list of start points, just before the first test, positional option or  
action.  
- -depth  
    - Process each dirctory's contents before the directory itself  
- -d  
    - A synonym for `-depth`, for compatibility with FreeBSD,NetBSD,MaxOS X and OpenBSD  
- files0-from *file*  
    - Read starting points from *file* instead of the command line  
- -help, --help  
    - Print a summary of the command-line usage of `find` and exit  
- -maxdepth *levels*  
    - Descend at most *levels* level of directories below the starting-points  
- -mindepth *levels*  
    - Do not apply any tests or actions at levels less than *levels*  
- -version, --version  
    - Print the `find` version and exit  
#### 2.4.3 Tests
Some test, for example `-newerXY` and `-samefile`, allow comparsion between  
the file currently being examined and some reference file specified on the  
command line.   

A numeric argument *n* can be specified to tests(like `-amin, -mtime, -gid,  
-inum, -perm, -links, -size, -uid and -used`) as  
- *+n*    for greater than *n*  
- *-n*    for less than *n*  
- *n*     for exactly *n*  

- `-regex pattern`  
    - File name matches regular expression pattern  
- `-name pattern`  
    - Base of file name matches shell pattern *pattern*  
- `-size n[cwbkMG]`  
    - 'b' for 512-byte blocks(this is default if no suffix is used)  
- `-type c`  
    - File is of type c  
    - 'b'    block(buffered) special  
    - 'c'    charater(unbuffered) special  
    - 'd'    directory  
    - 'p'    named pipe(FIFO)  
    - 'f'    regular file  
    - 'l'    symblic link  
    - 's'    socket  
    - 'D'    door(Solaris)  
- `-xtype c`  
    - The same as `-type` unless the file is a symblic link.  
#### 2.4.3 Actions
- `-delete`  
    - Delete files or directories; true if removal succeeded. The `-delete` action  
        will fail to remove a directory unless it is empty  
- `exec command ;`  
    - Execute command; true if 0 status is returned. The string '{}' is replaced  
        by the current file name  
- `exec command {} +`  
    - The variant of the `-exec` action runs the specified command on the selected files  
- `-ls`  
    - True;list current file in `ls -dils` format on standard output  
- `-fls file`  
    - True; like `-ls` but write to *file*  
- `print`  
    - True; print the full file name on the standard output, followed by a newline.  
- `print0`  
    - True; same as `print` but followed by a null character  
- `printf format`  
    - True; print *format* on the standard output  
### 2.5 Operators
Listed in order of descreasing precedence:  

- ( expr )  
- ! expr  
- -not expr  
- expr1 expr2  
- expr1 -a expr2  
- expr1 -and expr2  
- expr1 -o expr2  
- expr1 -or expr2  
- expr1 , expr2  
## 3. Example
1. Simple *find|xargs* approach  
    - Find file named *core* in or below the directory */tmp* and delete them  
        > `find \tmp -name core -type f -print | xargs rm -f`  

        Note that this will work incorrectly if there are any filenames containing  
        newlines, single or double quotes, or space.  
2. Safer *find -print0 | xargs -0* approach  
    - Files or directory names containing single or double quotes, spaces or  
        newlines are correctly handled  
        > `find /tmp -name core -type f -print0 | xargs -0 rm -f`  

3. Processing arbitrary starting points  
 - Given that another program *proggy* pre-filters and creates a huge NUL-separated list  
    of files, process those starting points, and find all regular, empty files among them :  
    > `proggy | find -files0-from - -maxdepth 0 -type f -empty`  

4. Executing a command for each file  
    - Run *file* on every file in or below the current directory.  
    > `find . -type f -exec file '{}' \;`

    Notice that the braces are enclosed in single quote marks to protect them from  
    interpretation as shell script punctuation  
    The semicolon is similarly protected by the use of a backslash, though single  
    quote could have been used in that case also  
[find manual page](https://man7.org/linux/man-pages/man1/find.1.html)

