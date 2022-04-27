/*
Team Name:-Runtime Error
Team Memebers:- 1.)Deepanshu Pal
                2.)Karan Singh  
                3.)Shikhar Sharma
                4.)Tushar Sharma
                5.)Talha Shaad
                6.)Urvi Rajawat
*/
#include<stdio.h>
#include<string.h>
//declaration of funtions and variables.  
char x,o;
char a[9]={'1','2','3','4','5','6','7','8','9'};
char u1[50],u2[50];
void board();
void rules();
int checkforwin();
int main()
{   //First screen of game from where Player inputs and selection of "X" and "O" to start the game,
    //P is used as pointer for score.txt which will store the result of game about the winner and Draws in game.
    FILE *p;
    p=fopen("score.txt","a+");
    fclose(p);
    system("color 09");
    int player=1;
    int choice,score=-1;
    char symbol,re;
    char start,dec;
    int s;

    //rule funtion call before the starting of game. 
    rules();

    //Selection Between Start the game or To View Result of Previous Games.
    printf("\n\nType 1 to start the game:-\nType 2 to view Result:-\n");
    scanf("%d",&s);
    if(s==1)
    {

    //Read is considered as loop which is used in various places to send back the compiler to here when it is needed or required.
    read:
        p=fopen("score.txt","a+");
    printf("\nEnter name of player1: ");
    scanf("%s",u1);
    fprintf(p,"\n%s",u1);
    printf("Enter name of player2: ");
    scanf("%s",u2);
    fprintf(p,"\t%s",u2);
    fclose(p);
    if(!strcmp(u1,u2))
    {
        printf("Enter names of different players!\n\n");
        goto read;
    }
    else
        decision();


    system("color fc");
    board();

    do
    {
        //Here the board entry loop starts which is will fill the entry in board as per Player response.
        player=((player%2)?1:2);
        if(player==1)
        printf("%s Type any digit from 1-9 to fill your response:- ",u1);
        else
            printf("%s Type any digit from 1-9 to fill your response:- ",u2);
        scanf("%d",&choice);
        symbol=((player==1)?x:o);
        if(choice==1 && a[0]=='1')
            a[0]=symbol;
        else if(choice==2 && a[1]=='2')
            a[1]=symbol;
        else if(choice==3 && a[2]=='3')
            a[2]=symbol;
        else if(choice==4 && a[3]=='4')
            a[3]=symbol;
        else if(choice==5 && a[4]=='5')
            a[4]=symbol;
        else if(choice==6 && a[5]=='6')
            a[5]=symbol;
        else if(choice==7 && a[6]=='7')
            a[6]=symbol;
        else if(choice==8 && a[7]=='8')
            a[7]=symbol;
        else if(choice==9 && a[8]=='9')
            a[8]=symbol;
        else
            {printf("Wrong Selection\n");player--;}

        //Function call to check for the winner in the Games as per rules. 
        score=checkforwin();
        player++;
        board();
    }while(score == -1);

    
    p=fopen("score.txt","a+");
    /*Loop to print the winner as per rules.
    It also gives option wether to satrt the game again or to exit from the application.
    */
    if(score==1)
    {
        int cho;
        if(player==2)
        {printf("\n\nPlayer1 %s Wins!\n\n",u1);fprintf(p,"\t%s",u1);
        getch();}
        else
            {printf("\n\nPlayer2 %s Wins!\n\n",u2);fprintf(p,"\t%s",u2);
        getch();
            }
        fclose(p);
              printf("\n\nPress 1 to start the game:- ");
        scanf("%d",&cho);
        if(cho==1)
            goto read;
        else
            getch();
    }
    }
    else
    {
        printf("\n\nEnter to View Result!\n\n");fprintf(p,"\t%s","RESULT");
        getch();
    }
    /*Call back to Start screen of choice of starting the game or to view result.
    As per loop new window will appear with results of previous matches which is stored in score.txt. 
    It also gives choice to user to start the game from that screen onwards.
    */
    if(s==2)
    {
        int cho;
        system("cls");
        printf("\n\n");
        printf("\tResult\n\n");
        char c;
        p=fopen("score.txt","r");
        while((c=getc(p))!=EOF)
        {
            printf("%c",c);
        }
        fclose(p);
        printf("\n\nPress 1 to start the game:- ");
        scanf("%d",&cho);
        if(cho==1){
        system("cls");
            goto read;
            }
        else{
            getch();
            }
    }
    else
    {
        printf("\n\nShould have typed 1 to play the game!\nHope to see you back soon!\n\n");
        getch();
    }
}

//Here all the condition of winning as per rules is checked once the game concluded and Winner/Tie of the round is Announced. 
int checkforwin()
{
    if(a[0]==a[1] && a[1]==a[2])
        return 1;
    else if(a[3]==a[4] && a[4]==a[5])
        return 1;
    else if(a[6]==a[7] && a[7]==a[8])
        return 1;
    else if(a[0]==a[3] && a[3]==a[6])
        return 1;
    else if(a[1]==a[4] && a[4]==a[7])
        return 1;
    else if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else if(a[0]==a[4] && a[4]==a[8])
        return 1;
    else if(a[2]==a[4] && a[4]==a[6])
        return 1;
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    else
        return -1;
}

//Here lie the Board Appearance of our game.
void board()
{
    int i;

    system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("%s:- (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,o);

        printf("  %c |  %c | %c\n",a[0],a[1],a[2]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("    |    |    \n");
        printf("  %c |  %c | %c\n",a[3],a[4],a[5]);
        printf("    |    |    \n");
        printf("----|----|----\n");
        printf("  %c |  %c | %c\n",a[6],a[7],a[8]);
        printf("    |    |    \n");
    }

/*Information About the Team.
  Games Rules How Game is played and what are condition of winning.
  */
void rules()
{
    printf("\tTic-Tac-Toe\n\n");
        printf("\t\tThis Project Was Made By Team Runtime Error\n ");
        printf("\t\t  Member 1:-Deepanshu Pal  CRN No:-21BCA107\n");
        printf("\t\t  Member 2:-Karan Singh  CRN No:-21BCA043\n");
        printf("\t\t  Member 3:-Shikhar Sharma  CRN No:-21BCA080\n");
        printf("\t\t  Member 4:-Tushar Sharma  CRN No:-21BCA094\n");
        printf("\t\t  Member 5:-Talha Shaad  CRN No:-21BCA090\n");
        printf("\t\t  Member 6:-Urvi Rajawat  CRN No:-21BCA095\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");

}

/*Decision making point between player fot "X" and "O".
  As first person gets to choose between "X" and "O".
  Second person is assigned the left over option byitself.
   */
int decision()
{
    char dec;
        deci:
        printf("\n\nPlayer1 %s choose the X or 0:",u1);
        dec=getchar();
        scanf("%c",&dec);
        {
            if(dec=='X' || dec=='x')
            {
                x='X';
                o='0';
            }
            else if(dec=='0')
            {
                x='0';
                o='X';
            }
            else
            {
                printf("Please enter either X or 0 only \n\n");
                goto deci;
            }
        }
}
