#include <iostream>
#include <array>

void bubbleSortAscending(int* tab, int size)
{
    /*sert de permutation*/ int p = 0;
    
    
    for (int i= size -1; i > 0; i--)
    {
       for (int j=0 ;j < i-1 ; j++)
        {
            if(tab[j] > tab[j+1])
            {
                p = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = p;
            }
        }
    }
}

void bubbleSortDescending(int* tab, int size)
{
    int p = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > i; j--) 
        {
            if (tab[j] > tab[j - 1])
            {
                p = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = p;
            }
        }
    }
}

void displayIntArray(int* tab, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << tab[i] << std::endl;
    }
}

int main()
{
    int tab[] = {5,2,7,4,9};
    int size = 5;

    std::cout << " Ordre Croissant "<< std::endl;
    bubbleSortAscending(tab, size);
    displayIntArray(tab, size);

    std::cout << " Ordre Décroissant " << std::endl;
    bubbleSortDescending(tab, size);
    displayIntArray(tab, size);
    return 0;
}