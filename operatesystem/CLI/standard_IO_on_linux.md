# Standard IO on linux
## 1. What is standard IO ?
- Standard IO include standard input, standard ouput and standard error  
- Standard input usually is terminal emulator or keyboard terminal or console  
- Standard output usually is a file or device terminal like screen  
- Standard error usually is a file or block device like `/dev/null`  
## 2. How to redirect standard IO ?
### 2.1 Use pipe
- `|` is a pipe command direct the output of preceding command as input to   
    the succeeding command  
### 2.2 Use redirect operator
- `>` redirect standard output  
- `>>` is same to `>` but appending  
- `<` redirect standard input  
- `0` stand for standard input, `1` stand for stand output and  
    `2` stand for standard error  
