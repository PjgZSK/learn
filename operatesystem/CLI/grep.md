
<!-- vim-markdown-toc GitLab -->

* [Grep command](#grep-command)
    * [1. What does grep command do ?](#1-what-does-grep-command-do-)
    * [2. Synopsis](#2-synopsis)
    * [3. Options](#3-options)
        * [3.1 Genaric program infomation](#31-genaric-program-infomation)
        * [3.2 Pattern syntax](#32-pattern-syntax)
        * [3.3 Matching control](#33-matching-control)
        * [3.4 General output control](#34-general-output-control)
        * [3.5 Output line prefix control](#35-output-line-prefix-control)

<!-- vim-markdown-toc -->
# Grep command
## 1. What does grep command do ?
- `grep` command search for patterns in each given file, and print  
    each line that matches a pattern.  
## 2. Synopsis
- syntax  
    ```
    grep [OPTIONS...] PATTERNS [FILE...]
    grep [OPTIONS...] -e PATTERNS [FILE...]
    grep [OPTIONS...] -f PATTERN_FILES [FILE...]
    ```
- description
    - `grep` searches for patterns in each file  
    - `PATTERNS` is one or more patterns separated by newline characters  
    - if no `FILE` given, recursive searches examine the work directory and  
        nonrecursive searches read standard input  
## 3. Options
### 3.1 Genaric program infomation
- `--help` : output a usage infomation and exit  
- `-V, --version` : output the version number of grep and exit  
### 3.2 Pattern syntax
- `-E, --extended-regexp` : interpret `PATTERNS` as extended regular expressions.  
- `-F, --fixed-strings` : interpret `PATTERNS` as fixed strings, not regular expressions.  
- `-G, --basic-regexp` : interpret `PATTERNS` as basic regular expressions, **this is default**.  
- `-P, --perl-regexp` : interpret `PATTERNS` as Perl-compatiable regular expressions.  
### 3.3 Matching control
- `-e PATTERNS, --regexp=PATTERNS` : use `PATTERNS` as the patterns.  
- `-f FILE, --file=FILE` : obtain patterns from FILE, one per line.  
- `-i, --ignore-case` : ignore case distinctions in patterns and input data.  
- `--no-ignore-case` : do not ignore case distinctions in patterns and input data.  
- `-v, --invert-match` : invert the sense of the matching, to select no-matching lines.  
### 3.4 General output control
- `-c, --count` : suppress normal output; instead print a count of matching line for each input file  
- `--color[=WHEN], --colour[=WHEN]` : surround the matched string etc with escape sequence to display  
    them in color on the terminal. The color are defined by the environment variable *GREP_COLORS*.  
    `WHEN` is `never`, `always`, or `auto`.  
- `-L, --files-without-match` : suppress normal output; instead print the name of each input file  
    from which no output would normally have been printed.  
- `-l, --files-with-matches` : suppress normal output; instead print the name of each input file from  
    output would normally have been printed.  
- `-m NUM, --max-count=NUM` : stop reading a file after `NUM` matching lines.  
### 3.5 Output line prefix control
- `-H, --with-filename` : print the file name for each match. This is a default when there is more  
    than one file to search.  
- `-h, --no-filename` : suppress the prefixing of file name on output. This is default when there is   
    only one file to search.  
