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

inline float oppose(float n)
{
    return -n;
}


int main(int argc, char* argv[])
{
    std::stack<float> stack_calcul;
    if (argc == 2)
    {
        std::cout<< atoi(argv[1]) << std::endl;
    }

    else
    {
         stack_calcul.push(atoi(argv[1]));

    stack_calcul.push(atoi(argv[2]));
    int n = 3;



    while (n< argc)
    {
        if (*argv[n] == '+' or *argv[n] == '-' or *argv[n] == 'x' or *argv[n] == '/')
        {
            char op = *argv[n];
            float k = stack_calcul.top();

            stack_calcul.pop();
            float l = stack_calcul.top();

            
            stack_calcul.pop();
            stack_calcul.push(operation(l, k, op));
           

        }

        else if (*argv[n] == '!')
        {
            float k = stack_calcul.top();
            stack_calcul.pop();
            stack_calcul.push(oppose(k));
           
        }

        else
        {
            stack_calcul.push(atoi(argv[n]));
        }

        n += 1;

    

    }
   
    }

    std::cout<< stack_calcul.top() << std::endl;

    return 0;
}