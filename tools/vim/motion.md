
<!-- vim-markdown-toc GFM -->

* [Motion In Vim](#motion-in-vim)
    * [1. Operator And Motion](#1-operator-and-motion)
        * [1.1 What Is A Operator ?](#11-what-is-a-operator-)
        * [1.2 What Is A Motion ?](#12-what-is-a-motion-)
    * [2. Operator](#2-operator)
    * [3. Visual Mode](#3-visual-mode)
    * [4. Motion](#4-motion)
        * [4.1 Left-right Motions](#41-left-right-motions)
        * [4.2 Up-down Motions](#42-up-down-motions)
        * [4.3 Word Motions](#43-word-motions)
        * [4.4 Object Motions](#44-object-motions)
        * [4.5 Text Object Selection](#45-text-object-selection)
        * [4.6 Mark Motions](#46-mark-motions)
        * [4.7 Jump Motions](#47-jump-motions)
        * [4.8 Various Motions](#48-various-motions)

<!-- vim-markdown-toc -->
# Motion In Vim
## 1. Operator And Motion
### 1.1 What Is A Operator ?
- The operator in vim is a command which can change the state of vim buffer.  
- Those operator exist in visual, normal, command and insert mode.  
- The operator in vim is diverse which there are file operator like `:w`, `:q` or `:wq` in  
    command mode , and there are text operator like `dd`, `yy` or `p` in normal mode.
- In this chapter, we will focus on text operator in normal mode and those operator which  
    can followed by motions.  
### 1.2 What Is A Motion ?
- The alone operator command most contain two parts, one is operator itself, and another  
    is the range of this operator.  
- Of course, the range of operator must have defualt value.  
- The motion determine the range.  
- Some motion can be used independently.   
- Visual mode can be treated as a special motion  
## 2. Operator
- There are some operators which can followed by motions:  
```
    c         change  
    d         delete  
    y         yank into register(does not change the text)  
    ~         swap case  
    g~        swap case  
    gu        make lowercase
    gU        make uppercase
    gq        text formatting
    gw        text formatting without cursor movement
    >         shift right
    <         shift left
    zf        define a fold
```
- Use cases  
```
    d3w     --   op:d, motion:w, delete 3 word.
    2d3w    --   delete 2 * 3 = 6 words.
    dd      --   delete one line
    2d3d    --   delete 2 * 3 = 6 lines
```
## 3. Visual Mode
- In visual mode, the selected text is a special motion which can be operated by  
    operator command.  
- This allows much more freedom, but requires more key strokes and has limited redo  
    functionality.  
## 4. Motion
### 4.1 Left-right Motions
- Base Left-right motions:  
```
    h        character to the left
    l        character to the right
    0        to the first character of the line
    ^        to the first non-blank character of the line
    $        to the end character of the line
    g_       to the last non-blank character of the line
```
- Advanced Left-right motions:  
```
    f{char}        To n'th occurrence of {char} to the right
    F{char}        To n'th occurrence of {char} to the left
    t{char}        Till before n'th occurrence of {char} to the right
    T{char}        Till before n'th occurrence of {char} to the left 
    ;              Repeat latest f,t,F,T n times
    ,              Repeat latest f,t,F,T in opposite direction n times
```
### 4.2 Up-down Motions
- Most commonly used motions:  
```
    k/j       lines upward/downward
    G         goto line n, default last line
    gg        goto line n, default first line
    {n}%      go to {n} percentage in the file
```
### 4.3 Word Motions
- Most commonly used motions:  
```
    w/b       word forward/backward
    e         forward to the end of word
```
### 4.4 Object Motions
- Most commonly used motions:  
```
    (/)       sentence backward/forward
    {/}       paragraph backward/forward
    [[/]]     section backward/forward
```
### 4.5 Text Object Selection
- This is a series of commands that can only be used while in visual mode or after an operator.  
- Commands:  
```
    aw       a word
    iw       inner word
    as       a sentence
    is       inner sentence
    ap       a paragraph
    ip       inner paragraph
```
### 4.6 Mark Motions
- Jumping to a mark can be done in two ways:  
```
`
or
'
```
- Most commonly used motions:  
```
    m{a-zA-Z}      set mark {a-zA-Z}
    :marks         list all the current marks
    :delm{marks}   delete specified marks
    :delm!         delete all marks
```
### 4.7 Jump Motions
- A jump is a command that normally moves the cursor several lines away.  
- The following commands are jump commands:  
```
'
`
G
/
?
n
N
%
(
)
[[
]]
{
}
:s
:tag
L
M
H
the commands that start editing a new file
```
- Jump list select:  
```
    Ctrl-O       previous position in jump list
    Ctrl-I       next position in jump list
    :ju          print the jump list
    :cle         clear the jump list
```
- Change list:  
```
    g;            previous position in change list
    g,            next position in change list
    :changes      print the change list
```
### 4.8 Various Motions
- Most commonly used motions:  
```
    %      match the next item
```
