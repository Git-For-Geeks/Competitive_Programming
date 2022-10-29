#include<stdio.h>
int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,x,y,c,d;
        scanf("%d %d %d %d",&a,&b,&x,&y);
        c =a/x;
        d = b/y;
        if(c<d){
            printf("Chef\n");
        }
        else if(c>d){
            printf("Chefina\n");
        }
        else{
            printf("Both");
        }
    }
}