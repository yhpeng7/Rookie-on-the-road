/*螺旋矩阵*/
void spiralOrder(int matrix[][8],int n)
{
    static x = 0,y = 0,start = 1;

    if(n <= 0)
        return;
    if(n == 1)
    {
        matrix[x][y] = start;
        return;
    }
    int i,j;
    /*UP*/
    for(i = x;i < x + n - 1;i++)
        matrix[y][i] = start++;
    /*RIGHT*/
    for(j = y;j < y + n - 1;j++)
        matrix[j][x + n - 1] = start++;
    /*DOWN*/
    for(i = x + n - 1;i > x;i--)
        matrix[y + n - 1][i] = start++;
    /*LEFT*/
    for(j = y + n - 1;j > y;j--)
        matrix[j][x] = start++;

        x += 1;
        y += 1;

     spiralOrder(matrix,n - 2);
}