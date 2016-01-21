/********************************************************************************************
* Game Name: Pebble Dropping (Version: 03)
* Developer: Minhas Kamal (minhaskamal024@gmail.com)
* Date: 24.April.2013
* Brief Description: It is one my favourite games. You drop a pebble in a column
*     and and try to align four pebbles sequentially. You can play with the computer
*     too. But the AI is not complete yet, so it is easy to win against. This is my
*     very first program of game.
*********************************************************************************************/

/********************************************************************************************
                                GNU GENERAL PUBLIC LICENSE
                                 Version 3, 29 June 2007
         This program is free software: you can redistribute it and/or modify
         it under the terms of the GNU General Public License as published by
         the Free Software Foundation, either version 3 of the License, or
         (at your option) any later version.
         This program is distributed in the hope that it will be useful,
         but WITHOUT ANY WARRANTY; without even the implied warranty of
         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
         GNU General Public License for more details.
         You should have received a copy of the GNU General Public License
         along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************************************/



#include <stdio.h>
#include <time.h>


void hvh_choice(char *p1, char *p2);  //human vs. human choice
void hvc_choice(char *h);  //human vs. computer choice
void box();
int assign(int s1, int pl);
int varification(int pl);
int Computers_Move(int i, int humn_sel);
void developer();

int assi=1;  //computer needs it for considering its move
int a, b, c, d, e;  //they represent the columns, i have made these global to use them in any function
char move[8][5][2] =  //this array collects the moves of the players
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



int main()
{
    developer();    //showing the profile
    system("cls");

    char again='A';  //controls the loop & players introduction


    while(1)
    {
        fflush(stdin);

        a=b=c=d=e=6;

        int i, j;
        for(i=0; i<7; i++)  //assigning values in the box
            for(j=0; j<5; j++)
                move[i][j][0]=' ';

        printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //introduction of game
        printf("## You can play against computer or human.\n");
        printf("## You can drop the pebble in any column you want.\n");
        printf("## Every player will get chance by turns.\n\n");

        int ag;
        if(again!='y')  //input will be asked first time
        {
            printf("\n* Whom do you want to play against?\n");
            printf("Press-\t1.against computer\n\t2.against human.\nSelection- ");
            scanf("%d", &ag);
            fflush(stdin);
        }

        if(ag==1)
        {
           char h[8];  //introduction of players
           if(again!='y')  //input will be asked only first time
           {
               printf("* Enter your name: ");
               gets(h);
               printf("Your symbol is '%c'.\n", 15);
               printf("Computer will be using '%c'.", 4);
           }
           hvc_choice(h);
        }


        else if(ag==2)
        {
            char p1[8], p2[8];  //introduction of players
            if(again!='y')  //input will be asked only first time
            {
                printf("* Enter player-1 name: ");
                gets(p1);
                printf("%s's symbol is '%c'.\n\n", p1, 15);
                printf("* Enter player-2 name: ");
                gets(p2);
                printf("%s's symbol is '%c'.\n\n", p2, 4);
            }

            hvh_choice(p1, p2);  //1st function, which organizes everything
        }

        else
        {
            printf("\a");
            system("cls");
            continue;
        }

        printf("\n\n* Do you want to play again?\n");
        printf("Press 'y'(yes) or 'n'(no): ");
        fflush(stdin);
        scanf("%c", &again);

        if(again!='n')
        {
        system("cls");
        }
        else break;
    }

    printf("\n\n\t*** GAME ENDS ***\n\n\n");

    return 0;
}



