/**
* Game's Name: 16-stones
* Version: 1
* Developer: Minhas Kamal (IIT - 5th Batch)
* Date: --.June.2013
* Comment: This is the demo of the main game.
**/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void board();
void delay(float t);


char cell[42];


int main()
{
    int i;
    for(i=0; i<16; i++) cell[i]=1;
    for(i=16; i<26; i++) cell[i]=0;
    for(i=26; i<42; i++) cell[i]=2;

    printf("\t\t**#Sixteen Stones#**\n\n\n");
    delay(0.3);

    char pl_n1[10], pl_n2[10];
    printf("\nEnter player-1 name: ");
    gets(pl_n1);
    delay(0.3);
    printf("Your Symbol is: %c\n", 1);
    delay(0.5);
    printf("\nEnter player-2 name: ");
    gets(pl_n2);
    delay(0.3);
    printf("Your Symbol is: %c\n", 2);
    delay(0.7);

    int pl_1_st=16, pl_2_st=16;
    i=0;
    while(1)
    {
        system("cls");

        printf("Move No: %d\n", i+1);
        board();

        int player;
        char *name, symbol;
        if(i%2==0) player=1;
        else player=2;
        if(player==1)
        {
            name=pl_n1;
            symbol=1;
        }
        else
        {
            name=pl_n2;
            symbol=2;
        }

        printf("%c Player %d: %s\n", symbol, player, name);

        int from;
        printf("Select the stone: ");
        scanf("%d", &from);
        delay(0.2);

        int to;
        printf("Select the place: ");
        scanf("%d", &to);
        delay(0.4);

        i++;
    }

    return 0;
}


void board()
{
    int j=0;

    printf("\t\t1     2     3     4     5\n\n");

    printf("\t\t %c\%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c\%c    1\n", cell[j++], 196,196,196,196, 196, 196,196,196,196,196, cell[j++], 196,196,196,196,196, 196, 196,196,196,196, cell[j++]);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,92,0,0, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 0,0,47,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,92,0, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 0,47,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,92, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 47,0,0,0,0, 0);

    printf("\t\t %c\%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c\%c    2\n", 0, 0,0,0,0, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,92,0,0,0, 179, 0,0,0,47,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,92,0,0, 179, 0,0,47,0,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,0,92,0, 179, 0,47,0,0,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,0,0,92, 179, 47,0,0,0,0, 0, 0,0,0,0,0, 0);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   3\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,0,47, 179, 92,0,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,47,0, 179, 0,92,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,47,0,0, 179, 0,0,92,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,47,0,0,0, 179, 0,0,0,92,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 47,0,0,0,0, 179, 0,0,0,0,92, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   4\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,47, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 92,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,47,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,92,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,47,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,92,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,47,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,92,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 47,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,92, 179);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   5\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   6\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 92,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,47, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,92,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,0,47,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,92,0,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,0,47,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,92,0, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 0,47,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,92, 179, 0,0,0,0,0, 179, 0,0,0,0,0, 179, 47,0,0,0,0, 179);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   7\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 92,0,0,0,0, 179, 0,0,0,0,47, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,92,0,0,0, 179, 0,0,0,47,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,92,0,0, 179, 0,0,47,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,92,0, 179, 0,47,0,0,0, 179, 0,0,0,0,0, 179);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 179, 0,0,0,0,0, 179, 0,0,0,0,92, 179, 47,0,0,0,0, 179, 0,0,0,0,0, 179);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c   8\n", cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++]);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,0,0,47, 179, 92,0,0,0,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,0,47,0, 179, 0,92,0,0,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,0,47,0,0, 179, 0,0,92,0,0, 0, 0,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,0, 0, 0,47,0,0,0, 179, 0,0,0,92,0, 0, 0,0,0,0,0, 0);
    printf("\t\t %c\%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c\%c    9\n", 0, 0,0,0,0, cell[j++], 196,196,196,196,196, cell[j++], 196,196,196,196,196, cell[j++], 0,0,0,0, 0);

    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,0,47, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 92,0,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,0,47,0, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 0,92,0,0,0, 0);
    printf("\t\t%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\n", 0, 0,0,47,0,0, 0, 0,0,0,0,0, 179, 0,0,0,0,0, 0, 0,0,92,0,0, 0);
    printf("\t\t %c\%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c%c\%c\%c%c%c%c\%c   10\n", cell[j++], 196,196,196,196, 196, 196,196,196,196,196, cell[j++], 196,196,196,196,196, 196, 196,196,196,196, cell[j]);
    printf("\n");

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

