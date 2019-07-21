int sudokuMatrix[9][9]={{8,1,4,0,7,0,6,9,5},
                        {0,0,2,1,6,0,3,0,0},
                        {0,0,0,0,0,5,0,1,0},
                        {1,0,5,9,3,0,0,0,4},
                        {0,0,8,6,2,0,0,0,3},
                        {9,0,3,4,5,7,1,8,6},
                        {3,0,0,2,0,9,5,6,0},
                        {0,0,0,0,0,0,8,0,0},
                        {7,8,6,0,0,3,2,4,9},
                        };
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
