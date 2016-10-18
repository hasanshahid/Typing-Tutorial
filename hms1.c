#include<stdio.h>
#include<ncurses.h>

#define WIDTH 52
#define HEIGHT 17

int startx = 0;
int starty = 0;
int row, col;

char *choices[] = {
		"Series Q	Quick QWERTY course	(Q1 - Q5) ",
		"Series R	Long QWERTY course	(R1 - R8) ",
		"Series T	QWERTY touch typing	(T1 - T10) ",
		"Series V	More QWERTY		(V1 - V8) ",
		"Series U	QWERTY review		(U1 - U6) ",
		"Series M	Typing drills		(M1 - M6) ",
		"Series S	Speed drills		(S1 - S3) ",
		"Series N	Calculator keypad	(N1 - N3) ",
		"More lessons... ",
		"Help ",
		"Exit ",
		  };
int n_choices = sizeof(choices) / sizeof(char *);
char *ch1[] = {
		"Lesson Q1	a s d f j k l ; e i",
		"Lesson Q2	h g o u n . t",
		"Lesson Q3	y r c , ? : p",
		"Lesson Q4	m w v z x b q",
		"Lesson Q5	' -"
	      };
int n_ch1 = sizeof(ch1) / sizeof(char *);
char *ch2[] = {
		"Lesson R1	Practise 1",
		"Lesson R2	Practise 2",
		"Lesson R3	Practise 3",
		"Lesson R4	Practise 4",
		"Lesson R5	Practise 5",
		"Lesson R6	Practise 6",
		"Lesson R7	Practise 7",
		"Lesson R8	Practise 8"
	      };
int n_ch2 = sizeof(ch2) / sizeof(char *);
char *ch3[] = {
		"Lesson T1	a s d f g h j k l ;",
		"Lesson T2	e g h ,",
		"Lesson T3	i r . shift",
		"Lesson T4	o p shift ?",
		"Lesson T5	t n b u / :",
		"Lesson T6	c m - q x z",
		"Lesson T7	w y v backspace",
		"Lesson T8	1 2 3 4 5 6 7 8 9 0 ( )",
		"Lesson T9	\' \" ! = * + > < ^",
		"Lesson T10	@ # $ % &"
	      };
int n_ch3 = sizeof(ch3) / sizeof(char *);
char *ch4[] = {
		"Lesson V1	R F U J D K E I",
		"Lesson V2	T Y G H",
		"Lesson V3	S L W O A ; Q P",
		"Lesson V4	Shift Keys",
		"Lesson V5	V M B N",
		"Lesson V6	Z X C , . / ?",
		"Lesson V7	1 2 3 4 5 6 7 8 9 0 -",
		"Lesson V8	Practise"
	      };
int n_ch4 = sizeof(ch4) / sizeof(char *);
char *ch5[] = {
		"Lesson U1	Home row",
		"Lesson U2	Other letters",
		"Lesson U3	Shift numerals figs",
		"Lesson U4	Practise",
		"Lesson U5	Drill on com-con combinations",
		"Lesson U6	Drill on sion-tion combinations"
	      };
int n_ch5 = sizeof(ch5) / sizeof(char *);
char *ch6[] = {
		"Lesson M1	Practise 1",
		"Lesson M2	Practise 2",
		"Lesson M3	Practise 3",
		"Lesson M4	Practise 4",
		"Lesson M5	Practise 5",
		"Lesson M6	Practise 6"
	      };
int n_ch6 = sizeof(ch6) / sizeof(char *);
char *ch7[] = {
		"Lesson S1	Speed Tests 1",
		"Lesson S2	Speed Tests 2",
		"Lesson S3	Speed Tests 3"
	      };
int n_ch7 = sizeof(ch7) / sizeof(char *);
char *ch8[] = {
		"Lesson N1	4 5 . 6 1",
		"Lesson N2	2 3 0 8 9 7",
		"Lesson N3	Practise"
	      };
