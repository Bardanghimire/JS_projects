#include <stdio.h>
#include <stdlib.h> //for system clear used later on //

int choice;
int any = 1;
char user;
int gameover = 0;
char again;

void display(char n[])
{
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("___%c___|___%c___|___%c___\n", n[6], n[7], n[8]);
    printf("___%c___|___%c___|___%c___\n", n[3], n[4], n[5]);
    printf("___%c___|___%c___|___%c___\n", n[0], n[1], n[2]);
    scanf("%d", &choice);
}

void logic(char n[])
{
    if (any == 1)
    {
        user = 'X';
        any = 0;
    }
    else
    {
        user = 'O';
        any = 1;
    }
    if (choice == 1)
    {
        n[0] = user;
    }
    else if (choice == 2)
    {
        n[1] = user;
    }
    else if (choice == 3)
    {
        n[2] = user;
    }
    else if (choice == 4)
    {
        n[3] = user;
    }
    else if (choice == 5)
    {
        n[4] = user;
    }
    else if (choice == 6)
    {
        n[5] = user;
    }
    else if (choice == 7)
    {
        n[6] = user;
    }
    else if (choice == 8)
    {
        n[7] = user;
    }
    else if (choice == 9)
    {
        n[8] = user;
    }
    // for winner and losser //
    // for X ;
    if(n[0] == 'X' && n[1] == 'X' && n[3] == 'X'){
        gameover = 1;
    }
    else if(n[3] == 'X' && n[4] == 'X' && n[5] == 'X'){
        gameover = 1;
    }
    else if(n[6] == 'X' && n[7] == 'X' && n[8] == 'X'){
        gameover = 1;
    }
    else if(n[0] == 'X' && n[3] == 'X' && n[6] == 'X'){
        gameover = 1;
    }
    else if(n[1] == 'X' && n[4] == 'X' && n[7] == 'X'){
        gameover = 1;
    }
    else if(n[2] == 'X' && n[5] == 'X' && n[8] == 'X'){
        gameover = 1;
    }
    else if(n[0] == 'X' && n[4] == 'X' && n[8] == 'X'){
        gameover = 1;
    }
    else if(n[2] == 'X' && n[4] == 'X' && n[6] == 'X'){
        gameover = 1;
    }
    //for O 
    if(n[0] == 'O' && n[1] == 'O' && n[3] == 'O'){
        gameover = 1;
    }
    else if(n[3] == 'O' && n[4] == 'O' && n[5] == 'O'){
        gameover = 1;
    }
    else if(n[6] == 'O' && n[7] == 'O' && n[8] == 'O'){
        gameover = 1;
    }
    else if(n[0] == 'O' && n[3] == 'O' && n[6] == 'O'){
        gameover = 1;
    }
    else if(n[1] == 'O' && n[4] == 'O' && n[7] == 'O'){
        gameover = 1;
    }
    else if(n[2] == 'O' && n[5] == 'O' && n[8] == 'O'){
        gameover = 1;
    }
    else if(n[0] == 'O' && n[4] == 'O' && n[8] == 'O'){
        gameover = 1;
    }
    else if(n[2] == 'O' && n[4] == 'O' && n[6] == 'O'){
        gameover = 1;
    }
    
}
int main(){
        char num[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        label:
            while(gameover != 1)
            {
                display(num);
                system("cls");
                logic(num);
            }
        printf("\n\n");
        printf("Player %c WINS\n",user);

        printf("*****************GAME OVER*****************\n");

        printf("Do you want to play again[y/n]\n");
        scanf(" %c",&again);

        if(again == 'y' || again == 'Y'){
            system("cls");
            num[0] = '1';
            num[1] = '2';
            num[2] = '3';
            num[3] = '4';
            num[4] = '5';
            num[5] = '6';
            num[6] = '7';
            num[7] = '8';
            num[8] = '9';
            gameover = 0;
            goto label;
        }
        else{
            return 0;
        }

        return 0;
    }