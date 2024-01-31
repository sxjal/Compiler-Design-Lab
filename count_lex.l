%{
#include <stdio.h>

int lineCount = 0;
int wordCount = 0;
int capitalCount = 0;
int smallCount = 0;
int numberCount = 0;
int digitCount = 0;
int specialCharCount = 0;
int delimiterCount = 0;
int operatorCount = 0;
int relationalOpCount = 0;
int charCount = 0;
%}

DIGIT [0-9]
CAPITALLETTER [A-Z]
SMALLLETTER [a-z]

%%

\n { lineCount++; }
[a-zA-Z]+ { wordCount++; }
{CAPITALLETTER} { capitalCount++; }
{SMALLLETTER} { smallCount++; }
{DIGIT}+ { numberCount++; digitCount += yyleng; }
[.,;:!?] { delimiterCount++; }
[+\-*/%] { operatorCount++; }
[<>]=?|== { relationalOpCount++; }
. { charCount++; }

%%

int main() {
    yylex();
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Capital Letters: %d\n", capitalCount);
    printf("Small Letters: %d\n", smallCount);
    printf("Numbers: %d\n", numberCount);
    printf("Digits: %d\n", digitCount);
    printf("Special Characters: %d\n", specialCharCount);
    printf("Delimiters: %d\n", delimiterCount);
    printf("Operators: %d\n", operatorCount);
    printf("Relational Operators: %d\n", relationalOpCount);
    printf("Total Characters: %d\n", charCount);
    return 0;
}

