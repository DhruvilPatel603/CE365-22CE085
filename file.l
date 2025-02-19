%{
    #include <stdio.h>
    int v = 0, c = 0;
%}

%%
[aeiouAEIOU]     {v++;}
[a-zA-z]    {c++;}
[ \t\n]     ;
.   ;
%%
int main()
{
    printf("Enter String");
    yylex();
    printf("Vowels : %d",v);
    return 0;
}
int yywrap()
{
    return 1;
}