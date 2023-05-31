# How to find large file with CLI ?
## 1. Prepose command
### 1.1 du command
#### 1.1.1 What does du command ?
- `du` command show the size of file within a file tree recirclely.  
#### 1.1.2 Options
- `a` -- all file, include hidden files.  
- `s` -- summarize, only show the value of root file.  
- `h` -- human-readable.  
- `b` -- use byte as size unit.  
- `k` -- use kb as size unit.  
- `m` -- use mb as size unit.  
- `B` -- result show unit.  
- `*` -- sub files under current path, not include hidden files.  
#### 1.1.3 Example  
- `du -sh *`  
- `du -sh ./*/`  
### 1.2 find command
#### 1.2.1 What does find command ?
- `find` command find files under specified terms.  
#### 1.2.2 Options
- `type` -- f represent normal file, d represent directory,  
    l represent link symbol, s represent socket.  
- `name` -- match file name, support simple regular character like "*".  
- `iname` -- same to `name`, but ignore case.  
- `path` -- match path, support simple regular.  
- `regex` -- match path, support regular.  
- `iregex` -- same to `regex`, but ignore case.  
- `maxdepth` -- max depth.  
- `mindepth` -- min depth.  
- `size` -- match file size.  
```
// case sensitive
b -- byte
c -- char
w -- word(2 char)
k -- kb
M -- mb
G -- gb

+ -- more than
- -- less than
  -- equal than 

// find file which size more than 100mb
find . +100M
```
- `delete` -- delete match file.  
- `!` -- nagative term.  
- `exec` -- follow other command.  
- time stamp  
    - access time : `atime` and `amin`  
    - modify time : `mtime` and `mmin`  
    - change time : `ctime` and `cmin`  
    - `time`'s unit is day, and `min`'s unit is minute.  
    - example  
        ```
        // before time flag
        + -- more than
        - -- less than
          -- equal than

        // find file which last access time more than 7 day ago
        find . -atime +7
        // find file which last access time less than 7 day ago
        find . -atime -7
        // find file which last access time equal than 7 day ago
        find . -atime 7
        ```
- permissions 
    - `perm` -- access permission  
    - `user` -- user permission  
    - `group` -- group permission  
- `prune` -- ignore specific path  
```
find . -path "ignore path" -prune -name "*.txt"
```
