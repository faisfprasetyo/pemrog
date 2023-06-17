#include <iostream>
using namespace std;

int main()
{
    int bil, bila, size=0, nilai, a, b;
    int *arr;
    arr=(int*)malloc((a+b)*sizeof(int));
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        cin >> bil;
        arr[size] = bil;
        size++;
    }
    for (int j = 0; j < b; j++)
    {
        cin >> bila;
        arr[size] = bila;
        size++;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                nilai = arr[i];
                arr[i] = arr[j];
                arr[j] = nilai;
            }
        }
    }
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i-1];
        if (i==size)
        {
            cout << "\n";
        }
        else
        {
            cout << " ";
        }
        
    }
    return 0;
    
  
}
