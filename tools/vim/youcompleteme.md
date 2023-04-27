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

* vim-plug
    > Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install() }, 'for': ['markdown', 'vim-plug']}

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

## 5.install on windows
* additional dependences
    > MSVC Build Tools  
    > LLVM for windows

* additional step
    > when you run `install.py`, you can add option `--msvc number` to specify a vs version  
    > `--msvc 15` for vs2017, `--msvc 16` for vs2019, `--help` for more info

    > LLVM for windows depend msvc build tools (default) to acquire system include and system lib  
    > run `your\vs\install\location\Common7\Tools\LaunchDevCmd.bat`, and use llvm in this cmd  
    > (compile or just use gvim open a .cpp if you has configure ycm in vimrc).  
    > it will auto set llvm env in windows.
