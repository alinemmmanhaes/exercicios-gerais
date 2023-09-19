#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int i, j, k, rows1, cols1, rows2, cols2, op=0;
    tMatrix matrix1, matrix2;
    
    scanf("%d %d", &rows1, &cols1);
    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &rows2, &cols2);
    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);

    while(op!=6){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &op);
        if(op==6){
            break;
        }
        if(op==1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                tMatrix res1;
                res1 = MatrixAdd(matrix1, matrix2);
                MatrixPrint(res1);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if(op==2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                tMatrix res2;
                res2 = MatrixSub(matrix1, matrix2);
                MatrixPrint(res2);
            }
            else{
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
        else if(op==3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                tMatrix res3;
                res3 = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(res3);
            }
            else{
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
        else if(op==4){
            int escalar, m;
            scanf("%d", &escalar);
            scanf("%d", &m);
            if(m==1){
                matrix1 = MatrixMultiplyByScalar(matrix1, escalar);
                MatrixPrint(matrix1);
            }
            else if(m==2){
                matrix2 = MatrixMultiplyByScalar(matrix2, escalar);
                MatrixPrint(matrix2);
            }
        }
        else if(op==5){
            tMatrix res51, res52;
            res51 = TransposeMatrix(matrix1);
            MatrixPrint(res51);
            res52 = TransposeMatrix(matrix2);
            MatrixPrint(res52);
        }
    }
    return 0;
}