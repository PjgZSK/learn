
<!-- vim-markdown-toc GitLab -->

* [Hard link and soft link](#hard-link-and-soft-link)
    * [1. What is hard link and soft link ?](#1-what-is-hard-link-and-soft-link-)
        * [1.1 Hard link](#11-hard-link)
        * [1.2 Soft link](#12-soft-link)
    * [2. How to create hard link or soft link ?](#2-how-to-create-hard-link-or-soft-link-)
        * [2.1 Windows system](#21-windows-system)
        * [2.2 Unix-like system](#22-unix-like-system)

<!-- vim-markdown-toc -->
# Hard link and soft link
## 1. What is hard link and soft link ?
- Hard link and soft link is a special file which is a alias for other file. 
### 1.1 Hard link
- To file system, hard link is same file with the aliased file.  
- This is like a black magic, and every black magics have their bad effect.  
    The bad effect upon hard link is that ${\color{Salmon}git}$ will corrupt  
    hard link because ${\color{Salmon}git}$ doesn't preserve hard links.  
### 1.2 Soft link
- To file system, soft link(also called symbol link) is independent file which  
    store the path to aliased file.  
## 2. How to create hard link or soft link ?
### 2.1 Windows system
- CLI  
```
// hard link
mklink link_path source_path
// soft link
mklink /s link_path source_path
```
### 2.2 Unix-like system
- Like linux or macOS in CLI  
```
// hard link
ln source_path link_path
// soft link
ln -s source_path link_path
```
