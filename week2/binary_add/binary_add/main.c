//
//  main.c
//  binary_add
//
//  Created by Tai Wei Tseng on 2020/06/16.
//  Copyright © 2020 man27382210. All rights reserved.
//

#include <stdio.h>
 
void binary_add(int A[], int B[], int n){
  int sum[n+1];
  int i;
  int carry = 0;
    for(i = n-1; i >= 0 ; i--){
        sum[i+1] = ((A[i] ^ B[i]) ^ carry);
        carry = ((A[i] & B[i]) | (A[i] & carry)) | (B[i] & carry);
    }
  sum[0] = carry;
  for(i = 0; i <= n; i++){
    printf("%d ", sum[i]);
  }
    printf("\n");
}
 
int main(){
//  int n;
//  scanf("%d", &n);
//  int i, j;
//  int A[n];
//  for(i = 0; i < n; i++){
//    scanf("%d", &A[i]);
//  }
//  int B[n];
//  for(j = 0; j < n; j++){
//    scanf("%d ", &B[j]);
//  }
    int n = 3;
    int A[3] = {1,1,0};
    int B[3] = {0,1,1};
  binary_add(A, B, n);
  return 0;
}
