#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void delay(unsigned int);
int main()
{
    int x, y = 0, z = 1, s[3], t = 2, n, l;
    char a = ' ', b = ' ', c = ' ', d = ' ', e = ' ', f = ' ', g = ' ', h = ' ', i = ' ', j, k, name1[40], name2[40], ch;

pl:
    z = 1, y = 0;
    a = ' ', b = ' ', c = ' ', d = ' ', e = ' ', f = ' ', g = ' ', h = ' ', i = ' ';
    system("cls");
    printf("Tic-Tac-Toe_Apocalypse\n\nEnter first player's name: ");
    fflush(stdin);
    gets(name1);
    printf("Enter 2nd player's name: ");
    fflush(stdin);
    gets(name2);

jk:
    printf("\n\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n");


    printf("\n%s's symbol= *\n", name1);

    printf("%s's symbol= o\n\n\n", name2);
    printf("current board\n\n");

    printf(" %c | %c | %c \n", a, b, c);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", d, e, f);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", g, h, i);
    printf("\n");
    if (z == 1)
    {
        system("COLOR A");

        printf("%s's turn: ", name1);
    }
    else
    {
        system("COLOR D");


        printf("%s's turn: ", name2);
    }

    scanf("%d", &x);
    if (x == 1 && z == 1)
    {
        if (a == ' ')
        {
            z--;
            a = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 1 && z == 0)
    {
        if (a == ' ')
        {
            a = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 2 && z == 1)
    {
        if (b == ' ')
        {
            b = '*';
            z--;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 2 && z != 1)
    {
        if (b == ' ')
        {
            b = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 3 && z == 1)
    {
        if (c == ' ')
        {
            z--;
            c = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 3 && z != 1)
    {
        if (c == ' ')
        {
            c = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 4 && z == 1)
    {
        if (d == ' ')
        {
            z--;
            d = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 4 && z != 1)
    {
        if (d == ' ')
        {
            d = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 5 && z == 1)
    {
        if (e == ' ')
        {
            e = '*';
            z--;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 5 && z != 1)
    {
        if (e == ' ')
        {
            e = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    if (x == 6 && z == 1)
    {
        if (f == ' ')
        {
            z--;
            f = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 6 && z != 1)
    {
        if (f == ' ')
        {
            f = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 7 && z == 1)
    {
        if (g == ' ')
        {
            z--;
            g = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 7 && z != 1)
    {
        if (g == ' ')
        {
            g = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 8 && z == 1)
    {
        if (h == ' ')
        {
            z--;
            h = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 8 && z != 1)
    {
        if (h == ' ')
        {
            h = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    else if (x == 9 && z == 1)
    {
        if (i == ' ')
        {
            z--;
            i = '*';
        }
        else
        {
            system("cls");
            goto jk;
        }
    }

    else if (x == 9 && z != 1)
    {
        if (i == ' ')
        {
            i = 'o';
            z++;
        }
        else
        {
            system("cls");
            goto jk;
        }
    }
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", a, b, c);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", d, e, f);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", g, h, i);
    printf("+---+---+---+\n");
    y++;

    if (y >= 5 && a == b && b == c && c == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && d == e && e == f && f == '*')
    {
        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && g == h && h == i && i == '*')
    {
        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && a == e && e == i && i == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && c == e && e == g && g == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && a == d && d == g && g == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && b == e && e == h && h == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }
    else if (y >= 5 && c == f && f == i && i == '*')
    {

        printf("\n\n!!!%s has won!!!", name1);
        goto m;
    }



    if (y >= 5 && a == b && b == c && c == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && d == e && e == f && f == 'o')
    {
        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && g == h && h == i && i == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && a == e && e == i && i == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && c == e && e == g && g == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && a == d && d == g && g == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && b == e && e == h && h == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }
    else if (y >= 5 && c == f && f == i && i == 'o')
    {

        printf("\n\n!!!%s has won!!!", name2);
        goto m;
    }




    if (y != 9)
    {
        system("cls");
    }
    if (y < 9)
    {
        goto jk;
    }
    if (y == 9)
    {
        printf("!!!DRAW!!!");
        goto m;
    }
m:
    printf("\n\nPress any key to exit from the game\n");
    printf("Press Y to play the game again\n");
    scanf("%c", &ch);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
       goto pl;
    }
}
void delay(unsigned int m)
{
    clock_t goal = m + clock();
    while (goal > clock());
}
