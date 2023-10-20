#include"iGraphics.h"
#include"bitmap_loader.h"
#include<stdio.h>
#include <iostream>
using namespace std;
bool gameover=false;
void kunaiRun();
bool mute = false;
bool musicOn;
bool musicOff;
bool play = false;
#define screenHeight 600
#define screenWidth 1195
bool run=false;
bool runOn=false;
#define upperscreenHeight
#define upperscreenWidth
#define upperscreenspeed 5

#define lowerscreenHeight
#define lowerscreenWidth
#define lowerscreenspeed 5
void Power();
#define middlescreenHeight
#define middlescreenWidth
#define middlescreenspeed 5
#define screenHeight 600
#define screenWidth 1195
int bgIndex=-1;
int Highlight_Index =-1;
int storyIndex;
int i;
char str[100],str2[100];
int mode;
int g_Screen1=1;
int g_Load=0;
int len;
bool jump= false;
bool jumpUp = false;
#define jumpLimite 200
int charJumpCordinate=0;

bool fire = false;


int charIndex=0;

bool stand=true;
int standCounter=0;

void showVirus();

int kunai_x=300;


char char1[][100] = {"charr\\1.png"};//stand char
char char2[][100] = {"charr\\4.png","charr\\5.png","charr\\6.png","charr\\7.png","charr\\8.png","charr\\9.png","charr\\10.png","charr\\11.png","charr\\12.png","charr\\13.png"};//run char
char char4[][100] = {"gv.png"};
char char6[][100] = {"charr\\14.png"};
char char3[][100] = {"charr\\2.png","charr\\3.png"};//jump

int charStand[1],charRun[10],charJump[2],charRun1[4], charV[1],kunai[1];

char middle[10][15]= {"bg\\1.bmp","bg\\2.bmp","bg\\3.bmp","bg\\4.bmp","bg\\5.bmp","bg\\6.bmp","bg\\7.bmp","bg\\8.bmp","bg\\9.bmp","bg\\10.bmp"};
char lower[10][15]= {"bg\\1.bmp","bg\\2.bmp","bg\\3.bmp","bg\\4.bmp","bg\\5.bmp","bg\\6.bmp","bg\\7.bmp","bg\\8.bmp","bg\\9.bmp","bg\\10.bmp"};

char upper[10][15]= {"bg\\back0.bmp", "bg\\back1.bmp","bg\\back2.bmp","bg\\back3.bmp","bg\\back4.bmp","bg\\back5.bmp","bg\\back6.bmp","bg\\a.bmp","bg\\b.bmp","bg\\c.bmp"};

int standIndex=0;
int runIndex=0;

void Sound_Control(bool musicOn);


struct Enemy
{
	double x, y;
	int charCordinateX, charCordinateY;
	bool state; //If on screen or not.
	int value;
	int image[20];
	int index;

	
 
 int CharSizeH;
 int CharSizeW;
  double speed;



	/*Enemy(int _x, int _y, bool _state, int _value, int _index)
	{
		x = _x;
		y = _y;
		state = _state;
		value = _value;
		index = _index;
	}
	*/
  
 Enemy(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _state,  int _value, int _index,double _speed)
	{
		x = _x;
		y = _y;
		charCordinateX= _dimension_x;
		charCordinateY = _dimension_y;
		CharSizeW = _extended_x;
		CharSizeH = _extended_y;
		state = _state;
		value = _value;
		index = _index;
		speed  = _speed;
    }


	void koi()
	{
	
	               x=+speed; //iShowImage(bullet_x, ground_player.y + jumping_height + 40, 20, 10, bullet_image);
	            if (x  >= 1120)
	             fire = false;
		      
	         
	
	}
	void PositionChange()
	  
