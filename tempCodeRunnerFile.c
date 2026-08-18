#include<stdio.h>
int main(){
    int n,m[5][5],num=1;
    printf("Enter the size of the matrix (max 5): ");
    scanf("%d",&n);
    int rowstart=0,rowend=n-1,colstart=0,colend=n-1,i,j;
    while(rowstart<=rowend && colstart<=colend){
        int i,j;
    for(i=rowstart;i<=colend;i++){
      m[rowstart][i]=num++;
    }
    rowstart++;
    for(i=rowstart;i<=rowend;i++){
      m[i][colend]=num++;
    }
    colend--;
    for(i=colend;i>=colstart;i--){
        m[rowend][i]=num++;
        }
    rowend--;
    for(i=rowend;i>=rowstart;i--){
        m[i][colstart]=num++;
        }
    colstart++;
    }
    printf("Spiral Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }


}