#include <iostream>
#include <string>
using namespace std;

//Global Variables and Data Structures
int index = 0;
char expression[10000];

int evaluate()
{
    int ans = 0;
    int b = 0;
    char operation = '+';

    while(expression[index] != ')') {
            
        //Handle Parantheses
        if(expression[index] == '(')
        {
            index++;
            b = evaluate();
                
            //Handle Operations: + - *
            if(operation == '+') {
                ans = ans + b;
            }
            if(operation == '-') {
                ans = ans - b;
            }
            if(operation == '*') {
                ans = ans * b;
            }
        }
            
        //Handle Single-Digit Integers (0-9)
        else if(expression[index] >= 48 && expression[index] <= 57) 
        {
                
            //Convert Character to Integer
            b = expression[index]-48;
                
            //Handle Operations: + - *
            if(operation == '+') {
                ans = ans + b;
            }
            if(operation == '-') {
                ans = ans - b;
            }
            if(operation == '*') {
                ans = ans * b;
            }
            index++;
        }
        else 
        {
            operation = expression[index];
            index++;
        }
    }
    
    return ans;
}

int main()
{
    int ans = 0;
    int b = 0;
    char operation = '+';

    cin >> expression;

    while(expression[index] != '\0') {
            
        //Handle Parantheses
        if(expression[index] == '(')
        {
            index++;    
            b = evaluate();
                
            //Handle Operations: + - *
            if(operation == '+') {
                    ans = ans + b;
            }
            if(operation == '-') {
                ans = ans - b;
            }
            if(operation == '*') {
                ans = ans * b;
            }
        }
            
        //Handle Single-Digit Integers (0-9)
        else if(expression[index] >= 48 && expression[index] <= 57) 
        {
                
            //Convert Character to Integer
            b = expression[index]-48;
                
            //Handle Operations: + - *
            if(operation == '+') {
                ans = ans + b;
            }
            if(operation == '-') {
                ans = ans - b;
            }
            if(operation == '*') {
                ans = ans * b;
            }
            index++;
        }
        else 
        {
            operation = expression[index];
            index++;
        }
            
    }

    cout << ans;

    return 0;
}