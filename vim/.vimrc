"basic
set nocompatible
set showmode
set showcmd
if version >= 603
	set helplang=cn
	set encoding=utf-8
endif

"file
filetype plugin indent on

"indent
set autoindent
set shiftwidth=4
set tabstop=4
if &filetype == 'makefile' || &filetype == 'make'
	set noexpandtab
else
	set expandtab
	set softtabstop=4
endif
"set list

"appearance
set number
set cursorline
set wrap
set wrapmargin=6
set textwidth=500
set laststatus=2
set ruler

"color
set t_Co=256
syntax enable
set background=dark
colorscheme solarized

"system
if has("win32") || has("win64")
    winpos 50 50
    set lines=40 columns=155
    noremap <leader>cd :!start %:h<cr>
    "python
    set pythonthreedll=python38.dll
    "set pythonthreehome="C:\Program Files\Python38"
    "set pythonhome='C:\Python27'
    set guifont=Consolas:h12
else
    set guifont=Monaco:h18
endif

"clipboard
set clipboard=unnamed

"IM
if has("gui_running")
    set imactivatekey=C-space
    inoremap <ESC> <ESC>:set iminsert=2<CR>
endif

"keymap
imap <C-s> <ESC>:w<CR>a
imap <S-Up> <ESC>V
imap <S-Down> <ESC>V
imap <S-Left> <ESC>V
imap <S-Right> <ESC>V
vmap <C-c> "+y
vmap <C-v> "+p
imap <C-v> <C-r>+
"C，C++ 按F5编译运行
map <F5> :call CompileRunGcc()<CR>
func! CompileRunGcc()
	exec "w"
	if &filetype == 'c'
		exec "!g++ % -o %<"
		exec "!time ./%<"
	elseif &filetype == 'cpp'
		exec "!g++ % -std=c++11 -o %< && ./%<"
	elseif &filetype == 'java' 
		exec "!javac %" 
		exec "!time java %<"
	elseif &filetype == 'sh'
		:!time bash %
	elseif &filetype == 'python'
		exec "!time python2.7 %"
    elseif &filetype == 'html'
        exec "!firefox % &"
    elseif &filetype == 'go'
"        exec "!go build %<"
        exec "!time go run %"
    elseif &filetype == 'mkd'
        exec "!~/.vim/markdown.pl % > %.html &"
        exec "!firefox %.html &"
	endif
endfunc
"C,C++的调试
map <F8> :call Rungdb()<CR>
func! Rungdb()
	exec "w"
	exec "!g++ % -std=c++11 -g -o %<"
	exec "!gdb ./%<"
endfunc


"command line
set wildmenu
set wildmode=longest:list,full

"key
set backspace=indent,eol,start

"search
set showmatch
set hlsearch
set ignorecase
" 当光标一段时间保持不动了，就禁用高亮
"autocmd cursorhold * set nohlsearch
" 当输入查找命令时，再启用高亮
"noremap n :set hlsearch<cr>n
"noremap N :set hlsearch<cr>N
"noremap / :set hlsearch<cr>/
"noremap ? :set hlsearch<cr>?
"noremap * *:set hlsearch<cr>
noremap n :set hlsearch<cr>n
noremap N :set hlsearch<cr>N
noremap / :set hlsearch<cr>/
noremap ? :set hlsearch<cr>?
noremap * *:set hlsearch<cr>

nnoremap <c-h> :call DisableHighlight()<cr>
function! DisableHighlight()
        set nohlsearch
    endfunc

"automatic insertion head
autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()"
func SetTitle()
    if &filetype == 'sh'
        call setline(1,"\#########################################################################")
        call append(line("."), "\# File Name: ".expand("%"))
        call append(line(".")+1, "\# Author: pjg")
        call append(line(".")+2, "\# mail: ")
        call append(line(".")+3, "\# Created Time: ".strftime("%c"))
        call append(line(".")+4, "\#########################################################################")
        call append(line(".")+5, "\#!/bin/bash")
        call append(line(".")+6, "")
    else
        call setline(1, "/*************************************************************************")
        call append(line("."), "    > File Name: ".expand("%"))
        call append(line(".")+1, "    > Author: pjg")
        call append(line(".")+2, "    > Mail: ")
        call append(line(".")+3, "    > Created Time: ".strftime("%c"))
        call append(line(".")+4, " ************************************************************************/")
        call append(line(".")+5, "")
    endif
    if &filetype == 'cpp'
        "call append(line(".")+6, "#include <iostream>")
        "call append(line(".")+7, "using namespace std;")
        "call append(line(".")+8, "")
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include")
        call append(line(".")+7, "")
    endif
endfunc
autocmd BufNewFile * normal G

"dict
" autocmd FileType markdown set dictionary+=~/.vim/dict/md.dict

"vundle
"set rtp+=~/.vim/bundle/Vundle.vim
"call vundle#begin()
"Plugin 'VundleVim/Vundle.vim'
"Plugin 'scrooloose/nerdtree'
"Plugin 'altercation/vim-colors-solarized'
"Plugin 'SuperTab'
"Plugin 'iamcco/markdown-preview.nvim'
"Plugin 'YouCompleteMe'
"call vundle#end()

"vim-plug
call plug#begin()
Plug 'ervandew/supertab'
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install() }, 'for': ['markdown', 'vim-plug']}
Plug 'ycm-core/YouCompleteMe',{ 'for' : ['c', 'cpp'] }
Plug 'preservim/nerdtree'
Plug 'Xuyuanp/nerdtree-git-plugin'
call plug#end()

"nerdtree
nnoremap <leader>n :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>
" Start NERDTree. If a file is specified, move the cursor to its window.
" autocmd StdinReadPre * let s:std_in=1
" autocmd VimEnter * NERDTree | if argc() > 0 || exists("s:std_in") | wincmd p | endif
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
" 不显示这些文件
let NERDTreeIgnore=['\.filters$[[file]]', '\.user$[[file]]', '\.vcxproj$[[file]]', '\.dir$[[dir]]', '\.pdb$[[file]]', '\.ilk$[[file]]'] "ignore files in NERDTree
" 不显示项目树上额外的信息，例如帮助、提示什么的
" let NERDTreeMinimalUI=1

"nerdtree-git
" let g:NERDTreeGitStatusShowIgnored = 1 " a heavy feature may cost much more time. default: 0
let g:NERDTreeGitStatusIndicatorMapCustom = {
                    \ 'Modified'  :'*',
                \ 'Staged'    :'+',
                \ 'Untracked' :'-',
                \ 'Renamed'   :'->',
                \ 'Unmerged'  :'=',
                \ 'Deleted'   :'x',
                \ 'Dirty'     :'!',
                \ 'Ignored'   :'^',
                \ 'Clean'     :':',
                \ 'Unknown'   :'?',
                \ }

"auto complete
set completeopt=longest,menu

"clangd
" Let clangd fully control code completion
let g:ycm_clangd_uses_ycmd_caching = 0
" Use installed clangd, not YCM-bundled clangd which doesn't get updates.
let g:ycm_clangd_binary_path = exepath("clangd")


