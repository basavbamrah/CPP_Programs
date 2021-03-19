/**
 * @file Eval_pstfix.cpp
 * @author Basav Bamrah
 * @brief evalute a postfix expression using stack data structure in cpp
 * @version 0.1
 * @date 2020-11-21
 * 
 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string pstfix;
double stack[100] = {};
int top = -1;
double sum = 0;
void push(double a)
{
    stack[++top] = a;
}
double pop()
{
    return stack[top--];
}

void input()
{
    cout << "Enter an expression in postfix form separate each element using comma " << endl;
    getline(cin, pstfix);
}

void eval()
{
    pstfix = pstfix + ",),";
    int a = 0;
    string w = "";
    int flag = 1;
    while (flag != 0)
    {
        char ch = pstfix[a];
        int p = pstfix.find(',', a);
        w = pstfix.substr(a, p - a);
        double t1, t2;
        a = p + 1;
        if (w.compare(")") == 0)
        {
            flag = 0;
        }
        else
        {
            switch (ch)
            {
            case '+':
                sum = pop() + pop();
                push(sum);
                break;
            case '-':
                t1 = pop();
                t2 = pop();
                sum = t2 - t1;
                push(sum);
                break;
            case '*':
                sum = pop() * pop();
                push(sum);
                break;
            case '/':
                t1 = pop();
                t2 = pop();
                sum = t2 / t1;
                push(sum);
                break;
            case '^':
                t1 = pop();
                t2 = pop();
                sum = pow(t2, t1);
                push(sum);
                break;

            default:
                double x = stod(w);
                push(x);
                break;
            }
        }
    }
}
int main()
{
    input();
    eval();
    cout << "Result: " << sum;
    cout << endl;
}