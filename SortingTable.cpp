#include <iostream>
#include <array>
#include <chrono>
#include <random>

// BUBBLESORT
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

void bubbleSortImplemented()
{
    int tab[] = {5,2,7,4,9};
    int size = 5;

    std::cout << " Ordre Croissant "<< std::endl;
    bubbleSortAscending(tab, size);

    std::cout << " Ordre Décroissant " << std::endl;
    bubbleSortDescending(tab, size);
     std::cout << " " << std::endl;
}

void manualbubbleSortTable()
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

// INSERTIONSORT
void insertionSortAscending(int* tab, int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int p = tab[i];
        int j = i - 1;

        while (j >= 0 && tab[j] > p) 
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = p;
    }
    for (int i = 0; i < size; i++) 
    {
        
        std::cout << tab[i] << std::endl;
    }
}

void insertionSortDescending(int* tab, int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int p = tab[i];
        int j = i - 1;

        while (j >= 0 && tab[j] < p) 
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = p;
    }
    for (int i = 0; i < size; i++) 
    {
        
        std::cout << tab[i] << std::endl;
    }
}

void insertionSortImplemented() {
    int tab[] = {4, 3, 9, 6, 1};
    int size = 5;

    std::cout << "Ordre Croissant" << std::endl;
    insertionSortAscending(tab, size);

    std::cout << "Ordre Décroissant" << std::endl;
    insertionSortDescending(tab, size);
    std::cout << std::endl;
}

void manualInsertionSortTable()
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
        insertionSortAscending(tab, size);
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
        insertionSortDescending(tab, size);
    }
    else 
    {
        std::cout << "Choix non valide." << std::endl;
    }
    delete[] tab;
}

void swap(int* tab, int i, int j) 
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int partition(int* tab, int debut, int fin)
{
    int pivot = fin;
    int j = debut;

   for (int i = debut; i < fin; ++i) 
    {
        if (tab[i] <= tab[pivot])
        {
            swap(tab, i, j);
            j++;
        }
    }
    swap(tab, j, pivot);
    return j;
}

int partitionInverse(int* tab, int debut, int fin)
{
    int pivot = fin;
    int j = debut;

   for (int i = debut; i < fin; ++i) 
    {
        if (tab[i] >= tab[pivot])
        {
            swap(tab, i, j);
            j++;
        }
    }
    swap(tab, j, pivot);
    return j;
}

void triRapide(int* tab, int debut, int fin)
{
    if (debut < fin) 
    {
        int pivotIndex = partition(tab, debut, fin);
        triRapide(tab, debut, pivotIndex - 1);
        triRapide(tab, pivotIndex + 1, fin);
    }
}

void triRapideInverse(int* tab, int debut, int fin)
{
    if (debut < fin) 
    {
        int pivotIndex = partitionInverse(tab, debut, fin);
        triRapideInverse(tab, debut, pivotIndex - 1);
        triRapideInverse(tab, pivotIndex + 1, fin);
    }
}

void afficherTableau(int* tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

void randomizeArray(int* tab, int sizeRandomArray)
{
    const int min = 0;
    const int max = 100;

     for (int i = 0; i < sizeRandomArray; ++i) 
     {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(min, max);
        tab[i] = distr(eng);
     }
}

void quickSort()
{
    char choice;
    std::cout << "Choisissez le tableau : " << std::endl;
    std::cout << "   a : Tableau déjà défini" << std::endl;
    std::cout << "   b : Tableau de taille 100" << std::endl;
    std::cout << "   c : Tableau de taille 10000 trié" << std::endl;
    std::cout << "   d : Tableau de taille 10000 trié dans l'ordre inverse" << std::endl;
    std::cin >> choice;

    //Tableau déjà implanté
    if (choice == 'a' || choice == 'A') 
    {
        int tab[] = {7, 1, 5, 2, 3};
        int size = sizeof(tab) / sizeof(tab[0]);

        auto start = std::chrono::high_resolution_clock::now();
        triRapide(tab, 0, size - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "Tableau trié (taille 5): " << std::endl;
        afficherTableau(tab, size);
        std::cout << "Temps d'exécution pour le tri rapide : " << duration.count() << " microseconds" << std::endl;
    }

    //Test avec un tableau de taille 100
    if(choice == 'b' || choice == 'B')
    {
        const int size = 100;
        int tab[size];
        
        auto start = std::chrono::high_resolution_clock::now();
        randomizeArray(tab, size);
        triRapide(tab, 0, size - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        
        std::cout << "Contenue du tableau de 100" << std::endl;
        afficherTableau(tab, size);

        std::cout << "Taille du tableau: " << size << std::endl;
        
        std::cout << "Temps d'exécution pour le tri rapide : " << duration.count() << " microseconds" << std::endl;
    }

    //Test avec un tableau de taille 10000
    if(choice == 'c' || choice == 'C')
    {
        const int size = 10000;
        int tab[size];

        auto start = std::chrono::high_resolution_clock::now();
        randomizeArray(tab, size);
        triRapide(tab, 0, size - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        
        std::cout << "Contenue du tableau de 100" << std::endl;
        afficherTableau(tab, size);

        std::cout << "Taille du tableau: " << size << std::endl;
        
        std::cout << "Temps d'exécution pour le tri rapide : " << duration.count() << " microseconds" << std::endl;
    }

    //Test avec un tableau de taille 10000 trié dans l'ordre inverse
    if(choice == 'd' || choice == 'D')
    {
        const int size = 10000;
        int tab[size];

        auto start = std::chrono::high_resolution_clock::now();
        randomizeArray(tab, size);
        triRapideInverse(tab, 0, size - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        
        std::cout << "Contenue du tableau de 100" << std::endl;
        afficherTableau(tab, size);

        std::cout << "Taille du tableau: " << size << std::endl;

        std::cout << "Temps d'exécution pour le tri rapide : " << duration.count() << " microseconds" << std::endl;
    }
}

int main()
{
/*BUBBLESORT*/
    //bubbleSortImplemented();
    //manualbubbleSortTable();

/*INSERTIONSORT*/
    //insertionSortImplemented();
    //manualbubbleSortTable();

/*QUICKSORT*/
    quickSort();
    return 0;
}