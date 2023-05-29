
<!-- vim-markdown-toc GFM -->

* [Python Regular](#python-regular)
    * [1. Introdution](#1-introdution)
        * [1.1 What is a regular ?](#11-what-is-a-regular-)
        * [1.2 What is a python regular ?](#12-what-is-a-python-regular-)
    * [2. Regular Expression Syntax](#2-regular-expression-syntax)
        * [2.1 Special Characters](#21-special-characters)
            * [2.1.1 Raw Special Characters](#211-raw-special-characters)
            * [2.1.2 Special Sequence](#212-special-sequence)
        * [2.2 Extension Notation](#22-extension-notation)
    * [3. Python Regular Object](#3-python-regular-object)

<!-- vim-markdown-toc -->

# Python Regular
## 1. Introdution
### 1.1 What is a regular ?
- A regular is a string which can be explained by a regular interpreter.  
- A regular is a rule which you can use to match a given string.  
- A lots of special Characters used by the regular.  
- Some special Characters are composed by normal Characters, and some normal  
    Characters are interpreted by interpreter as special Characters which means  
    you must use some special Characters for show those normal Characters.  
### 1.2 What is a python regular ?
- A regular is explained by a python regular interpreter.  
## 2. Regular Expression Syntax
### 2.1 Special Characters
#### 2.1.1 Raw Special Characters
- Raw special characters:  
```
.
        dot, match any character
^
        match the start of the string
$
        match the end of the string
*
        match 0 or more repetitions of the preceding RE
+
        match 1 or more repetitions of the preceding RE
?
        match 0 or 1 repetitions of the preceding RE
{m}
        match m repetitions of the preceding RE
{m,n}
        match from m to n repetitions of the preceding RE, match as many repetitions as possible
{m,n}?
        same to {m,n}, but match as few repetitions as possible
{m,n}+
        same to {m,n}, but without establishing any backtracking points.
        for example, with 'aaaaaa' string, re 'a{3,5}aa' match and re
        'a{3,5}+aa' not match.
[]
        indicate a set of characters. In a set:
            * characters can be listed, like [amk] match 'a', 'm' or 'k'
            * range of characters, like [a-z0-9A-Z] match a~z,0~9 and A~Z
            * special character invalid, like [+*] match '+' or '*'
            * character classes such as '\w' or '\S'(defined below)
            * opposite the range. for example, [^z] will match any character except 'z'
|
        A|B, match either A or B, test A first
(...)
        sub regular group, the mache result can be retrieved by '\number' 
        special sequence after match
(?...)
        extension notation, for example, (?#...) is a comment
\
        either escape special character, or signals a special sequence. for
        example, '\$' match '$' and '\d' is a character class
```
#### 2.1.2 Special Sequence 
- Escape special character  
```
\special character
        escape special character, for example, '\$' match '$'
```
- Character classes  
```
\number
        the result of sub regular group number(start with 0),
        for example, '(.+) \1' match 'the the' or '55 55'
\A
        match the start of the string
\Z
        match the end of the string
\b
        match the empty string, but only at the begining or end 
        of a word.
\B
        match the empty string, but not only at the beginning or end
        of a word
\d
        match decimal digit
\D
        match except decimal digit
\s
        match whitespace characters include [\t\n\r\f\v] and many other characters
\S
        match except whitespace characters
\w
        match word characters include [a-zA-Z0-9_]
\W
        match except word character
```
### 2.2 Extension Notation
- Extension notation standard syntax  
```
(?...)
```
- Extensions  
```
(?#...)
        comment
(?=...)
        lookahead assertion, matched if ... test pass but not consume any of string
(?!...)
        negative lookahead assertion, matched if ... test failed but not consume any
        of string
(?<=...)
        positive lookbehind assertion
(?<!...)
        negative lookbehind assertion
(?P<name>)
        group name
(?P=<name>)
        call group named 'name'
```
## 3. Python Regular Object
- match  
```
match.group(index)      get group result by group index(start with 1)
match.group(name)       get group result by group name
```

