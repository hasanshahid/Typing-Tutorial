#include<stdio.h>
#include<ncurses.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define WIDTH 52
#define HEIGHT 17

int startx = 0;
int starty = 0;
int row, col;
int strleng[16];

char *choices[] = {
		"Series Q	Quick QWERTY course	(Q1 - Q5) ",
		"Series R	Long QWERTY course	(R1 - R3) ",
		"Series T	QWERTY touch typing	(T1 - T10) ",
		"Series V	More QWERTY		(V1 - V8) ",
		"Series U	QWERTY review		(U1 - U6) ",
		"Series M	Typing drills		(M1 - M3) ",
		"Series S	Speed drills		(S1 - S3) ",
		"Series N	Calculator keypad	(N1 - N3) ",
		"More lessons... ",
		"Help "
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
		"Lesson R4	Practise 4"
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
		"Lesson M3	Practise 3"
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
char *sq1[] = {
		"asdf ;lkj asdf ;lkj asdf ;lkj asdf ;lkj asdf ;lkj asdf ;lkj",
		"asdef ;lkij asdef ;lkij asdef ;lkij asdef ;lkij asdef ;lkij",
		"Dad adds a salad  A lad asks  Salad falls as a lad asks Dad",
		"Lease a desk  Add a safe deal  Ask less fees  Add a lease",
		"Sid adds all sail as Dad sees a safe sea as idle as a lake"
	      };
int no_q1 = sizeof(sq1) / sizeof(char *);
char *sq2[] = {
		"a;sldkfjgh a;sldkfjgh a;sldkfjgh a;sldkfjgh a;sldkfjgh",
		"asdefghk lokijujhjn asdefghk lokijujhjn asdefghk",
		"Ed had his ease.  Sis liked a safe shed.  Sis had shade.",
		"Sid used us.  Sid sued us.  Ada used us as aid.  I did aid.",
		"Dean is indeed sad as he sees Sis and Ed inside.  At nine he sees Sis dine.",
		"He sees that in a test he has to state and use a sane idea."
	     };
int no_q2 = sizeof(sq2) /  sizeof(char *);
char *sq3[] = {
		"deki frju dck, dcl. frju ftjy deki frju dck, dcl. frju ftjy",
		"fgjh ;p;? jujy dedc lol. kik, fgju ;:;: frfk jujy dedc kik,",
		"Chance can aid a nice choice.  It can teach one to count his costs too.",
		"He is going to hunt again.  As night ends he sets out.",
		"Papa can not plan to get us all there in such a car as this."
	      };
int no_q3 = sizeof(sq3) / sizeof(char *);
char *sq4[] = {
		"dedc kik, frfv jujm swsx lol. aqaz ;p;p frfv jujm ftfb jyjn ",
		"aqsw az;p sxl. fvjm fvjn fbjn aqsw az;p sxl. fvjm fvjn fbjn",
		"Iowa was white with snow when we went down town and saw a show.",
		"John has to use a tan and jet auto.  He joined Jane in its joint use.",
		"Jack asks to use a kodak to take along on these keen skates and skis.",
		"I advise Eva in vain to avoid an auto visit in seven states.",
		"Ask them to let us have the car if they both go to the show."
	      };
int no_q4 = sizeof(sq4) / sizeof(char *);
char *sq5[] = {
		"dedc kik, frfv jujm swsx lol. aqaz ;p;p frfv jujm ftfb jyjn", 
		"frfk fvfb jujy jmjn aqsw azsw azsx ;plo ;p;- kik, ;p;-",
		"l-t o-d s-c p-t o-d n-y r-o g-d r-h d-g n't t's l's y's I'l",
		"They often need funds but don't think it is any fun to study.",
		"She is to adjust her six visits to have a snow-white Maine Christmas."
	      };
int no_q5 = sizeof(sq5) / sizeof(char *);
char *sr1[] = {
		"Up to date I can not see that the thing is as good as this one.",
		"uch pos oug ept ing ope hic ati sch cou get ice con goo ght",
		"Nan is cute.  She can sing and dance.  She can tap a piano.",
		"Tonight Nan opens the piano.  She sings such good songs and\n"
		"soon dashes into a dance.  Nan can dance.  The noise stops.",
		"Nan gets us going.  The dance is on.  Ted pounds the piano\n"
		"as Ann stops to go to the phone.  She has to get the gang.\n"
		"This chance scene passes too soon.  I hope it happens again."
	      };
int no_r1 = sizeof(sr1) / sizeof(char *);
char *sr2[] = {
		"It is a good thing to use good habits each time you practice.",
		"Dad and his son, Dan, are to go east on a great auto trip.",
		"The phone rings.  Dan hopes the rain has not upset the trip.\n"
		"Soon the pair share a snug rug and start out in our red car.",
		"Dad had a short rest in order to start on the hard car trip."
	      };
int no_r2 = sizeof(sr2) / sizeof(char *);
char *sr3[] = {
		"After that date I believe he can not say that it is not a fact.",
		"I feel sorry to say I can not send a full order on that day.\n"
		"Forty-odd pounds is all that I can spare at this early date.",
		"In any case there is only one order that is long past due.",
		"With that end in view I may soon have to put this question.",
		"Even her very quick smile never makes us quite at our ease."
	      };
int no_r3 = sizeof(sr3) / sizeof(char *);
char *sr4[] = {
		"k9 d3 j8 f4 j7 f5 f6 j6 10 s2 j8 f4 j7 f5 f6 j6 k9 d3 ;- s2\n"
		"k98 d34 j87 f45 109 s23 k93 d39 j84 f48 j75 f57 j76 f56 102",
		"10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29",
		"As soon as you can type at 12 words a minute, jump to 24;\n"
		"later to 30, 36, 42, 48, or other rate that seems to fit.",
		"In order to park on Sixth at 11:05 we have to beat 135 cars!"
	     };
int no_r4 = sizeof(sr4) / sizeof(char *);
char *st1[] = {
		"ffjj ddkk ssll aa;; fjfj dkdk fdks a;a; slsl asdf ;lkj",
		"asgh sdfg jkgh lasd kalg glad fall ask had slash",
		"hash lash all lag hall shall gas flash dad; glass"
	      };
int no_t1 = sizeof(st1) / sizeof(char *);
char *st2[] = {
		"ddd eee ggg hhh ded hh gj kl ed safd ;lkj gh fal",
		"lake asked fake gale egg flesh see elf fee, flask",
		"lad had a flash, he had salad, she had fake egg"
	      };
int no_t2 = sizeof(st2) / sizeof(char *);
char *st3[] = {
		"rr ii frf kik frfr ki k ir frki fkir rake rag her",
		"red far jar read fare rid fair l.l .l. ... ",
		"Fred Dale Hasan India WHO Dr. Sir, Mr. Chirag"
	      };
int no_t3 = sizeof(st3) / sizeof(char *);
char *st4[] = {
		"lol rod for roll oleo load ollo lll ;pp; ;p; p;p ?;?",
		"pad peg ape poke pear peek opera hope drape hear lord",
		"Is he here? Jake heard he is OK."
	      };
int no_t4 = sizeof(st4) / sizeof(char *);
char *st5[] = {
		"fff ttt ftf jjj nnn jnj ?.,:",
		"three often there ton opening interest kneeling",
		"The talk is that those three are threatening her.",
		"bbb fbf uuu juj fbuj jubf bufj /;/",
		"blast radio bus bleed tour start four pure born bag",
	      };
int no_t5 = sizeof(st5) / sizeof(char *);
char *st6[] = {
		"dcd mjm cdc jmj aqa sxs zaz saq zasq",
		"zing QWERTY queue mall-madam carrom stock flock maid mock"
	      };
int no_t6 = sizeof(st6) / sizeof(char *);
char *st7[] = {
		"wsw fvf jyj wvy fwvy",
		"meterology camera wet who Washington July yard vine very",
		"Were your yard sales much better last year?"
	      };
int no_t7 = sizeof(st7) / sizeof(char *);
char *st8[] = {
		"1234567890 0123456789 123311234254 2341233434543",
		"(1223) () 13243255 333221 9876598765 112123"
	      };
int no_t8 = sizeof(st8) / sizeof(char *);
char *st9[] = {
		"1+2=3 * 2>4 42^64 <> >< = ",
		"Sum = 1 + 2 = 3",
		"Product = 1 * 2 = 2"
	      };
int no_t9 = sizeof(st9) / sizeof(char *);
char *st10[] = {
		" @ # $ % & # @ $ % &",
		"something@yahoo.com a&b c % D A#s"
	       };
int no_t10 = sizeof(st10) / sizeof(char *);
char *sv1[] = {
		"fff jjj fff jjj fff jjj fjf uuu uff juu jff",
		"fru urf juf fuj fur jur fjj uuj fju",
		"ddd kkk iii eee did rid eke ire ire die",
		"kid fee red fir fee free fire deer rude dire ride"
	       };
int no_v1 = sizeof(sv1) / sizeof(char *);
char *sv2[] = {
		"tttt yyy gg h ftf jyj ftf jyj fgf jhj hjh gfg",
		"hit get yet try the get key try kit tie hit",
		"here they true there fruit right third dried their truth"
	      };
int no_v2 = sizeof(sv2) / sizeof(char *);
char *sv3[] = {
		"s ll www oooo sl ls slo wol sw lo",
		"lol slow sow row low too wit what sit wool style loose",
		"aa ;;;; qqq pp aqa p;p qaq ;p; apa",
		"up; pa; quay quip apt; sip paid aqua pass paid pair",
		"quote paper prefer postage quarter quality"
	       };
int no_v3 = sizeof(sv3) / sizeof(char *);
char *sv4[] = {
		"F HH JJJ RRRR Fa Jay Ray Hal Kay",
		"Dora; Harry Hasan Messi Yemen Arthur Joseph"
	      };
int no_v4 = sizeof(sv4) / sizeof(char *);
char *sv5[] = {
		"vvv mm bbbb n fvf bfb jnj mjm",
		"over home; more ever vast gave time bin now big bent vine",
		"You must devote more time to your daily work."
		"We require more time to turn out a very good job."
	       };
int no_v5 = sizeof(sv5) / sizeof(char *);
char *sv6[] = {
		"zzz xxx cc k,k ;/; ?/? fcd sxs aza l.l",
		"can, cue cash lace clerk could six etc. fixes mixes",
		"expert expect zip c/o I/O lazy zest zebra amaze blaze zero",
		"Mr. Cox examined the mixture with extreme care."
	      };
int no_v6 = sizeof(sv6) / sizeof(char *);
char *sv7[] = {
		"0123456789 9876543210 1234564321",
		"f4f j7j d3d k8k s2s l9l 0;0 1a1 f5f 6j6",
		"I am born on 25 March, 1997"
	      };
int no_v7 = sizeof(sv7) / sizeof(char *);
char *sv8[] = {
		"You type capital letters by holding down a key\n"
		"called the shift key while you strike the letter key.\n"
		"\n"
		"The Johnston Hardware Company, Toledo, Ohio has\n"
		"ordered the following supplies:  15 Pruning Shears,\n"
		"10-inch, at $.795; 24 Steel Rakes, 14-inch, at $.815;\n"
		"16 Steel Spades, D-Handle, at $.935.",
		"Our company ordered 15 Ajax Pencil Sharpeners at\n"
		"$0.98; 6 doz. Circular Rubber Erasers at $.43; 24 No.  68\n"
		"Spiral Stenographic Notebooks at $.075."
	     };
int no_v8 = sizeof(sv8) / sizeof(char *);
char *su1[] = {
		"has half hag gash glass gad glass sash ash slash shall flash",
		"had hall gas gaff gall glad dash ask slag shad ah"
	      };
int no_u1 = sizeof(su1) / sizeof(char *);
char *su2[] = {
		"jug part aqua their hearty dry great whose youth free type last",
		"dear rear pretty fresh grip quiet where proud yellow please",
		"sweep man come body vacant ribbon lining believing name examine",
		"cancel mention commission opening branch become native"
	      };
int no_u2 = sizeof(su2) / sizeof(char *);
char *su3[] = {
		"Do you live in Pune, Maharashtra?",
		"Sita and Gita are twin sisters."
		"Joseph, Kevin and Ben are staying at the Hotel Commodore"
	      };
int no_u3 = sizeof(su3) / sizeof(char *);
char *su4[] = {
		"The quick brown fox jumps over the lazy dog.",
		"This is a specimen of the work done on this machine.",
		"1$ 2$ 3$ 4$ 5$ 6$ 7$ 8$ 9$ 10$\n"
		"2 coats @ $20.00 5 hats @ $4.00"
	      };
int no_u4 = sizeof(su4) / sizeof(char *);
char *su5[] = {
		"com recom discom incom uncom\n"
		"con recon discon incon uncon",
		"common commit connect contrast commerce compare contrary",
		"commence uncomfortable complete inconvenient convince"
	      };
int no_u5 = sizeof(su5) / sizeof(char *);
char *su6[] = {
		"asion esion ision osion usion\n"
		"ation etion ition otion ution",
		"action motion quotation session impression situation condition",
		"possession creation station commission division"
	      };
int no_u6 = sizeof(su6) / sizeof(char *);
char *sm1[] = {
		"If you can do so, will you kindly let us know by return mail.",
		"My totals were:  $2,309, $5,687, $3,498, $2,408, and $3,697.",
		"A student may type 1 word per minute faster for each added\n"
		"year of age: i.e., 13 to 14, to 15, to 16, to 17, to 18.",
		"I said, \"Never promise to take much money to such places.\""
	      };
int no_m1 = sizeof(sm1) / sizeof(char *);
char *sm2[] = {
		"How do I lose if I read a book that doesn't have much in it?",
		"He says he hasn't been very blue once in his two weeks here.",
		"Get any piece, since I can't guess the color he always used.",
		"Some women who could write her won't raise a hand to help."
	      };
int no_m2 = sizeof(sm2) / sizeof(char *);
char *sm3[] = {
		"They were often too tired to be certain they heard the hour.",
		"Though I don't seem to hear the doctor, I know he is early.",
		"At the last minute he wrote that he knew it was done again.",
		"He would separate the whole business and buy out their half."
	      };
int no_m3 = sizeof(sm3) / sizeof(char *);
char *ss1[] = {
		"Now, it is a fact, that there was nothing at all par-\n"
		"ticular about the knocker on the door, except that it\n"
		"was very large.  It is also a fact, that Scrooge had\n"
		"seen it, night and morning, during his whole residence\n"
		"in that place; also that Scrooge has as little of what\n"
		"is called fancy about him as any man in the city of\n"
		"London, even including--which is a bold word--the\n"
		"corporation, aldermen, and livery.  Let it also be\n"
		"borne in mind that Scrooge had not bestowed one\n"
		"thought on Marley, since his last mention of his\n"
		"seven year's dead partner that afternoon.  And then\n"
		"let any man explain to me, if he can, how it happened\n"
		"that Scrooge, having his key in the lock of the door,\n"
		"saw in the knocker, without its undergoing any inter-\n"
		"mediate process of change--not a knocker, but Mar-\n"
		"ley's face."
	     };
int no_s1 = sizeof(ss1) / sizeof(char *);
char *ss2[] = {
		"A man can live well even in a palace.",
		"My chief want in life is someone who shall make me do what I can.",
		"No man can be called friendless when he has God and the\n"
		"companionship of good books.",
		"I like the silent church before the service begins better than any preaching."
	      };
int no_s2 = sizeof(ss2) / sizeof(char *);
char *ss3[] = {
		"Dear Sirs:\n"
		"\n"
		"I have just purchased a Heathkit H89 computer system and would\n"
		"like to order two boxes of diskettes for it.  This system uses\n"
		"5 1/4 inch, hard-sectored, ten-sector, single-sided, single-\n"
		"density diskettes.\n"
		"\n"
		"Enclosed is my check for $45.00.  Please rush this order, as I\n"
		"can not use my system before they arrive.\n"
		"\n"
		"Sincerely,\n"
		"\n"
		"Mr. Smith"
	     };
int no_s3 = sizeof(ss3) / sizeof(char *);
char *sn1[] = {
		"6666 656565 66655544555666 555...555 54.64.4",
		"111.444 456.654 6665541 414.564 111.555\n"
		"615.14 64545.156 16.161 1651615"
	      };
int no_n1 = sizeof(sn1) / sizeof(char *);
char *sn2[] = {
		"5552225.525.52 45.25 24.42 14.52 66333.63",
		"465.123 313.423 12.33 65.25 40044.401 410.210\n"
		"0.03 12.00 588.85 48.080 81.04 28 696969 595.679 49.9"
	      };
int no_n2 = sizeof(sn2) / sizeof(char *);
char *sn3[] = {
		"111 222 333 444 555 666 777 888 999 000",
		"123 654 879 264\n"
		"128 364 928 187\n"
		"987 234 681 287",
		"82.01 35 28.50 12\n"
		"50.00 79 40.25 37"
	      };
int no_n3 = sizeof(sn3) / sizeof(char *);

void print_menu(WINDOW *menu_win, int highlight);
void print(WINDOW *menu_win, int highlight, int n_ch, char *ch[]);
int chr1(WINDOW *sub_menu);
int chr2(WINDOW *sub_menu);
int chr3(WINDOW *sub_menu);
int chr4(WINDOW *sub_menu);
int chr5(WINDOW *sub_menu);
int chr6(WINDOW *sub_menu);
int chr7(WINDOW *sub_menu);
int chr8(WINDOW *sub_menu);
void more(WINDOW *sub_menu);
void help(WINDOW *sub_menu);

WINDOW *menu_win;
int series(WINDOW *sub_menu, int no, char *s[]);
int speed(WINDOW *sub_menu, int no, char *s[]);
void cho_ice(int choice);
void destroy_win(WINDOW *local_win);
int create(WINDOW *menu_win);

int main() {
	WINDOW *sub_menu;
	int highlight = 1;
	int choice = 0;
	int c, i;
	int c1, c2, c3, c4, c5, c6, c7, c8;

	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
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
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
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
			case 81: case 113:
				endwin();
				return 2;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)
			break;
	}
	cho_ice(choice);
	clrtoeol();
	clear();
	refresh();
	endwin();
	return 0;
}
//Takes choice and creates new window
void cho_ice(int choice) {
	WINDOW *sub_menu;
	int c1, c2, c3, c4, c5, c6, c7, c8;
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
				c4 = chr4(sub_menu);
				clear();
				refresh();
				break;
			case 5:
				c5 = chr5(sub_menu);
				clear();
				refresh();
				break;
			case 6:
				c6 = chr6(sub_menu);
				clear();
				refresh();
				break;
			case 7:
				c7 = chr7(sub_menu);
				clear();
				refresh();
				break;
			case 8:
				c8 = chr8(sub_menu);
				clear();
				refresh();
				break;
			case 9:
				more(sub_menu);
				clear();
				refresh();
				break;
			case 10:
				help(sub_menu);
				clear();
				refresh();
				break;

		}
		if(choice == 0)
			endwin();
	}
	clrtoeol();
	refresh();
}
//create a new window
int create(WINDOW *menu_win) {
	int c, i;
	int highlight = 1;
	int choice = 0;
	destroy_win(menu_win);
	menu_win = newwin(HEIGHT, WIDTH, startx, starty);
	keypad(menu_win, TRUE);
	mvprintw(0, 30, "TYPING TUTOR");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The following 8 lesson series are available");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
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
			case 81: case 113:
				endwin();
				clear();
				exit(0);
				return 2;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)
			break;
	}
	cho_ice(choice);
	clrtoeol();
	clear();
	refresh();
	endwin();
	return 0;
}
	
