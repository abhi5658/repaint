#include<graphics.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

/*
=====================================================================================================
|   Fill : select new color other then border color | select fill | press right click in area       |
|   Line/Rectangle/Circle : select line | press right click | press left click for the other end    |
=====================================================================================================
|   ||=====\\   ||=======       ||=====\\       //\\        ====||====  ||\\      ||    =========   |
|   ||      ||  ||              ||      ||     //  \\           ||      || \\     ||        ||      |
|   ||     //   ||              ||     //     //    \\          ||      ||  \\    ||        ||      |
|   ||======    ||=======  ==   ||======     ||======||         ||      ||   \\   ||        ||      |
|   ||   \\     ||              ||           ||      ||         ||      ||    \\  ||        ||      |
|   ||    \\    ||              ||           ||      ||         ||      ||     \\ ||        ||      |
|   ||     \\   ||=======       ||           ||      ||     ====||====  ||      \\||        ||      |
=====================================================================================================
|	Features:                               														|
|	*Color panel                            														|
|	*Eraser                                 														|
|	*Brush size:                            														|
|	    *increase                           														|
|	    *decrease                           														|
|	*Draw:                                  														|
|	    *Circle                             														|
|	    *Rectangle                          														|
|	    *Line                               														|
|	*Fill Color                             														|
|	*Clear Screen                           														|
=====================================================================================================
|	Code by: Abhishek Shah & Aseem Thakkar                                                          |
=====================================================================================================
*/

int thick = 7;
int flag = 0;
int lineFlag = 0;
int fillFlag = 0;
int rectFlag = 0;
int circFlag = 0;
int currentcolor=BLACK;
int partSwitcher=0;
int partMaxX=0;
int partMaxY=0;

void ui()
{     //close window box
    setfillstyle(SOLID_FILL,WHITE);
	bar(1268,0,1297,19);
	setfillstyle(SOLID_FILL,RED);
	bar(1270,2,1295,17);
	setfillstyle(SOLID_FILL,RED);
	line(1270,2,1295,17);
	line(1295,2,1270,17);


	//drawing area
	setfillstyle(SOLID_FILL,WHITE);
	bar(50,50,1300,700);

	//color pallete---------------------------->
	//pallete background
	setfillstyle(SOLID_FILL,WHITE);
	bar(50,710,355,750);
	//black
	setfillstyle(SOLID_FILL,BLACK);
	bar(60,720,80,740);
	//blue
	setfillstyle(SOLID_FILL,BLUE);
	bar(90,720,110,740);
	//green
	setfillstyle(SOLID_FILL,GREEN);
	bar(120,720,140,740);
	//red
	setfillstyle(SOLID_FILL,RED);
	bar(150,720,170,740);
	//brown
	setfillstyle(SOLID_FILL,BROWN);
	bar(180,720,200,740);
	//light gray
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(210,720,230,740);
	//lightblue
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar(240,720,260,740);
	//lightgreen
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	bar(270,720,290,740);
	//lightred
	setfillstyle(SOLID_FILL,LIGHTRED);
	bar(300,720,320,740);
	//yellow
	setfillstyle(SOLID_FILL,YELLOW);
	bar(330,720,350,740);
	//white
	setfillstyle(SOLID_FILL,WHITE);
	bar(360,720,380,740);
	//color pallete end------------------>

	//increase brush size------------->
	//- tool
	rectangle(400,720,420,740);
	bar(404,728,416,732);
	// + tool
    rectangle(440,720,460,740);
	bar(444,729,456,731);
    bar(449,724,451,736);


    //tools--------------------------->
    setcolor(WHITE);
    //clear
    rectangle(1075,715,1145,745);
    //arc(1135,730,80,280,11);
    outtextxy(1087,722,"CLEAR");
    //line
    rectangle(1195,715,1225,745);
    line(1217,723,1203,737);
    //circle
    rectangle(1240,715,1270,745);
    circle(1255,730,12);
    //rectangle
    rectangle(1155,715,1185,745);
    rectangle(1160,725,1180,735);
    //floodfill
    rectangle(1025,715,1060,745);
    outtextxy(1030,722,"FILL");

	setfillstyle(SOLID_FILL,BLACK);
}

void linee()
{
    //std::cout<<"aayo"<<std::endl;
    POINT cursor;
    int cx,cy;
    int a,b,p,q,counter=0;
    setcolor(BLACK);
    while(counter<2)
    {
        GetCursorPos(&cursor);
            cx = cursor.x;
            cy = cursor.y;
            if(GetAsyncKeyState(VK_RBUTTON)&& counter==0)
            {
                a=cx;
                b=cy;
                counter++;
            }
            else if(GetAsyncKeyState(VK_LBUTTON)&& counter==1)
            {
                p=cx;
                q=cy;
                counter++;
            }
    }
    setcolor(currentcolor);
    line(a,b,p,q);
    line(a+1,b,p+1,q);
    line(a+2,b,p+2,q);
    line(a+3,b,p+3,q);
    line(a-1,b,p-1,q);
    line(a-2,b,p-2,q);
    line(a-3,b,p-3,q);
    lineFlag=0;
}

