#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#define UPB 20
#define LFB 20
#define DNB 300
#define RTB 300
int fruitEaten=0;
int snakeposx=23, snakeposy=23;
int fruitposx=53, fruitposy=53;
int p=0;
int dir=6;
//int snakeLength[10][2]={0};
void goup()
{
	dir=8;
}
void godown()
{
	dir=2;
}
void goleft()
{
	dir=4;
}
void goright()
{
	dir=6;
}
void pause()
{
	if(p)
	{
		p=0;
	}
	else
	{
		p=1;
		while(getch()!='p'){}
	}
}
void snakemove()
{
     switch(dir)
     {
	case 6:
	snakeposx+=5;
	break;
	case 8:
	snakeposy-=5;
	break;
	case 2:
	snakeposy+=5;
	break;
	case 4:
	snakeposx-=5;
	break;
     }

}
int isGameOver()
{
	if(snakeposx>LFB && snakeposx<=RTB && snakeposy>UPB && snakeposy<=DNB)
	{
		return 1;
	}
	return 0;
}
void snake()
{
	setcolor(15);
	circle(snakeposx,snakeposy,3);
	if(dir==6)

	{
		for(int i=0;i<=fruitEaten;i++)
		{

			circle(snakeposx-5*i,snakeposy,3);
		}
	}
	else if(dir==4)
	{
		for(int i=0;i<=fruitEaten;i++)
		circle(snakeposx-5*i,snakeposy,3);
	}
	else if(dir==2)
	{
		for(int i=0;i<=fruitEaten;i++)
		circle(snakeposx,snakeposy-5*i,3);
	}
	else if(dir==8)
	{
		for(int i=0;i<=fruitEaten;i++)
		circle(snakeposx,snakeposy-5*i,3);
	}

}
void fruitpos()
{
	randomize();
	fruitposx=random(56)*5+23;
	fruitposy=random(56)*5+23;
}

void fruit(int c1,int c2)
{
	setcolor(15);
	rectangle(c1,c2,c1+2,c2+2);
	if(snakeposx==fruitposx && snakeposy==fruitposy)
	{

		fruitpos();
		fruitEaten++;
	}
}
void setBoard()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"C:/TURBOC3/BGI/");
	setcolor(10);
	rectangle(UPB-1,LFB-1,DNB+1,RTB+1);

}
void board()
{
	setfillstyle(SOLID_FILL,0);
	int poly[]= {UPB,LFB,UPB,RTB,DNB,RTB,DNB,LFB};
	fillpoly(4,poly);
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w':goup();break;
			case 's':godown();break;
			case 'd':goright();break;
			case 'a':goleft();break;
			case 'p':pause();
			    break;

		}
	}
}

void main()
{
	clrscr();
	setBoard();
	while(isGameOver())
	{
		board();
		//snake(snakeposx,snakeposy);
		snake();
		fruit(fruitposx,fruitposy);
		delay(200);
		//fruit(50,50);
		input();
		snakemove();
	}
	getch();
	closegraph();
}




/*
for(int i=0;i<=fruitEaten;i++)
	{
		if(dir==6)
			circle(snakeposx-5,snakeposy,3);
		else if(dir==2)
			circle(c1,c2-5,3);
		else if(dir==8)
			circle(c1,c2+5,3);
		else if(dir==4)
			circle(c1+5,c2,3);
	}


*/