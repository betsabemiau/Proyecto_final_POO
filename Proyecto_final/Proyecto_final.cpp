// Proyecto_final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void combSort(int arr[], int n) 
{
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) 
    {
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void shellSort(int arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int sequentialSearch(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;  
}

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target) 
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return -1;  
}


void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    const int SIZE = 100;
    int arr[SIZE];

  
    srand(time(nullptr));
    for (int i = 0; i < SIZE; i++) 
    {
        arr[i] = rand() % 1000; 
    }

   
    int option;
    cout << "Algoritmo de ordenamiento:" << endl;
    cout << "1. Combsort" << endl;
    cout << "2. Shellsort" << endl;
    cout << "3. Bubblesort" << endl;
    cout << "Seleccione un algoritmo de ordenamiento (1-3): ";
    cin >> option;

   
    switch (option) 
    {
    case 1:
        combSort(arr, SIZE);
        cout << "Arreglo ordenado con Combsort: ";
        printArray(arr, SIZE);
        break;
    case 2:
        shellSort(arr, SIZE);
        cout << "Arreglo ordenado con Shellsort: ";
        printArray(arr, SIZE);
        break;
    case 3:
        bubbleSort(arr, SIZE);
        cout << "Arreglo ordenado con Bubblesort: ";
        printArray(arr, SIZE);
        break;
    default:
        cout << "Opcion invalida." << endl;
        return 0;
    }

   
    int searchOption;
    cout << "\nAlgoritmo de busqueda:" << endl;
    cout << "1. Busqueda secuencial" << endl;
    cout << "2. Busqueda binaria" << endl;
    cout << "Seleccione un algoritmo de busqueda (1-2): ";
    cin >> searchOption;

    int target;
    cout << "Ingrese el elemento a buscar: ";
    cin >> target;

    int index;
    switch (searchOption)
    {
    case 1:
        index = sequentialSearch(arr, SIZE, target);
        break;
    case 2:
        index = binarySearch(arr, 0, SIZE - 1, target);
        break;
    default:
        cout << "Opcion invalida." << endl;
        return 0;
    }

    if (index != -1) 
    {
        cout << "Elemento encontrado en el indice: " << index << endl;
    }
    else
    {
        cout << "Elemento no encontrado." << endl;
    }

    return 0;
}