void rect()
{
    //std::cout<<"rectaayo"<<std::endl;
    POINT cursor;
    int cx,cy;
    int a,b,p,q,counter=0;
    setcolor(BLACK);
    while(counter<2)
    {
        GetCursorPos(&cursor);
            cx = cursor.x;
            cy = cursor.y;
            if(GetAsyncKeyState(VK_RBUTTON)&& counter==0)
            {
                a=cx;
                b=cy;
                counter++;
            }
            else if(GetAsyncKeyState(VK_LBUTTON)&& counter==1)
            {
                p=cx;
                q=cy;
                counter++;
            }
    }
    rectangle(a,b,p,q);
    rectangle(a+1,b+1,p+1,q+1);
    rectangle(a+2,b+2,p+2,q+2);
    rectangle(a+3,b+2,p+3,q+2);
    rectangle(a-1,b-1,p-1,q-1);
    rectangle(a-2,b-2,p-2,q-2);
    rectangle(a-3,b-3,p-3,q-3);
    rectFlag=0;
}

void circ()
{
    POINT cursor;
    int cx,cy;
    int a,b,p,q,counter=0;
    setcolor(BLACK);
    while(counter<2)
    {
        GetCursorPos(&cursor);
            cx = cursor.x;
            cy = cursor.y;
            if(GetAsyncKeyState(VK_RBUTTON)&& counter==0)
            {
                a=cx;
                b=cy;
                counter++;
            }
            else if(GetAsyncKeyState(VK_LBUTTON)&& counter==1)
            {
                p=cx;
                q=cy;
                counter++;
            }
    }

    int daig=(int)sqrt(((a-p)*(a-p))+((b-q)*(b-q)));
    int r=daig/2;
    int xcen=(a+p)/2,ycen=(b+q)/2;
    circle(xcen,ycen,r-3);
    circle(xcen,ycen,r-2);
    circle(xcen,ycen,r-1);
    circle(xcen,ycen,r);
    circle(xcen,ycen,r+1);
    circle(xcen,ycen,r+2);
    circle(xcen,ycen,r+3);
    circFlag=0;
}
int part(int x,int y)
{
    switch(partSwitcher)
    {
    case 0:
        if(x>partMaxX && y<=partMaxY)
            return 1;
        else
            return 0;
            break;
    case 1:
        if(x>=partMaxX && y>partMaxY)
            return 1;
        else
            return 0;
            break;
    case 2:
        if(x<partMaxX && y>=partMaxY)
            return 1;
        else
            return 0;
            break;
    case 3:
        if(x<=partMaxX && y<partMaxY)
            return 1;
        else
            return 0;
            break;
    }
    return 0;
}
void myfill(int x, int y, int fillcolor, int basecolor)
{
    int currentpixelcolor = getpixel(x,y);
    if(currentpixelcolor==basecolor && part(x,y))
    {
        putpixel(x,y,fillcolor);
        myfill(x+1,y,fillcolor,basecolor);//east
        //myfill(x+1,y+1,fillcolor,basecolor);//southeast
        myfill(x,y+1,fillcolor,basecolor);//south
        //myfill(x-1,y+1,fillcolor,basecolor);//southwest
        myfill(x-1,y,fillcolor,basecolor);//west
        //myfill(x-1,y-1,fillcolor,basecolor);//northwest
        myfill(x,y-1,fillcolor,basecolor);//north
        //myfill(x+1,y-1,fillcolor,basecolor);//northeast
    }
}
void filler()
{
    POINT cursor;
    int cx,cy;
    int p,q,fillcolor,basecolor,counter=0;
    setcolor(BLACK);
    while(counter<2)
    {
        GetCursorPos(&cursor);
            cx = cursor.x;
            cy = cursor.y;
            if(GetAsyncKeyState(VK_RBUTTON)&& counter==0)
            {
                fillcolor=getpixel(cx,cy);
                counter++;
            }
            else if(GetAsyncKeyState(VK_LBUTTON)&& counter==1)
            {
                p=cx;
                q=cy;
                basecolor=getpixel(p,q);
                counter++;
            }
    }
    partMaxX=p;
    partMaxY=q;
    putpixel(p,q,fillcolor);
    myfill(p+1,q-1,fillcolor,basecolor);
    partSwitcher=1;
    myfill(p+1,q+1,fillcolor,basecolor);
    partSwitcher=2;
    myfill(p-1,q+1,fillcolor,basecolor);
    partSwitcher=3;
    myfill(p-1,q-1,fillcolor,basecolor);
    partSwitcher=0;
    fillFlag=0;
}

