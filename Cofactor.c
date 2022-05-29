#include <stdio.h>
#include <string.h>

void menual_();
void input_matrix();
void det_m(int *matrix_data);
void cofact_m(int *matrix_data);
void inverse_m();

int matrix[3][3] = { {0,},{0,} };
int cofact_matrix[3][3]={{0,},{0,}};
float inverse_num;

void menual_()    // 시작점
{
    printf("Industry Math\n");
    printf("Inverse Matrix = 1/det A * Cofactor\n");

    input_matrix();
}

void input_matrix()    // 행렬을 1차원으로 입력 받은 후 2차원으로 변환
{
    int k=0;
    int matrix_data[9]={0,};
    
    printf("input matrix >>\n");
    for(int i=0;i<9;i++)    // 1차원으로 입력
    {
        scanf("%d",matrix_data);
    }
    
    /* for(int i=0;i<3;i++)    // 2차원으로 변환
    {
        for(int j=0;j<3;j++)
        {
            Matrix_2nd[i][j] = matrix_data[k];
            k++;
        }
    } */
    /*for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", Matrix_2nd[i][j]);
        }
        printf("\n");
    }*/

    det_m(matrix_data);
    cofact_m(matrix_data);

    inverse_m();
}

void inverse_m()
{
    float inverse_matrix[3][3]={{0,},{0,}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            inverse_matrix[i][j]=(float)cofact_matrix[i][j]*inverse_num;
            printf("%2.2f ",inverse_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    menual_();
    return 0;
}

void det_m(int *matrix_data)   // 입력받은 행렬의 행렬식
{
    int k=0;
    for(int i=0;i<3;i++)    // 2차원으로 변환
    {
        for(int j=0;j<3;j++)
        {
            matrix[i][j] = matrix_data[k];
            k++;
        }
    }
    int plus_n =0 , minus_n =0;

    plus_n=(matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+(matrix[0][2]*matrix[1][0]*matrix[2][1]);
    minus_n=(matrix[0][2]*matrix[1][1]*matrix[2][0])+(matrix[0][0]*matrix[1][2]*matrix[2][1])+(matrix[0][1]*matrix[1][0]*matrix[2][2]);
    inverse_num=((float)plus_n-minus_n)*0.1;
}   

void cofact_m(int *matrix_data)
{
    int cofact_Minor[3][3]={{0,},{0,}};
    int k=0;
    for(int i=0;i<3;i++)    // 2차원으로 변환
    {
        for(int j=0;j<3;j++)
        {
            cofact_Minor[i][j] = matrix_data[k];
            k++;
        }
    }

    cofact_matrix[0][0]=(cofact_Minor[1][1]*cofact_Minor[2][2])-(cofact_Minor[1][2]*cofact_Minor[2][1]);   //C11
    cofact_matrix[1][0]=(cofact_Minor[1][0]*cofact_Minor[2][2])-(cofact_Minor[1][2]*cofact_Minor[2][0])*-1;   //C12
    cofact_matrix[2][0]=(cofact_Minor[1][0]*cofact_Minor[2][1])-(cofact_Minor[1][1]*cofact_Minor[2][0]);    //C13

    cofact_matrix[0][1]=(cofact_Minor[0][1]*cofact_Minor[2][2])-(cofact_Minor[0][2]*cofact_Minor[2][1])*-1;    //C21
    cofact_matrix[1][1]=(cofact_Minor[0][0]*cofact_Minor[2][2])-(cofact_Minor[2][0]*cofact_Minor[0][2]);    //C22
    cofact_matrix[2][1]=(cofact_Minor[0][0]*cofact_Minor[2][1])-(cofact_Minor[0][1]*cofact_Minor[2][0])*-1;    //C23

    cofact_matrix[0][2]=(cofact_Minor[0][1]*cofact_Minor[1][2])-(cofact_Minor[1][1]*cofact_Minor[0][2]);    //C31
    cofact_matrix[1][2]=(cofact_Minor[0][0]*cofact_Minor[1][2])-(cofact_Minor[1][0]*cofact_Minor[0][2])*-1;    //C32
    cofact_matrix[2][2]=(cofact_Minor[0][0]*cofact_Minor[1][1])-(cofact_Minor[0][1]*cofact_Minor[1][0]);    //C33
}