int chr1(WINDOW *sub_menu) {
	int highlight1 = 1;
	int choice1 = 0;
	int c, i, d;
	int q1, q2, q3, q4, q5;
	clear();
	mvprintw(0, 30, "Series Q");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The Q series contain 5 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit"); 
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
			case 81: case 113:
				d = create(menu_win);
				return 3;
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
	while(1) {
		switch(choice1) {
			case 1:
				q1 = series(sub_menu, no_q1, sq1);
				break;
			case 2:
				q2 = series(sub_menu, no_q2, sq2);
				break;
			case 3:
				q3 = series(sub_menu, no_q3, sq3);
				break;
			case 4:
				q4 = series(sub_menu, no_q4, sq4);
				break;
			case 5:
				q5 = series(sub_menu, no_q5, sq5);
				break;
		}
		return 1;
	}	
	refresh();
	endwin();
	return 0;
}

int chr2(WINDOW *sub_menu) {
	int highlight2 = 1;
	int choice2 = 0;
	int c, i, d;
	int r1, r2, r3, r4;
	mvprintw(0, 30, "Series R");
	for(i = 0; i< col; i++)
		mvprintw(1, col, "_");
	mvprintw(2, 15, "The R series contain 4 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
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
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight2, n_ch2, ch2);
		if(choice2 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice2) {
			case 1:
				r1 = series(sub_menu, no_r1, sr1);
				break;
			case 2:
				r2 = series(sub_menu, no_r2, sr2);
				break;
			case 3:
				r3 = series(sub_menu, no_r3, sr3);
				break;
			case 4:
				r4 = series(sub_menu, no_r4, sr4);
				break;
		}
		return 1;
	}
	refresh();
	endwin();
	return 0;
}

