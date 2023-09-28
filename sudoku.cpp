#include <stdio.h>
int su[11][11], tm=0;
void sudoku(int y, int x)
{
    if(y == 9)
    {
        tm = 1;
        return;
    }
    if(su[y][x])
    {
        sudoku(y+x/8, (x+1)%9);
        return;
    }
    int t, i, j;
    for(t=1; t<=9; t++)
    {
        int p=0;
        for(i=y/3*3; i<=y/3*3+2; i++)
        {
            for(j=x/3*3; j<=x/3*3+2; j++)
            {
                if(su[i][j] == t)
                {
                    p=1;
                    break;
                }
            }
            if(p == 1) break;
        }
        if(p == 1) continue;
        for(i=0; i<9; i++)
        {
            if(su[i][x] == t)
            {
                p = 2;
                break;
            }
        }
        if(p == 2) continue;
        for(j=0; j<9; j++)
        {
            if(su[y][j] == t)
            {
                p = 3;
                break;
            }
        }
        if(p == 3) continue;
        su[y][x] = t;
        sudoku(y+x/8, (x+1)%9);
        if(tm == 1) return;
        su[y][x] = 0;
    }
    return;
}
int main()
{
    int i, j;
    printf("Fill in the blank with 0\n");
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            scanf("%d", &su[i][j]);
        }
    }
    sudoku(0, 0);
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            printf("%d ", su[i][j]);
        }
        printf("\n");
    }
}