	 { 
		 x -= speed;
	   if(x<120)
		x=1100 ;
      }
	void setPosition()
 {
	 if(y<=0)
	 { 
		 x=250+rand()%(1100-charCordinateY);
		 y=screenHeight;
	 }
	 else
	 { 
		 y-=speed;
	 }

 }
	
}virus1(900,600,70,70,70,70,true,0,0,.2),virus2(900,70,70,70,70,70,true,0,0,.2),ku(200,100,70,70,30,20,true,0,0,4);

 struct Character
{
	int x, y;
	int charCordinateX, charCordinateY; //Character's actual dimension, not the image's dimension.
	int CharSizeW, CharSizeH; //As the images have some blank spaces around the character.
	int condition; //This number will represent if the player standing, walking or jumping. 
	int condition_changer;
	bool visible;
	int score;
	int health;
	

	
 Character	(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, int _condition, int _condition_changer, bool _visible, int _score, int _health)
	{
		//This constructor is for the player of level one.
		x = _x;
		y = _y;
		charCordinateX= _dimension_x;
		charCordinateY = _dimension_y;
		CharSizeW = _extended_x;
		CharSizeH = _extended_y;
		condition = _condition;
		condition_changer = _condition_changer;
		visible = _visible;
		score = _score;
		health = _health;
	}

	Character (int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _visible)
	{
		x = _x;
		y = _y;
		 charCordinateX = _dimension_x;
		 charCordinateY = _dimension_y;
		CharSizeW = _extended_x;
		CharSizeH = _extended_y;
		visible = _visible;
	}

	
} player(140, 50, 100, 100, 100, 100, 0, 0, true, 0, 100);
 





struct background
{
    int x;
    int y;
};

background upperbg[10];
background middlebg[10];
background lowerbg[10];



