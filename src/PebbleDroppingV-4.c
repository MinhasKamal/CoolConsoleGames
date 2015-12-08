/**
* Game's Name: Pebble Dropping
* Version: 04(last) (Incomplete)
* Developer: Minhas Kamal (IIT - 5th Batch)
* Date: 0-.June.2013
* Comment: I wish it will give u as much challenge as I had, developing it.
**/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void introduction();
void box();
void delay(float t);

void hvh_choice(char *p1, char *p2);  //human vs. human choice
void hvc_choice(char *h, int level);  //human vs. computer choice

int assign(int s1, int pl);
int varification(int pl);

int Computers_Move(int i, int humn_sel, int level);


int a, b, c, d, e;  //they represent the columns, i have made these global to use them in any function
char move[8][5][2] =  //to initialise it as a box i made it a two bite array
{
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {"X", "X", "X", "X", "X"}  //this last line works as the foundation
};

/****/

int main()
{
    char p_again='A';  //controls the loop & players introduction

    while(1)
    {
        fflush(stdin);
        a=b=c=d=e=6;

        int i, j;
        for(i=0; i<7; i++)  //assigning values in the box
            for(j=0; j<5; j++)
                move[i][j][0]=' ';

        introduction();
        delay(1.4);

        char against;
        if(p_again!='y')  //input will be asked first time
        {
            printf("\n* Whom do you want to play against?\n");
            delay(0.9);
            printf("Press-\t1.against computer\n");
            delay(0.5);
            printf("\t2.against human.\n");
            delay(0.5);
            printf("Selection- ");
            fflush(stdin);
            scanf("%c", &against);
            fflush(stdin);
            printf("\n");
        }

        if(against-48==1)
        {
           int level;
           char p[8];  //name of player
           if(p_again!='y')  //input will be asked only first time
           {
               printf("* Enter your name: ");
               gets(p);
               printf("Your symbol is '%c'.\n", 15);
               delay(0.5);
               printf("\nComputer's symbol is '%c'.", 4);
               delay(1.3);

               while(1)  //the loop assures valid input
               {
                    printf("\n\n* What should be the computer level?\n");
                    delay(0.5);
                    printf("* Press 1(normal) or 2(advanced): ");

                    char ch;  //this technique prevents program crush when error is input
                    fflush(stdin);
                    scanf("%c", &ch);
                    level=ch-48;

                    if(level>2 || level<1) printf("\n**Wrong input!\a\n**Try again.\n");
                    else break;
               }

           }

           hvc_choice(p, level);
        }


        else if(against-48==2)
        {
            char p1[8], p2[8];  //name of players
            if(p_again!='y')  //input will be asked only first time
            {
                printf("* Enter player-1 name: ");
                gets(p1);
                printf("%s's symbol is '%c'.\n\n", p1, 15);
                delay(0.5);
                printf("* Enter player-2 name: ");
                gets(p2);
                printf("%s's symbol is '%c'.\n\n", p2, 4);
                delay(1.2);
            }

            hvh_choice(p1, p2);
        }

        else
        {
            printf("Wrong input!\n\a");
            delay(0.7);
            system("cls");
            continue;
        }

        printf("\n\n* Do you want to play again?\n");
        delay(0.5);
        printf("Press 'y'(yes) or 'n'(no): ");
        fflush(stdin);
        scanf("%c", &p_again);
        delay(0.5);

        if(p_again!='n')
            system("cls");
        else break;
    }

    printf("\n\n\t*** GAME ENDS ***\n");delay(0.5);  //end view
    printf("\t     .");delay(0.5);printf("  .");delay(0.5);
    printf("  .\n\n\n");delay(1.2);

    return 0;
}

/****/

