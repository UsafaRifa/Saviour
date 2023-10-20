#include"iGraphics.h"
#include"bitmap_loader.h"
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define screenHeight 600
#define screenWidth 1195
#define upperscreenHeight
#define upperscreenWidth
#define upperscreenspeed 5
#define lowerscreenHeight
#define lowerscreenWidth
#define lowerscreenspeed 5
#define lvl2screenspeed 5
#define middlescreenHeight
#define middlescreenWidth
#define middlescreenspeed 5
#define screenHeight 600
#define screenWidth 1195
#define jumpLimite 200

char score_string[20];
int fireJump=0;
bool checkCollision(int object1_x, int object1_y, int dim1_x, int dim1_y, int object2_x, int object2_y, int dim2_x, int dim2_y);
void Sound_Control(bool musicOn);
void Char_Fire_Function();
bool state=false;
int introload=0;
int name_index = 0;
void BOSS_HEAL();
void BOSS_Fire_Function();
bool gameover=false;
bool mute = false;
bool musicOn;
bool musicOff;
bool play = false;
bool run=false;
bool runOn=false;
bool run1=false;
bool runOn1=false;
bool run2=false;
bool runOn2=false;
bool run3=false;
bool runOn3=false;
bool run4=false;
bool runOn4=false;
bool run5=false;
bool runOn5=false;
bool run6=false;
bool runOn6=false;
int standIndex=0;
int runIndex=0;
int player_rank;
void ScoreShow(int x, int y, int size, int score);
int score_x, score_y;
int score[6];
int scoreImage[11];
int bgIndex=-1;
int Highlight_Index =-1;
int i;
char str[100],str2[100];
int mode;
int g_Screen1=1;
int g_Load=0;
int len;
bool jump= false;
bool jumpUp = false;
int charJumpCordinate=0;
bool fire = false;
bool active_shield=false;
int charIndex=0;
bool stand=true;
int standCounter=0;
void showVirus();
void showVirus1();
void showVirus2();
void showStone1();
void showStone2();
void showStone3();
void showStone5();
void showVirus4();
void obstacle();
void positionHealthGem();
void Lvl2Load();
int lvl2_Load=0;
int  lvl2_Screen1=1;
int shield_count = 0;
int shield_bar[11];
int shieldImage[1];
int shieldImage2[1];
char charShield[][100]= {"Cc.png"};
char charShield2[][100]= {"sheild.png"};
char shield_bar_image[][100] = {"shield_bar000.png","shield_bar001.png","shield_bar002.png","shield_bar003.png", "shield_bar004.png","shield_bar005.png","shield_bar006.png", "shield_bar007.png","shield_bar008.png", "shield_bar009.png", "shield_bar010.png"};
void showShieldIcon();
bool current_collision = false;
bool last_collision = false;
char char1[][100] = {"charr\\1.png"};//stand char
char char2[][100] = {"charr\\4.png","charr\\5.png","charr\\6.png","charr\\7.png","charr\\8.png","charr\\9.png","charr\\10.png","charr\\11.png","charr\\12.png","charr\\13.png"};//run char
char char4[][100] = {"gv.png"};
char char6[][100] = {"charr\\14.png"};
char char3[][100] = {"charr\\2.png","charr\\3.png"};//jump
char char20[][100] = {"yv.png"};//yellow virus
char char5[][100] = {"Bv.png"};//violet virus
char vi1[][100]= {"Virus 2.png"};
char vi2[][100]= {"virus3.png"};
char st1[][100]= {"stone 1.png"};
char st2[][100]= {"stone 3.png"};
char st3[][100]= {"ss.png"};
char ob[][100]= {"obj.png"};
char spaceship[][100]= {"space ship.png"};
char f1[][100]= {"fire 2.png"};
char f2[][100]= {"fire.png"};
char b2[][100]= {"ship1.png","ship1.png","ship2.png","ship2.png","ship3.png","ship3.png","ship4.png","ship4.png","ship5.png"};
int charStand[1],charRun[10],charJump[2],charRun1[4], charV[1],kunai[1],v1[1],v2[1],s1[1],s2[1],s3[1],spaceShip[1],fire1[1],fire2[1],boss2[9],charC[1],charB[1],obj[1];
char middle[10][15]= {"bg\\1.bmp","bg\\2.bmp","bg\\3.bmp","bg\\4.bmp","bg\\5.bmp","bg\\6.bmp","bg\\7.bmp","bg\\8.bmp","bg\\9.bmp","bg\\10.bmp"};
char lvl[10][15]= {"bg\\aa.bmp","bg\\bb.bmp","bg\\cc.bmp","bg\\d.bmp","bg\\e.bmp","bg\\f.bmp","bg\\g.bmp","bg\\h.bmp","bg\\i.bmp","bg\\j.bmp"};
char lower[10][15]= {"bg\\1.bmp","bg\\2.bmp","bg\\3.bmp","bg\\4.bmp","bg\\5.bmp","bg\\6.bmp","bg\\7.bmp","bg\\8.bmp","bg\\9.bmp","bg\\10.bmp"};
char upper[10][15]= {"bg\\back0.bmp", "bg\\back1.bmp","bg\\back2.bmp","bg\\back3.bmp","bg\\back4.bmp","bg\\back5.bmp","bg\\back6.bmp","bg\\a.bmp","bg\\b.bmp","bg\\c.bmp"};
int health_bar[12];
char health_bar_image[12][33] = { "health_bar000.png", "health_bar001.png","health_bar002.png", "health_bar003.png", "health_bar004.png","health_bar005.png", "health_bar006.png", "health_bar007.png","health_bar008.png", "health_bar009.png", "health_bar010.png" };
char charScore[11][23] = {"numbers\\00.png", "numbers\\11.png","numbers\\22.png", "numbers\\33.png", "numbers\\44.png","numbers\\55.png", "numbers\\66.png", "numbers\\77.png","numbers\\88.png", "numbers\\99.png" };

void CheckPosition();
int s,j;
int playerCounter=0;
int Counter=9;
FILE *highscorefile;
char ch;
typedef struct Score_info Score_info;


struct Score_info
{

    char name[100];

    int score;


} score_info[1000];



typedef struct High_Score_info Hscore;


struct High_Score_info
{

    char name[100];

    int score;


} high_score_info[100];


void swap(Hscore *st1,Hscore *st2)
{
    Hscore temp;
    temp=*st1;
    *st1=*st2;
    *st2=temp;
}









struct Enemy
{
    double x, y;
    int charDimensionX, charDimensionY;
    bool state;
    int value;
    int index;
    double speed;