int chr3(WINDOW *sub_menu) {
	int highlight3 = 1;
	int choice3 = 0;
	int c, i, d;
	int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	mvprintw(0, 30, "Series T");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The T series contain 10 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN  to select, q/Q to quit");
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
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight3, n_ch3, ch3);
		if(choice3 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch (choice3) {
			case 1:
				t1 = series(sub_menu, no_t1, st1);
				break;
			case 2:
				t2 = series(sub_menu, no_t2, st2);
				break;
			case 3:
				t3 = series(sub_menu, no_t3, st3);
				break;
			case 4:
				t4 = series(sub_menu, no_t4, st4);
				break;
			case 5:
				t5 = series(sub_menu, no_t5, st5);
				break;
			case 6:
				t6 = series(sub_menu, no_t6, st6);
				break;
			case 7:
				t7 = series(sub_menu, no_t7, st7);
				break;
			case 8:
				t8 = series(sub_menu, no_t8, st8);
				break;
			case 9:
				t9 = series(sub_menu, no_t9, st9);
				break;
			case 10:
				t10 = series(sub_menu, no_t10, st10);
				break;
		}
		return 1;
	}
	refresh();
	endwin();
	return 0;
}

int chr4(WINDOW *sub_menu) {
	int highlight4 = 1;
	int choice4 = 0;
	int c, i, d;
	int v1, v2, v3, v4, v5, v6, v7, v8;
	mvprintw(0, 30, "Series V");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The V series contain 8 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
	refresh();
	print(sub_menu, highlight4, n_ch4, ch4);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight4 == 1)
					highlight4 = n_ch4;
				else
					--highlight4;
				break;
			case KEY_DOWN:
				if(highlight4 == n_ch4)
					highlight4 = 1;
				else
					++highlight4;
				break;
			case 10:
				choice4 = highlight4;
				clear();
				refresh();
				break;
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight4, n_ch4, ch4);
		if(choice4 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice4) {
			case 1:
				v1 = series(sub_menu, no_v1, sv1);
				break;
			case 2:
				v2 = series(sub_menu, no_v2, sv2);
				break;
			case 3:
				v3 = series(sub_menu, no_v3, sv3);
				break;
			case 4:
				v4 = series(sub_menu, no_v4, sv4);
				break;
			case 5:
				v5 = series(sub_menu, no_v5, sv5);
				break;
			case 6:
				v6 = series(sub_menu, no_v6, sv6);
				break;
			case 7:
				v7 = series(sub_menu, no_v7, sv7);
				break;
			case 8:
				v8 = speed(sub_menu, no_v8, sv8);
				break;
		}
		return 1;
	}
	refresh();
	endwin();
	return 0;
}