void hvc_choice(char *h, int level)  //this function takes the input of the players & arranges other function works
{
    int p;
    while(1)  //the loop assures valid input
    {
        printf("\n\n* Who will give first move?\n");
        delay(0.5);
        printf("* Press 1(human) or 2(computer): ");

        char ch;  //this technique prevents program crush when error is input
        fflush(stdin);
        scanf("%c", &ch);
        p=ch-48;

        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int i=0;
    while(1)  //the loop will give at most 35 chances
    {
        system("cls");  //this action makes a still screen
        introduction();
        printf("\n##**HUMAN vs. COMPUTER\n\n");
        printf("\n# Move No: %d", i+1);
        box();  //2nd function

        int pl;
        char *name;
        if(i%2==0) pl=p;
        else pl=3-p;
        if(pl==1) name=h;
        else name="Computer";

        delay(0.35);
        printf("## Player-%d: %s\n", pl, name);
        delay(0.5);

        while(1)  //the loop will assure valid choice
        {
            int sel;  //player's selection
            printf("Select a column (1-5): ");

            if(pl==1)  //human choice
            {
                char ch;  //this technique prevents program crush when error is input
                fflush(stdin);
                scanf("%c", &ch);
                sel=ch-48;
            }
            else  //computer choice
            {
                sel=Computers_Move(i, sel, level);
                delay(0.7);
                printf("%d", sel);
                delay(1.0);
            }


            printf("\n");

            if(sel<1 || sel>5)
            {
                printf("**Wrong input1!\a\n");
                continue;
            }
            else if(assign(sel, pl))
            {
                printf("\nInvalid move!\a\n");
                continue;
            }
            break;
        }

        if(varification(pl))  //finds winner
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n# Move No: %d", i+1);
            box();
            delay(0.4);
            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\n", 1, pl, name);
            delay(0.35);
            printf("\a");
            delay(0.6);
            printf("\a\a");
            break ;
        }
        else if(i==34)
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n# Move No: %d", i+1);
            box();
            delay(0.4);
            printf("\a\n**The match is draw.\n");
            delay(0.2);
            printf("\a");
            delay(0.4);
            printf("\a");
            break ;
        }

        i++;
    }

}

void hvh_choice(char *p1, char *p2)  //this function takes the input of the players & arranges other function works
{
    int p;
    while(1)  //the loop assures valid input
    {
        printf("\n* Who will give first move?\n");
        delay(0.5);
        printf("* Press 1(player-1) or 2(player-2): ");

        char ch;  //this technique prevents program crush when error is input
        fflush(stdin);
        scanf("%c", &ch);
        p=ch-48;

        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int i=0;
    while(1)  //the loop will give at most 35 chances
    {
        system("cls");  //this action makes a still screen
        introduction();
        printf("\n##**HUMAN vs. HUMAN\n\n");
        printf("\n# Move No: %d", i+1);
        box();  //2nd function

        int pl;
        char *name;
        if(i%2==0) pl=p;
        else pl=3-p;
        if(pl==1) name=p1;
        else name=p2;

        delay(0.35);
        printf("## Player-%d: %s\n", pl, name);
        delay(0.5);

        while(1)  //the loop will assure valid choice
        {
            int sel;  //player's selection
            printf("Select a column (1-5): ");

            char ch;  //this technique prevents program crush when error is input
            fflush(stdin);
            scanf("%c", &ch);
            sel=ch-48;

            printf("\n");

            if(sel<1 || sel>5)
            {
                printf("**Wrong input1!\a\n");
                continue;
            }
            else if(assign(sel, pl))
            {
                printf("\nInvalid move!\a\n");
                continue;
            }
            break;
        }

        if(varification(pl))  //finding winner
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n# Move No: %d", i+1);
            box();
            delay(0.4);
            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\n", 1, pl, name);
            delay(0.35);
            printf("\a");
            delay(0.6);
            printf("\a\a");
            break ;
        }
        else if(i==34)
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n# Move No: %d", i+1);
            box();
            delay(0.4);
            printf("\a\n**The match is draw.\n");
            delay(0.2);
            printf("\a");
            delay(0.4);
            printf("\a");
            break ;
        }

        i++;
    }
}

/****/

void introduction()  //this function prints the introduction of the game
{
    printf("\t\t***%c%c PEBBLE DROPPING GAME %c%c***\n\n\n", 1, 1, 1, 1);  //still image
    printf("## You can play against computer or human.\n");
    printf("## You have to drop pebble in the columns.\n");
    printf("## Every player will get chance by turns.\n\n");

    return ;
}

void box()  //this function creates the box
{
    printf("\n\n");

    int i, j;

    for(i=0; i<8; i++)  //7 rows
    {
        printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c", 197, 196,196,196,197, 196,196,196,197, 196,196,196,197);
        printf("%c%c%c%c%c%c%c%c\n", 196,196,196,197, 196,196,196,197, 196,196,196,197);

        if(i>6) break;  //this action is necessary to make the last line

        printf("  %c ", 179);

        for(j=0; j<5 ; j++)  //5 columns
        {
            printf("%s", move[i][j]);
            printf(" %c ", 179);
        }
        printf("\n");
    }
    printf("    1   2   3   4   5  \n\n\n");  //column number

    return ;
}