void hvc_choice(char *h)
{
    int i=0;
    while(i<35)  //the loop will give at most 30 chances
    {
        system("cls");  //this action makes a still screen
        printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
        printf("## You can play against computer or human.\n");
        printf("## You can drop the pebble in any column you want.\n");
        printf("## Every player will get chance by turns.\n\n");

        printf("\n##**HUMAN vs. COMPUTER\n\n");

        printf("\n# Move No: %d", i+1);
        box();  //2nd function

        int pl;
        char *name;
        if(i%2==0)
        {
            pl=1;
            name=h;
        }
        else
        {
            pl=2;
            name="Computer";
        }


        printf("## Player-%d: %s\n", pl, name);

        for( ; ; )  //the loop will assure valid choice
        {
            int sel;  //player's selection
            printf("Select a column (1-5): ");

            if(pl==1) scanf("%d", &sel);  //human choice
            else
            {
                sel=Computers_Move(i, sel);  //computer choice
                printf("%d", sel);

                clock_t start=clock();
                while((clock()-start)<(1300));

            }
            printf("\n");

            if(sel<1 || sel>5)
            {
                printf("**Wrong input1!\a\n");
                continue;
            }
            else
            {
                assi = assign(sel, pl);
                if(assi==0)
                {
                    printf("\nInvalid move!\a\n");
                    continue;
                }

            }
            break;
        }

        int r; //this integer holds the result
        r = varification(pl);

        if(r==1)
        {
            system("cls");  //this action makes a still screen
            printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
            printf("## You can play against computer or human.\n");
            printf("## You can drop the pebble in any column you want.\n");
            printf("## Every player will get chance by turns.\n\n");

            printf("\n# Move No: %d", i+1);
            box();

            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\a\n", 1, pl, name);
            break ;
        }
        else if(i==34)
        {
            system("cls");  //this action makes a still screen
            printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
            printf("## You can play against computer or human.\n");
            printf("## You can drop the pebble in any column you want.\n");
            printf("## Every player will get chance by turns.\n\n");

            printf("\n# Move No: %d", i+1);
            box();

            printf("\a\n**The match is draw.\a\n");
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
        printf("* Press 1(player-1) or 2(player-2): ");
        scanf("%d", &p);
        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int i=0;
    while(i<35)  //the loop will give at most 30 chances
    {
        system("cls");  //this action makes a still screen
        printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
        printf("## You can play against computer or human.\n");
        printf("## You can drop the pebble in any column you want.\n");
        printf("## Every player will get chance by turns.\n\n");

        printf("\n##**HUMAN vs. HUMAN\n\n");

        printf("\n# Move No: %d", i+1);
        box();  //2nd function

        int pl;
        char *name;
        if(i%2==0) pl=p;
        else
        {
            if(p==2) pl=1;
            else pl=2;
        }
        if(pl==1) name=p1;
        else if(pl==2) name=p2;

        printf("## Player-%d: %s\n", pl, name);

        for( ; ; )  //the loop will assure valid choice
        {
            int sel;  //player's selection
            printf("Select a column (1-5): ");
            scanf("%d", &sel);
            printf("\n");

            if(sel<1 || sel>5)
            {
                printf("**Wrong input1!\a\n");
                continue;
            }
            else
            {
                assi = assign(sel, pl);
                if(assi==0)
                {
                    printf("\nInvalid move!\a\n");
                    continue;
                }

            }
            break;
        }

        int r; //this integer holds the result
        r = varification(pl);

        if(r==1)
        {
            system("cls");  //this action makes a still screen
            printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
            printf("## You can play against computer or human.\n");
            printf("## You can drop the pebble in any column you want.\n");
            printf("## Every player will get chance by turns.\n\n");

            printf("\n# Move No: %d", i+1);
            box();

            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\a\n", 1, pl, name);
            break ;
        }
        else if(i==34)
        {
            system("cls");  //this action makes a still screen
            printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
            printf("## You can play against computer or human.\n");
            printf("## You can drop the pebble in any column you want.\n");
            printf("## Every player will get chance by turns.\n\n");

            printf("\n# Move No: %d", i+1);
            box();

            printf("\a\n**The match is draw.\a\n");
            break ;
        }

        i++;
    }
}



void box()  //this function creates the box
{
    printf("\n");

    int i, j;

    for(i=0; i<8; i++)  //7 rows
    {
        printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 197, 196,196,196, 197, 196,196,196, 197, 196,196,196, 197, 196,196,196, 197, 196,196,196, 197);
        printf("\n");

        if(i>6) break;

        printf("  %c ", 179);

        for(j=0; j<5 ; j++)  //5 columns
        {
            printf("%s", move[i][j]);
            printf(" %c ", 179);
        }
        printf("\n");
    }

    printf("    1   2   3   4   5  \n\n");  //column number
}



int assign(s1, pl)  //this function inputs the value in 'move'
{
    char symbol;

    if(pl==1) symbol=15;
    else symbol=4;

    if((s1==1&&a<0) || (s1==2&&b<0) || (s1==3&&c<0) || (s1==4&&d<0) || (s1==5&&e<0))
        return 0;  //will make know if move is invalid

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

        return 1;
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



int Computers_Move(int i, int humn_sel)  //computer gives a move
{
    int v1, v2;
    static int comp_sel;

    //Initial_Move:

    if(i==1)
    {
        if(humn_sel==3 || humn_sel==4 || humn_sel==5)comp_sel=humn_sel;
        else comp_sel=humn_sel+1;
    }
    else if(i==3)
    {
        if(comp_sel!=2 && humn_sel!=2) comp_sel=2;
        else if(comp_sel!=4 && humn_sel!=4) comp_sel=4;
        else if(comp_sel!=3 && humn_sel!=3) comp_sel=3;
        else comp_sel=humn_sel;
    }
    else if(i==5)
    {
        if(comp_sel!=humn_sel) comp_sel=humn_sel;
        else comp_sel=1;
    }



    else if(assi!=0){
    //**#Matching_Move:

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


    //**#Bloking_Move:

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



    //**#Planning_Move:

    int k=1, l=2, m=3, n=4, o=5;  //we need them
    int neg;

    //Neglecting_Law:

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


    if(m!=0 && c>=0) comp_sel=m;
    else if(l!=0 && b>=0) comp_sel=l;
    else if(n!=0 && d>=0) comp_sel=n;
    else if(k!=0 && a>=0) comp_sel=k;
    else if(o!=0 && e>=0) comp_sel=o;
    else comp_sel=(comp_sel+3)/2;
    }

    else comp_sel=(rand()%5)+1;

    return comp_sel;
}


//developer's profile
void developer(){
    printf("\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n");
    printf("   * Game's Name: Pebble Dropping\n");
    printf("   * Developer: Minhas Kamal (BSSE-0509, IIT-5th, DU)\n");
    printf("   * Date: 24.April.2013\n");

    //delay
    clock_t start=0, finish=0;
    start=clock();

    while((finish-start)<1800)
        finish=clock();

    return ;
}




