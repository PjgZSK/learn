
# Command-chaining operators
## 1. What is command-chainning operator?
- Usually used for linking different commands   
## 2. Common command-chaining operators
### 2.1 The ampersand operator(&)
- By appending the ampersand operator to any command, you dictate the shell  
    to execute that command in the background  
### 2.2 The semicolon operator(;)
- Separating commands and those commands will execute in order  
- Lets try those commands:  
    ```
    pwd ; mkdir test ; cd test ; touch file 
    ```
### 2.3 The or operator(||)
- The or operator will execute the command that follows only if  
    the preceding command fails  
### 2.4 The pipe operator(|)
- The pipe operator directs the output of the preceding command as input  
    to the succeeding command  
### 2.5 The and operator(&&)
- The and operator will execute the command that follows only if  
    the preceding command succeed.  
### 2.6 The not operator(!)
- The not operator works in similar ways to an except statement in programming  
- For example  
    ```
    rm -r path/* !(*.txt)
    ```
- Note that you should enable **extglob** to use invert or nagetive wildcard:  
    ```
    shopt -s extglob
    ```
- Note that charater '!' is used to refer to previous commands on linux,  
    you can turn off this by :  
    ```
    set +H
    ```
### 2.7 The precedence operator((..))
- A command list embedded between parentheses run as a subshell  
### 2.8 The combination operator({..})
- sub command group   
### 2.9 the escape operator(\)
- escape operator  
### 2.10 The redirection operator(>, >>, <)
- `>` redirect standard output  
- `>>` is same to `>` but appending  
- `<` redirect standart input  
