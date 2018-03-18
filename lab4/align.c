/**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int i, j;
  
typedef struct costMatrix{
  int *cost;
  int rows;
  int cols;
} CostMatrix

int getCost(CostMatrix mat, int row, int col){
  return mat.cost[row*mat.cols+col];
}

void setCost(CostMatrix mat, int row, int col, int val){
  mat.cost[row*mat.cols+col] = val;
}
  
int minimum(int c0, int c1, int c2){
  if(c1<c0 && c1<c2){
    return c1;
  } else if(c2<c0 && c2<c1){
    return c2;
  } else {
    return c0;
  }
}

void printMatrix(int **matrix, int rows, int cols){
  printf("_|_0_|");
  for(j=0;j<cols-1;++j)
    printf("_%c_|",t[j]);
  printf("\n0");
  for(i=0;i<rows;++i){
    for(j=0;j<cols;++j){
      printf("|%3i",matrix[i][j]);
    }
    printf("|\n");
    printf("%c",s[i]);
  }
}

int getMatchCost(char s_i, char t_j){
  if(s_i==t_j) return 0;
  return 1;
}

int main(void){
  unsigned int rows=0, cols=0;
  int length1=0, length2=0, c_ij=0; //n: length of string1, m: length of string2
  //FILE* out;
  
  /* enter lengths of strings and the strings */
//printf("INPUTS:\n\tLength of string 1:\n\tString 1:\n\tLength of string 2:\n\tString 2:\n");
  scanf("%i",&length1);
  char *s = (char*)malloc(length1*sizeof(char));
  scanf("%s",s);
  scanf("%i",&length2);
  char *t = (char*)malloc(length2*sizeof(char));
  scanf("%s",t);
  
  /* initialize the cost matrix */
  rows=length1+1;
  cols=length2+1;
  int **cost=(int **)malloc(rows*sizeof(int *));
  for(i=0;i<rows;i++){
    cost[i]=(int *)malloc(cols*sizeof(int));
  }
  
  /* fill the cost matrix */
  for(i=0;i<rows;++i){
    cost[i][0]=i;
    for(j=1;j<cols;++j){
      if(i==0){ 
        cost[i][j]=j;
        continue;
      }
      cost[i][j]=minimum(cost[i-1][j-1]+getMatchCost(s[i],t[j]),cost[i-1][j]+1,cost[i][j-1]+1);
    }
  }
  
  /* print the cost matrix */
  printMatrix(cost, rows, cols);
  
  /* output results */
  //out=fopen("cost_matrix_out.txt","w");
  ////  each row of cost matrix on its own line
  ////  minimum cost output to screen and output file
  printf("min cost: %i\n",cost[rows-1][cols-1]);
  //fprintf(out,"min cost: %i\n",cost[rows-1][cols-1]);
  ////  optimal alignment(s) output to screen and output file
  //fclose(out);
  return 0;
}
