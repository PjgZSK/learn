# file command
## normal use
1. collect specific file  
```
file(GlOB var "*.cpp" "*.c")
file(GlOB var RELATIVE relative_path  "*.cpp" "*.c")
```
2. with recurse
```
file(GlOB_RECURSE var "*.cpp" "*.c")
file(GlOB_RECURSE var RELATIVE relative_path  "*.cpp" "*.c")
```
## actual work
1. file collect all file in current dir, and match the regex expression you give.  
2. file without recurse will force match the prefix of the regex expressio you give,  
for example, the files of file collect is "a/1.cpp 1.cpp", if file without recurse,  
the regex expression "*.cpp" only match "1.cpp", and not match "a/1.cpp", but file  
with recurse will match all -- "1.cpp" and "a/1.cpp".
