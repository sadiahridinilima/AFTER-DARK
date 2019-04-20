#include "iGraphics.h"
#include "bitmap_loader.h"
#include"myheaderfiles.h"
#include <iostream>
#define BIKENUMBERS 9

bool musicOn = true;
using namespace std;

int image2,image3,image4,image5,image1,image6;
int mposx=0,mposy=0;
int p =0;
int q =0;
int x=280;
int y=10;
int state = 1;
int timing = 1;


//int bike_x=0;
//int bike_y=0;
//int bike_dx=0;
//int bike_dy=0;




int imageA,imageB,imageC,imageD,imageE,imageF,imageG;
int flagforstart=0;
int r =255;
int g =255;
int b =255;
int dx=10;
int dy=10;
int page=0;
int flag=0;

int length=450;
int width=798;


struct bikes{
	int bikeX;
	int bikeY;
	int bikeWidth;
	int bikeHeight;
	
	bikes()
	{
	bikeY =10;
	bikeWidth = 155;
	bikeHeight = 183;
	bikeX =280;
	
	}
	
}bikes1,bikes2,bikes3,bikes4,cars1,cars2;

void change();




/*Background variables*/
int background[2];
int background_x[] = {0,0},background_y[]={0,800};


/*Time show code*/
int timecount=0;
char str_time[10];

void showTime()
{
	timecount ++;

}

/*
Background Timer

*/

void change_background()
{ for(int i=0;i<2;i++)
	{
		background_y[i] -= 10; //left slide
		if(background_y[i]+800<0) //left slide out of frame
			background_y[i] = background_y[(i+1)%2]+800; 

	}
}

void collisioncheck(){
	if((bikes1.bikeX >cars1.bikeX-100 && bikes1.bikeWidth<cars1.bikeWidth-100) && (bikes1.bikeY>200-cars1.bikeY && bikes1.bikeHeight<cars1.bikeHeight-100)){
		printf("DDD");
		state = -1;
		iText(50,50,"Game over",GLUT_BITMAP_TIMES_ROMAN_24);}
	//else if((bikes1.bikeX > cars2.bikeX+270 && bikes1.bikeWidth<cars2.bikeWidth-100) && (bikes1.bikeY>cars2.bikeY+50 && bikes1.bikeHeight<=cars2.bikeHeight-100)){
		//printf("DDD");
		//state = -1;
		//iText(50,50,"Game over",GLUT_BITMAP_TIMES_ROMAN_24);}
	//cout << x << endl;
	else state=0;
}



void lap_variation();
void timer();



/*
 function iDraw() is called again and again by the system.

 */



void iDraw()
{
	//place your drawing codes here
	iClear();
	//timing = timing+1;
	//("%d\n", timing);
	//if(timing > 10000)
		//exit(0);
	//if(state == -1){
		//exit(0);}
	iShowImage(0,0,800,800,imageA);
	iText(50,50,"START",GLUT_BITMAP_TIMES_ROMAN_24);

	     if(flagforstart==0)
		 {
			 iShowImage(0,0,800,800,background[0]);
		 }
		 else if(flagforstart==1)
		 {
		for(int i=0;i<2;i++){
		iShowImage(0,background_y[i],800,800,background[i]);
		}
		 }

   
	
	iShowImage(bikes1.bikeX,bikes1.bikeY,bikes1.bikeWidth,bikes1.bikeHeight,imageB);

	iShowImage(cars1.bikeX-100,280-cars1.bikeY,cars1.bikeWidth-100,cars1.bikeHeight-100,imageC);
	iShowImage(558-bikes2.bikeX,bikes2.bikeY+160,bikes2.bikeWidth-100,bikes2.bikeHeight-100,imageD);
	iShowImage(cars2.bikeX+270,cars2.bikeY+50,cars2.bikeWidth-100,cars2.bikeHeight-100,imageE);
	iShowImage(bikes3.bikeX+200,bikes3.bikeY+320,bikes3.bikeWidth-100,bikes3.bikeHeight-100,imageF);
	iShowImage(bikes4.bikeX+150,bikes4.bikeY+130,bikes4.bikeWidth-100,bikes4.bikeHeight-100,imageG);





    if(page==0)
	{
	iShowImage(0,0,800,450,image2);
	iShowImage(90,290,100,50,image3);
	iShowImage(90,210,100,50,image4); //control menu button
	iShowImage(90,130,100,50,image5);
	iShowImage(90,50,100,50,image6);

	iRectangle(90,290,100,50); //"start" menu button's rectangle
	iRectangle(90,210,100,50); //"control" menu button's rectangle
	iRectangle(90,130,100,50); //"score" menu button's rectangle
	iRectangle(90,50,100,50); //"exit" menu button's rectangle

	iSetColor(r,g,b);
	
	
	iText(90,360,"After Dark Menu Page",GLUT_BITMAP_TIMES_ROMAN_24);
	}
//	if(flag==0)
//	{ iShowImage(0,0,1920,1080,image1);}
	if(page==1)
	{

      
	}
	collisioncheck();
}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);

	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	mposx=mx;
	mposy=my;
 
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if(mx>=90&&mx<=190&&my>=290&&my<=340)
	{
		page=1;
		
	}
	if(mx>=90&&mx<=190&&my>=50&&my<=100)
	{
	flag =1;
	exit(0);
	}
	

}

