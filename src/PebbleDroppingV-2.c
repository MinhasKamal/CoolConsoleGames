/**
* Developer: Minhas Kamal (IIT - 5th Batch)
* Date: 19.April.2013
* Game's Name: Pebble Dropping
**/



#include <stdio.h>

void choice(char *p1, char *p2);
void box();
int assign(int s1, int pl);
int varification(int pl);

int a, b, c, d, e;  //i have made these global to use them in any function
char move[6][5][2] =  //this array collects the moves of the players
{
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " "}
};



int main()
{
    char again='y';
    int z=1;

    for( ; ; )
    {
        fflush(stdin);

        a=5;
        b=5;
        c=5;
        d=5;
        e=5;

        int i, j;
        for(i=0; i<6; i++)  //assigning values in the box
            for(j=0; j<5; j++)
                move[i][j][0]=' ';

        printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //introduction of game
        printf("## Two players can play the game.\n");
        printf("## You can drop the pebble in any column you want.\n");
        printf("## Every player will get chance by turns.\n\n");

        char p1[8], p2[8];  //introduction of players
        if(z);  //input will be asked only first time
        {
            printf("* Enter player-1 name: ");
            gets(p1);
            printf("%s's symbol is '%c'.\n\n", p1, 15);
            printf("* Enter player-2 name: ");
            gets(p2);
            printf("%s's symbol is '%c'.\n\n", p2, 4);
        }
        z=0;

        choice(p1, p2);  //1st function, which organizes everything

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



void choice(char *p1, char *p2)  //this function takes the input of the players & arranges other function works
{
    int p;
    for( ; ; )  //the loop assures valid input
    {
        printf("\n* Who will give first move?\n");
        printf("* Press 1(player-1) or 2(player-2): ");
        scanf("%d", &p);
        if(p>2 || p<1) printf("\n**Wrong input!\a\n**Try again.\n");
        else break;
    }

    int i=0;
    for( ; i<30; )  //the loop will give at most 30 chances
    {
        system("cls");  //this action makes a still screen
        printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
        printf("## Two players can play the game.\n");
        printf("## You can drop the pebble in any column you want.\n");
        printf("## Every player will get chance by turns.\n\n");

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
                int assi = assign(sel, pl);
                if(assi==1)
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
            printf("## Two players can play the game.\n");
            printf("## You can drop the pebble in any column you want.\n");
            printf("## Every player will get chance by turns.\n\n");

            printf("\n# Move No: %d", i+1);
            box();

            printf("\a\a\n%c\t**## Player-%d: %s wins! ##**\a\n", 1, pl, name);
            break ;
        }
        else if(i==29)
        {
            system("cls");  //this action makes a still screen
            printf("\t\t***## THIS IS A PEBBLE DROPPING GAME ##***\n\n\n");  //still image
            printf("## Two players can play the game.\n");
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

    for(i=0; i<7; i++)  //6 rows
    {
        printf("  +%c%c%c+%c%c%c+%c%c%c+%c%c%c+%c%c%c+", 196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
        printf("\n");

        if(i>5) break;

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

        return 2;
    }
}



int varification(int pl)  //finds out the winner
{
    int v1, v2;
    char symbol;

    if(pl==1) symbol=15;
    else symbol=4;

    for(v1=0; v1<6; v1++)  //finds row match
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1][v2+1][0]==symbol && move[v1][v2+2][0]==symbol && move[v1][v2+3][0]==symbol)
                return 1;

    for(v1=5; v1>2; v1--)  //finds column match
        for(v2=0; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2][0]==symbol && move[v1-2][v2][0]==symbol && move[v1-3][v2][0]==symbol)
                return 1;

    for(v1=3; v1<6; v1++)  //finds right-angle match
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2+1][0]==symbol && move[v1-2][v2+2][0]==symbol && move[v1-3][v2+3][0]==symbol)
                return 1;

    for(v1=3; v1<6; v1++)  //finds left-angles match
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2-1][0]==symbol && move[v1-2][v2-2][0]==symbol && move[v1-3][v2-3][0]==symbol)
                return 1;

    return 0;
}

