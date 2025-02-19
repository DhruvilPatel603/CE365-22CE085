%option noyywrap
%{
    #include<stdio.h>
    int v=0, c=0;
%}

%%
[aeiouAEIOU]    {v++;}
[a-zA-Z]    {c++;}
[ \t\n]     ;
.   ;
%%
int main(){
    printf("Enter String: ");
    yylex();
    printf("no of vowels : %d\n",v);
    printf("no of consonants : %d",c);
    return 0;
}