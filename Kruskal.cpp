#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

const int N = 5;

bool complete(bool arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == false)
            return false;
    }
    return true;
}

void Kruskal(int matrix[N][N])
{
    int suma = 0;
    int n = 1;
    int kruskalM[N][N] = { 0 };
    bool para[N] = { false };

    while(!complete(para, N))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (matrix[i][j] == n && !(para[i] == true && para[j] == true))
                {
                    suma += matrix[i][j];
                    para[i] = true;
                    para[j] = true;
                    kruskalM[i][j] = matrix[i][j];
                    kruskalM[j][i] = matrix[i][j];

                }
            }
        }
        n++;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << kruskalM[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Waga = " << suma;
}

int main()
{
    srand(time(0));
    int random;
    int matrix[N][N] = { 0 };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                break; 
            random = 1 + (rand() % 9);
            matrix[i][j] = random;
            matrix[j][i] = random;
        }
        Sleep(0 + (rand() % 10));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    Kruskal(matrix);
  
}