int assign(int from, int to)
{
    int index=from, move[2], i;
    for(i=0; i<2; i++)
    {
        if(index==11) move[i]=0;
        else if(index==31) move[i]=1;
        else if(index==51) move[i]=2;
        else if(index==22) move[i]=3;
        else if(index==32) move[i]=4;
        else if(index==42) move[i]=5;
        else if(index==13) move[i]=6;
        else if(index==23) move[i]=7;
        else if(index==33) move[i]=8;
        else if(index==43) move[i]=9;
        else if(index==53) move[i]=10;
        else if(index==14) move[i]=11;
        else if(index==24) move[i]=12;
        else if(index==34) move[i]=13;
        else if(index==44) move[i]=14;
        else if(index==54) move[i]=15;
        else if(index==15) move[i]=16;
        else if(index==25) move[i]=17;
        else if(index==35) move[i]=18;
        else if(index==45) move[i]=19;
        else if(index==55) move[i]=20;
        else if(index==16) move[i]=21;
        else if(index==26) move[i]=22;
        else if(index==36) move[i]=23;
        else if(index==46) move[i]=24;
        else if(index==56) move[i]=25;
        else if(index==17) move[i]=26;
        else if(index==27) move[i]=27;
        else if(index==37) move[i]=28;
        else if(index==47) move[i]=29;
        else if(index==57) move[i]=30;
        else if(index==18) move[i]=31;
        else if(index==28) move[i]=32;
        else if(index==38) move[i]=33;
        else if(index==48) move[i]=34;
        else if(index==58) move[i]=35;
        else if(index==29) move[i]=36;
        else if(index==39) move[i]=37;
        else if(index==49) move[i]=38;
        else if(index==110) move[i]=39;
        else if(index==310) move[i]=40;
        else if(index==510) move[i]=41;
        else return 1;

        index=to;
    }

    int f=move[0]+1, t=move[1]+1;

    if(f==t || cell[f]==0 || cell[t]>0) return 2;

    if(f==1 && (t<5||t==7));
    else if((f==2) && (t==1||t==3||t==5||t==9));
    else if((f==3) && (t==1||t==2||t==6||t==9));
    else if((f==4) && (t==1||t==5||t==6||t==9||t==15));
    else if((f==5) && (t==2||t==4||t==6||t==9||t==14));
    else if((f==6) && (t==3||t==4||t==5||t==9||t==13));
    else if((f==7) && (t==8||t==9||t==12||t==17));
    else if((f==8) && (t==7||t==9||t==10||t==13||t==18));
    else if((f==9) && (t<12||t==13||t==14||t==15||t==17||t==19||t==21));
    else if((f==10) && (t==11||t==9||t==8||t==15||t==20));
    else if((f==11) && (t==10||t==9||t==16||t==21));
    else if((f==12) && (t==7||t==13||t==14||t==17||t==22));
    else if((f==13) && (t==12||t==8||t==9||t==6||t==14||t==15||t==18||t==23||t==17));
    else if((f==14) && (t==9||t==5||t==15||t==16||t==19||t==24||t==13||t==12));
    else if((f==15) && (t==9||t==4||t==21||t==16||t==20||t==25||t==14||t==13));
    else if((f==16) && (t==11||t==21||t==26||t==15||t==14));
    else if((f==17) && (t==12||t==7||t==13||t==9||t==18||t==19||t==22||t==27));
    else if((f==18) && (t==17||t==13||t==8||t==19||t==20||t==23||t==28));
    else if((f==19) && (t==14||t==9||t==20||t==21||t==24||t==29||t==18||t==17));
    else if((f==20) && (t==15||t==10||t==21||t==25||t==30||t==19||t==18));
    else if((f==21) && (t==16||t==11||t==26||t==31||t==20||t==19||t==15||t==9));
    else if((f==22) && (t==17||t==12||t==23||t==24||t==28||t==34||t==27||t==32));
    else if((f==23) && (t==22||t==18||t==13||t==24||t==25||t==28||t==33));



    return 0;
}


