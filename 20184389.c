#include <stdio.h>
#include <stdlib.h>
int** scan_mat(int** mat)
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}
void print_mat(int** mat)
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++) printf("%d ", mat[i][j]);
		puts("");
	}
}
int** index_add_mat(int** mat1, int** mat2, int** temp)
{
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++) temp[i][j] = mat1[i][j] + mat2[i][j];
	}
	return temp;
}
int** ptr_prod_mat(int** mat1, int** mat2, int** temp)
{
	int i, j, k, sum=0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++) sum += (*(*(mat1 + i)+k)) * (*(*(mat2 + k)+j));
			*(*(temp+i)+j) = sum;
			sum = 0;
		}
	}
	return temp;
}
int main(void)
{
	int i;
	int** mat1 = (int**)malloc(sizeof(int *)*3);
	for(i=0; i<3; i++) mat1[i] = malloc(sizeof(int) * 3);
	int** mat2 = (int**)malloc(sizeof(int *)*3);
	for(i=0; i<3; i++) mat2[i] = malloc(sizeof(int) * 3);
	int** temp = (int**)malloc(sizeof(int *)*3);
	for(i=0; i<3; i++) temp[i] = malloc(sizeof(int) * 3);
	printf("Enter the Number for Matrix 1: ");
	scan_mat(mat1);
	print_mat(mat1);
	printf("Enter the Number for Matrix 2: ");
	scan_mat(mat2);
	print_mat(mat2);
	printf("Added Mat is :\n");
	print_mat(index_add_mat(mat1, mat2, temp));
	printf("Producted Mat is :\n");
	print_mat(ptr_prod_mat(mat1, mat2, temp));
	return 0;
}
