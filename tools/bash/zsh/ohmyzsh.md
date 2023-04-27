# oh my zsh
## 1. introduction
* zsh completion scripts collection
* [github](https://github.com/zsh-users/zsh-completions)

## 2. install
* clone the repository  
    `git clone https://github.com/zsh-users/zsh-completions.git`
* include the rep to your `$fpath`, in `~/.zshrc` add below code:  
    `  fpath=(path/to/zsh-completions/src $fpath)`
* rebuild `zcompdump`  
    `rm -f ~/.zcompdump; compinit`