void loadImage()
{
    for (int standIndex = 0; standIndex <1; standIndex++)
    {
        charStand[standIndex] = iLoadImage(char1[standIndex]);
    }

    for (int i = 0; i <1; i++)
    {
    	 charV[i] = iLoadImage(char4[i]);
    }
    
	for (int i = 0; i <1; i++)
    {
    	 kunai[i] = iLoadImage(char6[i]);
    }
	
    for (int i = 0; i <10; i++)
    {
        charRun[i] = iLoadImage(char2[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        charJump[i] = iLoadImage(char3[i]);
    }
}




void Loading_Screen() //Load Screen g_Screen 1
{

    iClear();
    iShowBMP(0,0, "Loading_Sc.bmp");
    iSetColor(255,69,0);
    iRectangle(100,40,1000,40);
	iRectangle(98,38,1004,44);
    iSetColor(0,0,255);
    iFilledRectangle(100,40,g_Load,40);
    iSetColor(255,0,0);
}


void Load()
{
    g_Load+=5;
    if(g_Load==1000)
        g_Screen1=2;
}
/*
function iDraw() is called again and again by the system.

*/


void iDraw()
{
    iClear();

    if(g_Screen1==1)

        Loading_Screen();
    if(g_Screen1==2)
    {

        if ( bgIndex==-1)
        {   iShowBMP(0,0, "Menu_sc.bmp");
            iShowBMPAlternativeSkipWhite(400,420, "game name.bmp");
            iShowBMP(500,345, "start.bmp");
            iShowBMP(500,285, "inst.bmp");
            iShowBMP(500,225, "main story.bmp");
            iShowBMP(500,165,"high score.bmp");
            iShowBMP(500,105,  "about.bmp");
            iShowBMP(50,45, "exit.bmp");
        }

     if ( bgIndex==-1 && Highlight_Index ==0)
		{
		
		 iShowBMP(400,420, "high game name.bmp");
		
		}


	   if ( bgIndex==-1 && Highlight_Index ==1)
		{
		
		 iShowBMP(500,345, "high start.bmp");
		
		}

	   

	     if ( bgIndex==-1 && Highlight_Index ==2)
		{
		
		 iShowBMP(500,285, "high ins.bmp");
		
		}

          if ( bgIndex==-1 && Highlight_Index ==4)
		{
		
		 iShowBMP(500,225, "high Story.bmp");
		
		}


		    if ( bgIndex==-1 && Highlight_Index ==6)
		{
		
		 iShowBMP(500,165, "high high.bmp");
		
		}


          if ( bgIndex==-1 && Highlight_Index ==8)
		{
		
		 iShowBMP(500,105,"high about .bmp");
		
		}

  
		  if ( bgIndex==-1 && Highlight_Index ==9)
		{
		
		 iShowBMP(50,45, "high exit.bmp");
		
		}

  /*if (( bgIndex==1 && Highlight_Index ==3) || ( bgIndex==2 && Highlight_Index ==3) || ( bgIndex==1 && Highlight_Index ==3))
		{
		
		 iShowBMP(570,35, "high back.bmp");
		
		}

*/


        if(bgIndex==0)
        {
            iSetColor(255,255,255);

            iShowBMP(0, 0, "demo back.bmp");
            iShowBMP(450,300, "Enter Name.bmp");
            iText(500,420,"Please Enter Your Name");
            iText(425, 260, "Press 'Insert' to activate the box, 'Enter' to finish.");

        }



        if(bgIndex==0 && mode == 1) // name Input Screen
        {
            iSetColor(255,69,0);
            iShowBMP(450,300, "highlight.bmp");
            iText(540, 350, str,GLUT_BITMAP_TIMES_ROMAN_24);
        }


        if(bgIndex==0 && mode == 2) // start game
        {      
            for (int i=0; i<10; i++)
            {

                iShowBMP(upperbg[i].x,upperbg[i].y, upper[i]);

                iShowBMP(middlebg[i].x,middlebg[i].y, middle[i]);

                iShowBMP(lowerbg[i].x,lowerbg[i].y, lower[i]);

			

			 showVirus();
			 virus1.setPosition();
	         iShowImage(virus1.x,virus1.y,virus1.CharSizeH,virus1.CharSizeW,charV[0]);
			if(jump)
			{
				if(jumpUp)
				{
				iShowImage(player.x, player.y + charJumpCordinate, player.CharSizeH, player.CharSizeW,charJump[0]);
				}
				else 
				{
				iShowImage(player.x, player.y + charJumpCordinate,  player.CharSizeH, player.CharSizeW,charJump[1]);//charJump[1]
				}
			
			}
			else
			{
			 if(!stand)
                {
                   iShowImage(player.x, player.y, player.CharSizeH, player.CharSizeW,charRun[runIndex]);
				  
					standCounter++;
                    if(standCounter>=20)
                    {
                        standCounter=0;//
						runIndex=0;
                        stand= true;
                    }
                    
			 }
                else
                   {
					   iShowImage(player.x, player.y, 80, 80,charStand[0]);

			       }
              }
			
		if(run && (jump|| jumpUp|| stand||!stand))
			{
				if(runOn)
				
				  iShowImage(ku.x,ku.y+charJumpCordinate, ku.CharSizeW, ku.CharSizeH, kunai[0]);
				
		}}
         	
       iShowBMP(0, 0, "120.bmp");
         iText(10, 330, str2,GLUT_BITMAP_TIMES_ROMAN_24);
   }

        if(bgIndex==1)
        {
            iShowBMP(0, 0, "demo back.bmp");
         
        }

        if(bgIndex==2)
        {
            iShowBMP(0, 0, "demo back.bmp");
            iSetColor(0,0,0);
            iText(460, 350, str2,GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(bgIndex==3)
        {

            iShowBMP(0, 0, "demo back.bmp");   
        }

        if(bgIndex==4)
        {


            iShowBMP(0, 0, "demo back.bmp");

        }

        if(bgIndex==5)
        {
            exit(0);

        }

    }

}

void iPassiveMouse(int mx, int my)
{
   printf("x = %d, y= %d\n", mx, my); //highlight menu

   	if (bgIndex == -1)
		{
			if (mx>=420 && mx<= 770 && my>=430 && my<=540)
			{
				Highlight_Index = 0;
			}
    
			else if(mx>=500 && mx<= 700 && my>=345 && my<=385 )
            {
               Highlight_Index=1;
            }

        
			else if(mx>=500 && mx<= 700 && my>=285 && my<=325 )
            {
                 Highlight_Index=2;
            }

        
			else if(mx>=500 && mx<= 700 && my>=225 && my<=265 )
            {
                 Highlight_Index=4;
            }

      
   
        
			else  if(mx>=500 && mx<= 700 && my>=165 && my<=205 )
            {
                 Highlight_Index=6;
            }
   
        
			else  if(mx>=500 && mx<= 700 && my>=105 && my<=145 )
            {
                 Highlight_Index=8;
            }

       
			else  if(mx>=50 && mx<= 250 && my>=45 && my<=85 )
            {
                 Highlight_Index=9;
            }
			
			else
				  Highlight_Index=10;
        }
   
	


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
    if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=500 && mx<= 700 && my>=345 && my<=385 )
            {
                bgIndex=0;
            }

        }

    }

    if(bgIndex==0) // back to main menu
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75) //mx>=450 && mx<= 750 && my>=300 && my<=400
            {
                bgIndex=-1;
            }

        }

    }


    if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=500 && mx<= 700 && my>=285 && my<=325 )
            {
                bgIndex=1;
            }

        }

    }

    if(bgIndex==1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75 )
            {
                bgIndex=-1;
            }

        }

    }

    
	if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=500 && mx<= 700 && my>=225 && my<=265 )
            {
                bgIndex=2;
            }

        }

    }

    if(bgIndex==2)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75 )
            {
                bgIndex=-1;
            }

        }

    }

    if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=500 && mx<= 700 && my>=165 && my<=205 )
            {
                bgIndex=3;
            }

        }

    }

    if(bgIndex==3)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75 )
            {
                bgIndex=-1;
            }

        }

    }



	 if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=500 && mx<= 700 && my>=105 && my<=145 )
            {
                bgIndex=4;
            }

        }

    }

    if(bgIndex==4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75 )
            {
                bgIndex=-1;
            }

        }

    }
    if(bgIndex==-1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=50 && mx<= 250 && my>= 45 && my<=85 )
            {
                bgIndex=5;
            }

        }

    }
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
  if(mode == 1)
    {
        if(key == '\r')
        {
            mode = 2;
              Sound_Control(true);

            strcpy(str2, str);
            printf("%s\n", str2);
            for(i = 0; i < len; i++)
                str[i] = 0;
            len = 0;


        }
        else
        {
            str[len] = key;
            len++;
        }
    }

	if(key == ' ')
	{
	  if(!jump)
	  {
		  jump = true;
		  jumpUp= true;

	  }
	}
  if (key == 'a' || key == 'A')
    {
		
		
	  if(!run)
	  {
		  run = true;
		  runOn= true;

	  }

    }
}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE_UP,
 GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{

    if (key ==  GLUT_KEY_INSERT)
    {
        mode=1;
    }

    if (key == GLUT_KEY_PAGE_DOWN)
    {
		 if(play)
	   {  	
		   Sound_Control(true);
	        play = false;
	   }
	   else
	   {
	     Sound_Control(false);
	        play = true;
	   }

    }

    if(key == GLUT_KEY_HOME)
       bgIndex=-1;

    if (key ==  GLUT_KEY_UP)
    {
		if(player.y>=9 && player.y<=101)
		player.y+=10;
    }

    if (key ==  GLUT_KEY_DOWN)

    { if(player.y>9 && player.y<101)
		  player.y-=10;
    }

    if (key ==  GLUT_KEY_LEFT)
    {
        player.x-=10;
        runIndex--;
        if(runIndex < 0)
            //runIndex=3;
		 runIndex=9;

        stand=false;
    }


    if (key ==  GLUT_KEY_RIGHT)
    {
        player.x+=10;
        runIndex++;
        if(runIndex>=9)//3
            runIndex=0;


        stand=false;

    }

}

