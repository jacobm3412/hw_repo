//*****************************************************************************
//
// This program calculates the product of a square matrix with itself:
//
// B = A * A
//
// Please keep all code in this single file.
//
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>
void file_to_array(char* file,  int* arr, int mat_len)
{
FILE *fp_in;
fp_in = fopen(file,"r");

if( fp_in == NULL) {
  printf("invalid file name - file not found, exiting.... \n");
  exit(0);
}
int i;
int j;
printf("matrix size: %d\n", mat_len);
for (i =0;i<mat_len;i++){
   for(j = 0; j<mat_len; j++){
   fscanf(fp_in,"%d",&arr[i*mat_len + j]);
   }
}

fclose(fp_in);
}

void matrix_multiplication(int * arrA, int * arrB, int  mat_length)
{
int x;
int y;
int z;
for(x = 0; x< mat_length; x++){
  for(y=0; y< mat_length; y++) {
    for(z = 0; z< mat_length; z++){
      arrB[x*mat_length + z] = arrB[x*mat_length + z] + arrA[x*mat_length + y]*arrA[y*mat_length + z];
}
}
}
}

void matrix_readout(int * arrC,int matrix_length )
{
int e;
for(e = 0; e <matrix_length*matrix_length;e++){
if((e+1)%3 == 0){
printf("%d\n",arrC[e]);
} 
else{
printf("%d ",arrC[e]);
}
}
}
int main(int argc, char ** argv)
{
   
   // check command line arguments
   if ( argc != 3 ) {
      printf("This program computes the product of n x n matrix with itself\n");
      printf("Usage: ./matrix_multiply filename n\n");
      exit(0);
   }

   // TODO: parse input arguments
   int size = sizeof(argv);
   int matrix_size = atoi(argv[2]);
   // TODO: dynamically allocate space for matrix_A (input matrix) in 1d array
   int * matrix_A =malloc(matrix_size * matrix_size * sizeof(int));  // declare input matrix

   // TODO: call function to read data from file and copy into matrix_A
   file_to_array(argv[1],matrix_A,matrix_size);
   // TODO: dynamically allocate space for matrix_B (output matrix) in 1d array
   int * matrix_B =malloc(matrix_size * matrix_size * sizeof(int));  // declare output matrix

   // TODO: call function to perform matrix multiplication ( matrix_B = matrix_A * matrix_A )
   matrix_multiplication(matrix_A, matrix_B, matrix_size);
   // TODO: call function to write results (matrix_B) to stdout
   matrix_readout(matrix_B,matrix_size);
   // TODO: free space allocated for matrix_A and matrix_B
   free(matrix_A);
   free(matrix_B);
   return 0;

}