void delay(float t)  //delays t seconds
{
    clock_t start=0;
    start=clock();

    while((clock()-start)<(t*1000));

    return ;
}

/****/

int assign(s1, pl)  //this function inputs the value in 'move'
{
    char symbol;

    if(pl==1) symbol=15;
    else symbol=4;

    if((s1==1&&a<0) || (s1==2&&b<0) || (s1==3&&c<0) || (s1==4&&d<0) || (s1==5&&e<0))
        return 1;  //will make know if move is invalid

    else
    {
        if(s1==1)
        {
            move[a][s1-1][0]=symbol;
            a--;
        }
        else if(s1==2)
        {
            move[b][s1-1][0]=symbol;
            b--;
        }
        else if(s1==3)
        {
            move[c][s1-1][0]=symbol;
            c--;
        }
        else if(s1==4)
        {
            move[d][s1-1][0]=symbol;
            d--;
        }
        else
        {
            move[e][s1-1][0]=symbol;
            e--;
        }

        return 0;
    }
}

int varification(int pl)  //finds out the winner
{
    int v1, v2;
    char symbol;

    if(pl==1) symbol=15;
    else symbol=4;

    for(v1=0; v1<7; v1++)  //finds row match
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1][v2+1][0]==symbol && move[v1][v2+2][0]==symbol && move[v1][v2+3][0]==symbol)
                return 1;

    for(v1=6; v1>2; v1--)  //finds column match
        for(v2=0; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2][0]==symbol && move[v1-2][v2][0]==symbol && move[v1-3][v2][0]==symbol)
                return 1;

    for(v1=3; v1<7; v1++)  //finds right-angle match
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2+1][0]==symbol && move[v1-2][v2+2][0]==symbol && move[v1-3][v2+3][0]==symbol)
                return 1;

    for(v1=3; v1<7; v1++)  //finds left-angles match
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2-1][0]==symbol && move[v1-2][v2-2][0]==symbol && move[v1-3][v2-3][0]==symbol)
                return 1;

    return 0;
}

/****/