int chr5(WINDOW *sub_menu) {
	int highlight5 = 1;
	int choice5 = 0;
	int c, i, d;
	int u1, u2, u3, u4, u5, u6;
	mvprintw(0, 30, "Series U");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The U series contain 6 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
	refresh();
	print(sub_menu, highlight5, n_ch5, ch5);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight5 == 1)
					highlight5 == n_ch5;
				else
					--highlight5;
				break;
			case KEY_DOWN:
				if(highlight5 == n_ch5)
					highlight5 = 1;
				else
					++highlight5;
				break;
			case 10:
				choice5 = highlight5;
				clear();
				refresh();
				break;
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight5, n_ch5, ch5);
		if(choice5 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice5) {
			case 1:
				u1 = series(sub_menu, no_u1, su1);
				break;
			case 2:
				u2 = series(sub_menu, no_u2, su2);
				break;
			case 3:
				u3 = series(sub_menu, no_u3, su3);
				break;
			case 4:
				u4 = series(sub_menu, no_u4, su4);
				break;
			case 5:
				u5 = series(sub_menu, no_u5, su5);
				break;
			case 6:
				u6 = series(sub_menu, no_u6, su6);
				break;
		}
		return 1;
	}
	refresh();
	endwin();
	return 0;
}

int chr6(WINDOW *sub_menu) {
	int highlight6 = 1;
	int choice6 = 0;
	int c, i, d;
	int m1, m2, m3;
	mvprintw(0, 30, "Series M");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The M series contain 3 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
	refresh();
	print(sub_menu, highlight6, n_ch6, ch6);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight6 == 1)
					highlight6 = n_ch6;
				else
					--highlight6;
				break;
			case KEY_DOWN:
				if(highlight6 == n_ch6)
					highlight6 = 1;
				else
					++highlight6;
				break;
			case 10:
				choice6 = highlight6;
				clear();
				refresh();
				break;
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight6, n_ch6, ch6);
		if(choice6 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice6) {
			case 1:
				m1 = series(sub_menu, no_m1, sm1);
				break;
			case 2:
				m2 = series(sub_menu, no_m2, sm2);
				break;
			case 3:
				m3 = series(sub_menu, no_m3, sm3);
				break;
		}
		return 1;
	}
	refresh();
	endwin();
	return 0;
}

