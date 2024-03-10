#include<stdio.h>
#include<string.h>

int romanToDecimal(char *roman){
    int result=0;
    int length=strlen(roman);

    for(int i=0;i<length;i++){
        switch(roman[i]){
            case 'I' : if(i<length-1 && (roman[i+1]=='V'||roman[i+1]=='X')){
                        result-=1;
                    } else {
                        result+=1;
                    }
                    break;
            case 'V' : result+=5;
                    break;
            case 'X' : if(i<length-1 && (roman[i+1]=='L'||roman[i+1]=='C')){
                        result-=10;
                    } else {
                        result+=10;
                    }
                    break;
            case 'L':result+=50;
                    break;
            case 'C':if(i<length-1 && (roman[i+1]=='D'||roman[i+1]=='M')){
                        result-=100;
                    } else {
                        result+=100;
                    } break;
            case 'D':result+=500;
                    break;
            case 'M':result+=1000;
                    break;
            default : return -1;
        }  
    }   return result;
}

int main(){
    char romanNumeral[20];
    scanf("%s", romanNumeral);

    int result=romanToDecimal(romanNumeral);

    if(result!=-1){
        printf("%d\n",result);
    }
    return 0;
}