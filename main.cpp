#include<GL/glut.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<sstream>
#include<time.h>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

stringstream ss;
int phyWidth= 700;
int phyHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX=logWidth/2;
int centerY=logHeight/2;
int sqWid= 20;
int sqWid7= 6;
int alphaX=0;
int alphaY=0;
int answer;
int keyboardIp=0;
int check_answer= 10000;
int array_scores[10];
int scoresize = 0;
char str[15];
char Newstr[2]={' ','\0'};
int flag=0;
bool fileFlag = 1;
int Rank = 0;
char Rank2[50];
char high_score[10];


int flagintro=1;
int flag1=0;
int flag2=0;
int flag3=0;
int flag4=0;
int old_t=0;
int total_time=60;
int rightClickFlag=0;
int t_counter=0;


int x1Bonus=0;
int x2Bonus=0;
int sqDelta2=0;
int sqUp2=0;

int specialKeyflag=0;

    char* var11_old=" ";
    char* var22_old=" ";
    char* var33_old=" ";

    char* var11=" ";
    char* var22=" ";
    char* var33=" ";

    char* var1=" ";
    char* var2=" ";
    char* var3=" ";

    char str_equ1[100];
    char str_equ2[100];
    char str_equ3[100];

int j;

    int mouseX;
    int mouseY;

    int Score=0;

    bool sqUp=true;
    int sqDelta;
//int maxY=70;//slow move

    int maxY=80;//fast move

typedef struct Equation{
    int cx;
    int cy;
    int i1=rand()%9;
    int j1=rand()%3;
    int k1=rand()%9;

    //int sqhight;

    //int sqwidth;

    char equation[70];
    int ans;
    bool state_ans=FALSE;
    int  index;
}Equation;

Equation eq[70];

int check_answer2=0;


void timeFunc(void) {
    if(t_counter%1000==0&&flag1) old_t++;
}



void printSome(char *str,int x,int y) {
//glColor3f (0.0, 0.0, 0.5);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
glFlush();
}

void check(int i)
{




    if(check_answer == eq[i].ans && eq[i].state_ans==0)
    {
        eq[i].state_ans=1;
        Score++;
        check_answer2 =eq[i].ans;
    }
    else if(check_answer == eq[i+1].ans && eq[i+1].state_ans==0)
    {
        eq[i+1].state_ans=1;
        Score++;
        check_answer2 =eq[i+1].ans;
    }
    else if(check_answer == eq[i+2].ans && eq[i+2].state_ans==0)
    {
        eq[i+2].state_ans=1;
        Score++;
        check_answer2 =eq[i+2].ans;
    }
    else if(check_answer == eq[i+3].ans && eq[i+3].state_ans==0)
    {
        eq[i+3].state_ans=1;
        Score++;
        check_answer2 =eq[i+3].ans;
    }
    else if(check_answer == eq[i+4].ans && eq[i+4].state_ans==0)
    {
        eq[i+4].state_ans=1;
        Score++;
        check_answer2 =eq[i+4].ans;
    }

    check_answer = 10000;

}

void Keyboard22(unsigned char key, int x, int y)
{
    ss<<key;


    if(key == (char)13)
    {

        ss>>check_answer;
        ss.clear();
        //printf("answer = %d\n",check_answer); debug
        //check();
    }


}



void init(float r, float g, float b)
{

glClearColor( r, g, b, 0.0); // COLORBACKGROUND
glMatrixMode( GL_PROJECTION);

gluOrtho2D( 0.0, logWidth, 0.0, logHeight);

}


void mouseClick(int btn, int state, int x, int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
mouseX = x; mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
mouseY = phyHeight- y;mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
}
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) {
rightClickFlag=1;
exit(1); // To Exit the Program
}
glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
if(key==GLUT_KEY_UP)
alphaY+=5;
if(key== GLUT_KEY_DOWN)
alphaY-=5;
if(key== GLUT_KEY_LEFT)
alphaX-=5;
if(key== GLUT_KEY_RIGHT)
alphaX+=5;
glutPostRedisplay();
}