void  backgroundSetting()
{
    int sum=0;
    for(int i=0; i<10; i++)

    {   
		upperbg[i].y=170;
        middlebg[i].y=78;
        lowerbg[i].y=0;

        upperbg[i].x=sum;
        middlebg[i].x=sum;
        lowerbg[i].x=sum;

        sum+=120;
    }
}

void  backgroundMoving()

{
    for(int i=0; i<10; i++)

    {
        upperbg[i].x-=upperscreenspeed;
        middlebg[i].x-=middlescreenspeed;
        lowerbg[i].x-=lowerscreenspeed;

        if(upperbg[i].x<=0)
        {
            upperbg[i].x=screenWidth;

        }


        if(middlebg[i].x<=0)
        {
            middlebg[i].x=screenWidth;

        }


        if(lowerbg[i].x<=0)
        {
            lowerbg[i].x=screenWidth;
        }
    }

}

void jumping()
{
    if(jump)
{
	  if(jumpUp)
	{
    	charJumpCordinate+=8;
	    if(charJumpCordinate>=jumpLimite)
	    jumpUp= false;
	}

  else 
 {

	charJumpCordinate-=10;
	if(charJumpCordinate<0)
	{
	 jump=false;
	 charJumpCordinate =0;
	}
  }
}
}

void kunaiRun()
{
    if(run)
{
	  if(runOn)
	{
    	ku.x+=30;
	    if(ku.x>=1100)
	    runOn= false;
	}

  else 
 {  run=false;
	 ku.x =player.x;
	}
  
}

}
 void Sound_Control(bool musicOn)
{
	if (!mute)
	{
		if (musicOn)
		{
			if (bgIndex == 0 && mode == 2)
			{
				PlaySound("music\\intro.wav", NULL, SND_LOOP | SND_ASYNC); 
			}

			else if (gameover)
			{
				PlaySound(0,0,0); 
			}

			else
			{
				PlaySound(0,0,0); 
			}
		}

		else
		{
			PlaySound(0, 0, 0);
		}
	}
}
 

 bool current_collision = false;
