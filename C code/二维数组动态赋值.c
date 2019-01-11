int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    matrix = (int **)malloc(matrixRowSize * sizeof(int *));
    int i;
    for(i = 0;i < matrixRowSize;i++)
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
}