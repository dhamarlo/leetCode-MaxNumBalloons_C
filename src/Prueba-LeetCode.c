#include <stdio.h>
#include <string.h>

int maxNumberOfBalloons(char * text){
   
    char bchar [5] = {'b','a','l','o','n'};
    int bchar_min [5] = {1,1,2,2,1};
    int bchar_count [5] = {0,0,0,0,0};
    
    int i_text;
    int n_text;
    int i_bchar;
    int n_bchar=5;
    
    int i_count;
    int bempty = 0;
    int balloons = 0;
    
    n_text = strlen(text);
    
    for(i_text=0; i_text<n_text; i_text++){
        for(i_bchar=0;i_bchar<n_bchar; i_bchar++){
            if (text[i_text]==bchar[i_bchar]){
                bchar_count[i_bchar]++;
            }
        }        
    }
    
    while (bempty==0){
        for(i_bchar=0;i_bchar<n_bchar; i_bchar++){
            if (bchar_count[i_bchar]<bchar_min[i_bchar]){
                bempty=1;
            }
            bchar_count[i_bchar]=bchar_count[i_bchar]-bchar_min[i_bchar];
        }
        if (bempty==0){
            balloons++;
        }
    }

    return balloons;     

}


int main() {
    
    char text[10000];
    printf("Let's count ballons\n + Enter text:");
    scanf("%s", text);
    printf("The text introduced is: %s, \n\n");

    int result = maxNumberOfBalloons (text);
    int exit;

    printf("Number of balloons = %d\n\n", result);
    system ("pause");

    return 0;
}