#include <iostream>
#include <array>

int tab[] = {5,2,7,4,9};
int size = 5;

void bubbleSort()
{
    /*sert de permutation*/ int p = 0;
    
    for (int i=0;i < size;i++)
    {
        for (int j=0;j < size - i -1; j++)
        {
            if(tab[i] > tab[i+1])
            {
                p = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = p;
            }
        }
    }    
}

void displayIntArray() 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << tab[i] << std::endl;
    }
}

int main()
{
    bubbleSort();
    displayIntArray();
    return 0;
}