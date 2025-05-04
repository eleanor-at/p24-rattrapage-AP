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

    std::cout<< "taille debut" << stack_calcul.size() << std::endl;

    
   
    stack_calcul.push(atoi(argv[1]));

    stack_calcul.push(atoi(argv[2]));
    int n = 3;

    std::cout<< "top pile debut" << stack_calcul.top()<< std::endl;



    while (stack_calcul.size() > 1)
    {
        if (*argv[n] == '+' or *argv[n] == '-' or *argv[n] == 'x' or *argv[n] == '/')
        {
            char op = *argv[n];
            float k = stack_calcul.top();

            std::cout<< "k" << k << std::endl; 

            stack_calcul.pop();
            float l = stack_calcul.top();

            std::cout<< "l" << l << std::endl; 
            stack_calcul.pop();
            stack_calcul.push(operation(l, k, op));
            std::cout<< "k*l" << stack_calcul.top() << std::endl;

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

        std::cout<< "taille après une itération" << stack_calcul.size();
        
    

    }

    std::cout<< n << std::endl;
    std::cout<< argc<< std::endl;
    std::cout<< stack_calcul.size();


    std::cout<< stack_calcul.top() << std::endl;



    
 


   
   

    

    
    
    

    return 0;
}