    Enemy(int _x, int _y, int _dimension_x, int _dimension_y, bool _state,double _speed)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        state = _state;
        speed  = _speed;
    }

    Enemy(int _x, int _y, int _dimension_x, int _dimension_y,bool _state, int _value, int _index)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        state = _state;
        value = _value;
        index = _index;
    }

    void PositionChange()

    {
        x -= speed;
        if(x<120)
            x=1100 ;
    }

    void PositionChange1()

    {
        if(x<=0)
        {
            y=10+rand()%(300);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }

    void PositionChange2()

    {
        if(x<=0)
        {
            y=10+rand()%(500);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }


    void PositionChange3()

    {
        if(x<=0)
        {
            y=0+rand()%(200);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }

    void PositionChange4()

    {
        if(x<=0)
        {
            y=10+rand()%(400);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }

    void PositionChange5()

    {
        if(x<=0)
        {
            y=10+rand()%(530);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }

    void PositionChange6()

    {
        if(x<=0)
        {
            y=10+rand()%(530);
            x=screenWidth;
        }
        else
        {
            x-=speed;
        }
    }

    void setPosition()
    {
        if(y<=0)
        {
            x=250+rand()%(1000);
            y=screenHeight;
        }
        else
        {
            y-=speed;
        }

    }
    void Reset(int _x, int _y, int _dimension_x, int _dimension_y, bool _state,double _speed)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        state = _state;
        speed  = _speed;
    }

    void reset(int _x, int _y,  int _dimension_x, int _dimension_y,bool _state, int _value, int _index)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        state = _state;
        value = _value;
        index = _index;
    }

} virus1(900,600,50,50,true,1),virus2(900,90,50,50,true,1), virus5(900,220,75,75,true,1),ku(140,120,32,20,true,30),ku1(140,120,32,20,true,30),virus3(900,400,50,50,true,.8),virus4(900,200,100,80,true,1),stone4(900,500,70,70,true,1),stone1(900,500,100,100,true,.5),stone2(900,300,100,100,true,.5),stone3(900,100,50,50,true,.4),fi1(140,300,40,20,true,100),stone5(800,80,20,20,true,1),fi5(140,300,40,20,true,100),fi2(900,305,70,70,true,100),fi3(900,305,70,70,true,100),fi4(900,305,70,70,true,100),BOSS(900,250,280,200, true, 100, 0),shield(900, 450, 50, 50,true, .6),o(140, 90, 100, 100,  true, .6),gem(140, 90, 100, 100,  true, .1);

struct Character
{
    int x, y;
    int charDimensionX, charDimensionY;
    int CharSizeW, CharSizeH;
    bool visible;
    int score;
    int health;

    void Reset(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _visible, int _score, int _health)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        CharSizeW = _extended_x;
        CharSizeH = _extended_y;

        visible = _visible;
        score = _score;
        health = _health;

    }

    Character	(int _x, int _y, int _dimension_x, int _dimension_y, int _extended_x, int _extended_y, bool _visible, int _score, int _health)
    {
        x = _x;
        y = _y;
        charDimensionX= _dimension_x;
        charDimensionY = _dimension_y;
        CharSizeW = _extended_x;
        CharSizeH = _extended_y;

        visible = _visible;
        score = _score;
        health = _health;


    }




} player(140, 90, 100, 100, 0, 0, true, 0, 100),player2(140, 300, 100, 100, 0, 0, true, 100, 100);






struct background
{
    int x;
    int y;
};
background lvlbg[10];
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
        charC[i] = iLoadImage(char20[i]);
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

    for (int i = 0; i <= 9; i++)
    {
        scoreImage[i] = iLoadImage(charScore[i]);
    }

    for (int i = 0; i <= 10; i++)
    {
        health_bar[i] = iLoadImage(health_bar_image[i]);
    }

    for (int i = 0; i <1; i++)
    {
        v1[i] = iLoadImage(vi1[i]);
    }

    for (int i = 0; i <1; i++)
    {
        v2[i] = iLoadImage(vi2[i]);
    }

    for (int i = 0; i <1; i++)
    {
        s1[i] = iLoadImage(st1[i]);
    }
    for (int i = 0; i <1; i++)
    {
        s2[i] = iLoadImage(st2[i]);
    }
    for (int i = 0; i <1; i++)
    {
        s3[i] = iLoadImage(st3[i]);
    }

    for (int i = 0; i <1; i++)
    {
        spaceShip[i] = iLoadImage(spaceship[i]);
    }
    for (int i = 0; i <1; i++)
    {
        fire1[i] = iLoadImage(f1[i]);
    }

    for (int i = 0; i <1; i++)
    {
        fire2[i] = iLoadImage(f2[i]);
    }
    for (int i = 0; i <9; i++)
    {
        boss2[i] = iLoadImage(b2[i]);
    }

    for (int i = 0; i <= 11; i++)
    {
        shield_bar[i] = iLoadImage(shield_bar_image[i]);

    }


    for (int i = 0; i < 1; i++)
    {
        shieldImage[i] = iLoadImage(charShield[i]);

    }


    for (int i = 0; i < 1; i++)
    {
        shieldImage2[i] = iLoadImage( charShield2[i]);

    }

    for (int i = 0; i <1; i++)
    {
        charB[i] = iLoadImage(char5[i]);
    }
    for (int i = 0; i <1; i++)
    {
        obj[i] = iLoadImage(ob[i]);
    }


}

void Loading_Screen() //Load Screen g_Screen 1
{

    iClear();
    iShowBMP(0,0, "Loading_Sc.bmp");
    if(introload%4==0)//blink the load

    {

        iShowBMPAlternativeSkipWhite(400,420, "game name.bmp");
        iShowImage(900, 300, 100,100,v2[i] );
        iShowImage(800, 300, 100,100, charV[i]);
        iShowImage(900, 500, 100,100,  v1[i] );
        iShowImage(600, 300, 100,100, charC[i]);
        iShowImage(50, 435, 100,100, charV[i]);
        iShowImage(150, 270, 100,100, charV[i]);
        iShowImage(400, 150, 100,100, charV[i]);
        iShowImage(300, 250, 100,100, v2[i]);
        iShowImage(550, 200, 100,100,charC[i] );
        iShowImage(900, 200, 100,100, charV[i]);
        iShowImage(250, 150, 100,100, charV[i]);
        iShowImage(100, 100, 100,100,   v1[i] );
    }


    iSetColor(255,69,0);
    iRectangle(100,40,1000,40);
    iRectangle(98,38,1004,44);
    iSetColor(0,0,255);
    iFilledRectangle(100,40,g_Load,40);
    iSetColor(255,0,0);
    iSetColor(255,0,0);
    if(introload%4==0)//blink the load
    {
        iSetColor(255,255,255);
        iText(500,54,"Loading",GLUT_BITMAP_TIMES_ROMAN_24 );
    }


}

void introMove() //introLoading move
{
    introload++;
}



void lvl2_Loading_Screen()
{

    iClear();

    iShowBMP(0,0,"Loading_Sc.bmp");

    iSetColor(255,69,0);
    iRectangle(100,40,1000,40);
    iRectangle(98,38,1004,44);
    iSetColor(0,0,255);
    iFilledRectangle(100,40,lvl2_Load,40);
    iSetColor(255,0,0);
}


void Load()
{
    g_Load+=5;
    if(g_Load==1000)
        g_Screen1=2;
}