void Timer(int value) {


glutTimerFunc(100, Timer, value); // slow move
t_counter+=100;
timeFunc();

//glutTimerFunc(100, Timer, value); // fast move
glutPostRedisplay();

}









void printnum(int score,int x, int y)
{

char str[100];
sprintf(str, "%d", score);
printSome(str,x,y);
}
void deletenum(int x1,int x2,int y1,int y2)
{
    glColor3f(0.764, 0.764, 0.764);//blue background

glBegin(GL_QUADS);

glVertex2i(x1,y1);
glVertex2i(x1,y2);
glVertex2i(x2,y2);
glVertex2i(x2,y1);

glEnd();
}




int ctr=0;








int ExitFlag=0;


int index=-4;

int drawSquareMany8(int yPos)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    init(0.764, 0.764, 0.764);

    glClear(GL_COLOR_BUFFER_BIT);





printnum(old_t,80,80);
if(old_t==total_time)
{
     ExitFlag=1;

}
if(flag1==1 && flag2==0&& flag3==0 && flag4==0 && flagintro==0)
        //old_t=0;

glColor3f (0.0, 0.0, 0.5);
printSome("SCORE : ",10,95);
printnum(Score,25,95);
deletenum( 20,30,90, 95);

glColor3f (0.0, 0.0, 0.5);
printSome("answer : ",10,85);
printnum(check_answer2,25,85);
deletenum( 20,30,80, 85);


//**************************************BONUS PART (NEEDS FURTHER DEBUG BUT PARTIALLY WORKS )**************************
//
//    x1Bonus=0-2+sqDelta2;
//    x2Bonus=0+2+sqDelta2;
//
//   if(old_t>10)
//    {
//        glColor3f(1.0f, 1.0f, 1.0f); // green-
//        glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
//        glVertex2f(x1Bonus, 30); // x, y
//        glVertex2f(x2Bonus, 30); // x, y
//        glVertex2f(x2Bonus, 34); // x, y
//        glVertex2f(x1Bonus, 34); // x, y
//        glEnd();
//        sqUp2=true;
//        if(x1Bonus==100)
//        sqUp2=false;
//        if((mouseX>x1Bonus && mouseX<x2Bonus) && (mouseY>30 && mouseY<34) )
//        {
//            Score+=10;
//            //total_time+=10;
//            //printSome("BONUS !!",10,75);
//            mouseX=0;
//            mouseY=0;
//        }
//
//    }
//    //printf("x1Bonus = %d x2Bonus = %d \n",x1Bonus,x2Bonus);
//
//    //xPos+=10;
//
//if (sqUp2) sqDelta2+=2;



int yPosOrigin=yPos;
int y1=yPos-sqWid7/2+sqDelta;
int y2=yPos+sqWid7/2+sqDelta;
int y11=y1;
int y22=y2;



for (int i=0;i<=70 ;i++)
{


    y1=yPos-sqWid7/2+sqDelta;
    y2=yPos+sqWid7/2+sqDelta;

    if( y2<0)
    {
        index=0;
    }

    else if(y2>0 && y2<=25)
    {
        eq[i].index=1;
    }
     else if(y2>25 && y2<=50)
    {
        eq[i].index=2;
    }
     else if(y2>50 && y2<=75)
    {
        eq[i].index=3;
    }
     else if(y2>75 && y2<=100)
    {
        eq[i].index=4;
    }
    else
        eq[i].index=5;

    if (eq[i].index>0 && eq[i].index<5)
    {
        check(i);
//        if(i<70)//debug
        //printf("eq %d = %s  && state = %d index = %d \n",i, eq[i].equation ,eq[i].state_ans,eq[i].index);//**** debug;
    }

    //check(i,eq);
    if(eq[i].state_ans==0)
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    else if(eq[i].state_ans==1)
    glColor3f(0.0f, 1.0f, 0.0f); // green-




    glBegin(GL_POLYGON); // Each set of 4 vertices form a quad
    glVertex2f(38, y1); // x, y
    glVertex2f(65, y1); // x, y
    glVertex2f(65, y2); // x, y
    glVertex2f(38, y2); // x, y
    glEnd();


  glColor3f (0.0, 0.0, 0.5);
  printSome(eq[i].equation,45,y1);
  printnum(i,40,y1);

    yPos-=30;

}
    // bonus square


