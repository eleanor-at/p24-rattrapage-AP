#include <iostream>

class Cell
{
    private:
    Cell* precedent;
    Cell* suivant;
    int valeur;

    public: 
    Cell(Cell* p = nullptr, int v = 0, Cell* s = nullptr) : precedent(p), valeur(v), suivant(s) {}

    int get_valeur()
    {
        return valeur;
    }

    Cell* get_prec()
    {
        
        return precedent;
    }


    Cell* get_suiv()
    {
        return suivant;
    }

    void modif_prec(Cell* prec)
    {
        precedent = prec;
    }

    void modif_suiv(Cell* suiv)
    {
        suivant = suiv;
    }

    void modif_valeur(int v)
    {
        valeur = v;
    }

};


class LinkedList
{
    private:
    int n;
    Cell* first; 
    Cell* last; 

    public:
    LinkedList() : n(0), first(nullptr) , last(nullptr) {}

    int size()
    {
        return n;
    }

    int front()
    {
        if (first != nullptr)
        {
            return (*first).get_valeur();
        }

        return 0; //par défaut la valeur est 0 si la liste est vide

    }

    int back()
    {
        if (last != nullptr)
        {
            return (*last).get_valeur();
        }

        return 0;
        
        
    }

    void insertFront(int value)
    {
        Cell* new_first = new Cell(nullptr, value, first); //sinon new_first n'existe plus en dehors de la fonction et le pointeur first n'a plus de sens
        
        if (first == nullptr)
        {
            last = new_first;
        }

        else
        {
            (*first).modif_prec(new_first);    
        }

        first = new_first;
        n++;
        
    }

    



    ~LinkedList()
    {
        Cell* elem = first;
        while (elem != nullptr)
        {
            Cell* suiv = (*elem).get_suiv();
            delete elem;
            elem = suiv;


        }
    }



};





int main()
{
   
   LinkedList li;
   li.insertFront(1);
   li.insertFront(2);
   
  
   std::cout<< li.front() << std::endl;
   std::cout<< li.back() << std::endl;
   

   
    return 0;
}