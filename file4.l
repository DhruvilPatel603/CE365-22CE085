%{
    #include<stdio.h>
    int v=0,c=0;
%}
%%
[aeiouAEIOU]     {v++;}
[a-zA-Z]    {c++;}
[ \t\n]     ;
.   ;
%%
int main()
{
    printf("Enter String ");
    yylex();
    printf("Vowels : %d\n",v);
    printf("consonents: %d\n",c);
    return 0;
}
int yywrap()
{
    return 1;
}