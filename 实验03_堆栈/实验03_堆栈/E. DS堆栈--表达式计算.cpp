#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
using namespace std;

#define opsetsize 7
typedef int Status;

char opset[opsetsize] = { '+', '-', '*', '/', '(', ')','#' };
char Prior[7][7] = 
{
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>',
    '<','<','<','<','<','=',' ',
    '>','>','>','>',' ','>','>',
    '<','<','<','<','<',' ',' '
};

double Operate(double a, char theta, double b)
{
    if (theta == '+') 
    {
        return a + b;
    }
    else if (theta == '-') 
    {
        return a - b;
    }
    else if (theta == '*') 
    {
        return a * b;
    }
    else if (theta == '/') 
    {
        return a / b;
    }
    else
        return '0';
}

Status in(char Test, char* Testop) 
{
    for (int k = 0; k < opsetsize; k++) 
    {
        if (Test == Testop[k])
            return 1;
    }
    return 0;
}
char precede(char Aop, char Bop) 
{
    int a = 0;
    for (a = 0; a < opsetsize; a++)
        if (opset[a] == Aop)
            break;
    int b = 0;
    for (b = 0; b < opsetsize; b++)
        if (opset[b] == Bop)
            break;
    return Prior[a][b];
}

double Evaluate(string Myexp) 
{
    stack<char> Optr;
    stack<double> Opnd;
    char Tempdata[20];
    double data;
    char theta, dr[2];
    char ch;
    int i = 0;

    Optr.push('#');
    ch = Myexp[0];

    strcpy(Tempdata, "\0");
    while (ch != '#' || Optr.top() != '#') //到尾巴或者只剩下#
    {
        if (!in(ch, opset)) //不是符号
        {
            dr[0] = ch;
            dr[1] = '\0';
            strcat(Tempdata, dr);
            i++;
            ch = Myexp[i];
            if (in(ch, opset)) 
            {
                data = (double)atof(Tempdata);
                Opnd.push(data);
                strcpy(Tempdata, "\0");
            }
        }
        else 
        {
            switch (precede(Optr.top(), ch)) 
            {
            case '<':
                Optr.push(ch);
                i++;
                ch = Myexp[i];
                break;
            case '=':
                Optr.pop();
                i++;
                ch = Myexp[i];
                break;
            case '>':
                double b = Opnd.top();
                Opnd.pop();
                double a = Opnd.top();
                Opnd.pop();
                theta = Optr.top();
                Optr.pop();
                Opnd.push(Operate(a, theta, b));
                break;
            }
        }
    }
    return Opnd.top();
}
int main() 
{
    string exp;
    int t;
    double result;
    cin >> t;
    while (t--) 
    {
        cin >> exp;
        result = Evaluate(exp);
        cout << fixed << setprecision(4) << result << endl;
    }
    return 0;
}
