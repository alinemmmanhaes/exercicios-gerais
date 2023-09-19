#include "matrix_utils.h"
#include <stdio.h>

tMatrix MatrixCreate(int rows, int cols){
    tMatrix matriz;
    matriz.rows = rows;
    matriz.cols = cols;
    return matriz;
}

tMatrix MatrixRead(tMatrix matrix){
    int i, j;
    for(i=0; i<matrix.rows; i++){
        for(j=0; j<matrix.cols; j++){
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

void MatrixPrint(tMatrix matrix){
    int i, j;
    for(i=0; i<matrix.rows; i++){
        for(j=0; j<matrix.cols; j++){
            if(j==0){
                printf("|");
            }
            printf("%d", matrix.data[i][j]);
            if(j==matrix.cols-1){
                printf("|");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }
    return 0;
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }
    return 0;
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }
    return 0;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    int i, j;
    result = MatrixCreate(matrix1.rows, matrix1.cols);
    for(i=0; i<matrix1.rows; i++){
        for(j=0; j<matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    int i, j;
    result = MatrixCreate(matrix1.rows, matrix1.cols);
    for(i=0; i<matrix1.rows; i++){
        for(j=0; j<matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    int i, j, k;
    tMatrix result;
    result = MatrixCreate(matrix1.rows, matrix2.cols);
    for(i=0; i<matrix1.rows; i++){
        for(j=0; j<matrix2.cols; j++){
            result.data[i][j] = 0;
        }
    }
    for(i=0; i<matrix1.rows; i++){
            for(j=0; j<matrix2.cols; j++){
                for(k=0; k<matrix2.rows; k++){
                    result.data[i][j] += (matrix1.data[i][k]*matrix2.data[k][j]);
                }
            }
    }
    return result;
}

tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result;
    int i, j;
    result = MatrixCreate(matrix.rows, matrix.cols);
    for(i=0; i<matrix.rows; i++){
        for(j=0; j<matrix.cols; j++){
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    int i, j;
    for(i=0; i<matrix.rows; i++){
        for(j=0; j<matrix.cols; j++){
            matrix.data[i][j] = scalar*matrix.data[i][j];
        }
    }
    return matrix;
}