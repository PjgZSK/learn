# Git clean
## 1. What is git clean ?
- `git clean` is a git command which remove untracked file in git tree.  
- Usually only the file git don't know will be removed.  
## 2. How to use ?
- CLI
```
git clean -- <path>
```
## 3. Options
- `-d` -- remove directory  
- `-f` -- force remove  
- `-x` -- remove ignore files(ignore files does't remove without this option)  
- `-n` -- show files which will be removed  