void Lvl2Load()
{
    lvl2_Load+=5;
    if(lvl2_Load==1000)
        lvl2_Screen1=2;
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
        {
            Sound_Control(true);
            iShowBMP(0,0, "Menu_sc.bmp");
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
            //showHighScores();
        }


        if ( bgIndex==-1 && Highlight_Index ==8)
        {

            iShowBMP(500,105,"high about .bmp");

        }


        if ( bgIndex==-1 && Highlight_Index ==9)
        {

            iShowBMP(50,45, "high exit.bmp");

        }




        if(bgIndex==0 && mode == 0 && player.score<=100)
        {
            for (int i=0; i<10; i++)
            {

                iShowBMP(upperbg[i].x,upperbg[i].y, upper[i]);

                iShowBMP(middlebg[i].x,middlebg[i].y, middle[i]);

                iShowBMP(lowerbg[i].x,lowerbg[i].y, lower[i]);



                showVirus();
                if (checkCollision(virus2.x, virus2.y, virus2.charDimensionX, virus2.charDimensionY, player.x + player.CharSizeW,player.y + player.CharSizeH, player.charDimensionX, player.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        if (!active_shield)
                        {
                            if (player.health >= 10)
                            {
                                player.health -= 10;
                            }
                            else
                            {
                                player.health = 0;
                                mode=3;
                                Sound_Control(true);
                                bgIndex=10;
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        virus2.state = false;
                        virus2.x = 1100 + rand() % 120;
                    }
                }

                showVirus4();
                if (checkCollision(virus5.x, virus5.y, virus4.charDimensionX, virus5.charDimensionY, player.x + player.CharSizeW,player.y + player.CharSizeH, player.charDimensionX, player.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        if (!active_shield)
                        {
                            if (player.health >= 10)
                            {
                                player.health -= 10;
                            }
                            else
                            {
                                player.health = 0;
                                mode=3;
                                bgIndex=10;
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        virus5.state = false;
                        virus5.x = 1100 + rand() % 120;
                    }
                }



                virus1.setPosition();
                iShowImage(virus1.x,virus1.y,virus1.charDimensionX,virus1.charDimensionY,charV[0]);

                if (checkCollision(virus1.x, virus1.y, virus1.charDimensionX, virus1.charDimensionY, player.x + player.CharSizeW,player.y + player.CharSizeH, player.charDimensionX, player.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        if (!active_shield)
                        {
                            if (player.health >= 10)
                            {
                                player.health -= 10;
                            }
                            else
                            {
                                player.health = 0;
                                mode=3;
                                Sound_Control(true);
                                bgIndex=10;
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        virus1.state = false;
                        virus1.x = 250+rand()%(1000);
                    }
                }


                if(jump)
                {
                    if(jumpUp)
                    {
                        iShowImage(player.x, player.y + charJumpCordinate, player.charDimensionX, player.charDimensionY,charJump[0]);
                    }
                    else
                    {
                        iShowImage(player.x, player.y + charJumpCordinate,  player.charDimensionX, player.charDimensionY,charJump[1]);
                    }

                }
                else
                {
                    if(!stand)
                    {
                        iShowImage(player.x, player.y, player.charDimensionX, player.charDimensionY,charRun[runIndex]);

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
                        iShowImage(player.x, player.y, player.charDimensionX, player.charDimensionY,charStand[0]);

                    }
                }

                if(run && (jump|| jumpUp|| stand||!stand))
                {
                    if(runOn)

                        iShowImage(ku.x,ku.y+charJumpCordinate, ku.charDimensionX, ku.charDimensionY, kunai[0]);
                    if (run && virus2.state && checkCollision(virus2.x, virus2.y, virus2.charDimensionX, virus2.charDimensionY, ku.x,ku.y, ku.charDimensionX, ku.charDimensionY))
                    {
                        if ((jump|| jumpUp|| stand||!stand))
                        {
                            player.score += 5;
                            run = false;
                            virus2.x = 1100 + rand() % 120;
                            ku.x = player.x+60;

                        }
                    }
                    if (run && virus1.state && checkCollision(virus1.x, virus1.y, virus1.charDimensionX, virus1.charDimensionY, ku.x,ku.y, ku.charDimensionX, ku.charDimensionY))
                    {
                        if ((jump|| jumpUp|| stand||!stand))
                        {
                            player.score += 5;
                            run = false;
                            virus1.x = 1100 + rand() % 120;
                            ku.x = player.x+60;

                        }
                    }
                }

                if(run1 && (jump|| jumpUp|| stand||!stand))
                {
                    if(runOn1)
                        iRotate(ku1.x,ku1.y,45);
                    iShowImage(ku1.x,ku1.y+charJumpCordinate, ku1.charDimensionX, ku1.charDimensionY, kunai[0]);
                    iUnRotate();
                    if (run1 && virus1.state && checkCollision(virus1.x, virus1.y, virus1.charDimensionX, virus1.charDimensionY, ku1.x,ku1.y, ku1.charDimensionX, ku1.charDimensionY))
                    {
                        if ((jump|| jumpUp|| stand||!stand))
                        {
                            player.score += 10;
                            run1 = false;
                            virus1.x = 250+rand()%(1000);
                            ku1.x = player.x+60;

                        }
                    }
                    if (run1 && virus2.state && checkCollision(virus2.x, virus2.y, virus2.charDimensionX, virus2.charDimensionY, ku1.x,ku1.y, ku1.charDimensionX, ku1.charDimensionY))
                    {
                        if ((jump|| jumpUp|| stand||!stand))
                        {
                            player.score += 5;
                            run1 = false;
                            virus2.x = 250+rand()%(1000);
                            ku1.x = player.x+60;

                        }
                    }
                }

                if(run1 && (jump|| jumpUp|| stand||!stand))
                {
                    if(runOn1)
                        iRotate(ku1.x,ku1.y,45);
                    iShowImage(ku1.x,ku1.y+charJumpCordinate, ku1.charDimensionX, ku1.charDimensionY, kunai[0]);
                    iUnRotate();
                    if (run1 && virus5.state && checkCollision(virus5.x, virus5.y, virus5.charDimensionX, virus5.charDimensionY, ku1.x,ku1.y, ku1.charDimensionX, ku1.charDimensionY))
                    {
                        if ((jump|| jumpUp|| stand||!stand))
                        {
                            player.score += 5;
                            run1 = false;
                            virus5.x = 250+rand()%(1000);
                            ku1.x = player.x+60;

                        }
                    }

                }


                obstacle();
                if (checkCollision(stone5.x, stone5.y, stone5.charDimensionX, stone5.charDimensionY, player.x + player.CharSizeW,player.y + player.CharSizeH, player.charDimensionX, player.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        if (!active_shield)
                        {
                            if (player.health >= 10)
                            {
                                player.health -= 10;
                            }
                            else
                            {
                                player.health = 0;
                                mode=3;
                                bgIndex=10;
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        stone5.state = false;
                        stone5.x = 1100 + rand() % 120;
                    }
                }




                if (o.state)
                {
                    if (checkCollision(player.x + player.CharSizeW, player.y +player.  CharSizeW + charJumpCordinate, 80, 130, o.x, o.y, o.charDimensionX, o.charDimensionY))
                    {
                        //cout << "Boom!" << endl;
                        if (shield_count <= 9)
                        {
                            shield_count++;
                        }

                        o.state = false;
                    }
                }
                if (active_shield)
                {
                    iShowImage(player.x -10, player.y -15 +charJumpCordinate, 140, 147,shieldImage[0] );

                }

                void shieldPositionChange();
                iShowImage(o.x, o.y, 30, 35, shieldImage2[0] );

                {
                    static int choose_call = 0;



                    if (choose_call % 40 == 0)
                    {
                        o.state = false;
                    }

                    if (choose_call %800 == 0)
                    {
                        o.x = rand() % (1520 - o.charDimensionX);
                        o.y = 70 + rand() % 200;
                        o.state = true;

                    }


                    choose_call++;

                    if (choose_call >= 1200)
                    {
                        choose_call = 0;
                    }
                }

                if (gem.state)
                {
                    if (checkCollision(player.x + player.CharSizeW, player.y +player.  CharSizeW + charJumpCordinate, 80, 130, gem.x, gem.y, gem.charDimensionX, gem.charDimensionY))
                    {
                        //cout << "Boom!" << endl;
                        if (player.health <= 90)
                        {
                            player.health+=10;
                        }

                        gem.state = false;
                    }
                }

                void positionHealthGem();
                iShowImage(gem.x, gem.y,50,50, s3[0] );
                {
                    static int choose_call = 0;



                    if (choose_call % 20 == 0)
                    {
                        gem.state = false;
                    }

                    if (choose_call % 400 == 0)
                    {
                        gem.x = rand() % (1100 - gem.charDimensionX);
                        gem.y = 70 + rand() % 200;
                        gem.state = true;
                    }


                    choose_call++;

                    if (choose_call >= 1500)
                    {
                        choose_call = 0;
                    }




                }





            }

            iShowBMP(0, 0, "120.bmp");

            iShowImage(30, 250, 200, 200, health_bar[player.health / 10]);
            iShowImage(80, 250, 200, 200,  shield_bar [shield_count]);
            sprintf(score_string, "%d", player.score);
            iSetColor(255, 255, 255);
            iText(10, 500, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
            iText(22,130, "SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
            ScoreShow(10, 50, 20, player.score);
           //iText(0,20, "Press P to pause",GLUT_BITMAP_HELVETICA_12);


        }

    }


   


    if(bgIndex==0 && mode == 0 &&(player.score>=100 && player2.score<=300))
    {

        for (int i=0; i<10; i++)
        {
            iShowBMP(lvlbg[i].x,lvlbg[i].y, lvl[i]);




            showVirus1();
            if (checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    virus3.state = false;
                    virus3.y=10+rand()%(300);
                    virus3.x=screenWidth;
                }
            }

            showVirus2();
            if (checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, player2.x + player2.CharSizeW,player2.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    virus4.state = false;
                    virus4.y=10+rand()%(500);
                    virus4.x=screenWidth;
                }
            }

            /////////////////////////////////////////////
            showStone1();
            if (checkCollision(stone1.x,stone1.y, stone1.charDimensionX, stone1.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    stone1.state = false;
                    stone1.y=10+rand()%(300);
                    stone1.x=screenWidth;
                }
            }

            showStone2();
            if (checkCollision( stone2.x,stone2.y,stone2.charDimensionX, stone2.charDimensionY, player2.x + player2.CharSizeW,player2.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    stone2.state = false;
                    stone2.y=10+rand()%(500);
                    stone2.x=screenWidth;
                }
            }

            showStone3();
            if (checkCollision(stone3.x,stone3.y, stone3.charDimensionX, stone3.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {


                    if (player2.health <= 90)
                    {
                        player2.health =10 ;
                    }



                    stone3.state = false;
                    stone3.y=10+rand()%(300);
                    stone3.x=screenWidth;
                }
            }

            iShowImage(player2.x, player2.y, player2.charDimensionX, player2.charDimensionY, spaceShip[0]);



            if(run2 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn2)

                    iShowImage(fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY, fire1[0]);
                if (run2 && virus3.state && checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 10;
                        run2 = false;
                        virus3.y=10+rand()%(500);
                        virus3.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
                if (run2 && virus4.state && checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 10;
                        run2 = false;
                        virus4.y=10+rand()%(500);
                        virus4.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
            }

            ///////

            if(run2 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn2)

                    iShowImage(fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY, fire1[0]);
                if (run2 && stone1.state && checkCollision(stone1.x, stone1.y, stone1.charDimensionX, stone1.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        stone1.y=10+rand()%(500);
                        stone1.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
                if (run2 && stone2.state && checkCollision(stone2.x, stone2.y, stone2.charDimensionX, stone2.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        stone2.y=10+rand()%(500);
                        stone2.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
            }

            if(run3 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn3)

                    iShowImage(fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY, fire1[0]);
                if (run3 && virus3.state && checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        virus3.y=10+rand()%(500);
                        virus3.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
                if (run3 && virus4.state && checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        virus4.y=10+rand()%(500);
                        virus4.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
            }
            if(run3 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn3)

                    iShowImage(fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY, fire1[0]);
                if (run3 && stone1.state && checkCollision(stone1.x, stone1.y, stone1.charDimensionX, stone1.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        stone1.y=10+rand()%(500);
                        stone1.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
                if (run3 && stone2.state && checkCollision(stone2.x, stone2.y, stone2.charDimensionX, stone2.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        stone2.y=10+rand()%(500);
                        stone2.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
            }


            showShieldIcon();
            if (shield.state)
            {
                if (checkCollision(player2.x + player2.CharSizeW, player2.y +player2.CharSizeW, 100, 100, shield.x, shield.y, shield.charDimensionX, shield.charDimensionY))
                {

                    if (shield_count <= 10)
                    {
                        shield_count++;

                    }
                    shield.state = false;
                    shield.y=10+rand()%(500);
                    shield.x=screenWidth;

                }
            }

            if (active_shield)
            {
                iShowImage(player2.x - 50, player2.y - 50, 200, 200,shieldImage[0]);

            }



        }

		

        iShowBMP(0, 0, "120.bmp");

        iShowImage(30, 250, 200, 200, health_bar[player2.health / 10]);
        iShowImage(80, 250, 200, 200,  shield_bar [shield_count]);
        sprintf(score_string, "%d", player2.score);
        iSetColor(255, 255, 255);
        iText(10, 500, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(22,130, "SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        ScoreShow(10, 50, 20, player2.score);
		//iText(0,20, "Press P to pause",GLUT_BITMAP_HELVETICA_12);

    }



    if(bgIndex==0 && mode == 0 && player2.score>=300)
    {


        for (int i=0; i<10; i++)
        {
            iShowBMP(lvlbg[i].x,lvlbg[i].y, lvl[i]);


            iShowImage(player2.x, player2.y, player2.charDimensionX, player2.charDimensionY, spaceShip[0]);

            showStone3();
            if (checkCollision(stone3.x,stone3.y, stone3.charDimensionX, stone3.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health <= 90)
                        {
                            player2.health +=10 ;
                        }
                        else
                        {
                            player2.health = 100;

                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    stone3.state = false;
                    stone3.y=10+rand()%(300);
                    stone3.x=screenWidth;
                }
            }

            if (BOSS.state)
            {
                iShowImage(BOSS.x, BOSS.y, BOSS.charDimensionX, BOSS.charDimensionY, boss2[BOSS.index]);//BOSS.index
                iSetColor(255, 0, 0);
                iFilledRectangle(1040, 420, BOSS.value, 10);
                iSetColor(0, 0, 0);
                iRectangle(1040, 420, 100, 10);
            }

            if(run2 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn2)

                    iShowImage(fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY, fire1[0]);
                if (run2 && BOSS.state && checkCollision(BOSS.x,BOSS.y, BOSS.charDimensionX, BOSS.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        {
                            player2.score += 100;
                            run2 = false;
                            fi1.x = player2.x+60;
                            fi1.y = player2.y+60;
                            BOSS.value -= 10;
                        }
                        if (BOSS.value <= 0)
                        {
                            BOSS.state = false;
                            bgIndex=11;
                            mode=4;
                        }

                    }
                }

            }

            if(run3 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn3)

                    iShowImage(fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY, fire1[0]);
                if (run3 && BOSS.state && checkCollision(BOSS.x,BOSS.y, BOSS.charDimensionX, BOSS.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 100;
                        run3 = false;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                        BOSS.value -= 10;
                        if (BOSS.value <= 0)
                        {
                            BOSS.state = false;
                            bgIndex=11;
                            mode=4;
                        }

                    }
                }

            }


            if(run5 && BOSS.state )
            {
                if(runOn5)
                    iShowImage(fi2.x,fi2.y, fi2.charDimensionX, fi2.charDimensionY, fire2[0]);
                if (run5 && BOSS.state && checkCollision(player2.x,player2.y, player2.charDimensionX, player2.charDimensionY, fi2.x,fi2.y, fi2.charDimensionX, fi2.charDimensionY))
                {
                    if (BOSS.state)
                    {
                        if (!active_shield)
                        {
                            if (player2.health >= 10)
                            {
                                player2.health -= 10;

                            }
                            else
                            {
                                player2.health = 0;
                                mode=3;
                                Sound_Control(true);
                                bgIndex=10;
                              
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        run5 = false;
                        fi2.x =900;
                    }
                }
            }
            if(run4 && BOSS.state)
            {
                if(runOn4)

                    iShowImage(fi3.x,fi3.y, fi3.charDimensionX, fi3.charDimensionY, fire2[0]);

                if (run4 && BOSS.state && checkCollision(player2.x, player2.y, player2.charDimensionX, player2.charDimensionY, fi3.x,fi3.y, fi3.charDimensionX, fi3.charDimensionY))
                {

                    if (BOSS.state)
                    {
                        if (!active_shield)
                        {
                            if (player2.health >= 10)
                            {
                                player2.health -= 10;

                            }
                            else
                            {
                                player2.health = 0;
                                mode=3;
                                Sound_Control(true);
                                bgIndex=10;
                                
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        run4 = false;
                        fi3.x =900;
                    }


                }
            }



            if(run6 && BOSS.state)
            {
                if(runOn6)

                    iShowImage(fi4.x,fi4.y, fi4.charDimensionX, fi4.charDimensionY, fire2[0]);

                if (run6 && BOSS.state && checkCollision(player2.x, player2.y, player2.charDimensionX, player2.charDimensionY, fi4.x,fi4.y, fi4.charDimensionX, fi4.charDimensionY))
                {
                    if (BOSS.state)
                    {
                        if (!active_shield)
                        {
                            if (player2.health >= 10)
                            {
                                player2.health -= 10;

                            }
                            else
                            {
                                player2.health = 0;
                                mode=3;
								bgIndex=10;
                                Sound_Control(true);
                                
                               
                            }
                        }
                        else
                        {
                            shield_count--;
                            if (shield_count <= 0)
                            {
                                active_shield = false;
                            }
                        }
                        run6 = false;
                        fi4.x =900;
                    }
                }
            }


            showVirus1();
            if (checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                           
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    virus3.state = false;
                    virus3.y=10+rand()%(300);
                    virus3.x=screenWidth;
                }
            }

            showVirus2();
            if (checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, player2.x + player2.CharSizeW,player2.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                           
                           
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    virus4.state = false;
                    virus4.y=10+rand()%(500);
                    virus4.x=screenWidth;
                }
            }

            /////////////////////////////////////////////
            showStone1();
            if (checkCollision(stone1.x,stone1.y, stone1.charDimensionX, stone1.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                           
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    stone1.state = false;
                    stone1.y=10+rand()%(300);
                    stone1.x=screenWidth;
                }
            }

            showStone2();
            if (checkCollision( stone2.x,stone2.y,stone2.charDimensionX, stone2.charDimensionY, player2.x + player2.CharSizeW,player2.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {
                    if (!active_shield)
                    {
                        if (player2.health >= 10)
                        {
                            player2.health -= 10;
                        }
                        else
                        {
                            player2.health = 0;
                            mode=3;
                            Sound_Control(true);
                            bgIndex=10;
                          
                        }
                    }
                    else
                    {
                        shield_count--;
                        if (shield_count <= 0)
                        {
                            active_shield = false;
                        }
                    }
                    stone2.state = false;
                    stone2.y=10+rand()%(500);
                    stone2.x=screenWidth;
                }
            }

            showStone3();
            if (checkCollision(stone3.x,stone3.y, stone3.charDimensionX, stone3.charDimensionY, player2.x + player2.CharSizeW,player.y + player2.CharSizeH, player2.charDimensionX, player2.charDimensionY))
            {
                if ((jump|| jumpUp|| stand||!stand))
                {


                    if (player2.health <= 90)
                    {
                        player2.health +=10 ;
                    }


                    stone3.state = false;
                    stone3.y=10+rand()%(300);
                    stone3.x=screenWidth;
                }
            }
            //////////////////////////////////
            iShowImage(player2.x, player2.y, player2.charDimensionX, player2.charDimensionY, spaceShip[0]);



            if(run2 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn2)

                    iShowImage(fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY, fire1[0]);
                if (run2 && virus3.state && checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        virus3.y=10+rand()%(500);
                        virus3.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
                if (run2 && virus4.state && checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        virus4.y=10+rand()%(500);
                        virus4.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
            }

            ///////

            if(run2 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn2)

                    iShowImage(fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY, fire1[0]);
                if (run2 && stone1.state && checkCollision(stone1.x, stone1.y, stone1.charDimensionX, stone1.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        stone1.y=10+rand()%(500);
                        stone1.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
                if (run2 && stone2.state && checkCollision(stone2.x, stone2.y, stone2.charDimensionX, stone2.charDimensionY, fi1.x,fi1.y, fi1.charDimensionX, fi1.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run2 = false;
                        stone2.y=10+rand()%(500);
                        stone2.x=screenWidth;
                        fi1.x = player2.x+60;
                        fi1.y = player2.y+60;
                    }
                }
            }




            if(run3 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn3)

                    iShowImage(fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY, fire1[0]);
                if (run3 && virus3.state && checkCollision(virus3.x, virus3.y, virus3.charDimensionX, virus3.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        virus3.y=10+rand()%(500);
                        virus3.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
                if (run3 && virus4.state && checkCollision(virus4.x, virus4.y, virus4.charDimensionX, virus4.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        virus4.y=10+rand()%(500);
                        virus4.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
            }
            if(run3 && (jump|| jumpUp|| stand||!stand))
            {
                if(runOn3)

                    iShowImage(fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY, fire1[0]);
                if (run3 && stone1.state && checkCollision(stone1.x, stone1.y, stone1.charDimensionX, stone1.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        stone1.y=10+rand()%(500);
                        stone1.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
                if (run3 && stone2.state && checkCollision(stone2.x, stone2.y, stone2.charDimensionX, stone2.charDimensionY, fi5.x,fi5.y, fi5.charDimensionX, fi5.charDimensionY))
                {
                    if ((jump|| jumpUp|| stand||!stand))
                    {
                        player2.score += 5;
                        run3 = false;
                        stone2.y=10+rand()%(500);
                        stone2.x=screenWidth;
                        fi5.x = player2.x+60;
                        fi5.y = player2.y+60;
                    }
                }
            }



            showShieldIcon();
            if (shield.state)
            {
                if (checkCollision(player2.x + player2.CharSizeW, player2.y +player2.CharSizeW, 100, 100, shield.x, shield.y, shield.charDimensionX, shield.charDimensionY))
                {

                    if (shield_count <= 10)
                    {
                        shield_count++;

                    }
                    shield.state = false;
                    shield.y=10+rand()%(500);
                    shield.x=screenWidth;

                }
            }
            if (active_shield)
            {
                iShowImage(player2.x - 50, player2.y - 50, 200, 200,shieldImage[0]);
            }





        }
		





        iShowBMP(0, 0, "120.bmp");

        iShowImage(20, 250, 200, 200, health_bar[player2.health / 10]);
        iShowImage(80, 250, 200, 200,  shield_bar [shield_count]);
        sprintf(score_string, "%d", player2.score);
        iSetColor(0, 0, 0);
        iText(10, 500, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(10, 200, "NAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(2, 165,str2, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(22,130, "SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        ScoreShow(10, 50, 20, player2.score);
		//iText(0,20, "Press P to pause",GLUT_BITMAP_HELVETICA_12);

    }


    /*if(bgIndex==10 && mode==3)
    {

        gameover=true;
        iShowBMP(0, 0, "game over.bmp");
        sprintf(score_string, "%d", player2.score);
        iText(25, 200, "NAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25, 165, str2,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200, 500, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
        player.health=100;
        checkPosition();


        if(introload%4==0)//blink the load
        {
            iSetColor(255,0,0);
            iText(500,54,"Press HOME for back to the Menu",GLUT_BITMAP_TIMES_ROMAN_24 );
        }



    }




    if(bgIndex==11 && mode==4)
    {
        iSetColor(255, 255, 255);
        iShowBMP(0, 0, "game jitlam.bmp");
        sprintf(score_string, "%d", player2.score);
        iText(440,440, "NAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440, 400, str2,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(630,440, "SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(635, 400, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
        player.health=100;
    }*/

    /*if(bgIndex==6 && mode==1)
    {

    FILE *fp = fopen("saveload.txt", "w");


    			fprintf(fp, "%d\n", player.x);
    			fprintf(fp, "%d\n", player.y);
    			fprintf(fp, "%d\n", player2.x);
    			fprintf(fp, "%d\n", player2.y);

    			fprintf(fp, "%d\n", player.score);
    			fprintf(fp, "%d\n", player.health);
    			fprintf(fp, "%d\n", player2.score);
    			fprintf(fp, "%d\n", player2.health);

    			fprintf(fp, "%d\n", shield_count);
    			fprintf(fp, "%d\n", bgIndex);
    			fprintf(fp, "%d\n", mode);
    			fprintf(fp, "%d\n", BOSS.x);
    			fprintf(fp, "%d\n", BOSS.Y);
    			fprintf(fp, "%d\n", BOSS.value);
    			fprintf(fp, "%d\n", BOSS.state);



    			fclose(fp);
    		//////


    	}

    	if (bgIndex == 1 && filesave == 2){
    		play = 1;
    		FILE *fp = fopen("saveload.txt", "r");

    		    fscanf(fp, "%d\n", &player.x);
    			fscanf(fp, "%d\n", &player.y);
    			fscanf(fp, "%d\n", &player2.x);
    			fscanf(fp, "%d\n", &player2.y);
    			fscanf(fp, "%d\n", &player.score);
    			fscanf(fp, "%d\n", &player.health);
    			fscanf(fp, "%d\n", &player2.score);
    			fscanf(fp, "%d\n", &player2.health);
    			fscanf(fp, "%d\n", &shield_count);
    			fscanf(fp, "%d\n", &bgIndex);
    			fscanf(fp, "%d\n", &mode);
    			fscanf(fp, "%d\n", &BOSS.x);
    			fscanf(fp, "%d\n", &BOSS.Y);
    			fscanf(fp, "%d\n", &BOSS.value);
    			fscanf(fp, "%d\n", &BOSS.state);

    		fclose(fp);
    		filesave = 3;
    	}
    }*/

    if(bgIndex==10 && mode==3)
    {
        iSetColor(255,255,255);

        iShowBMP(0, 0, "demo back.bmp");
        iShowBMP(450,300, "Enter Name.bmp");
        iText(500,420,"Please Enter Your Name");
        iText(425, 260, "Press 'Insert' to activate the box, 'Enter' to finish.");
    }
    if( bgIndex==10 && mode==4)
    {
        iShowBMP(0, 0, "demo back.bmp");
        iSetColor(255,69,0);
        iShowBMP(450,300, "highlight.bmp");
        iText(540, 350, str,GLUT_BITMAP_TIMES_ROMAN_24);
    }





    if(bgIndex==10 && mode==5)
    {
        iShowBMP(0, 0, "game over.bmp");
        sprintf(score_string, "%d", player2.score);
        iText(550, 90, "NAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(550, 50, str2,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(750, 90, "Score",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(750, 50, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
		
        if(introload%4==0)//blink the load
        {
            iSetColor(255,0,0);
            iText(500,500,"Press HOME for back to the Menu",GLUT_BITMAP_TIMES_ROMAN_24 );
        }
		//iText(600,50, "Press N to victory page",GLUT_BITMAP_HELVETICA_12);
       
    }

    if(bgIndex==11 && mode==6)
    {
        iSetColor(255, 255, 255);
        iShowBMP(0, 0, "game jitlam.bmp");
        sprintf(score_string, "%d", player2.score);
        iText(440,440, "NAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440, 400, str2,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(630,440, "SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(635, 400, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
      
    }



    if(bgIndex==1)
    {
        iShowBMP(0, 0, "ins.bmp");
        iShowBMP(600, 30, "backkk.bmp");

    }

    if(bgIndex==2)
    {
        iShowBMP(0, 0, "Story.bmp");
        iShowBMP(600, 30, "backkk.bmp");
    }

    if(bgIndex==3)
    {

        iShowBMP(0, 0, "Score.bmp");
        iShowBMP(600, 30, "backkk.bmp");
        CheckPosition();
    }

    if(bgIndex==4)
    {

        iShowBMP(0, 0, "about us.bmp");
        iShowBMP(600, 30, "backkk.bmp");


    }

    if(bgIndex==5)
    {
        exit(0);

    }

}



void iPassiveMouse(int mx, int my)
{
    printf("x = %d, y= %d\n", mx, my);

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

    if(bgIndex==0)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=570 && mx<= 630 && my>=35 && my<=75)
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
    if(mode == 4)
    {
        if(key == '\r')
        {
            mode = 5;
            Sound_Control(true);

            strcpy(str2, str);
            printf("%s\n", str2);
            //////////////////////
            highscorefile=fopen("HIGH SCORE.txt","a");


            fprintf(highscorefile,"%s %d\n",str2,player2.score);
            strcpy(high_score_info[playerCounter].name,str2);
            high_score_info[playerCounter].score=player2.score;
            playerCounter++;
            fclose(highscorefile);







            highscorefile=fopen("HIGH SCORE.txt","r");
            while((ch=fgetc(highscorefile))!=EOF)
            {


                if(ch=='\n')
                {

                    Counter++;

                }

            }

            for(int s=0; s<Counter; s++)
            {
                fscanf(highscorefile, "%s\t\t%d",&high_score_info[s].name,&high_score_info[s].score);
            }


            for( int s=0; s<Counter-1; s++)
            {
                for( int j=s+1; j<Counter; j++)
                {
                    if(high_score_info[s].score <= high_score_info[j].score)
                    {

                        swap(&high_score_info[s],&high_score_info[j]);

                    }
                }
            }
            fclose(highscorefile);

            highscorefile=fopen("HIGH SCORE.txt","w");
            for(int s=0; s<Counter; s++)
            {
                fprintf(highscorefile, "%s\t\t%d\n",high_score_info[s].name,high_score_info[s].score);
            }
            fclose(highscorefile);

            /////////////////////
            for(int i = 0; i < len; i++)
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

    if (key == 'd' || key == 'D')
    {


        if(!run2)
        {
            run2 = true;
            runOn2= true;

        }

    }

    if (key == 's' || key == 'S')
    {


        if(!run1)
        {
            run1 = true;
            runOn1= true;

        }

    }

    if (key == 'e' || key == 'E')
    {


        if(!run3)
        {
            run3 = true;
            runOn3= true;

        }

    }

    if (key == 'z' || key == 'Z')
    {
        if ( shield_count > 0)
        {
            if (!active_shield)
            {
                active_shield = true;
            }
            else
            {
                active_shield = false;
            }
        }
    }

	 if (key == 'N' || key == 'n')
    {

		bgIndex=11;
		mode=6;

    }
	 

	 if (key == 'M' || key == 'm')
    {

		BOSS.state=true;
        player.x=140;
        player.y=90;
        player2.x=140;
        player2.y=300;
        player.health=100;
        player2.health=100;
        player.score=0;
        player2.score=100;
        shield_count = 9;
        BOSS.x=900;
        BOSS.y=250;
        BOSS.value=100;
        bgIndex=-1;
        mode=0;

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
        mode=4;
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

    {
        BOSS.state=true;
        player.x=140;
        player.y=90;
        player2.x=140;
        player2.y=300;
        player.health=100;
        player2.health=100;
        player.score=0;
        player2.score=100;
        shield_count = 9;
        BOSS.x=900;
        BOSS.y=250;
        BOSS.value=100;
        bgIndex=-1;
        mode=0;




    }


    if (key ==  GLUT_KEY_UP)
    {
        player2.y+=40;
        //if(player.y>=9 && player.y<=101)
        //player.y+=10;
    }

    if (key ==  GLUT_KEY_DOWN)

    {
        player2.y-=40;
        //if(player.y>9 && player.y<101)
        //player.y-=10;
    }

    if (key ==  GLUT_KEY_LEFT)
    {
        player.x-=10;
        player2.x-=10;
        runIndex--;
        if(runIndex < 0)
            //runIndex=3;
            runIndex=9;

        stand=false;
    }


    if (key ==  GLUT_KEY_RIGHT)
    {
        player.x+=5;
        player2.x+=5;
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

void  backgroundSettinglvl2()
{
    int sum=120;
    for(int i=0; i<10; i++)

    {


        lvlbg[i].x=sum;


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

void  backgroundMovinglvl2()

{
    for(int i=0; i<10; i++)

    {
        lvlbg[i].x-=lvl2screenspeed;


        if(lvlbg[i].x<=0)
        {
            lvlbg[i].x=screenWidth;

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

            else if (bgIndex==10 && mode ==3)
            {
                PlaySound("music\\game over.wav", NULL, SND_LOOP | SND_ASYNC);
            }

            else
            {
                PlaySound("music\\start.wav", NULL, SND_LOOP | SND_ASYNC);
            }
        }

        else
        {
            PlaySound(0, 0, 0);
        }
    }
}





bool checkCollision(int object1_x, int object1_y, int dim1_x, int dim1_y, int object2_x, int object2_y, int dim2_x, int dim2_y)
{
    current_collision = ((object1_x >= object2_x && object1_x <= object2_x + dim2_x) ||( object1_x + dim1_x >= object2_x && object1_x + dim1_x <= object2_x + dim2_x )|| (object1_x <= object2_x && object1_x + dim1_x >= object2_x + dim2_x)) &&
                        ((object1_y >= object2_y && object1_y <= object2_y + dim2_y) || (object1_y + dim1_y >= object2_y && object1_y + dim1_y <= object2_y + dim2_y) || (object1_y <= object2_y && object1_y + dim1_y >= object2_y + dim2_y));

    if (!last_collision && current_collision)
    {

        last_collision = current_collision;
        return true;
    }

    else if (last_collision && !current_collision)
    {

        last_collision = current_collision;
        return false;
    }

    else
    {

        return false;
    }
}

void showVirus()
{
    virus2.PositionChange();
    iShowImage(virus2.x,virus2.y,virus2.charDimensionX,virus2.charDimensionY,charC[0]);


    if (virus2.x <= 1100)
    {
        virus2.state = true;
    }
    else
    {
        virus2.state = false;
    }
}

void showVirus1()
{
    virus3.PositionChange1();
    iShowImage(virus3.x,virus3.y,virus3.charDimensionX,virus3.charDimensionY,v1[0]);


    if (virus3.x <= 1100)
    {
        virus3.state = true;
    }
    else
    {
        virus3.state = false;
    }
}

void showVirus2()
{
    virus4.PositionChange2();
    iShowImage(virus4.x,virus4.y,virus4.charDimensionX,virus4.charDimensionY,v2[0]);


    if (virus4.x <= 1100)
    {
        virus4.state = true;
    }
    else
    {
        virus4.state = false;
    }
}

void showVirus4()
{
    virus5.PositionChange();
    iShowImage(virus5.x,virus5.y,virus5.charDimensionX,virus5.charDimensionY,charB[0]);


    if (virus5.x <= 1100)
    {
        virus5.state = true;
    }
    else
    {
        virus5.state = false;
    }
}

void obstacle()
{
    stone5.PositionChange();
    iShowImage(stone5.x,stone5.y,stone5.charDimensionX,stone5.charDimensionY,obj[0]);


    if (stone5.x <= 1100)
    {
        stone5.state = true;
    }
    else
    {
        stone5.state = false;
    }
}



void showStone1()
{
    stone1.PositionChange3();
    iShowImage(stone1.x,stone1.y,stone1.charDimensionX,stone1.charDimensionY,s1[0]);


    if (stone1.x <= 1100)
    {
        stone1.state = true;
    }
    else
    {
        stone1.state = false;
    }
}

void showStone2()
{
    stone2.PositionChange4();
    iShowImage(stone2.x,stone2.y,stone2.charDimensionX,stone2.charDimensionY,s2[0]);


    if (stone2.x <= 1100)
    {
        stone2.state = true;
    }
    else
    {
        stone2.state = false;
    }
}

void showStone3()
{
    stone3.PositionChange5();
    iShowImage(stone3.x,stone3.y,stone3.charDimensionX,stone3.charDimensionY,s3[0]);


    if (stone3.x <= 1100)
    {
        stone3.state = true;
    }
    else
    {
        stone3.state = false;
    }
}

void showShieldIcon()
{
    shield.PositionChange6();
    iShowImage(shield.x,shield.y,shield.charDimensionX,shield.charDimensionY,shieldImage2[0]);

    if (shield.x <= 1100)
    {
        shield.state = true;
    }
    else
    {
        shield.state = false;
    }
}



void Char_Fire_Function()
{
    if(run)
    {
        if(runOn)
        {
            ku.x+=ku.speed;
            if(ku.x>=1100)
                runOn= false;
        }

        else
        {
            run=false;
            ku.x =150;
        }

    }

    if(run1)
    {
        if(runOn1)
        {
            ku1.x+=ku1.speed;
            ku1.y+=ku1.speed;
            if(ku1.x>=1100 || ku1.y>=599)
                runOn1= false;
        }

        else
        {
            run1=false;
            ku1.x =player.x+60;
            ku1.y=player.y+50;
        }

    }



    if(jump)
    {
        if(jumpUp)
        {
            charJumpCordinate+=20;
            if(charJumpCordinate>=jumpLimite)
                jumpUp= false;
        }

        else
        {

            charJumpCordinate-=20;
            if(charJumpCordinate<0)
            {
                jump=false;
                charJumpCordinate =0;
            }
        }
    }

    if(run2)
    {
        if(runOn2)
        {
            fi1.x+=fi1.speed;
            if(fi1.x>=1100)
                runOn2= false;
        }

        else
        {
            run2=false;
            fi1.x =player2.x+10;
            fi1.y=player2.y+65;
        }

    }

    if(run3)
    {
        if(runOn3)
        {
            fi5.x+=fi5.speed;
            if(fireJump<=100)
            {
                fireJump+=20;
                fi5.y+=20;
            }

            if(fi5.x>=1100 || fi5.y>=599)
            {
                runOn3= false;
            }
        }

        else
        {
            fireJump=0;
            run3=false;
            fi5.x =player2.x+60;
            fi5.y=player2.y+50;
        }

    }




}

void BOSS_Fire_Function()

{
    if(run4)
    {
        if(runOn4)
        {
            fi3.x-=fi3.speed;
            if(fi3.y<=400)
                fi3.y+=fi3.speed;
            if(fi3.x<=100 || fi3.y>=599)
                runOn4= false;
        }

        else
        {
            run4=false;
            fi3.x =900;
            fi3.y=305;
        }

    }

    if(run5)
    {
        if(runOn5)
        {
            fi2.x-=fi2.speed;
            if(fi2.x<=100)
                runOn5= false;
        }

        else
        {
            run5=false;
            fi2.x =900;
        }

    }

    if(run6)
    {
        if(runOn6)
        {
            fi4.x-=fi4.speed;
            if(fi4.y>=206)
                fi4.y-=fi4.speed;
            if(fi4.x<=100 ||fi4.y>=599)
                runOn6= false;
        }

        else
        {
            run6=false;
            fi4.x =900;
            fi4.y=305;
        }

    }
}



void BOSS_HEAL()
{

    if (BOSS.value < 100)
    {
        BOSS.value++;
    }

}





void ScoreShow(int x, int y, int size, int number)
{
    score_x = x + 4 * size;
    score_y = y;

    for (int i = 0; i < 5; i++)
    {
        if (number > 0)
        {
            score[i] = number % 10;
            number = number / 10;
        }
        else
        {
            score[i] = 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        iShowImage(score_x - i * size, score_x, size, 1.4*size, scoreImage[score[i]]);
    }
}




void BOSS_FUNCTION()
{

    if (BOSS.index >=8)
    {
        BOSS.index = 1;
    }
    else
    {
        BOSS.index++;
    }

    if(!run4)
    {
        run4 = true;
        runOn4= true;

    }
    if(!run5)
    {
        run5 = true;
        runOn5= true;

    }
    if(!run6)
    {
        run6 = true;
        runOn6= true;

    }
}
void CheckPosition()
{ 
	

	highscorefile=fopen("HIGH SCORE.txt","r");
	if (highscorefile == NULL)
	{
		highscorefile= fopen("HIGH SCORE.txt", "w");
		fclose(highscorefile);

		highscorefile = fopen("HIGH SCORE.txt", "r");
	}



	for( int i=0; i<5;i++)
	{
		fscanf(highscorefile, "%s\t\t%d",&high_score_info[i].name,&high_score_info[i].score);
	}

	fclose(highscorefile);

	score_string[100];
	int positionX=300;
	int positionY=400;
	iSetColor(255,255,255);
	for(int i=0; i<5;i++)
	{   
		iText(positionX,positionY,high_score_info[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score_string, "%d", high_score_info[i].score);
	     
		iText(positionX+500, positionY, score_string, GLUT_BITMAP_TIMES_ROMAN_24);
		positionY=positionY-50;

	}
}



int main()
{
    //place your own initialization codes here.
    len = 0;
    mode = 0;
    str[0]= 0;
    iSetTimer(0,Load);
    mode=0;
    iSetTimer(200,introMove);
    backgroundSetting();
    backgroundSettinglvl2();
    iSetTimer(1,backgroundMovinglvl2);
    iSetTimer(1,backgroundMoving);
    iSetTimer(1, Char_Fire_Function);
    //iSetTimer(1, );
    //iSetTimer(1,);
    iSetTimer(1, BOSS_Fire_Function);

    //iSetTimer(1,  Lvl2Load);
    //iSetTimer(1, );
    iSetTimer(500, BOSS_HEAL);
    iSetTimer(100, BOSS_FUNCTION);

    system("Color 1A");
    cout << "READY STEADY GO....." << endl;
    iInitialize(screenWidth, screenHeight, "THE SAVIOUR");


    loadImage();


    iStart(); // it will start drawing

    return 0;
}