bool last_collision = false;
//checkCollision(enemy_one1.x, enemy_one1.y, 190, 135, ground_player.x + ground_player.extended_x, ground_player.y + ground_player.extended_y, ground_player.dimension_x, ground_player.dimension_y))
/*This function checks if collision happened or not between two objects or characters and returns a bolean value.
It takes two objects' co-ordinates and dimensions as parameters.*/
bool checkCollision(int object1_x, int object1_y, int dim1_x, int dim1_y, int object2_x, int object2_y, int dim2_x, int dim2_y)
{
	current_collision = (object1_x >= object2_x && object1_x <= object2_x + dim2_x || object1_x + dim1_x >= object2_x && object1_x + dim1_x <= object2_x + dim2_x || object1_x <= object2_x && object1_x + dim1_x >= object2_x + dim2_x) &&
		(object1_y >= object2_y && object1_y <= object2_y + dim2_y || object1_y + dim1_y >= object2_y && object1_y + dim1_y <= object2_y + dim2_y || object1_y <= object2_y && object1_y + dim1_y >= object2_y + dim2_y);

	if (!last_collision && current_collision)
	{
		//cout << "True!" << endl;
		last_collision = current_collision;
		return true;
	}

	/*else if (last_collision && current_collision)
	{
		return false;
	}*/

	else if (last_collision && !current_collision)
	{
		//cout << "False!" << endl;
		last_collision = current_collision;
		return false;
	}

	/*else if (!last_collision && !current_collision)
	{
		return false;
	}*/

	else
	{
		//cout << object1_x << " " << object1_y << " " << dim1_x << " " << dim1_y << " " << object2_x << " " << object2_y << " " << dim2_x << " " << dim2_y << endl;
		return false;
	}
}

void showVirus()
{
	 virus2.PositionChange();
     iShowImage(virus2.x,virus2.y,virus2.CharSizeH,virus2.CharSizeW,charV[0]);


	if (virus2.x <= 1100)
	{
		virus2.state = true;
	}
	else
	{
		virus2.state = false;
	}	
}

/*void Power()
{            
	if (fire && (stand || !stand || jump ||jumpUp))
	           {
		        
				   ku.koi();
	              //iShowImage(bullet_x, ground_player.y + jumping_height + 40, 20, 10, bullet_image);
	            }
	
                
}*/
/*if (fire && (stand || !stand || jump ||jumpUp))
	{
		iShowImage(kunai_x + player.x + 110,  player.y + charJumpCordinate + 40, 20, 10, bullet_image);

		kunai_x=+5;

		if (kunai_x > 1520)
		{
			fire = false;
			kunai_x = player.x + 110;
		}

}
*/

int main()
{
    //place your own initialization codes here.
    len = 0;
    mode = 0;
    str[0]= 0;
    iSetTimer(10,Load);
    mode=0;

    backgroundSetting();

    iSetTimer(1, backgroundMoving);
	iSetTimer(0, jumping);
	iSetTimer(0, kunaiRun);
	//iSetTimer(2, Power);
	//iSetTimer(1, virus1.setPosition());
	//iSetTimer(1, virus2.PositionChange());
	///virus1.setLocation();
	//virus1.speed=.20;
    system("Color 1A"); //For only windows platform.
	cout << "The Saviour is loading! Please, wait!" << endl;
    iInitialize(screenWidth, screenHeight, "THE SAVIOUR");


    loadImage();
	

    iStart(); // it will start drawing

    return 0;
}

