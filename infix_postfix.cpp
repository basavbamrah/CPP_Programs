/**
 * @file infix_postfix.cpp
 * @author Basav Bamrah
 * @brief convert an infix expression to postfix using stack data  structure in cpp
 * @version 0.1
 * @date 2020-11-20
 *      
 * 
 */
#include <iostream>
#include <string>
using namespace std;

string infix, pstfix;
char stack[100]; // stack used in converting the expression from infix to postfix
int top = -1;

void input() // function to input infix expression
{
    cout << "Enter an expression in inflix form:\n";
    getline(cin, infix);
}

void push(char ch) // Function to push into stack
{
    if (top > 99)
    {
        cout << "OVERFLOW!!!: REDUCE THE TERMS OF EXPRESSION" << endl;
        exit(0);
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop() // function to pop elements from the stack
{
    if (top < 0)
        return '#';
    else
    {
        return stack[top--];
    }
}

void infix2pstfix() // function to convert infix expression to postfix using stack
{
    push('('); // push ( into stack to marks an ending
    while (top != -1)
    {
        for (int i = 0; i < infix.length(); i++)
        {
            char ch = infix[i]; //traversing through the given expression
            if (ch >= 48 && ch <= 57 || ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
                pstfix = pstfix + ch; //  add to the postfix expression
            else if (ch == '(')
            {
                push(ch);
            }
            else if (ch == '^')
            {
                char p = stack[top];
                while (p == '^')
                {
                    pstfix = pstfix + pop();
                }
                push(ch);
            }

            else if (ch == '/' || ch == '*' || ch == '%' || ch == '^')
            {
                char p = stack[top];
                while (p == '/' || p == '*' || p == '%' || p == '^')
                {
                    pstfix = pstfix + pop();
                    p = stack[top];
                }
                push(ch);
            }
            else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '%' || ch == '^')
            {
                char p = stack[top];
                while (p == '+' || p == '-' || p == '/' || p == '*' || p == '%' || p == '^')
                {
                    pstfix = pstfix + pop();
                    p = stack[top];
                }
                push(ch);
            }

            else if (ch = ')')
            {

                char p = stack[top];

                while (p != '(')
                {
                    pstfix = pstfix + pop();
                    p = stack[top];
                }
                pop();
            }
        }
    }
}

int main()
{
    input();
    cout << infix;
    cout << endl;
    infix = infix + ')';
    infix2pstfix();
    cout << "POSTFIX EXPRESSION: \n";
    cout << pstfix;
    cout << endl;
    return 0;
}
