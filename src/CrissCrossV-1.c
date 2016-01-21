/********************************************************************************************
* Game Name: CrissCross (Version: 01)
* Developer: Minhas Kamal (minhaskamal024@gmail.com)
* Date: 02.June.2013
* Brief Description: This is a simple Tic-Tac-Toe game. Players can play with the computer too.
*     The computer has two types of AI, having two levels of smartness. I wish it will give u 
*     as much pleasure as I had, developing it.
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
#include <stdlib.h>
#include <time.h>


void introduction();
void board();
void delay();
void developer();

void hvh_choice(char *p1, char *p2);  //human vs. human choice
void hvc_choice(char *h);  //human vs. computer choice

int varification();

int Computers_Move(int i, int humn_sel);


char move[3][3];


int main()
{
    developer();    //showing the profile
    delay();delay();delay();
    system("cls");


    char p_again='A';  //controls the loop & players introduction

    while(1)
    {
        int i, j, k=49;
        for(i=0; i<3; i++)  //assigning values in the box
            for(j=0; j<3; j++)
            {
                move[i][j]=k;
                k++;
            }
        introduction();
        delay();delay();delay();

        char against;
        if(p_again!='y')  //input will be asked first time
        {
            printf("\n* Whom do you want to play against?\n");
            delay();delay();
            printf("Press-\t1.against computer\n");
            delay();
            printf("\t2.against human.\n");
            delay();
            printf("Selection- ");
            fflush(stdin);
            scanf("%c", &against);
            fflush(stdin);
            printf("\n");
        }

        if(against-48==1)
        {
           char p[8];  //name of player
           if(p_again!='y')  //input will be asked only first time
           {
               printf("* Enter your name: ");
               gets(p);
               printf("Your symbol is 'X'.\n");
               delay();
               printf("\nComputer's symbol is 'O'.");
               delay();delay();delay();
           }

           hvc_choice(p);
        }


        else if(against-48==2)
        {
            char p1[8], p2[8];  //name of players
            if(p_again!='y')  //input will be asked only first time
            {
                printf("* Enter player-1 name: ");
                gets(p1);
                printf("%s's symbol is 'X'.\n\n", p1);
                delay();
                printf("* Enter player-2 name: ");
                gets(p2);
                printf("%s's symbol is 'O'.\n\n", p2);
                delay();delay();delay();
            }

            hvh_choice(p1, p2);
        }

        else
        {
            printf("Wrong input!\n\a");
            delay();delay();
            system("cls");
            continue;
        }

        printf("\n\n* Do you want to play again?\n");
        delay();
        printf("Press 'y'(yes) or 'n'(no): ");
        fflush(stdin);
        scanf("%c", &p_again);
        delay();

        if(p_again!='n')
            system("cls");
        else break;
    }

    printf("\n\n\t*** GAME ENDS ***\n");delay();  //end view
    printf("\t     .");delay();printf("  .");delay();
    printf("  .\n\n\n");delay();delay();delay();

    return 0;
}

/****/

