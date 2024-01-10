#include <stdio.h>

int main(){
    char str[]="....o..\n..o..o.\no..o...";
    char matriz[3][7];
    int i=0,count=0,max=0,k=0,j=0;
    while(i<3){
        j=0;
        while(j<7){
            if(str[k]=='\n') k++;
            matriz[i][j]=str[k];
            k++;j++;
        }
        i++;
    }
    while(str[i]!='\0'){
        if(str[i]=='o' || str[i]=='\n'){
            if(count > max)
                max = count;
            count=0;
            i++;
            continue;
        }
        count++;
        i++;
    }
    
   for(i=0;i<3;i++){
        for(j=0;j<7;j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
   }
    //printf("%d\n",max);
    return 0;
}