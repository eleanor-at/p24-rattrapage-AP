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


inline std::pair<std::stack<int>, std::stack<char>> data(char*[] array) //extrait en deux piles distinctes opérateurs et opérandes
{
    std::stack<int> number_stack;
    std::stack<char> operator_stack;
    
    for (char elem : array)
    {
        if (atoi(elem) == 0 && elem != '0') 
        {
            operator_stack.push(elem);
        }
        
        else
        {
            number_stack.push(atoi(elem));
        }
    }

    return std::make_pair(number_stack, operator_stack);

}



int main(int argc, char* argv[])
{
    std::cout<< data(argv).first.top() << std::endl;


    return 0;
}