if (sqUp) sqDelta+=2;





//flag=1;
return 0;

}



void playPage(void)
{
    //flag=2;


drawSquareMany8(25);

glutSwapBuffers();

glFlush();


}

void introPage(void)
{
//flag=1;
glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);   //<--- add
    glLoadIdentity();
init(0.0,0.0,0.0);

glColor3f(1.0, 1.0, 1.0);
printSome("Ma+h Her0",42,95);

glColor3f(1.0, 1.0, 1.0);
//draw a line
glBegin(GL_QUADS);

glVertex2i(38,65);
glVertex2i(38,75);
glVertex2i(65,75);
glVertex2i(65,65);

glEnd();
glColor3f (0.0, 0.0, 0.5);
printSome("PLAY",47,70);

glColor3f(1.0, 1.0, 1.0);
//draw a line
glBegin(GL_QUADS);

glVertex2i(38,45);
glVertex2i(38,55);
glVertex2i(65,55);
glVertex2i(65,45);

glEnd();
glColor3f (0.0, 0.0, 0.5);
printSome("HIGHSCORES",40,50);

glColor3f(1.0, 1.0, 1.0);
//draw a line
glBegin(GL_QUADS);

glVertex2i(38,25);
glVertex2i(38,35);
glVertex2i(65,35);
glVertex2i(65,25);

glEnd();
glColor3f (0.0, 0.0, 0.5);
printSome("QUIT",47,30);

glutSwapBuffers();

glFlush();

}



void file()
{

    FILE *scoresFile = fopen("E:/computer_graphics_projects/mathHeroProject/scoresFile.txt","a");
    fprintf(scoresFile,"%d\n",Score);
    fclose(scoresFile);

    int i = 0;

    scoresFile = fopen("E:/computer_graphics_projects/mathHeroProject/scoresFile.txt","r");
    while(~fscanf(scoresFile,"%d",&array_scores[i])){i++;}
    fclose(scoresFile);

    scoresize = i;

    sort(array_scores, array_scores+scoresize);
}


void GameOver(int Rank , int Score) // should be trigerred after 60 seconds will playing
{
    flag1=0;
    //flagintro=1;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);   //<--- add
    glLoadIdentity();
    init(1.0, 1.0, 1.0);





    printSome("Your score is:", 42, 65);

    printnum(Score,70,65);

    printSome("Your rank is:", 42, 35);

    printnum(Rank,70,35);

        //flag1=0;

    glutSwapBuffers();

    glFlush();
}