int chr7(WINDOW *sub_menu) {
	int highlight7 = 1;
	int choice7 = 0;
	int c, i, d;
	int s1, s2, s3;
	mvprintw(0, 30, "Series S");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The S series contain 3 lessons");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
	refresh();
	print(sub_menu, highlight7, n_ch7, ch7);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight7 == 1)
					highlight7 = n_ch7;
				else
					--highlight7;
				break;
			case KEY_DOWN:
				if(highlight7 == n_ch7)
					highlight7 = 1;
				else
					++highlight7;
				break;
			case 10:
				choice7 = highlight7;
				clear();
				refresh();
				break;
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight7, n_ch7, ch7);
		if(choice7 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice7) {
			case 1:
				s1 = speed(sub_menu, no_s1, ss1);
				break;
			case 2:
				s2 = speed(sub_menu, no_s2, ss2);
				break;
			case 3:
				s3 = speed(sub_menu, no_s3, ss3);
				break;
		}
		return 1;
	}
	clear();
	endwin();
	return 0;
}

int chr8(WINDOW *sub_menu) {
	int highlight8 = 1;
	int choice8 = 0;
	int c, i, d;
	int n1, n2, n3;
	mvprintw(0, 30, "Series N");
	for(i = 0; i < col; i++)
		mvprintw(1, i, "_");
	mvprintw(2, 15, "The N series contain 3 lesson");
	mvprintw(row - 1, 0, "Use arrow keys to move around, RETURN to select, q/Q to quit");
	refresh();
	print(sub_menu, highlight8, n_ch8, ch8);
	while(1) {
		c = wgetch(sub_menu);
		switch(c) {
			case KEY_UP:
				if(highlight8 == 1)
					highlight8 = n_ch8;
				else
					--highlight8;
				break;
			case KEY_DOWN:
				if(highlight8 == n_ch8)
					highlight8 = 1;
				else
					++highlight8;
				break;
			case 10:
				choice8 = highlight8;
				clear();
				refresh();
				break;
			case 81: case 113:
				d = create(menu_win);
				return 3;
				break;
		}
		print(sub_menu, highlight8, n_ch8, ch8);
		if(choice8 != 0)
			break;
	}
	clrtoeol();
	clear();
	refresh();
	while(1) {
		switch(choice8) {
			case 1:
				n1 = series(sub_menu, no_n1, sn1);
				break;
			case 2:
				n2 = series(sub_menu, no_n2, sn2);
				break;
			case 3:
				n3 = speed(sub_menu, no_n3, sn3);
				break;
		}
		return 1;
	}
	clear();
	endwin();
	return 0;
}
//Calculates speed for normal lessons
int series(WINDOW *sub_menu, int no, char *s[]) {
	int c, i, mistakes, j, words, diff, h, m, sec;
	float errper, wpm, cpm;
	time_t start_t, end_t;
	initscr();
	keypad(stdscr, true);
	noecho();
	for(i = 0; i < no; i++)
		strleng[i] = strlen(s[i]);
	while(1) {
		for(i = 0; i < no; ) {
			mistakes = 0;
			words = 1;
			mvprintw(row - 1, 0, "Press ESC to clear");
			mvprintw(0, 0, "%s\n", s[i]);
			time(&start_t);
			for(j = 0; j < strleng[i] + 1; j++) {
				c = getch();
				if(c == s[i][j])
					printw("%c", c);
				else {
					printw("~");
					mistakes++;
				}
				if(s[i][j] == ' '|| s[i][j] == '?' || s[i][j] == '.' || s[i][j] == ',')
					words++;
				if(c == 27) {
					clear();
					mvprintw(row - 1, 0, "Press ESC to clear, q/Q to quit");
					mvprintw(0, 0, "%s\n", s[i]);
					refresh();
					words = 0;
					c = getch();
					if(c == 81 || c == 113) {
						destroy_win(sub_menu);
						return 2;
					}
					else
						j = -1;
					time(&start_t);
				}
			}
			time(&end_t);
			clear();
			diff = end_t - start_t;
			wpm = words * 60.0 / diff;
			cpm = j * 60.0 / diff;
			h = (int)(diff / 3600);
			diff = diff - (h * 3600);
			m = (int)(diff / 60);
			diff = diff - (m * 60);
			sec = (int)diff;
			errper = (mistakes - 1) * 100.0 / strleng[i];
			mvprintw(5, 15, "Mistakes %d", mistakes);
			mvprintw(6, 15, "Words %d", words);
			mvprintw(7, 15, "Error percentage %f", errper);
			mvprintw(8, 15, "WPM %f", wpm);
			mvprintw(9, 15, "CPM %f", cpm);
			mvprintw(10, 15, "Time taken %dh %dm %ds", h, m, sec);
			mvprintw(row - 1, 0, "Press n/N for next lesson, q/Q to quit, r/R to repeat");
			refresh();
			c = getch();
			if(c == 78 || c == 110)
				i++;
			if(c == 81 || c == 113) {
				destroy_win(sub_menu);
				return 2;
			}
			if(c == 82 || c ==114)
				j--;
			clear();
		}
		if(i == no)
			break;
	}
	refresh();
	getch();
	endwin();
	return 0;
}
//Calculate speed for practise
int speed(WINDOW *sub_menu, int no, char *s[]) {
	int c, i, mistakes, j, words, diff, h, m, sec;
	float errper, wpm, cpm;
	time_t start_t, end_t;
	initscr();
	keypad(stdscr, true);
	noecho();
	for(i = 0; i < no; i++)
		strleng[i] = strlen(s[i]);
	while(1) {
		for(i = 0; i < no; ) {
			mistakes = 0;
			words = 1;
			time(&start_t);
			mvprintw(0, 0,"%s\n", s[i]);
			mvprintw(row - 1, 0, "Press ESC to clear");
			move(0, 0);
			for(j = 0; j < strleng[i] + 1; j++) {
				c = getch();
				if(c == s[i][j])
					printw("%c", c);
				else {
					printw("~");
					mistakes++;
				}
				if(s[i][j] == ' ' || s[i][j] == '?' || s[i][j] == '.' || s[i][j] == ',')
					words++;
				if(c == 27) {
					clear();
					mvprintw(row - 1, 0, "ESC to clear, q/Q to quit");
					mvprintw(0, 0, "%s\n", s[i]);
					move(0, 0);
					refresh();
					words = 0;
					c = getch();
					if(c == 81 || c == 113) {
						destroy_win(sub_menu);
						return 2;
					}
					else
						j = -1;
					time(&start_t);
				}
			}
			time(&end_t);
			clear();
			diff = end_t - start_t;
			wpm = words * 60.0 / diff;
			cpm = j * 60.0 / diff;
			h = (int)(diff / 3600);
			diff = diff - (h * 3600);
			m = (int)(diff / 60);
			diff = diff - (m * 60);
			sec = (int)diff;
			errper = mistakes * 100.0 / strleng[i];
			mvprintw(5, 15, "Mistakes %d", mistakes);
			mvprintw(6, 15, "Words %d", words);
			mvprintw(7, 15, "Error percentage %f", errper);
			mvprintw(8, 15, "WPM %f", wpm);
			mvprintw(9, 15, "CPM %f", cpm);
			mvprintw(10, 15, "Time taken %dh %dm %ds", h, m, sec);
			mvprintw(row - 1, 0, "Press n/N for next lesson, q/Q to quit, r/R to repeat");
			refresh();
			c = getch();
			if(c == 78 || c == 110)
				i++;
			if(c == 81 || c == 113) {
				destroy_win(sub_menu);
				return 2;
			}
			clear();
		}
		if(i == no)
			break;
	}
	refresh();
	getch();
	endwin();
	return 0;
}
//Print main menu
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
//Print sub_menu
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
//Destroy a window
void destroy_win(WINDOW *local_win)
{
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
//Show the other lessons of gtypist
void more(WINDOW *sub_win) {
	int c, d;
	clear();
	mvprintw(0, 0, "For more lessons and information visit:");
	mvprintw(1, 0, "http://pebbles.schattenlauf.de/layout.php?language=de");
	mvprintw(2, 0, "http://en.wikipedia.org/wiki/Dvorak_Simplified_Keyboard");
	mvprintw(row - 1, 0, "Press RETURN to continue");
	refresh();
	c = getch();
	clear();
	d = create(menu_win);
	refresh();
}
//Print the help for users
void help(WINDOW *sub_menu) {
	int c, d;
	clear();
	mvprintw(0, 0, "1.Use arrow keys to move up and down");
	mvprintw(1, 0, "2.Press RETURN or ENTER to select");
	mvprintw(2, 0, "3.Press q/Q to quit");
	mvprintw(3, 0, "4.Press ESC to clear");
	mvprintw(4, 0, "5.Press r/R to repeat");
	mvprintw(5, 0, "6.Press n/N for next lesson");
	mvprintw(row - 1, 0, "Press RETURN to continue");
	refresh();
	c = getch();
	clear();
	d = create(menu_win);
	refresh();
}
