version 6.0
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <S-Tab> =BackwardsSnippet()
inoremap <silent> <SNR>18_AutoPairsReturn =AutoPairsReturn()
snoremap <silent> 	 i<Right>=TriggerSnippet()
map  MACROTEXT 
snoremap  b<BS>
nnoremap $ <Nop>
snoremap % b<BS>%
snoremap ' b<BS>'
nmap <silent> ,cc :ErrorAtCursor
nnoremap B ^
nnoremap E $
snoremap U b<BS>U
map Y y$
snoremap \ b<BS>\
snoremap ^ b<BS>^
nnoremap ^ <Nop>
snoremap ` b<BS>`
nmap gx <Plug>NetrwBrowseX
snoremap <Left> bi
snoremap <Right> a
snoremap <BS> b<BS>
snoremap <silent> <S-Tab> i<Right>=BackwardsSnippet()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
inoremap <silent> 	 =TriggerSnippet()
inoremap <silent> 	 =ShowAvailableSnips()
imap JJ 
imap Jj 
imap jj 
let &cpo=s:cpo_save
unlet s:cpo_save
set autoindent
set backspace=indent,eol,start
set backup
set backupdir=~/.vim/backup
set cindent
set copyindent
set directory=~/.vim/tmp
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set ignorecase
set laststatus=2
set matchtime=2
set modelines=0
set mouse=a
set runtimepath=~/.vim,~/.vim/bundle/TabBar,~/.vim/bundle/Vundle.vim,~/.vim/bundle/auto-pairs,~/.vim/bundle/errormarker.vim,~/.vim/bundle/nerdtree,~/.vim/bundle/syntastic,~/.vim/bundle/vim-colors-solarized,~/.vim/bundle/vim-misc,~/.vim/bundle/vim-monokai,~/.vim/bundle/vim-railscasts,~/.vim/bundle/vim-session,~/.vim/bundle/vim-tomorrow-theme,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,~/.vim/after
set scrolloff=4
set shiftwidth=4
set noshowmode
set smartcase
set smarttab
set statusline=%#warningmsg#%{SyntasticStatuslineFlag()}%*
set tabstop=4
set title
set window=0
" vim: set ft=vim :
