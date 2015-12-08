/**
* Developer: Minhas Kamal (IIT - 5th Batch)
* Date: 18.April.2013
* Game's Name: Pebble Dropping
**/



#include <stdio.h>


void choice();
void box();
int assign(int s1, int i);
int varification(int i);


int a, b, c, d, e;  //these will control the rows
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
    char dis='y';

    while(dis!='n')
    {
        a=5;
        b=5;
        c=5;
        d=5;
        e=5;
        int i, j;
        for(i=0; i<6; i++)  //assigning values in the box
            for(j=0; j<5; j++)
                move[i][j][0]=' ';

        fflush(stdin);
        fflush(stdout);

        choice();  //my main working function

        printf("\n**If you want to continue press 'y' else press 'n'.\n");
        printf("**Enter decision: ");
        fflush(stdin);
        scanf("%c", &dis);

        if(dis!='n')
        {
            system("cls");
        }

        else printf("\n\n##** END **##\n\n\n\n");
    }

    return 0;
}



void choice()  //this function arranges everything
{
    printf("\t***## THIS IS A PEEBLE DROPING GAME ##***\n\n\n");
    printf("**This game is human vs human.\n");
    printf("**Play by selecting columns.\n\n");

    int i;  //input numbers
    for(i=0; i<30; )
    {
        box();

        int p;
        if(i%2==0) p=1;
        else p=2;
        printf("##Player %d\n", p);

        int sel;
        printf("Select a column (1-5): ");
        scanf("%d", &sel);
        printf("\n");

        if(sel<1 || sel>5)
        {
            printf("**Wrong input1!\a");
            continue;
        }

        else
        {
            int assi=assign(sel, i);

            if(assi==1)
            {
                printf("\nInvalid move!\a");
                continue;
            }

        }

        int r;
        r = varification(i);

        if(r==1)
        {
            box();
            printf("\a\a\n**# Player %d wins! #**\a\n", p);
            break;
        }
        else if(i==29)
        {
            box();
            printf("\n**The match is draw.\n");
            break;
        }
        i++;
    }
    return;
}



void box()  //this function creates the box
{
    printf("\n");

    int i, j;

    for(i=0; i<7; i++)
    {
        printf("+---+---+---+---+---+");
        printf("\n");

        if(i>5) break;

        printf("| ");

        for(j=0; j<5 ; j++)
        {
            printf("%s", move[i][j]);
            printf(" | ");
        }
        printf("\n");
    }

    printf("  1   2   3   4   5  \n\n");
}



int assign(s1, i)  //this function inputs the value
{
    char symbol;

    if(i%2==0) symbol='X';
    else symbol='O';

    if((s1==1&&a<0) || (s1==2&&b<0) || (s1==3&&c<0) || (s1==4&&d<0) || (s1==5&&e<0))
        return 1;

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



int varification(int i)  //finds out the winner
{
    int result=0;
    int v1, v2;
    char symbol;

    if(i%2==0) symbol='X';
    else symbol='O';

    for(v1=0; v1<6; v1++)
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1][v2+1][0]==symbol && move[v1][v2+2][0]==symbol && move[v1][v2+3][0]==symbol)
            {
                result=1;
                return result;
            }
    for(v1=5; v1>2; v1--)
        for(v2=0; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2][0]==symbol && move[v1-2][v2][0]==symbol && move[v1-3][v2][0]==symbol)
            {
                result=1;
                return result;
            }
    for(v1=3; v1<6; v1++)
        for(v2=0; v2<2; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2+1][0]==symbol && move[v1-2][v2+2][0]==symbol && move[v1-3][v2+3][0]==symbol)
            {
                result=1;
                return result;
            }
    for(v1=3; v1<6; v1++)
        for(v2=3 ; v2<5; v2++)
            if(move[v1][v2][0]==symbol && move[v1-1][v2-1][0]==symbol && move[v1-2][v2-2][0]==symbol && move[v1-3][v2-3][0]==symbol)
            {
                result=1;
                return result;
            }
}