void display (void)
{



     //printf("display: %d %d %d %d %d\n",flagintro,flag1,flag2,flag3,flag4);

if(flagintro==1 && flag1==0 &&flag2==0 &&flag3==0 && flag4==0)
    introPage();



if ((mouseX<=65 && mouseX>= 38)&&(mouseY<= 35 && mouseY>=25))//exit
{
    flag3=1;
    //flagintro=0;

    if(flag3==1)
    {

        exit(0);
    }

}

else if ((mouseX<=65 && mouseX>= 38)&&(mouseY<= 55 && mouseY>=45))//highscore
{
    flag2=1;

}

else if ((mouseX<=65 && mouseX>= 38)&&(mouseY<= 75 && mouseY>=65))//play
{
     flag1=1;
     flagintro=0;
     mouseX=0;
     mouseY=0;
}

if(flagintro==1)
{

    introPage();
}


if(flag1==1) //play page on
{
    playPage();


    if(ExitFlag==1)
    {


                int ctrr=0;

                fileFlag = 1;

                file();


                Rank = upper_bound(array_scores, array_scores+scoresize, Score) - array_scores;
                Rank = scoresize - Rank +1;
                printf("rank = %d \n",Rank);

                GameOver(Rank,Score);
                flag1=0;
                flag2=0;
                flag4=1;
                ExitFlag=0;
                fileFlag=0;
                //exit(1);
         //exit(0);
    }

}



 if(flag2==1)//highscore page on
{
    flagintro=0;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);   //<--- add
    glLoadIdentity();
    init(0.0,0.0,0.0);
    int i=0;
            glColor3f(1,1,1);
            printSome("HIGH SCORE",37,93);
            glEnd();

            //fileFlag=1;
                //printf("fileflag = %d \n",fileFlag);

            if(fileFlag==1)
            {
                //int i = 0;

                FILE *scoresFile = fopen("E:\\computer_graphics_projects\\mathHeroProject\\scoresFile.txt","r");
                while(~fscanf(scoresFile,"%d",&array_scores[i])){
                        //printf("array_score[%d] = %d \n",i,array_scores[i]);
                        i++;
                        }
                fclose(scoresFile);

                scoresize = i;

//                printf("scoresize = %d \n",scoresize);
//                printf("i = %d \n",i);
                sort(array_scores, array_scores+scoresize, greater<int>());
                //fileFlag=0;
//                printf("sorted array  \n");
            }
                //fileFlag=0;

//            printf("i = %d",i);
            int y=70;
for(int j=0;j<i;j++)
{
                int x;

                sprintf(high_score,"  %d",array_scores[j]);
                glColor3f(1,1,1);
                printnum(j+1,5,y);
                printSome("-",7,y);
                printSome(high_score,10,y);
                y-=10;
}


            glutSwapBuffers();
            glFlush();


}
 if(flag4==1)
{

    flag1=0;
    flag2=0;
    flag3=0;
    flag4=1;
    GameOver(Rank,Score);



}


}


void generateRandom()
{
    srand(time(0));

    int ans11=0;
    char equ[10];
    for(int i=0;i<70;i++)
    {
        int a1=rand()%11;
        int a2=rand()%11;
        int j=rand()%3;
        char op[3]={'+','-','*'};
        char temp_op1=op[j];

           switch(temp_op1)
    {
        case '+': ans11=a1+a2;break;
        case '-': ans11=a1-a2;break;
        case '*': ans11=a1*a2;break;
    }

        sprintf(equ,"%d %c %d",a1,temp_op1,a2);
        strcpy(eq[i].equation,equ);
        eq[i].ans=ans11;
        //printf("%d %d %c %d = %d \n",i,a1,temp_op1,a2,ans11);
        //printf("%d eq = %s ans = %d \n",i,eq[i].equation,eq[i].ans);
    }
}

void speacial_keyboard(int key,int x,int y)
{
    if(key == GLUT_KEY_F1)//play again
    {
        printf("f1 invoked");
          //flag=2;

          flag1=1;
          flag2=0;
          flag3=0;
          flag4=0;
          old_t=0;
          Score=0;
          flagintro=0;
          //glutPostRedisplay();
//          playPage();
    }
    else if(key == GLUT_KEY_F2)//main menu
            {

              flagintro=1;//intro page {supposedly)
              //flag=1; //intro page {supposedly)
              flag1=0;//play page off
              flag2=0;//highscore page off
              flag3=0;//exit off
              flag4=0;
              old_t=0;
              Score=0;
            printf("f2 invoked: %d %d %d %d %d\n",flagintro,flag1,flag2,flag3,flag4);


            }
}

int main(int argc,char *argv[])
{



glutInit(&argc,argv);
glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE );
glutInitWindowSize (700, 700);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Math Heroooo");

generateRandom();


glutDisplayFunc(display);
glutMouseFunc(mouseClick);
glutKeyboardFunc(Keyboard22);
glutSpecialFunc(speacial_keyboard);

Timer(0);


glutMainLoop();

}
