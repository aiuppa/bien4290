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
  
int getMatchCost(char s_i, char t_j){
  if(s_i==t_j) return 0;
  return 1;
}

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

void printMatrix(CostMatrix mat){
  unsigned int row, col;
  for(row=0;row<mat.rows;++row){
    for(col=0;col<mat.cols;++col){
      printf("%i",getCost(mat,row,col);
    }
    printf("\n");
  }
}

void trace(CostMatrix mat, int row, int col, char *s, char *t, char *align1, char *align2, int i, int j){
  char a1[200], a2[200];
  int cost, left, diag, up, matchCost;
  
  strcpy(a1, align1);
  strcpy(a2, align2);
  
  if (row==1 && col==1){
    print("%s\n%s\n\n", a1, a2);
    return;
  }
  
  cost = get_cost(mat,row,col);
  matchCost = getMatchCost(s[col-1],t[row-1]);
  
  if(get_cost(mat,row,col-1)+1 == cost) { //left origin
    a1[i--] = '_';
    a2[j--] = t[row-1];
    trace(mat,row,col-1,s,t,a1,a2,i,j);
  } else if(get_cost(mat,row-1,col-1)+matchCost == cost) {  //diagonal origin
    a1[i--] = s[col-1];
    a2[j--] = t[row-1];
    trace(mat,row-1,col-1,s,t,a1,a2,i,j);
  } else if(get_cost(mat,row-1,col)+1 == cost) {   //above origin
    a1[i--] = s[col-1];
    a2[j--] = t[row-1];
    trace(mat,row-1,col,s,t,a1,a2,i,j);
  }
}

int main(int argc, char **argv){
  unsigned int row=0, col=0;
  int length1=0, length2=0, alignLength=0, c_ij=0;
  CostMatrix mat;
  //FILE* out;
  
  if(argc!=5){
    printf("%s", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  length1=atoi(argv[1]);
  length2=atoi(argv[3]);
  if(length1 > length2) alignLength=length1;
  else alignLength=length2;
  
  char *align1 = (char*)malloc(sizeof(char)*alignLength);
  char *align2 = (char*)malloc(sizeof(char)*alignLength);
  char *s = (char*)malloc(sizeof(char)*length1);
  char *t = (char*)malloc(sizeof(char)*length2);
  
  strcpy(s,argv[2]);
  strcpy(t,argv[4]);
  
  /* initialize the cost matrix */
  mat.cost=(unsigned int*)malloc(sizeof(unsigned int)*(length1+1)*(length2+1));
  mat.rows=length1+1;
  mat.cols=length2+1;
  /* fill the cost matrix */
  for(i=0;i<mat.rows;++i){
    setCost(mat,i,0,i);
    for(j=1;j<mat.cols;++j){
      if(i==0){ 
        setCost(mat,i,j,j);
        continue;
      }
      setCost(mat,i,j,minimum(getCost(mat,i-1,j-1)+getMatchCost(s[i],t[j]),getCost(mat,i-1,j)+1,getCost(mat,i,j-1)+1));
    }
  }
  
  /* print the cost matrix */
  printMatrix(mat);
  trace(mat,length1,length2,s,t,align1,align2,alignLength-1,alignLength-1);
  
  /* output results */
  //out=fopen("cost_matrix_out.txt","w");
  ////  each row of cost matrix on its own line
  ////  minimum cost output to screen and output file
  printf("min cost: %i\n",cost[rows-1][cols-1]);
  //fprintf(out,"min cost: %i\n",cost[rows-1][cols-1]);
  ////  optimal alignment(s) output to screen and output file
  //fclose(out);
  free(s);
  free(t);
  free(align1);
  free(align2);
  return 0;
}
