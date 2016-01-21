/********************************************************************************************
* Game Name: 3Stones (Version: 1)
* Developer: Minhas Kamal (minhaskamal024@gmail.com)
* Date: 17.June.2013
* Brief Description: In this game players place three stones on a board and move them.
*   So that they can align them serially or place against the opponent.
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
void delay(float t);
void developer();

int assign(int from, int to, int player);
int varification();

char move[9];

int main()
{
    developer();    //showing the profile
    delay(1.8);
    system("cls");


    char p_again='A';  //controls the loop & players introduction

    while(1)
    {
        int i;
        for(i=0; i<9; i++) move[i]=0;

        introduction();
        delay(0.6);

        char p1[8], p2[8];  //name of players
        if(p_again!='y'){  //input will be asked only first time
            fflush(stdin);
            printf("* Enter player-1 name: ");
            gets(p1);
            delay(0.3);
            printf("%s's symbol is '%c'.\n\n", p1, 5);
            delay(0.5);
            printf("* Enter player-2 name: ");
            gets(p2);
            delay(0.3);
            printf("%s's symbol is '%c'.\n\n", p2, 6);
        }

        int p;  //player
        while(1)  //the loop assures valid input
        {
            delay(0.7);
            printf("\n* Who will give first move?\n");
            delay(0.3);
            printf("* Press 1(player-1) or 2(player-2): ");

            char ch;  //this technique prevents program crush when error is input
            fflush(stdin);
            scanf("%c", &ch);
            p=ch-48;
            delay(0.3);

            if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
            else break;
        }

        i=0;
        while(1)  //primary input
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n##**HUMAN vs. HUMAN\n");
            printf("\n# Stone Placing\n");
            board();

            int player;
            char *name, symbol;
            if(i%2==0) player=p;
            else player=3-p;

            if(player==1){
                name=p1;
                symbol=5;
            }
            else{
                name=p2;
                symbol=6;
            }

            printf("%c Player-%d: %s", symbol, player, name);
            delay(0.3);
            printf("\nRemaining Stones: ");
            delay(0.3);

            int j;
            for(j=0; j<=(5-i)/2; j++)
                printf(" %c", symbol);
            int sel;
            printf("\nSelect the place: ");

            char ch;  //this technique prevents program crush when error is input
            fflush(stdin);
            scanf("%c", &ch);
            sel=ch-48;

            delay(0.2);

            if(move[sel-1]>1 || sel>9 || sel<1){
                printf("\nInvalid selection!\a\n");
                delay(0.5);
                continue;
            }

            else move[sel-1]=symbol;

            if(i>3 && varification()){
                system("cls");  //this action makes a still screen
                introduction();
                printf("\n##**HUMAN vs. HUMAN\n\n");
                printf("\n# Stone Placing\n");
                board();
                delay(0.4);
                printf("\n%c\t\a\a**## Player-%d: %s wins! ##**\n", 1, player, name);
                delay(0.6);
                printf("\a");
                delay(0.7);
                printf("\a\a");
                break ;
            }

            if(i>=5) break;
            i++;
        }

        i=0;
        while(!varification())  //secondary input
        {
            system("cls");  //this action makes a still screen
            introduction();
            printf("\n##**HUMAN vs. HUMAN\n\n");
            printf("\n# Move No: %d\n", i+1);
            board();

            int player;
            char *name, symbol;
            if(i%2==0) player=p;
            else player=3-p;

            if(player==1){
                name=p1;
                symbol=5;
            }
            else{
                name=p2;
                symbol=6;
            }

            int from, to;  //move
            printf("%c Player-%d: %s\n", symbol, player, name);
            delay(0.4);

            printf("Select the stone: ");
            char ch;  //this technique prevents program crush when error is input
            fflush(stdin);
            scanf("%c", &ch);
            from=ch-48;
            delay(0.2);

            printf("Select the place: ");
            fflush(stdin);  //this technique prevents program crush when error is input
            scanf("%c", &ch);
            to=ch-48;
            delay(0.3);

            if(from>9 || to>9 || from<1 || to<1){
                printf("\nWrong input!\a\n");
                delay(0.5);
                continue;
            }

            if(assign(from, to, player)){
                printf("\nInvalid input!\a\n");
                delay(0.5);
                continue;
            }

            if(varification()) {
                system("cls");  //this action makes a still screen
                introduction();
                printf("\n##**HUMAN vs. HUMAN\n\n");
                printf("\n# Move No: %d\n", i+1);
                board();

                delay(0.4);
                printf("\n%c\t\a\a**## Player-%d: %s wins! ##**\n", 1, player, name);
                delay(0.6);
                printf("\a");
                delay(0.7);
                printf("\a\a");
                break ;
            }

            i++;
        }

        printf("\n\n* Do you want to play again?\n");
        delay(0.5);
        printf("Press 'y'(yes) or 'n'(no): ");
        fflush(stdin);
        scanf("%c", &p_again);
        delay(0.3);

        if(p_again!='n') system("cls");
        else break;
    }

    printf("\n\n\t**%c GAME ENDS %c**\n", 177, 177);delay(0.5);  //end view
    printf("\t     .\a");delay(0.5);printf("  .\a");delay(0.5);
    printf("  .\a\n");delay(0.8);printf("\n");delay(0.6);

    return 0;
}

/*************************************************************/

