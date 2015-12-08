/**
* Game's Name: Game of Life
* Version: 1(only)
* Developer: Minhas Kamal (IIT - 5th Batch)
* Date: 16.September.2013
* Comment: It is a copy of a famous program called "The Game Of Life" developed by a mathematician at
           Cambridge. While developing it, I felt myself a real programmer.
**/


#include <stdio.h>
#include <time.h>

#define X 230       //length
#define Y 105       //width
#define wait 0.1    //time to wait

void printField(void);  //prints the field of life
void initialize(void);  //initializing the field as an empty field
void delay(float t);    //stops the program from running for some time
void userInput(void);   //takes user input as the primitive stage of evolution
void dataAnalyzer(void);//makes the evolution maintaining given rules

char field[Y+2][X+3];

int main()
{
    int t=0;

    printf("%c This is a demonstration of life being evolving.\n\n", 2);

    initialize();
    userInput();
    while(1){
        while(1){
            system("cls");  //clears the screen

            printf("Frame: %d", t++);

            printField();
            delay(wait);

            if(kbhit())
                break;

            dataAnalyzer();
        }
        getch();
        printf("\n# Enter 'e' to exit or else to continue.");
        if(getch()=='e') break;
    }
    printField();
    printf("\n%c It was a simple demonstration of evolution.\nThanks...", 2);
    getch();

    return 0;
}

void initialize()
{
    field[0][0]=218;     //initializing corners
    field[0][X+1]=191;
    field[Y+1][0]=192;
    field[Y+1][X+1]=217;

    int i, j;
    for(j=1; j<=X; j++) //top & bottom side initialization
        field[0][j]=field[Y+1][j]=196;
    for(i=1; i<=Y; i++) //left & right side initialization
        field[i][0]=field[i][X+1]=179;
    for(i=1; i<=Y; i++) //field initialization
        for(j=1; j<=X; j++)
            field[i][j]=32;

    for(i=0; i<Y+1; i++) //makes a new line
        field[i][X+2]=10;

    return ;
}

void printField()
{
    printf("\n");

    puts(field);

    return ;
}

void delay(float t)  //delays t seconds
{
    clock_t start=clock();

    while((clock()-start)<(t*1000));    //the loop is run until the it's time

    return ;
}

void userInput(void)
{
    printf("Do you want to use built in inputs?\npress- 1(no) or 2(yes): ");    //asking user choice
    char ch=getchar();

    if(ch==49){
        int x=1, y=1;
        printf("\n# Enter your coordinates.\n  Enter '0' to finish inputting.\n");    //user prompt
        while(x*y){     //takes the input
            printf("Coordinate: ");
            scanf("%d %d", &x, &y);

            if(x>0 && x<=X && y>0 && y<=Y)
                field[y][x]=254;
            else if(x*y!=0)     //prevents invalid input
                printf("Invalid input!\nRange is 1-%d & 1-%d\n", X, Y);
        }
    }
    else{                       //default initializer

        field[15][197]=field[15][198]=field[16][198]=field[16][199]=field[14][199]=254;  //small roaming creature
        field[28][28]=field[28][29]=field[29][29]=field[29][30]=field[30][28]=254;  //small roaming creature
        field[18][75]=field[18][76]=field[19][76]=field[19][77]=field[17][77]=254;  //small roaming creature
        field[90][150]=field[91][150]=field[90][151]=field[90][152]=field[92][151]=254;  //small roaming creature
        field[70][133]=field[71][133]=field[71][134]=field[72][134]=field[72][132]=254;//small roaming creature
        field[108][133]=field[109][133]=field[109][134]=field[110][134]=field[108][135]=254; //small roaming creature

        field[40][25]=field[40][26]=field[40][27]=field[41][24]=field[41][25]=field[41][26]=field[41][27]=field[41][28]=254;    //big roaming creature
            field[42][24]=field[42][25]=field[42][26]=field[42][28]=field[42][29]=field[43][27]=field[43][28]=254;
        field[90][5]=field[90][6]=field[90][7]=field[91][4]=field[91][5]=field[91][6]=field[91][7]=field[91][8]=254;    //big roaming creature
            field[92][4]=field[92][5]=field[92][6]=field[92][8]=field[92][9]=field[93][7]=field[93][8]=254;



        field[63][90]=field[63][91]=field[63][92]=254; //dancing small creatures
        field[53][7]=field[54][7]=field[55][7]=254;//dancing small creatures
        field[5][97]=field[5][98]=field[5][99]=254;//dancing small creatures

        field[30][120]=field[31][119]=field[32][119]=field[33][121]=field[31][122]=field[32][122]=254;//dancing big creature

        /*
        field[15][147]=field[16][148]=field[17][148]=field[15][150]=field[15][151]=field[14][149]=254;    //other patterns
        */
    }

    return ;
}

void dataAnalyzer(void)
{
    char abstracrField[Y+2][X+2];   //making an abstract field which is a underground version of real field
    int i=0, j=0,   //loop controller
        surrounding=0;  //state of the surrounding 8 rooms

    for(i=0; i<Y+2; i++)    //making a copy of field
        for(j=0; j<X+2; j++)
            abstracrField[i][j]=field[i][j];

    for(i=1; i<Y+1; i++)
        for(j=1; j<X+1; j++){
            surrounding = field[i-1][j-1]+field[i-1][j]+field[i-1][j+1] + field[i][j-1]+field[i][j+1] + field[i+1][j-1]+field[i+1][j]+field[i+1][j+1];

            if(field[i][j]==32){   //making new life
                if(surrounding==154)    //surrounded with 3 dots
                    abstracrField[i][j]=254;
            }
            else{    //deleting new life
                if(surrounding>220)   //surrounding is empty
                    abstracrField[i][j]=32;
                else if(surrounding<125)  //surrounding is over-crowded
                    abstracrField[i][j]=32;
            }

        }

    for(i=0; i<Y+2; i++)    //storing the outcome
        for(j=0; j<X+2; j++)
            field[i][j]=abstracrField[i][j];

    return ;
}