void iKeyboard(unsigned char key)
{
		if (key == 'q')
	{
		exit(0);
	}

		if (key == 'p')
	{
		x=x-10;
		collisioncheck();
	}

	//else if (ey == 'a' && speed < 5)
		//speed += 1;
	//else if (key == 's' && speed > 0)
		//speed -= 1;
	if(key == 's')
	{
		flagforstart=1;
	}
}



void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_UP)
	{
		//if(y>=20)
		//{
			//y+=10;
		//}
		/*else
		{
			x = 10;
		}*/
		cout << bikes1.bikeY << endl;
		bikes1.bikeY+=30;
		
	}

	if (key == GLUT_KEY_DOWN)
	{
		/*if(y>=20)
		{
			y-=10;
		}*/
		/*else
		{
			x = 10;
		}*/
		cout << bikes1.bikeY << endl;
		//y+=10;
		
		bikes1.bikeY-=20;
	}
	if (key == GLUT_KEY_LEFT)
	{ 
		if(bikes1.bikeX>=68)
		{
			bikes1.bikeX-=20;
		}
		/*else
		{
			x = 10;
		}*/
		cout << bikes1.bikeX << endl;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		
		if(bikes1.bikeX<=580)
		{
			bikes1.bikeX+=20;
		}
		
		cout <<  bikes1.bikeX << endl;
	}
	//place your codes for other keys here
}

void lap_variation(){
	for(int lap=1;lap<=3;lap++){
		if(x==800 && y==450){
			iText(50,50,"lap 1 finish",GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}


void timer(){
	int s=0,ms=0,flag=0;
	if(s==0 && ms==0 && flag==0){
		iText(50,50,"Start the game",GLUT_BITMAP_TIMES_ROMAN_24);
		}
}

int main()
{
	//place your own initialization codes here.
	if(state !=-1)
	iSetTimer(20, objectChange);
	iSetTimer(20,showTime);
	iSetTimer(20,change_background);
	iInitialize(800,450,"After Dark");
	dp = 5;
	dq = 7;

	pic_x = 0;
  	pic_y = 0;

	//collisioncheck();


	//int var=0;
	imageA = iLoadImage("images\\road1.jpg");
	imageB = iLoadImage("images\\bike3.png");
	//imageC = iLoadImage("images\\carPink.png");
	//imageD = iLoadImage("images\\v1 (1).png");
	//imageE = iLoadImage("images\\CarRed.png");
	//imageF = iLoadImage("images\\v3 (1).png");
	//imageG = iLoadImage("images\\v4 (1).png");

	imageC = iLoadImage("images\\CarRed1.png");
	imageD = iLoadImage("images\\CarRed1.png");
	imageE = iLoadImage("images\\CarRed1.png");
	imageF = iLoadImage("images\\CarRed1.png");
	imageG = iLoadImage("images\\CarRed1.png");
	//menu page image
	image2=iLoadImage("images\\3.png");
	image3=iLoadImage("images\\button.png");
	image4=iLoadImage("images\\cntrl.png");
	image5=iLoadImage("images\\score1.png");
	image6=iLoadImage("images\\exiit.png");
	//background images
	background[0] = iLoadImage("images\\road1.jpg");
	background[1] = iLoadImage("images\\road1.jpg");

	 if(musicOn)
	    PlaySound("music\\on_the_road_proud_music_preview.wav",NULL,SND_LOOP|SND_ASYNC);




	iStart(); 

	return 0;
}