void board()
{
    printf("\n   1          2          3\n");
    printf("    %c%c%c%c%c%c%c%c%c%c", move[0],196,196,196,196,196,196,196,196,196);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n", move[1],196,196,196,196,196,196,196,196,196,move[2]);

    printf("    %c\\        %c        /%c\n", 179, 179, 179);
    printf("    %c \\       %c       / %c\n", 179, 179, 179);
    printf("    %c  \\      %c      /  %c\n", 179, 179, 179);
    printf("    %c   \\     %c     /   %c\n", 179, 179, 179);
    printf("    %c    \\    %c    /    %c\n", 179, 179, 179);
    printf("    %c     \\   %c   /     %c\n", 179, 179, 179);
    printf("    %c      \\  %c  /      %c\n", 179, 179, 179);
    printf("    %c       \\ %c /       %c\n", 179, 179, 179);
    printf("    %c        \\5/        %c\n", 179, 179, 179);

    printf("  4 %c%c%c%c%c%c%c%c%c%c", move[3],196,196,196,196,196,196,196,196,196);
    printf("%c%c%c%c%c%c%c%c%c%c%c 6\n", move[4],196,196,196,196,196,196,196,196,196,move[5]);

    printf("    %c        /%c\\        %c\n", 179, 179, 179);
    printf("    %c       / %c \\       %c\n", 179, 179, 179);
    printf("    %c      /  %c  \\      %c\n", 179, 179, 179);
    printf("    %c     /   %c   \\     %c\n", 179, 179, 179);
    printf("    %c    /    %c    \\    %c\n", 179, 179, 179);
    printf("    %c   /     %c     \\   %c\n", 179, 179, 179);
    printf("    %c  /      %c      \\  %c\n", 179, 179, 179);
    printf("    %c /       %c       \\ %c\n", 179, 179, 179);
    printf("    %c/        %c        \\%c\n", 179, 179, 179);

    printf("    %c%c%c%c%c%c%c%c%c%c", move[6],196,196,196,196,196,196,196,196,196);
    printf("%c%c%c%c%c%c%c%c%c%c%c\n", move[7],196,196,196,196,196,196,196,196,196,move[8]);
    printf("   7          8          9\n\n");

    return ;
}

void introduction()  //this function prints the introduction of the game
{
    printf("\t\t***%c%c Three Stones %c%c***\n\n\n", 1, 2, 2, 1);  //still image
    printf("## This is a human vs. human game.\n");
    printf("## Every player will get chance by turns.\n\n\n");

    return ;
}

void delay(float t)  //delays t seconds
{
    clock_t start=0;
    start=clock();

    while((clock()-start)<(t*1000));

    return ;
}

/***********************************************************/

int assign(int from, int to, int player)
{
    from--;
    to--;

    if(!move[from]) return 1;
    if(move[to]) return 1;

    if(player==1 && move[from]==6) return 2;
    if(player==2 && move[from]==5) return 2;

    if(from==to) return 3;

    if(from==0 && (to<5 && to!=2));
    else if(from==1 && (to<5 && to!=3));
    else if(from==2 && (to<6 && to!=0 && to!=3));
    else if(from==3 && (!(to%2) && to!=2 && to!=8));
    else if(from==4);
    else if(from==5 && (!(to%2) && to!=0 && to!=6));
    else if(from==6 && (to>2 && to!=5 && to!=8));
    else if(from==7 && (to>3 && to!=5));
    else if(from==8 && (to>3 && to!=6));
    else return 4;

    move[from]=0;
    if(player==1) move[to]=5;
    else move[to]=6;

    return 0;
}

/**************************************************/

int varification()
{
    if(move[4])
    {
        if(move[0]==move[4] && move[4]==move[8]) return 1;
        if(move[2]==move[4] && move[4]==move[6]) return 1;
        if(move[1]==move[4] && move[4]==move[7]) return 1;
        if(move[3]==move[4] && move[4]==move[5]) return 1;
    }

    if(move[0]==move[1] && move[1]==move[2] && move[0]) return 1;
    if(move[2]==move[5] && move[5]==move[8] && move[2]) return 1;
    if(move[8]==move[7] && move[7]==move[6] && move[8]) return 1;
    if(move[6]==move[3] && move[3]==move[0] && move[6]) return 1;

    return 0;
}


//developer's profile
void developer(){
    printf("\n\n\n\n\n \n\n\n\n\n \n\n\n\n\n");
    printf("   * Game's Name:  Three_Stones\n");
    printf("   * Developer:  Minhas Kamal (BSSE-0509, IIT-5th, DU)\n");
    printf("   * Date:  17.June.2013\n");
    printf("   * Comment:  I have tried to improve the game made by my friends Shamim(BSSE-0511).\n");
}





