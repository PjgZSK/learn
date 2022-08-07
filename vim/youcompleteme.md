# youcompleteme/mac
## 1.install vundle
## 2.compile ycm

* install dependence
    
    > brew install cmake
    
    > brew install python3

* clone ycm

    > cd ~/.vim/bundle
    
    > git clone https://github.com/ycm-core/YouCompleteMe.git

* update submodule

    > git submodule update --init --recursive

* compile ycm

    > cd ~/.vim/bundle/YouCompleteMe

    > python3 install.py --clangd-completer

    run`python3 install.py --help`to choose support language options

## 3.vimrc
* vundle
    > Plugin 'YouCompleteMe'

* ycm
    > " Let clangd fully control code completion  
    > let g:ycm_clangd_uses_ycmd_caching = 0
    
    > " Use installed clangd, not YCM-bundled clangd which doesn't get updates.  
    > let g:ycm_clangd_binary_path = exepath("clangd")

## 4.ycm command
* auto fix
    
    > :YcmCompleter FixIt

* goto
    
    > :YcmCompleter GoTo

* rename

    > :YcmCompleter RefactorRename
