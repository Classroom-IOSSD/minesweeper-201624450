" Colors
syntax enable           " enable syntax processing

" Spaces & TABs
set tabstop=4           " number of visual spaces per TAB
set softtabstop=4       " number of spaces in tab when editing
set expandtab           " tabs are spaces
set autoindent          " default indent

" Mouse
set mouse=a             " set mouse mode all
" set mouse-=a          " unset mouse mode all

" UI Configuration
set nu                  " line number
set cursorline          " highlight current line
filetype indent on    " load filetype-specific indent files
set wildmenu            " visual autocomplete for command menu

" Searching
set incsearch           " search as characters are entered
set hlsearch            " highlight matches

" Folding
set foldenable          " enable folding
set foldlevelstart=10   " open most folds by default
set foldnestmax=10      " 10 nested fold max
" space open/closes folds
nnoremap <space> za
set foldmethod=indent   " fold based on indent level


