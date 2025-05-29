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

     void insertBack(int value)
     {
        Cell* new_last = new Cell(last, value, nullptr);
        if (last == nullptr)
        {
            first = new_last;
        }

        else
        {
            (*last).modif_suiv(new_last);    
        }

        last = new_last;
        n++;
     }

    void remove(int value)
    {
        Cell* elem = first;
        if (first != nullptr)
        {
        while (elem != nullptr)
        {
        
            Cell* suivant = (*elem).get_suiv();
            if ((*elem).get_valeur() == value)
            {
                Cell* old_prec = (*elem).get_prec();
                Cell* old_suiv = (*elem).get_suiv();
                if (old_prec != nullptr)
                {
                    (*old_prec).modif_suiv(old_suiv);
                }
                else
                {
                    first = old_suiv;
                }

                if (old_suiv != nullptr)
                {
                    (*old_suiv).modif_prec(old_prec);
                }

                else
                {
                    last = old_prec;
                }

                delete elem;
                n--;
              
            }

              elem = suivant;
     
        }
    }}

    bool search(int value)
    {
        
        Cell* elem = first;
        if (first == nullptr)
        {
            return false;
        } 

        while (elem != nullptr)
        {
            if ((*elem).get_valeur() == value)
            {
                elem = (*elem).get_suiv();
                return true;
            }
        }

            return false;
        }
    

    bool is_empty()
    {
        return (n == 0);
    }

    void remove_duplicate(int value)
    {
        remove(value); //je n'ai surement pas bien compris ce qui etait demandé je ne vois pas l'interêt de ma fonction
    }

    friend std::ostream& operator<<(std::ostream& os, LinkedList& li);



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

std::ostream& operator<<(std::ostream& os, LinkedList& li)
{
    if (li.first == nullptr)
    {
        os<< "la liste est vide"<< std::endl;
        return os;
    }

    else
    {
       Cell* elem = li.first;
       while (elem != nullptr)
       {
        os << (*elem).get_valeur() << std::endl;
        elem = (*elem).get_suiv();
       }
    }
    return os;
}



int main()
{
   
   LinkedList li;
   li.insertFront(1);
   li.insertBack(2);
   li.insertBack(1);
   li.insertBack(3);
   
   std::cout<< li << std::endl;
   

   

   
    return 0;
}