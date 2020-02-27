#include<stdio.h>

int main()
{
  int a[]={0,3,8,5,7,6,1,9,4};


  int i = 0,j=0;
  printf("排序后：");
  for(i = 0; i < 9;i++){
    printf("%d ",a[i]);
  }
  printf("\n");

  for( i = 0;i<9;i++){
    for( j = i;j<9;j++){
      if(a[i]>a[j]){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    
    }
  }

  printf("排序后：");
  for( i = 0; i < 9;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}
