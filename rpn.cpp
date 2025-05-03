#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string>
#include <utility>

inline float operation(float n, float m, char op)
{
    if (op == '+')
    {
        return n + m;
    }

    else if (op == 'x')
    {
       return n*m;
    }

    else if (op == '/')
    {
        return n/m;
    }
    
    else
    {
        return n-m;
    }

}


int main(int argc, char* argv[])
{
    std::stack<int> number_stack;
    std::stack<char> operator_stack;
    
    for (int i; i< argc; i++)
    {
        if (atoi(argv[i]) == 0)
        {
            operator_stack.push(*argv[i]);
        }
        
        else
        {
            number_stack.push(atoi(argv[i]));
        }
    }

    while (!number_stack.empty()) {
        std::cout << number_stack.top() << std::endl;
        number_stack.pop();  
    }

    
    
    

    return 0;
}