int Computers_Move(int i, int humn_sel, int level)  //computer gives a move
{
    int v1=1, v2=1;  //variables
    static int comp_sel;  //computer selection
    int s=1;  //probable selection

    /**Initial_Move**/

    if(i==0)
    {
        s=(rand()%5)+1;
        if(level==2)
        {
            if(s==1) s=2;
            if(s==5) s=4;
        }
        if(s==3) s=2;
        comp_sel=s;
    }
    else if(i==1)
    {
        s=(rand()%5)+1;
        if(s==1 || s==5)
        {
            if(b==6) comp_sel=2;
            else if(d==6 && level==2) comp_sel=4;
            else s=humn_sel;
        }
        comp_sel=s;
    }
    else if(i==2)
    {
        if(d==6) s=4;
        else if(b==6) s=2;
        else if(level==2 && c==6) s=3;
        else s=(rand()%5)+1;
        comp_sel=s;
    }
    else if(i==3)
    {
        if(c<6) s=3;
        else
        {
            s=(rand()%5)+1;
            if(s==3) s=4;
        }
        comp_sel=s;
    }

    /**After_Move**/

    else
    {

    /**Matching_Move**/

    for(v1=0; v1<7; v1++)  //finds row match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1][v2+1][0]==4 && move[v1][v2+2][0]==4 && move[v1+1][v2+3][0]!=' ')
                return v2+3+1;
    for(v1=0; v1<7; v1++)  //finds row match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1][v2+1][0]==4 && move[v1+1][v2+2][0]!=' ' && move[v1][v2+3][0]==4)
                return v2+2+1;
    for(v1=0; v1<7; v1++)  //finds row match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1+1][v2+1][0]!=' ' && move[v1][v2+2][0]==4 && move[v1][v2+3][0]==4)
                return v2+1+1;
    for(v1=0; v1<7; v1++)  //finds row match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1][v2+1][0]==4 && move[v1][v2+2][0]==4 && move[v1][v2+3][0]==4)
                return v2+1;


    for(v1=6; v1>2; v1--)  //finds column match for all
        for(v2=0; v2<5; v2++)
            if(move[v1][v2][0]==4 && move[v1-1][v2][0]==4 && move[v1-2][v2][0]==4 && move[v1-3][v2][0]==' ')
                return v2+1;


    for(v1=3; v1<7; v1++)  //finds right-angle match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1-1][v2+1][0]==4 && move[v1-2][v2+2][0]==4 && move[v1-3+1][v2+3][0]!=' ')
                return v2+3+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1-1][v2+1][0]==4 && move[v1-2+1][v2+2][0]!=' ' && move[v1-3][v2+3][0]==4)
                return v2+2+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==4 && move[v1-1+1][v2+1][0]!=' ' && move[v1-2][v2+2][0]==4 && move[v1-3][v2+3][0]==4)
                return v2+1+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1-1][v2+1][0]==4 && move[v1-2][v2+2][0]==4 && move[v1-3][v2+3][0]==4)
                return v2+1;


    for(v1=3; v1<7; v1++)  //finds left-angles match for 4th space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==4 && move[v1-1][v2-1][0]==4 && move[v1-2][v2-2][0]==4 && move[v1-3+1][v2-3][0]!=' ')
                return v2-3+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 3rd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==4 && move[v1-1][v2-1][0]==4 && move[v1-2+1][v2-2][0]!=' ' && move[v1-3][v2-3][0]==4)
                return v2-2+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 2nd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==4 && move[v1-1+1][v2-1][0]!=' ' && move[v1-2][v2-2][0]==4 && move[v1-3][v2-3][0]==4)
                return v2-1+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 1st space
        for(v2=3 ; v2<5; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1-1][v2-1][0]==4 && move[v1-2][v2-2][0]==4 && move[v1-3][v2-3][0]==4)
                return v2+1;

    /**Blocking_Move**/

    for(v1=0; v1<7; v1++)  //finds row match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1][v2+1][0]==15 && move[v1][v2+2][0]==15 && move[v1+1][v2+3][0]!=' ')
                return v2+3+1;
    for(v1=0; v1<7; v1++)  //finds row match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1][v2+1][0]==15 && move[v1+1][v2+2][0]!=' ' && move[v1][v2+3][0]==15)
                return v2+2+1;
    for(v1=0; v1<7; v1++)  //finds row match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1+1][v2+1][0]!=' ' && move[v1][v2+2][0]==15 && move[v1][v2+3][0]==15)
                return v2+1+1;
    for(v1=0; v1<7; v1++)  //finds row match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1][v2+1][0]==15 && move[v1][v2+2][0]==15 && move[v1][v2+3][0]==15)
                return v2+1;


    for(v1=6; v1>2; v1--)  //finds column match for all
        for(v2=0; v2<5; v2++)
            if(move[v1][v2][0]==15 && move[v1-1][v2][0]==15 && move[v1-2][v2][0]==15 && move[v1-3][v2][0]==' ')
                return v2+1;


    for(v1=3; v1<7; v1++)  //finds right-angle match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1-1][v2+1][0]==15 && move[v1-2][v2+2][0]==15 && move[v1-3+1][v2+3][0]!=' ')
                return v2+3+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1-1][v2+1][0]==15 && move[v1-2+1][v2+2][0]!=' ' && move[v1-3][v2+3][0]==15)
                return v2+2+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==15 && move[v1-1+1][v2+1][0]!=' ' && move[v1-2][v2+2][0]==15 && move[v1-3][v2+3][0]==15)
                return v2+1+1;
    for(v1=3; v1<7; v1++)  //finds right-angle match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1-1][v2+1][0]==15 && move[v1-2][v2+2][0]==15 && move[v1-3][v2+3][0]==15)
                return v2+1;


    for(v1=3; v1<7; v1++)  //finds left-angles match for 4th space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==15 && move[v1-1][v2-1][0]==15 && move[v1-2][v2-2][0]==15 && move[v1-3+1][v2-3][0]!=' ')
                return v2-3+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 3rd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==15 && move[v1-1][v2-1][0]==15 && move[v1-2+1][v2-2][0]!=' ' && move[v1-3][v2-3][0]==15)
                return v2-2+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 2nd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==15 && move[v1-1+1][v2-1][0]!=' ' && move[v1-2][v2-2][0]==15 && move[v1-3][v2-3][0]==15)
                return v2-1+1;
    for(v1=3; v1<7; v1++)  //finds left-angles match for 1st space
        for(v2=3 ; v2<5; v2++)
            if(move[v1+1][v2][0]!=' ' && move[v1-1][v2-1][0]==15 && move[v1-2][v2-2][0]==15 && move[v1-3][v2-3][0]==15)
                return v2+1;

    /**Chance_Breaker**/

    int k=1, l=2, m=3, n=4, o=5;  //we need them as column number
    int neg;  //neglecting columns

    for(v1=0; v1<7; v1++)  //finds row match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1][v2+1][0]!=' ' && move[v1][v2+2][0]!=' ' && move[v1+1][v2+3][0]==' ')
                {
                    neg=v2+3+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=0; v1<7; v1++)  //finds row match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1][v2+1][0]!=' ' && move[v1+1][v2+2][0]==' ' && move[v1][v2+3][0]!=' ')
                {
                    neg=v2+2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=0; v1<7; v1++)  //finds row match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1+1][v2+1][0]==' ' && move[v1][v2+2][0]!=' ' && move[v1][v2+3][0]!=' ')
                {
                    neg=v2+1+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=0; v1<7; v1++)  //finds row match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]==' ' && move[v1][v2+1][0]!=' ' && move[v1][v2+2][0]!=' ' && move[v1][v2+3][0]!=' ')
                {
                    neg=v2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }

    //we don't need column match

    for(v1=3; v1<7; v1++)  //finds right-angle match for 4th space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1][v2+1][0]!=' ' && move[v1-2][v2+2][0]!=' ' && move[v1-3+1][v2+3][0]==' ')
                {
                    neg=v2+3+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<7; v1++)  //finds right-angle match for 3rd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1][v2+1][0]!=' ' && move[v1-2+1][v2+2][0]==' ' && move[v1-3][v2+3][0]!=' ')
                {
                    neg=v2+2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<7; v1++)  //finds right-angle match for 2nd space
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1+1][v2+1][0]==' ' && move[v1-2][v2+2][0]!=' ' && move[v1-3][v2+3][0]!=' ')
                {
                    neg=v2+1+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<7; v1++)  //finds right-angle match for 1st space
        for(v2=0; v2<2; v2++)
            if(move[v1+1][v2][0]==' ' && move[v1-1][v2+1][0]!=' ' && move[v1-2][v2+2][0]!=' ' && move[v1-3][v2+3][0]!=' ')
                {
                    neg=v2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }


    for(v1=3; v1<6; v1++)  //finds left-angles match for 4th space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1][v2-1][0]!=' ' && move[v1-2][v2-2][0]!=' ' && move[v1-3+1][v2-3][0]==' ')
                {
                    neg=v2-3+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<6; v1++)  //finds left-angles match for 3rd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1][v2-1][0]!=' ' && move[v1-2+1][v2-2][0]==' ' && move[v1-3][v2-3][0]!=' ')
                {
                    neg=v2-2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<6; v1++)  //finds left-angles match for 2nd space
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]!=' ' && move[v1-1+1][v2-1][0]==' ' && move[v1-2][v2-2][0]!=' ' && move[v1-3][v2-3][0]!=' ')
                {
                    neg=v2-1+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }
    for(v1=3; v1<6; v1++)  //finds left-angles match for 1st space
        for(v2=3 ; v2<5; v2++)
            if(move[v1+1][v2][0]==' ' && move[v1-1][v2-1][0]!=' ' && move[v1-2][v2-2][0]!=' ' && move[v1-3][v2-3][0]!=' ')
                {
                    neg=v2+1;
                    if(neg==k) k=0;
                    else if(neg==l) l=0;
                    else if(neg==m) m=0;
                    else if(neg==n) n=0;
                    else if(neg==o) o=0;
                }

    /**Ignoring_Invalid_Move**/

    if(a==-1) k=0;
    if(b==-1) l=0;
    if(c==-1) m=0;
    if(d==-1) n=0;
    if(e==-1) o=0;

    /**Normal_Selection**/

    if(level==1)
    {
        while(1)
        {
            s=(rand()%5)+1;
            if(k+l+m+n+o==0) break;
            if(s!=k && s!=l && s!=m && s!=n && s!=o) continue;
            else break;
        }
        comp_sel=s;
    }

    /**Advanced_Selection**/

    else
    {
        comp_sel=(rand()%5)+1;
    }

    }

    return comp_sel;
}