void hvc_choice(char *h)  //this function takes the input of the players & arranges other function works
{
    int p;
    while(1)  //the loop assures valid input
    {
        printf("\n\n* Who will give first move?\n");
        delay();
        printf("* Press 1(human) or 2(computer): ");

        char ch;  //this technique prevents program crush when error is input
        fflush(stdin);
        scanf("%c", &ch);
        p=ch-48;

        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int sel;  //player's selection
    int i=0;
    while(i<9)  //the loop will give at most 35 chances
    {
        system("cls");  //this action makes a still screen
        introduction();
        printf("\n##**HUMAN vs. COMPUTER\n\n");
        board();  //2nd function

        int pl;
        char *name;
        if(i%2==0) pl=p;
        else pl=3-p;
        if(pl==1) name=h;
        else name="Computer";

        printf("## Player-%d: %s\n", pl, name);
        delay();

        while(1)  //the loop will assure valid choice
        {
            printf("Select a cell: ");

            if(pl==1)  //human choice
            {
                char ch;  //this technique prevents program crush when error is input
                fflush(stdin);
                scanf("%c", &ch);
                sel=ch-48;
            }
            else  //computer choice
            {
                sel=Computers_Move(i, sel);
                delay();
                printf("%d", sel);
                delay();delay();
            }

            printf("\n");

            char matched=0;

            int i, j;
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                    if(move[i][j]-48==sel)
                    {
                        if(pl==1) move[i][j]='X';
                        else move[i][j]='O';
                        matched=1;
                        break;
                    }
                if(matched) break;
            }

            if(!matched)
            {
                printf("\nInvalid move!\a\n");
                continue;
            }

            break;
        }

        if(varification())
        {
            system("cls");  //this action makes a still screen
            introduction();
            board();
            delay();
            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\a\n", 1, pl, name);
            break ;
        }
        else if(i==8)
        {
            system("cls");  //this action makes a still screen
            introduction();
            board();
            delay();
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
        delay();
        printf("* Press 1(player-1) or 2(player-2): ");

        char ch;  //this technique prevents program crush when error is input
        fflush(stdin);
        scanf("%c", &ch);
        p=ch-48;

        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int assi=1, i=0;
    while(i<9)  //the loop will give at most 35 chances
    {
        system("cls");  //this action makes a still screen
        introduction();
        printf("\n##**HUMAN vs. HUMAN\n\n");
        board();  //2nd function

        int pl;
        char *name;
        if(i%2==0) pl=p;
        else pl=3-p;
        if(pl==1) name=p1;
        else name=p2;

        printf("## Player-%d: %s\n", pl, name);
        delay();

        while(1)  //the loop will assure valid choice
        {
            int sel;  //player's selection
            printf("Select a cell: ");

            char ch;  //this technique prevents program crush when error is input
            fflush(stdin);
            scanf("%c", &ch);
            sel=ch-48;

            printf("\n");

            char matched=0;

            int i, j;
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                    if(move[i][j]-48==sel)
                    {
                        if(pl==1)move[i][j]='X';
                        else move[i][j]='O';
                        matched=1;
                        break;
                    }
                if(matched) break;
            }

            if(!matched)
            {
                printf("\nInvalid move!\a\n");
                continue;
            }

            break;
        }


        if(varification())
        {
            system("cls");  //this action makes a still screen
            introduction();
            board();
            delay();
            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\a\n", 1, pl, name);
            break ;
        }
        else if(i==8)
        {
            system("cls");  //this action makes a still screen
            introduction();
            board();
            delay();
            printf("\a\n**The match is draw.\a\n");
            break ;
        }

        i++;
    }
}

/****/

void board()
{
    int i, j;
    printf("\n\n");
    for(i=0; i<3; i++)
    {
        if(i)
        {
            printf("\n  %c%c%c%c%c%c", 196,196,196,197,196,196);
            printf("%c%c%c%c%c\n", 196,197,196,196,196);
        }
        printf("  ");
        for(j=0;j<3;j++)
        {
            printf(" %c ", move[i][j]);
            if(j!=2) printf("%c", 179);
        }
    }
    printf("\n\n");
}

void introduction()  //this function prints the introduction of the game
{
    printf("\t\t***%c%c CRISS-CROSS GAME %c%c***\n\n\n", 1, 1, 1, 1);  //still image
    printf("## You can play against computer or human.\n");
    printf("## Every player will get chance by turns.\n\n");

    return ;
}

void delay()  //delays 0.6 second
{
    clock_t start=0, finish=0;
    start=clock();

    while((finish-start)<600)
        finish=clock();

    return ;
}

/****/

int varification()
{
    int i;

    for(i=0; i<3; i++)  //row & column match
    {
        if(move[i][0]==move[i][1] && move[i][0]==move[i][2]) return 1;
        if(move[0][i]==move[1][i] && move[0][i]==move[2][i]) return 1;
    }

    if(move[0][0]==move[1][1] && move[1][1]==move[2][2]) return 1;

    if(move[0][2]==move[1][1] && move[1][1]==move[2][0]) return 1;

    return 0;
}

/****/

int Computers_Move(int i, int humn_sel)
{
    static int comp_sel;
    int s=1;

    if(i==0)
    {
        s=(rand()%9)+1;
        if(s%2==0) comp_sel=5;
        else comp_sel=s;
    }
    else if(i==1)
    {
        if(humn_sel==5)
        {
            s=(rand()%9)+1;
            if(s==5) comp_sel=7;
            else if(s%2==0) comp_sel=s-1;
            else comp_sel=s;
        }
        else return 5;
    }
    else if(i==2)
    {
        if(comp_sel==5)
        {
            if(humn_sel%2==0)
            {
                s=(rand()%9)+1;
                if(s%2==0 || s==5) comp_sel=3;
                else comp_sel=s;
            }
            else if(humn_sel==1) comp_sel=9;
            else if(humn_sel==9) comp_sel=1;
            else if(humn_sel==3) comp_sel=7;
            else if(humn_sel==7) comp_sel=3;
        }
        else
        {
            if(humn_sel%2==0) comp_sel=5;
            else if(humn_sel==5) comp_sel=(rand()%4)+1;
            else comp_sel=(comp_sel+humn_sel)/2;
        }
    }
    else
    {
        int j;
        /**matching move**/
        for(j=0; j<3; j++)
        {
            if(move[j][0]=='O' && move[j][0]==move[j][1] && move[j][2]<60) return 3*(j+1);
            if(move[j][0]=='O' && move[j][0]==move[j][2] && move[j][1]<60) return 3*(j+1)-1;
            if(move[j][1]=='O' && move[j][1]==move[j][2] && move[j][0]<60) return 3*(j+1)-2;

            if(move[0][j]=='O' && move[0][j]==move[1][j] && move[2][j]<60) return 7+j;
            if(move[0][j]=='O' && move[0][j]==move[2][j] && move[1][j]<60) return 4+j;
            if(move[1][j]=='O' && move[1][j]==move[2][j] && move[0][j]<60) return 1+j;
        }
        if(move[0][0]=='O' && move[0][0]==move[1][1] && move[2][2]<60) return 9;
        if(move[0][0]=='O' && move[0][0]==move[2][2] && move[1][1]<60) return 5;
        if(move[1][1]=='O' && move[1][1]==move[2][2] && move[0][0]<60) return 1;

        if(move[0][2]=='O' && move[0][2]==move[1][1] && move[2][0]<60) return 7;
        if(move[0][2]=='O' && move[0][2]==move[2][0] && move[1][1]<60) return 5;
        if(move[2][0]=='O' && move[2][0]==move[1][1] && move[0][2]<60) return 3;
        /**blocking move**/
        for(j=0; j<3; j++)
        {
            if(move[j][0]=='X' && move[j][0]==move[j][1] && move[j][2]<60) return 3*(j+1);
            if(move[j][0]=='X' && move[j][0]==move[j][2] && move[j][1]<60) return 3*(j+1)-1;
            if(move[j][1]=='X' && move[j][1]==move[j][2] && move[j][0]<60) return 3*(j+1)-2;

            if(move[0][j]=='X' && move[0][j]==move[1][j] && move[2][j]<60) return 7+j;
            if(move[0][j]=='X' && move[0][j]==move[2][j] && move[1][j]<60) return 4+j;
            if(move[1][j]=='X' && move[1][j]==move[2][j] && move[0][j]<60) return 1+j;
        }
        if(move[0][0]=='X' && move[0][0]==move[1][1] && move[2][2]<60) return 9;
        if(move[0][0]=='X' && move[0][0]==move[2][2] && move[1][1]<60) return 5;
        if(move[1][1]=='X' && move[1][1]==move[2][2] && move[0][0]<60) return 1;

        if(move[0][2]=='X' && move[0][2]==move[1][1] && move[2][0]<60) return 7;
        if(move[0][2]=='X' && move[0][2]==move[2][0] && move[1][1]<60) return 5;
        if(move[2][0]=='X' && move[2][0]==move[1][1] && move[0][2]<60) return 3;
        /**plan breaker move**/
        if(i==3)
        {
            if(move[1][1]=='O')
            {
                if(move[0][1]==move[1][2]) return 3;
                else if(move[0][1]==move[1][0]) return 1;
                else if(move[1][0]==move[2][1]) return 7;
                else if(move[2][1]==move[1][2]) return 9;
            }
            else if(move[1][1]=='X')
            {
                if(move[0][0]>60 && move[2][2]>60) return 7;
                else if(move[0][2]>60 && move[2][0]>60) return 9;
            }
        }
        /**planning move**/
        if(move[1][1]=='O')
        {
            if(move[0][0]=='O')
            {
                if(move[2][1]<60 && move[0][1]<60) return 2;
                else if(move[1][2]<60 && move[1][0]<60) return 4;
            }
            if(move[0][2]=='O')
            {
                if(move[1][0]<60 && move[1][2]<60) return 6;
                else if(move[2][1]<60 && move[0][1]<60) return 2;
            }
            if(move[2][0]=='O')
            {
                if(move[0][1]<60 && move[2][1]<60) return 8;
                else if(move[1][2]<60 && move[1][0]<60) return 4;
            }
            if(move[2][2]=='O')
            {
                if(move[0][1]<60 && move[2][1]<60) return 8;
                else if(move[1][0]<60 && move[1][2]<60) return 6;
            }
        }
        else if(move[0][0]<60) return 5;
        /**random move**/
        int sl=1;
        sl=((rand()%9)+1);
        if(sl==5) sl=6;
        comp_sel=sl;
    }

    return comp_sel;
}



//developer's profile
void developer(){
    printf("\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n");
    printf("   * Game's Name:  Criss-cross\n");
    printf("   * Developer:  Minhas Kamal (BSSE-0509, IIT-5th, DU)\n");
    printf("   * Date:  02.June.2013\n");
    printf("   * Comment:  I wish it will give u as much pleasure as I had, developing it.\n");

    return ;
}


