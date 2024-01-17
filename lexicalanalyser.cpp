#include<bits/stdc++.h>


using namespace std;


bool isdelimeter(char codechar)
{
    if(
        codechar== ' ' || codechar== '+' || codechar== '-' || codechar== '*' || 
		codechar== '/' || codechar== ',' || codechar== ';' || codechar== '>' || 
		codechar== '<' || codechar== '[' || codechar== ']' || codechar== '{' || 
        codechar== '}' || codechar== '=' || codechar== '.' || codechar== ':' ||
        codechar== '%'
    )
    return true;

    return false;
}

bool isoperator(char code){
    if (code == '+' || code == '-' || code == '*' || 
		code == '/' || code == '>' || code == '<' || 
		code == '=' || code == '!' ||
        code == '&' || code == '|'
    )
        return true;

    return false;
}

bool isvalididentifier(char* codechar){
    
    if (codechar[0] == '0' || codechar[0] == '1' || codechar[0] == '2' ||
		codechar[0] == '3' || codechar[0] == '4' || codechar[0] == '5' || 
		codechar[0] == '6' || codechar[0] == '7' || codechar[0] == '8' || 
		codechar[0] == '9' || isdelimeter(codechar[0]) == true
    )
		return false;
    return true;

}


bool iskeyword(char* codechar)
{
   if (!strcmp(codechar, "if") || !strcmp(codechar, "elseif") || !strcmp(codechar, "else") ||
		!strcmp(codechar, "while") || !strcmp(codechar, "for") || 
		!strcmp(codechar, "break") || !strcmp(codechar, "do") || 
		!strcmp(codechar, "continue") || !strcmp(codechar, "class") || !strcmp(codechar, "auto") ||
        !strcmp(codechar, "case") || !strcmp(codechar, "char") || !strcmp(codechar, "int") || !strcmp(codechar, "default")
        || !strcmp(codechar, "const") || !strcmp(codechar, "enum") || !strcmp(codechar, "float") || !strcmp(codechar, "int")
        || !strcmp(codechar, "string") || !strcmp(codechar, "long")|| !strcmp(codechar, "return") || !strcmp(codechar, "signed") || !strcmp(codechar, "unsigned")
        || !strcmp(codechar, "sizeof") || !strcmp(codechar, "static") || !strcmp(codechar, "typedef") || !strcmp(codechar, "void") 
		|| !strcmp(codechar, "struct") || !strcmp(codechar, "goto")
    )
		return true;
    
    return false;
}


bool isint(char* codechar)
{
	int i, len = strlen(codechar);

	if (len == 0)
		return false;
	for (i = 0; i < len; i++) {
		if (codechar[i] != '0' && codechar[i] != '1' && codechar[i] != '2'
			&& codechar[i] != '3' && codechar[i] != '4' && codechar[i] != '5'
			&& codechar[i] != '6' && codechar[i] != '7' && codechar[i] != '8'
			&& codechar[i] != '9' || (codechar[i] == '-' && i > 0)
        )
			return false;
	}
	return true;
}

char* subString(char* codechar, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = codechar[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}


 

int main()
{

	char code[] = "for ( int i = 0; i <= 5; i++)";

	int left = 0, right = 0;
	int len = strlen(code);

	while (right <= len && left <= right) {
		if (isdelimeter(code[right]) == false)
			right++;

		if (isdelimeter(code[right]) == true && left == right) {
			if (isoperator(code[right]) == true)
				cout<<"\n"<<code[right]<<": operator";

			right++;
			left = right;
		} else if (isdelimeter(code[right]) == true && left != right
				|| (right == len && left != right)) {
			char* subStr = subString(code, left, right - 1);

			if (iskeyword(subStr) == true)
                cout<<"\n"<<subStr<<": keyword";
			else if (isint(subStr) == true)
                cout<<"\n"<<subStr<<": integer";

			else if (isvalididentifier(subStr) == true
					&& isdelimeter(code[right - 1]) == false)
				cout<<"\n"<<subStr<<": valid identifier";

			else if (isvalididentifier(subStr) == false
					&& isdelimeter(code[right - 1]) == false)
				cout<<"\n"<<subStr<<": not a valid identifier";
			left = right;
		}
	}

    cout<<endl;

	return (0);
}