int n_ch8 = sizeof(ch8) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);
void print(WINDOW *menu_win, int highlight, int n_ch, char *ch[]);
int chr1(WINDOW *sub_menu);
int chr2(WINDOW *sub_menu);
int chr3(WINDOW *sub_menu);
/*t chr4();
int chr5();
int chr6();
int chr7();
int chr8();
void more();
void help();
*/
int main() {
	WINDOW *menu_win, *sub_menu;
	int highlight = 1;
	int choice = 0;
	int c, i;
	int c1, c2, c3, c4, c5, c6, c7, c8;

	initscr();
	clear();
	noecho();
	cbreak();
	getmaxyx(stdscr, row, col);
	starty = (80 - WIDTH) / 2;
	startx = (28 - HEIGHT) / 2;
	menu_win = newwin(HEIGHT, WIDTH, startx, starty);
	keypad(menu_win, TRUE);
	mvprintw(0, 30, "TYPING TUTOR");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The following 8 lesson series are available");
	mvprintw(25, 0, "Use arrow keys to move around, RETURN to select");
	refresh();
	print_menu(menu_win, highlight);
	while(1) {
		c = wgetch(menu_win);
		switch(c) {
			case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = highlight;
				clear();
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
//-------------------FUNCTION-----------------------
	clear();
	while(1) {
		sub_menu = newwin(HEIGHT, WIDTH, startx, starty);
		keypad(sub_menu, TRUE);
		switch(choice) {
			case 1:
				c1 = chr1(sub_menu);
				clear();
				refresh();
				break;
			case 2:
				c2 = chr2(sub_menu);
				clear();
				refresh();
				break;
			case 3:
				c3 = chr3(sub_menu);
				clear();
				refresh();
				break;
			case 4:
				//c4 = chr4();
				break;
			case 5:
				//c5 = chr5();
				break;
			case 6:
				//c6 = chr6();
				break;
			case 7:
				//c7 = chr7();
				break;
			case 8:
				//c8 = chr8();
				break;
			case 9:
				//more();
				break;
			case 10:
				//help();
				break;
		}
		if(choice == 0)
			endwin();
	}
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

int chr1(WINDOW *sub_menu) {
	int highlight1 = 1;
	int choice1 = 0;
	int c, i;
	clear();
	mvprintw(0, 30, "Series Q");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The Q series contain 5 lessons");
	mvprintw(25, 0, "Use arrow keys to move around, RETURN to select"); 
	refresh();
	print(sub_menu, highlight1, n_ch1, ch1);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight1 == 1)
					highlight1 = n_ch1;
				else
					--highlight1;
				break;
			case KEY_DOWN:
				if(highlight1 == n_ch1)
					highlight1 = 1;
				else
					++highlight1;
				break;
			case 10:
				choice1 = highlight1;
				clear();
				refresh();
				break;
		}
		print(sub_menu, highlight1, n_ch1, ch1);
		if(choice1 != 0)
			break;
	}
	clrtoeol();
	refresh();
	clear();
	refresh();
	while(1);
	refresh();
	endwin();
	return 0;
}

int chr2(WINDOW *sub_menu) {
	int highlight2 = 1;
	int choice2 = 0;
	int c, i;
	mvprintw(0, 30, "Series R");
	for(i = 0; i< col; i++)
		mvprintw(1, col, "_");
	mvprintw(2, 15, "The R series contain 8 lessons");
	mvprintw(25, 0, "Use arrow keys to move around, RETURN to select");
	refresh();
	print(sub_menu, highlight2, n_ch2, ch2);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight2 == 1)
					highlight2 = n_ch2;
				else
					--highlight2;
				break;
			case KEY_DOWN:
				if(highlight2 == n_ch2)
					highlight2 = 1;
				else
					++highlight2;
				break;
			case 10:
				choice2 = highlight2;
				clear();
				refresh();
				break;
		}
		print(sub_menu, highlight2, n_ch2, ch2);
		if(choice2 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1);
	refresh();
	endwin();
	return 0;
}

int chr3(WINDOW *sub_menu) {
	int highlight3 = 1;
	int choice3 = 0;
	int c, i;
	mvprintw(0, 30, "Series T");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The T series contain 10 lessons");
	mvprintw(25, 0, "Use arrow keys to move around, RETURN  to select");
	refresh();
	print(sub_menu, highlight3, n_ch3, ch3);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight3 == 1)
					highlight3 = n_ch3;
				else
					--highlight3;
				break;
			case KEY_DOWN:
				if(highlight3 == n_ch3)
					highlight3 = 1;
				else
					++highlight3;
				break;
			case 10:
				choice3 = highlight3;
				clear();
				refresh();
				break;
		}
		print(sub_menu, highlight3, n_ch3, ch3);
		if(choice3 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1);
	refresh();
	endwin();
	return 0;
}
s

void print_menu(WINDOW *menu_win, int highlight) {
	int x, y, i;
	x = y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; i++) {
		if(highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void print(WINDOW *sub_menu, int highlight, int n_ch, char *ch[]) {
	int x, y, i;
	x = y =2;
	box(sub_menu, 0, 0);
	for(i = 0; i < n_ch; i++) {
		if(highlight == i+1) {
			wattron(sub_menu, A_REVERSE);
			mvwprintw(sub_menu, y, x, "%s", ch[i]);
			wattroff(sub_menu, A_REVERSE);
		}
		else
			mvwprintw(sub_menu, y, x, "%s", ch[i]);
		++y;
	}
	wrefresh(sub_menu);
}
