#include <stdio.h>

int main(){
    int f1[5000];
    int f2[5000];
    f1[0] = 0, f1[1] = -1, f2[0] = 1, f2[1] = -1;
    int n, size = 0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    if(n == 0){
        printf("0\n");
    }
    else if(n == 1){
        printf("1\n");
    }
    else{
        for(int i=2;i<=n;i++){
            int t1 = 0, num1 = 0, num2 = 0;
            size = 0;
            while (f1[t1] != -1 && f2[t1] != -1){
                num2 = f1[t1]+f2[t1]+num2;
                num1 = num2 % 10;
                num2 = num2/10;
                f1[t1] = f2[t1];
                f2[t1] = num1;
                t1++;
                size++;
            }
            while (f2[t1] != -1){
                num2 = f2[t1]+num2;
                num1 = num2%10;
                num2 = num2/10;
                f1[t1] = f2[t1];
                f2[t1] = num1;
                t1++;
                size++;
            }
            f1[t1] = -1;
            if(num2 == 0){
                f2[t1] = -1;
            }
            else{
                f2[t1] = num2;
                f2[t1+1] = -1;
                size++;
            }
        }
        for(int i = size-1;i>=0;i--){
            printf("%d", f2[i]);
        }
        printf("\n");

    }
    return 0;
}