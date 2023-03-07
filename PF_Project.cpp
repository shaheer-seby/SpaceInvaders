#include<graphics.h>
#include<windows.h>
#include<time.h>

using namespace std;
int main()
{
	
	initwindow(800,600,"Space Invaders");
	


int spacex=300,xfire,fire=0,yfire=550,alien=0,xalien,yalien=50,alienrad=30,a=0,lives=3,score=0,level=1;
char b[10],c[10],d[10];







srand(time(0));
xalien=rand() % 490+60;
int s=0;

for (;;)
{

cleardevice();
rectangle(20,20,780,580);
setcolor(YELLOW);
settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(100,100,"WELCOME TO SPACE INVADERS");
	rectangle(60,80,740,200);
	setcolor(LIGHTBLUE);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(100,250,"INSTRUCTIONS:");
	 settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
	 setcolor(LIGHTRED);
	outtextxy(150,350,"PRESS 'A' OR 'D' TO MOVE LEFT OR RIGHT.");
	outtextxy(150,370,"PRESS SPACEBAR TO FIRE");
	outtextxy(150,390,"KILL ALIENS TO SCORE POINTS");
	outtextxy(150,410,"COMPLETE ALL 5 LEVELS TO WIN THE GAME");
outtextxy(150,430,"PRESS E TO EXIT");
setcolor(LIGHTGREEN);
	outtextxy(150,500,"PRESS ANY KEY TO START...");
	setcolor(CYAN);
	outtextxy(25,560,"By: Shaheer Ahmad, Uzair Shahid, Rameen Javed, Maryam Haroon");
	if(GetAsyncKeyState('E'))
{
	break;
}
	getch();
	
for(;;)
{
		cleardevice();
	settextstyle(BOLD_FONT,HORIZ_DIR,5);
	outtextxy(600,50,"SPACE");
	outtextxy(590,100,"INVADERS");
	setcolor(LIGHTBLUE);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	sprintf(d,"LEVEL: %d",level);
	outtextxy(590,200,d);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	
	sprintf(c,"SCORE: %d",score);
	outtextxy(590,500,c);

setbkcolor(BLACK);	
setcolor(LIGHTBLUE);	
arc(spacex,550,0,180,20);
setcolor(GREEN);
rectangle(20,20,580,580);
rectangle(25,25,585,585);




if(a==1)
{
	xalien=rand() % 490+60;
	alienrad=30;
	a=0;
}
setcolor(LIGHTRED);

circle(xalien,yalien,alienrad);
setcolor(YELLOW);
yalien=yalien+level;


if(GetAsyncKeyState('Q'))
{
	score=520;
}


if(GetAsyncKeyState('A')&& spacex>40)
{
	spacex=spacex-10;
}
if(GetAsyncKeyState('D') && spacex<560)
{
	spacex=spacex+10;
	
}
if(GetAsyncKeyState(' ') && fire==0)
{
	fire=1;
	xfire=spacex;
	
}
if(GetAsyncKeyState('E'))

{ 
break;
}
if(fire==1)
{
	
	circle(xfire,yfire,5);
	yfire=yfire-15;
}
if(yfire<=20)
{
	fire=0;
	yfire=500;
}


if(yfire>=yalien-30 &&yfire<=yalien+30 && xfire>=xalien-30 && xfire<=xalien+30)
{
	
	alienrad=0;
	fire=0;
	yfire=550;
	yalien=50;
	a=1;
	score+=10;
	setbkcolor(RED);
}

if(yalien==550)
{
	alienrad=0;
	fire=0;
	yfire=550;
	yalien=50;
	a=1;
	setbkcolor(RED);
	lives--;
	
}
if(GetAsyncKeyState('P'))
{
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
	outtextxy(200,300,"PRESS ANY KEY TO RESUME");
 getch();  	
}

settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
sprintf(b,"LIVES: %d",lives);
	outtextxy(600,400,b);

if(lives==0)
{
	settextstyle(BOLD_FONT,HORIZ_DIR,7);
	outtextxy(100,300,"GAME OVER!!");
	getch();
	break;
}


if(score>100)
{
	level=2;
	
}
if(score>200)
{
	level=3;
}
if(score>300)
{
	level=4;
}
if(score>400)
{
	level=5;
}
if(score>510)
{
	setcolor(LIGHTBLUE);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,7);
	outtextxy(100,300,"YOU WIN!!");
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(90,500,"PRESS ANY KEY TO");
	outtextxy(90,520,"RETURN TO MAIN MENU");
	break;
}


delay(10);
cleardevice();
}
}



closegraph();
system("pause");	
return 0;	
}
