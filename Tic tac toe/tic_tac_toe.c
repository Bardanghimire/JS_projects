

#include <stdio.h>
#include <stdlib.h>
int choice;
int any = 1;
char user;
int gameover = 1;
char again;

int display(char n[])
{
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("___%c___|___%c___|___%c___\n", n[6], n[7], n[8]);
    printf("___%c___|___%c___|___%c___\n", n[3], n[4], n[5]);
    printf("___%c___|___%c___|___%c___\n", n[0], n[1], n[2]);
    scanf("%d", &choice);
}
int logic(char n[])
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

    //******checking for winnner ******//
}
void check(char n[])
{
    //checking for X player
    if (n[0] == 'X' && n[1] == 'X' && n[2] == 'X')
    {
        gameover = 0;
    }
    else if (n[3] == 'X' && n[4] == 'X' && n[5] == 'X')
    {
        gameover = 0;
    }
    else if (n[6] == 'X' && n[7] == 'X' && n[8] == 'X')
    {
        gameover = 0;
    }


    else if (n[0] == 'X' && n[3] == 'X' && n[6] == 'X')
    {
        gameover = 0;
    }
    else if (n[1] == 'X' && n[4] == 'X' && n[7] == 'X')
    {
        gameover = 0;
    }
    else if (n[2] == 'X' && n[5] == 'X' && n[8] == 'X')
    {
        gameover = 0;
    }

    else if (n[0] == 'X' && n[4] == 'X' && n[8] == 'X')
    {
        gameover = 0;
    }
    else if (n[2] == 'X' && n[4] == 'X' && n[6] == 'X')
    {
        gameover = 0;
    }
    //************checking for O player*************//
    if (n[0] == 'O' && n[1] == 'O' && n[2] == 'O')
    {
        gameover = 0;
    }
    else if (n[3] == 'O' && n[4] == 'O' && n[5] == 'O')
    {
        gameover = 0;
    }
    else if (n[6] == 'O' && n[7] == 'O' && n[8] == 'O')
    {
        gameover = 0;
    }

    else if (n[0] == 'O' && n[3] == 'O' && n[6] == 'O')
    {
        gameover = 0;
    }
    else if (n[1] == 'O' && n[4] == 'O' && n[7] == 'O')
    {
        gameover = 0;
    }
    else if (n[2] == 'O' && n[5] == 'O' && n[8] == 'O')
    {
        gameover = 0;
    }

    else if (n[0] == 'O' && n[4] == 'O' && n[8] == 'O')
    {
        gameover = 0;
    }
    else if (n[2] == 'O' && n[4] == 'O' && n[6] == 'O')
    {
        gameover = 0;
    }
}

int main()
{
    //between two player//
    system("cls"); // it clear the previous screen like clrscr();
    char number[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
label:
    while (gameover != 0)
    {
        display(number);
        system("cls");
        logic(number);
        check(number);
    }
    printf("\n\n");
    printf("\t\t\tPlayer %c WINS\n", user);
    printf("**********************GAMEOVER********************\n");
    printf("Do you like to play again[y/n]\n");
    scanf(" %c", &again);
    if (again == 'y' || again == 'Y')
    {
        system("cls");
        any = 1;
        number[0] = '1', number[1] = '2', number[2] = '3', number[3] = '4', number[4] = '5', number[5] = '6', number[6] = '7', number[7] = '8', number[8] = '9';
        gameover = 1;
        goto label;
    }
    else
    {
        printf("THANKS FOR PLAYING\n");
        return 0;
    }

    return 0;
}