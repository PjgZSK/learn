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

"system
if has("win32") || has("win64")
    winpos 50 50
    set lines=40 columns=155
    noremap <leader>cd :!start %:h<cr>
    "python
    set pythonthreedll=python38.dll
    set guifont=Consolas:h20
    set shell=\"C:\Program\ Files\Git\git-bash\"
    " PlugUpdate
    command! MyPlugUpdate   :set shell=cmd.exe shellcmdflag=/c noshellslash guioptions-=! <bar> noau PlugUpdate
    " PlugInstall
    command! MyPlugInstall  :set shell=cmd.exe shellcmdflag=/c noshellslash guioptions-=! <bar> noau PlugInstall
    " PlugClean
    command! MyPlugClean    :set shell=cmd.exe shellcmdflag=/c noshellslash guioptions-=! <bar> noau PlugClean
    set encoding=utf-8   
    set rop=type:directx,gamma:1.0,contrast:0.5,level:1,geom:1,renmode:4,taamode:1
else
    set guifont=Monaco:h18
    set shell=/bin/zsh
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
autocmd BufNewFile,BufRead *.sh set filetype=sh 
autocmd BufNewFile,BufRead *.h set filetype=cpp 
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
        if expand("%:e") == 'h'
            let upperFileName = toupper(expand("%:t:r"))
            call append(line(".")+6, "#ifndef __".upperFileName."_H__")
            call append(line(".")+7, "#define __".upperFileName."_H__")
            call append(line(".")+8, "#endif /*__".upperFileName."_H__*/")
        endif
    endif
    if &filetype == 'c'
        call append(line(".")+6, "#include")
        call append(line(".")+7, "")
    endif
endfunc
autocmd BufNewFile * normal G

"vim-plug
call plug#begin()
Plug 'altercation/vim-colors-solarized'
Plug 'ervandew/supertab'
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install() }, 'for': ['markdown', 'vim-plug']}
Plug 'ycm-core/YouCompleteMe',{ 'for' : ['c', 'cpp'] }
Plug 'preservim/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'godlygeek/tabular' "必要插件，安装在vim-markdown前面
Plug 'tpope/vim-fugitive'
Plug 'plasticboy/vim-markdown'
Plug 'mzlogin/vim-markdown-toc'
Plug 'SirVer/ultisnips'
Plug 'majutsushi/tagbar', { 'on': 'TagbarToggle' }
Plug 'vim-airline/vim-airline-themes'
Plug 'vim-airline/vim-airline'
call plug#end()

"color
set t_Co=256
syntax enable
set background=dark
colorscheme solarized

"markdowm
set cocu=vc
set conceallevel=2
let g:vim_markdown_math = 1
let g:vim_markdown_conceal_code_blocks = 0
let g:vim_markdown_folding_style_pythonic = 1
let g:vim_markdown_folding_level = 1
"let g:vim_markdown_folding_disabled = 1
"设置tab键为触发键
let g:UltiSnipsExpandTrigger = '<tab>'
"设置向后跳转键
let g:UltiSnipsJumpForwardTrigger = '<tab>' 
"设置向前跳转键
let g:UltiSnipsJumpBackwardTrigger = '<S-tab>' 
"设置文件目录
let g:UltiSnipsSnippetDirectories=["path/of/snippetDirectories"]
"设置打开配置文件时为垂直打开
let g:UltiSnipsEditSplit="vertical"
let g:vmt_auto_update_on_save = 0
let g:vim_markdown_math = 1

" tag bar
nmap <F8> :TagbarToggle<CR>
let g:tagbar_autoclose = 1
"设置tagber对于markdown的支持
let g:tagbar_type_markdown = {
  \ 'ctagstype'	: 'markdown',
  \ 'kinds'		: [
    \ 'c:chapter:0:1',
    \ 's:section:0:1',
    \ 'S:subsection:0:1',
    \ 't:subsubsection:0:1',
    \ 'T:l4subsection:0:1',
    \ 'u:l5subsection:0:1',
  \ ],
  \ 'sro'			: '""',
  \ 'kind2scope'	: {
    \ 'c' : 'chapter',
    \ 's' : 'section',
    \ 'S' : 'subsection',
    \ 't' : 'subsubsection',
    \ 'T' : 'l4subsection',
  \ },
  \ 'scope2kind'	: {
    \ 'chapter' : 'c',
    \ 'section' : 's',
    \ 'subsection' : 'S',
    \ 'subsubsection' : 't',
    \ 'l4subsection' : 'T',
  \ },
\ }
" air line
let g:airline_extensions = ['branch', 'tagbar']
"不显示文档总字数
let g:airline#extensions#wordcount#enabled = 0
"不显示文件编码（Windows系统）
let g:airline#parts#ffenc#skip_expected_string='utf-8[dos]'
"取消显示warning部分
let g:airline_section_warning = ''
"let g:airline_section_c = airline#section#create(['filetype', 'file'])
"let g:airline_section_x = '' 
"取消显示section_b
"let g:airline_section_b = ''
"section_c显示为tagbar检索出来的标题
"let g:airline_section_c = airline#section#create(['tagbar'])
"section_x显示文件名
"let g:airline_section_x = '%{expand("%")}'
"section_y显示时间
"let g:airline_section_y = airline#section#create(['%{strftime("%D")}'])
"section_z显示日期
"let g:airline_section_z = airline#section#create(['%{strftime("%H:%M")}'])
"激活tagbar扩展
"let g:airline#extensions#tagbar#enabled = 1

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


