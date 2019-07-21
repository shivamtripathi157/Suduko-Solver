/*
*program to solve sudoku
*Author:Shivam Tripathi
*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int sudokuMatrix[9][9]={{0,0}};/*={{8,1,4,0,7,0,6,9,5},
                        {0,0,2,1,6,0,3,0,0},
                        {0,0,0,0,0,5,0,1,0},
                        {1,0,5,9,3,0,0,0,4},
                        {0,0,8,6,2,0,0,0,3},
                        {9,0,3,4,5,7,1,8,6},
                        {3,0,0,2,0,9,5,6,0},
                        {0,0,0,0,0,0,8,0,0},
                        {7,8,6,0,0,3,2,4,9},
                        }*/
void inputSudokuMatrix();
/*void displaySudoku();*/
void findSolution();
int foundInNonet(int p, int q, int n);
void solveNonet(int p, int q);
int countBlankCells();
void clearScreen();
void isSudokuValid();
void displaySudoku(int row,int col);
int main()
{
    char correct;

    beginning: //label
    clearScreen();
    inputSudokuMatrix();
    clearScreen();
    printf("Sudoku Puzzle is:\n\n");
    displaySudoku(-1,-1);
    printf("\n\aIs the Entered Sudoku Puzzle Correct(Y/N):");
    correct=getche();
    if(correct=='n'||correct=='N')
    {
        printf("\nEnter Sudoku Again!");
        getch();
        goto beginning;
    }
    getch();
    clearScreen();
    findSolution();
    printf("\aSolution is:\n\n");
    displaySudoku(-1,-1);
    return 0;
}
void inputSudokuMatrix()
{
    int row,col;
    char ch;
    printf("\n1:Enter number at the position of *");
    printf("\n2:Enter 0 for missing numbers");
    printf("\n\n\tPress Enter to begin\n\n");
    getch();
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            {
                displaySudoku(row,col);
                ch=getche();
                sudokuMatrix[row][col]=ch-'0';
               /* scanf("%d",&sudokuMatrix[row][col]);*/
            }

}
void clearScreen()
{
    system("cls");
    printf("\t\t\t\tSudoku Solver");
    printf("\n\n\n");

}
void findSolution()
{
    int p,q;
    do
    {
        for (p=0;p<9;p=p+3)
            for (q=0;q<9 ;q+=3)
                solveNonet(p,q);
    } while (countBlankCells());
}

int countBlankCells()
{
    int count,row,col;
    count=0;
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
            if(sudokuMatrix[row][col]==0)
                count++;
    return count;
}
void solveNonet(int p,int q)
{
    int missingNums[7],i,row,col,validPosMatrix[6][2],missingNumCount,validPosCount,l;
    missingNumCount=0;
    for(i=1;i<=9;i++)
        if(!foundInNonet(p,q,i))
            missingNums[missingNumCount++]=i;
    for(i=0;i<missingNumCount;i++)
    {
        validPosCount=0;
        for(row=p;row<3+p;row++)
            for (col=q;col<3+q ;col++ )
            {
                if(sudokuMatrix[row][col]==0)
                {
                    for(l=0;l<9;l++)
                        if (sudokuMatrix[row][l]==missingNums[i]||sudokuMatrix[l][col]==missingNums[i])
                            break;
                    if(l==9)
                    {
                        validPosMatrix[validPosCount][0]=row;
                        validPosMatrix[validPosCount++][1]=col;
                    }
                }
            }
        if(validPosCount==1)
            sudokuMatrix[validPosMatrix[0][0]][validPosMatrix[0][1]]=missingNums[i];
    }

}
int foundInNonet(int p,int q,int n)
{
    int row,col;
    for (row=p;row<3+p ;row++ )
        for (col=q;col<3+q ;col++ )
            if (sudokuMatrix[row][col]==n)
                return 1;
    return 0;
}


/*void displaySudoku()
{
    int row,col;
    for (row=0;row<9 ;row++ )
    {
        for (col=0;col<9 ;col++ )
        {
            if (col%3==0)
                printf("   ");
            printf(" %d ",sudokuMatrix[row][col]);
        }
        if(row%3==2)
            printf("\n");
        printf("\n");
    }
}*/
void displaySudoku(int row, int col)
{
    if(!(row==-1))
        clearScreen();
    int i,j;
    for (i=0;i<9 ;i++ )
    {
        for (j=0;j<9 ;j++ )
        {
            if (j%3==0)
                printf("   ");
            if(i==row&&col==j)
                printf(" * ");
            else if(sudokuMatrix[i][j]==0)
                printf(" . ");
            else
                printf(" %d ",sudokuMatrix[i][j]);
        }
        if(i%3==2)
            printf("\n");
        printf("\n");
    }

}
