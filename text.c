#include<stdlib.h>
#include<stdio.h>


int main (void) {
    char * long_str = "This is my awesome string! ";
    char * short_str = NULL;

    int long_str_len = 26;

    int x = 0, y=0;

    int char_width = 6;
    int line_len = 7;

    short_str = (char*)malloc((line_len+1)*sizeof(char));

    int str_pos = 0;
    int str_start_pos = str_pos;
    
    while(1) {
        str_start_pos = str_pos; 
        for(int i=0; i < line_len; i++) {
            short_str[i] = long_str[str_start_pos++%long_str_len];
        }
        
        printf("(%d, %d) \t",x,y);
        for(int i=0; i < line_len; i++) {
            printf("%c",short_str[i]);
        }
        printf("\n");

        x--;
        if (x*-1 > char_width) {
            x = 0;
            str_pos++;
            str_pos %= long_str_len+1;
        }
    }
}
