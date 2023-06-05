# du command
## 1. What does du command do ?
- `du` command estimate file space usage  
## 2. Synopsis
- Syntax  
    ```
    du [OPTION...] [FILE...]
    du [OPTION...] --file0-from=F
    ```
- Description  
    - Summarize device usage of the set of FILEs, recursively for directories  
## 3. Options
### 3.1 Search scope control 
- `--exclude=PATTERN` : exclude files than match PATTERN  
- `-X, --exclude-from=FILE` : exclude files that match any pattern in FILE  
- `-t, --threshold=SIZE` : exclude entries smaller that SIZE if positive,  
    or entries greater than SIZE if negative  
- `-x, --one-file-system` : skip directories on different file systems  
- `--files0-from=F` : summarize divece usage of the NUL-terminated file  
    names in file F; if F is -, then read names from standard input  
- `-D, --dereference-args` : dereference only symlinks that are listed  
    on the command line  
- `-H` : equivalent to `--dereference-args`  
- `-L, --dereference` : dereference all symbol links  
- `-l, --count-links` : count sizes many times if hard linked  
- `-P, --no-dereference` : don't follow any symbolic links (*this is default*)  
### 3.2 Generate output control
- `--apparent-size` : print apparent size rather than device usage  
- `-a, --all` : write counts for all files, not just directories  
- `-s, --summarize` : display only a total for each argument  
- `-d, --max-depth=N` : print the total for a directory (or file, with `--all`)  
    only if it is N or fewer levels below the command line argument  
- `-S, --separate-dirs` : for directories do not include size of subdirectories  
- `--inode` : list inode usage information instead of block usage  
- `-h, --human-readable` : print the sizes in human readable format(e.g., 1K 235M 2G)  
- `--si` : like `-h`, but use powers of 1000 not 1024  
- `-B, --block-size=SIZE` : scale size by SIZE before printing them; e.g., `-BM` prints  
    sizes in units of 1,048,576 bytes  
    The SIZE argument is an integer and optional unit (example : 10K is 10 * 1024)  
    Unit are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB... (powers of 1000). Binary  
    prefixes can be used, too: KiB=K, MiB=M, and so on.  
- `-b, --byte` : equivalent to `--apperent-size --block-size=1`  
- `-k` : like `--block-size=1K`  
- `-m` : like `--block-size=1M`  
- `-0, --null` : end each output line with NUL, not newline  
- `-c, --total` : produce a grand total  
- `--time` : show time of the last modification of any file in the directory, or any  
    of its subdirectories  
