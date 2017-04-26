
#include <termios.h>
#include <stdio.h>

void initTermios(int mytermios);

/* Restore old terminal i/o settings */
void resetTermios(void); 

/* Read 1 character - echo defines echo mode */
char getch_(int mytermios);

/* Read 1 character without echo */
char getch(void);

/* Read 1 character with echo */
char getche(void);

