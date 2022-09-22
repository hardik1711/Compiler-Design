#include<stdio.h>
#include<ctype.h>
#include<string.h>


void followfirst(char, int, int);
void follow(char c);


void findfirst(char, int, int);

int count, n = 0;


char calc_first[10][100];


char calc_follow[10][100];
int m = 0;


char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main(int argc, char **argv)
{
    int jm = 0;
    int km = 0;
    int i, choice;
    char c, ch;
    count = 8;
    
    
    strcpy(production[0], "S=AB");
    strcpy(production[1], "B=+AB");
    strcpy(production[2], "B=#");
    strcpy(production[3], "A=CD");
    strcpy(production[4], "D=*CD");
    strcpy(production[5], "D=#");
    strcpy(production[6], "C=(S)");
    strcpy(production[7], "C=a");
    
    int kay;
    char done[count];
    int ptr = -1;
    
    
    for(k = 0; k < count; k++) {
        for(kay = 0; kay < 100; kay++) {
            calc_first[k][kay] = '!';
        }
    }
    int point1 = 0, point2, xxx;
    
    for(k = 0; k < count; k++)
    {
        c = production[k][0];
        point2 = 0;
        xxx = 0;
        
        
        for(kay = 0; kay <= ptr; kay++)
            if(c == done[kay])
                xxx = 1;
                
        if (xxx == 1)
            continue;
        
        
        findfirst(c, 0, 0);
        ptr += 1;
        
        
        done[ptr] = c;
        printf("\n First(%c) = { ", c);
        calc_first[point1][point2++] = c;
        
        
        for(i = 0 + jm; i < n; i++) {
            int lark = 0, chk = 0;
            
            for(lark = 0; lark < point2; lark++) {
                
                if (first[i] == calc_first[point1][lark])
                {
                    chk = 1;
                    break;
                }
            }
            if(chk == 0)
            {
                printf("%c, ", first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        jm = n;
       point1++;
      
       }
}