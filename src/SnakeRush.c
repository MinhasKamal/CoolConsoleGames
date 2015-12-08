/**
* Game's Name: Snake_Rush
* Collector: Minhas Kamal (IIT - 5th Batch)
* Date: 19.September.2013
* Comment: Krishan Developed the program & all of its algorithms. He really have done a great
           gob. But the code was not easy-readable or commended & there were unnecessary
           complexities. So I(Minhas) re-arranged the code, did some modification & made the
           interface nicer. Even now this code is not very reliable.
**/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void printIntroduction();//prints instruction of game
void delay(int l);      //makes the image stuck for certain time
void Boarder();         //prints the screen
void move();            //controls snake movement
void Bend();            //bends the snake
void left();
void right();
void up();
void down();
int Scoreonly();        //counts the score
int scoreLifeCounter();     //counts the score & life and prints on the screen
void gotoXY(int x,int y);   //sends the cursor at different location
void Food();
void exitGame();
void record();          //stores the player information

int life;   //remaining life of the player
int length; //length of the snake
int bend_no;
int len;
char key;

struct coordinate{
    int x;  //X-axis
    int y;  //Y-axis
    int direction;
}head, bend[500], food, body[30];


int main()
{
    char key;

    printIntroduction();

    system("cls");

    length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;

    Boarder();

    Food();

    life=3;
    bend[0]=head;

    move();

    return 0;
}


void move()
{
    int a, i;
    do{
        Food();
        fflush(stdin);
        len=0;

        for(i=0; i<30; i++){
            body[i].x=0;
            body[i].y=0;
            if(i==length) break;
        }

        scoreLifeCounter();
        delay(length);

        Boarder();

        if(head.direction==RIGHT) right();
        else if(head.direction==LEFT) left();
        else if(head.direction==DOWN)down();
        else if(head.direction==UP) up();

        exitGame();
    } while(!kbhit());

    a=getch();

    if(a==27)
    {
        system("cls");
        exit(0);
    }

    key=getch();

    if((key==RIGHT && head.direction!=LEFT && head.direction!=RIGHT) || (key==LEFT && head.direction!=RIGHT && head.direction!=LEFT) || (key==UP && head.direction!=DOWN&&head.direction!=UP) || (key==DOWN&&head.direction!=UP && head.direction!=DOWN)){
        bend_no++;
        bend[bend_no]=head;
        head.direction=key;

        if(key==UP) head.y--;
        if(key==DOWN) head.y++;
        if(key==RIGHT) head.x++;
        if(key==LEFT) head.x--;

        move();
    }

    else if(key==27 || key=='e'){
        system("cls");
        exit(0);
    }

    else{
        printf("\a");
        move();
    }

    return ;
}

/******/

void up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y) && len<length; i++)
    {
        gotoXY(head.x,head.y+i);

        if(len==0) printf("%c", 30);
        else printf("%c", 15);

        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit()) head.y--;

    return ;
}

void down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y) && len<length; i++)
    {
        gotoXY(head.x,head.y-i);

        if(len==0) printf("%c", 31);
        else printf("%c", 15);

        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit()) head.y++;

    return ;
}

void left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        gotoXY((head.x+i),head.y);

        if(len==0) printf("%c", 17);
        else printf("%c", 15);

        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }

    Bend();
    if(!kbhit()) head.x--;

    return ;
}

void right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x) && len<length; i++)
    {
        body[len].x=head.x-i;
        body[len].y=head.y;
        gotoXY(body[len].x,body[len].y);
        {
            if(len==0) printf("%c", 16);
            else printf("%c", 15);
        }
        len++;
    }
    Bend();
    if(!kbhit()) head.x++;

    return ;
}

/******/

void exitGame()
{
    int i, check=0;

    for(i=4; i<length; i++){
        if(body[0].x==body[i].x && body[0].y==body[i].y) check++;
        if(i==length||check!=0)
        break;
    }

    if(head.x<=10 || head.x>=70 || head.y<=10 || head.y>=30 || check!=0){
        life--;

        if(life>=0){
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            move();
        }
        else{
            system("cls");
            printf("## You lost all lives.\n");
            printf("   Try harder next time!\n\n\n(press any key)");
            record();
            exit(0);
        }
    }

    return ;
}

void Food()
{
    if(head.x==food.x&&head.y==food.y){
        length++;
        time_t a;
        a=time(0);
        srand(a);

        food.x=rand()%70;
        if(food.x<=10) food.x+=11;

        food.y=rand()%30;
        if(food.y<=10) food.y+=11;
    }

    else if(food.x==0){
        food.x=rand()%70;
        if(food.x<=10) food.x+=11;

        food.y=rand()%30;
        if(food.y<=10) food.y+=11;
    }

    return ;
}

