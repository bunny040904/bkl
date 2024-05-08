#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int getWeight(char ch)
{
    switch (ch)
    {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void infix2postfix(char infix[], char postfix[], int size)
{
    stack<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;
    // iterate over the infix expression
    while (i < size)
    {
        ch = infix[i];
        if (ch == '(')
        {
            // simply push the opening parenthesis
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix[k++] = s.top();
                s.pop();
            }
            // pop off the opening parenthesis also
            if (!s.empty())
            {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if (weight == 0)
        {
            // we saw an operand
            // simply append it to postfix expression
            postfix[k++] = ch;
        }
        else
        {
            // we saw an operator
            if (s.empty())
            {
                // simply push the operator onto stack if
                // stack is empty
                s.push(ch);
            }
            else
            {
                while (!s.empty() && s.top() != '(' && weight <= getWeight(s.top()))
                {
                    postfix[k++] = s.top();
                    s.pop();
                }
                // push the current operator onto stack
                s.push(ch);
            }
        }
        i++;
    }
    while (!s.empty())
    {
        postfix[k++] = s.top();
        s.pop();
    }
    postfix[k] = 0; // null terminate the postfix expression
}
// main
int main()
{
    cout << "\n\nName : Dangat Amol Subhash" << endl;
    cout << "Roll No : 09 " << endl;
    char infix[20];
    cout << "Enter Infix Expression:";
    cin >> infix;
    int size = strlen(infix);
    char postfix[size];
    infix2postfix(infix, postfix, size);
    cout << "\nInfixExpression :: " << infix;
    cout << "\nPostfixExpression :: " << postfix;
    cout << endl;
    return 0;
}