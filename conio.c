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



#include "conio.h"

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  if(ch == '\x1b'){
    if(getchar()=='[') {
      switch(getchar()){
      case 'A':
        ch = '8';
        break;
      case 'B':
        ch = '2';
        break;
      case 'C':
        ch = '6';
        break;
      case 'D':
        ch = '4';
        break;
      }
    }
  }
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