/******/

void Bend()
{
    int i, j, diff;

    for(i=bend_no; i>=0 && len<length; i--){

        if(bend[i].x==bend[i-1].x){
            diff=bend[i].y-bend[i-1].y;

            if(diff<0)
                for(j=1; j<=(-diff); j++){
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    gotoXY(body[len].x,body[len].y);
                    printf("%c", 15);
                    len++;
                    if(len==length) break;
                }

            else if(diff>0)
                for(j=1; j<=diff; j++){
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    gotoXY(body[len].x,body[len].y);
                    printf("%c", 15);
                    len++;
                    if(len==length) break;
                }
        }

        else if(bend[i].y==bend[i-1].y){
            diff=bend[i].x-bend[i-1].x;

            if(diff<0)
                for(j=1; j<=(-diff) && len<length; j++){
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    gotoXY(body[len].x,body[len].y);
                    printf("%c", 15);
                    len++;
                    if(len==length) break;
                }

            else if(diff>0)
                for(j=1;j<=diff&&len<length;j++){
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    gotoXY(body[len].x,body[len].y);
                    printf("%c", 15);
                    len++;
                    if(len==length) break;
                }
        }
    }

    return ;
}

/*********/

void Boarder()
{
    system("cls");

    gotoXY(food.x,food.y);
    printf("%c", 4);

    int i;
    gotoXY(10,10);      //up side
    for(i=0; i<61; i++)
        printf("%c", 205);

    gotoXY(10,30);      //down side
    for(i=0; i<61; i++)
        printf("%c", 205);

    for(i=10;i<31;i++){ //left & right side
        gotoXY(10,i);
        printf("%c", 186);

        gotoXY(70,i);
        printf("%c", 186);
    }

    return ;
}

/******/

void printIntroduction()
{
    printf("\t\t%c%cWelcome to the Snake Rush Game%c%c\n\n\n\n", 16, 16, 17, 17);

    printf("* Developer: Krishan Kumar Ganguli (BSSE0505, IIT, DU)\n");
    printf("* Assistant Developer: Minhas Kamal (BSSE0509, IIT, DU)\n");
    printf("* Date: 19.September.2013\n\n\n\n");

    printf("## Game instructions:\n");
    printf("\n\t%c Use arrow keys to move the snake.", 175);
    printf("\n\t%c Eat food to grow the snake & your score.", 175);
    printf("\n\t%c You will have three lives. Your will loose life as you hit the wall or snake's body.", 175);
    printf("\n\t%c You can pause the game by pressing 'P'.", 175);
    printf("\n\t%c If you want to exit press 'Esc' or 'e'.", 175);
    printf("\n\n\n Press any key to start the game...");

    char ch=getch();
    if(ch==27 || ch=='e') exit(0);

    return ;
}

/******/

int scoreLifeCounter()
{
    int score=length-5;

    gotoXY(20,8);
    printf("%c SCORE: %d                 %c LIFE: %d", 4, score, 3, life);

    return score;
}

int Scoreonly()
{
    int i = scoreLifeCounter();
    system("cls");
    return i;
}

void delay(int l)  //delays t seconds
{
    clock_t start=clock();
    float t=0.23-((l-4)/70);

    while((clock()-start)<(t*1000));    //the loop is run until the it's time

    return ;
}

/******/

void gotoXY(int x, int y)
{
    COORD coordinate;
    //fflush(stdout);
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);

    return ;
}

/******/

void record()
{
    char plname[20],nplname[20],cha,c;
    int i, j, px;
    FILE *info;

    info=fopen("Snake_Rush_Record.txt","a+");
    getch();
    system("cls");
    printf("Enter your name: ");
    scanf("%[^\n]", plname);        /************/

    for(j=0; plname[j]!='\0'; j++){
        nplname[0]=toupper(plname[0]);

        if(plname[j-1]==' '){
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }

    nplname[j]='\0';
    fprintf(info, "Player Name: %s\n", nplname);
    time_t mytime;
    mytime = time(NULL);
    fprintf(info, "Date: %s", ctime(&mytime));
    fprintf(info, "Score: %d\n", px=Scoreonly());

    for(i=0;i<=50;i++)
        fprintf(info,"%c",'_');

    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records? Press 'y'\n");
    cha=getch();
    system("cls");  //clears the screen

    if(cha=='y'){
        info=fopen("Snake_Rush_Record.txt","r");
        do{
            putchar(c=getc(info));
        }while(c!=EOF);
    }
    fclose(info);

    return ;
}