/*void filler()
{
    POINT cursor;
    int cx,cy;
    int a,b,p,q,counter=0;
    setcolor(BLACK);
    while(counter<1)
    {
        GetCursorPos(&cursor);
            cx = cursor.x;
            cy = cursor.y;
            if(GetAsyncKeyState(VK_RBUTTON)&& counter==0)
            {
                floodfill(cx,cy,BLACK);
                counter++;
            }
    }
    fillFlag=0;
}
*/


int within(int topx,int topy,int belowx,int belowy,int x,int y)
{
	if(x>=topx && x<=belowx && y>=topy && y<=belowy)
		return 1;
	else
		return 0;
}

void whathappens(int x,int y)
{
	if(within(1270,2,1295,17,x,y))//close button
		exit(1);
	else if(within(60,720,80,740,x,y))//black color
		{
		    setfillstyle(SOLID_FILL,BLACK);
		    currentcolor=BLACK;
        }
	else if(within(90,720,110,740,x,y))//blue color
		{
		    setfillstyle(SOLID_FILL,BLUE);
		    currentcolor=BLUE;
        }
	else if(within(120,720,140,740,x,y))//green color
		{
		    setfillstyle(SOLID_FILL,GREEN);
		    currentcolor=GREEN;
        }
	else if(within(150,720,170,740,x,y))//red color
		{
		    setfillstyle(SOLID_FILL,RED);
		    currentcolor=RED;
        }
	else if(within(180,720,200,740,x,y))//brown color
		{
		    setfillstyle(SOLID_FILL,BROWN);
		    currentcolor=BROWN;
        }
	else if(within(210,720,230,740,x,y))//lightgray color
		{
		    setfillstyle(SOLID_FILL,LIGHTGRAY);
		    currentcolor=LIGHTGRAY;
        }
	else if(within(240,720,260,740,x,y))//lightblue color
		{
		    setfillstyle(SOLID_FILL,LIGHTBLUE);
		    currentcolor=LIGHTBLUE;
        }
	else if(within(270,720,290,740,x,y))//lightgreen color
		{
		    setfillstyle(SOLID_FILL,LIGHTGREEN);
		    currentcolor=LIGHTGREEN;
        }
	else if(within(300,720,320,740,x,y))//lightred color
		{
		    setfillstyle(SOLID_FILL,LIGHTRED);
		    currentcolor=LIGHTRED;
        }
	else if(within(330,720,350,740,x,y))//yellow color
		{
		    setfillstyle(SOLID_FILL,YELLOW);
		    currentcolor=YELLOW;
        }
	else if(within(360,720,380,740,x,y))//white color
		{
		    setfillstyle(SOLID_FILL,WHITE);
		    currentcolor=WHITE;
        }
    else if(within(400,720,420,740,x,y)&&thick > 3&& flag ==0)//decrease brush size
        {thick = thick -2;std::cout<<thick<<std::endl;flag=1;}
    else if(within(440,720,460,740,x,y)&&thick <20 && flag == 0)//increase brush size
        {thick = thick+ 2;std::cout<<thick<<std::endl;
            flag=1;
        }
    else if(within(1195,715,1225,745,x,y)&& lineFlag==0)//line
        {
            linee();
            delay(500);
            //lineFlag=1;
        }
    else if(within(1155,715,1185,745,x,y)&&rectFlag==0)//rect
        {
            delay(500);
            rect();
            delay(500);
        }
    else if(within(1240,715,1270,745,x,y)&&circFlag==0)//circle
        {
            delay(500);
            circ();
            delay(500);
        }
    else if(within(1075,715,1145,745,x,y))//clear
        {
            cleardevice();
            ui();
        }
    else if(within(1025,715,1060,745,x,y)&&fillFlag==0)//fill
        {
            filler();
            delay(500);
        }
	else if(within(50+thick,50+thick,1300,700,x,y))//draw....more important
		{bar(x-thick,y-thick,x+thick,y+thick);flag=0;}
}

int main()
{

	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"",-3,-3);
    ui();
    POINT cursor;
    int cx,cy;
    std::cout<<getmaxx();
    while(1)
    {
        GetCursorPos(&cursor);
        cx = cursor.x;
        cy = cursor.y;
        if(GetAsyncKeyState(VK_LBUTTON))
            whathappens(cx,cy);
        //delay(5);
    }
	getch();
	closegraph();
}
