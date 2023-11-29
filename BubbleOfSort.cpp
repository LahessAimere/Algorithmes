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
     for (int i = 0; i < size; i++) 
    {
        
        std::cout << tab[i] << std::endl;
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
     for (int i = 0; i < size; i++) 
    {
        
        std::cout << tab[i] << std::endl;
    }
}

void TableAlreadyImplemented()
{
    int tab[] = {5,2,7,4,9};
    int size = 5;

    std::cout << " Ordre Croissant "<< std::endl;
    bubbleSortAscending(tab, size);

    std::cout << " Ordre Décroissant " << std::endl;
    bubbleSortDescending(tab, size);
     std::cout << " " << std::endl;
}

void ManualLayoutTable()
{
    int size;
    int* tab;

    char choice;
    std::cout << "Veux tu un tableau en ordre croissant (c) ou décroissant (d) ?" << std::endl;
    std::cin >> choice;

    if (choice == 'c' || choice == 'C') 
    {
        std::cout << "Entrez la taille du tableau : ";
        std::cin >> size;

        tab = new int[size];

        std::cout << "Entrez les éléments du tableau (séparés par des espaces) : ";
        for (int i = 0; i < size; ++i) 
        {
            std::cin >> tab[i];
        }
        bubbleSortAscending(tab, size);
    }
    else if (choice == 'd' || choice == 'D')
    {
        std::cout << "Entrez la taille du tableau : ";
        std::cin >> size;

        tab = new int[size];

        std::cout << "Entrez les éléments du tableau (séparés par des espaces) : ";
        for (int i = 0; i < size; ++i) 
        {
            std::cin >> tab[i];   
        }
        
        bubbleSortDescending(tab, size);
    }
    else 
    {
        std::cout << "Choix non valide." << std::endl;
    }
    delete[] tab;
}

int main()
{
    TableAlreadyImplemented();
    ManualLayoutTable();

    return 0;
}