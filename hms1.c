#include <stdio.h>
#include <ncurses.h>

#define WIDTH 52
#define HEIGHT 17 

int startx = 0;
int starty = 0;

char *choices[] = { 
			"Series Q	Quick QWERTY course	(Q1 - Q5) ",
			"Series R	Long QWERTY course	(R1 - R14) ",
			"Series T	QWERTY touch typing	(T1 - T16) ",
			"Series V	Yet more QWERTY		(V1 - V19) ",
			"Series U	QWERTY review		(U1 - U13) ",
			"Series D	Dvorak touch typing	(D1 - D14) ",
			"Series C	Colemak touch typing	(C1 - C17) ",
			"Series M	Typing drills		(M1 - M11) ",
			"Series S	Speed drills		(S1 - S4) ",
			"Series N	Calculator keypad	(N1 - N3) ",
			"More lessons... ",
			"Help... ",
			"Exit"
		  };
int n_choices = sizeof(choices) / sizeof(char *);

char *subch[] = {
			"Lesson Q1	a s d f j k l ; e i ",
			"Lesson Q2	h g o u n . t ",
			"Lesson Q3	y r c , ? : p ",
			"Lesson Q4	m w v z x b q ",
			"Lesson Q5	` - "
		};
int ns_choices = sizeof(subch) / sizeof(char *);
int print_menu(WINDOW *menu_win, int highlight);
//int decide(WINDOW *menu_win, int choice);
int print_sub(WINDOW *sub_win, int highlight);

int main()
{	WINDOW *menu_win;
	WINDOW *sub_win;
	int highlight = 1;
	int choice = 0;
	int choice1 = 0;
	int c;
	int y = 2;
	int x = 2;
	initscr();
	clear();
	noecho();
	cbreak();	
	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	mvprintw(0, 15, "The following 10 lesson series are available");
	refresh();
	print_menu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
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
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)	
			break;
	}	
	//mvprintw(10, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	//c = decide(menu_win, choice);
	clrtoeol();
	clear();
	refresh();
	highlight = 0;
	print_sub(sub_win, highlight);
	while(1)
	{
		c = wgetch(sub_win);
		switch(c)
		{
			case KEY_UP:
				if(highlight == 1)
					highlight = ns_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == ns_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice1 = highlight;
				clear();
				refresh();
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_sub(sub_win, highlight);
		if(c != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1);
	endwin();
	return 0;
}


int print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) 
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
	return 0;
}

int print_sub(WINDOW *sub_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(sub_win, 0, 0);
	for(i = 0; i < ns_choices; ++i)
	{	if(highlight == i + 1) 
		{	wattron(sub_win, A_REVERSE); 
			mvwprintw(sub_win, y, x, "%s", subch[i]);
			wattroff(sub_win, A_REVERSE);
		}
		else
			mvwprintw(sub_win, y, x, "%s", subch[i]);
		++y;
	}
	wrefresh(sub_win);
	return 0;
}
