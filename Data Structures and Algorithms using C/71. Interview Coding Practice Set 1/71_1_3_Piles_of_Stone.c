#include<stdio.h>

int main(){
    int a,b,c,x,y;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if((a+b+c==x+y)&&(a<=x+y)&&(b<=x+y)&&(c<=x+y)&&(a+b>=x)&&(b+c>=y)){
        printf("YES");
    } else{
        printf("NO");
    }
    return 0;
}