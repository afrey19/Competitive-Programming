#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

//Method and Array of Words Declarations
int partition(int low, int right);
void quick_sort(int left, int right);
string words[50000];

//Quick Sort Function
void quick_sort(int left, int right)
{
    if(left < right) {
        int index = partition(left, right);
        quick_sort(left, (index -1));
        quick_sort((index + 1), right);
    }
}

//Partition Function
int partition(int left, int right)
{
    string pivot = words[right];

    int index = left;

    int i;

    string temp;

    for(i = left; i < right; i++) {
        if(words[i] <= pivot) {
            temp = words[i];
            words[i] = words[index];
            words[index] = temp;
            index++;
        }
    }

    temp = words[right];
    words[right] = words[index];
    words[index] = temp;

    return index;
}

int main()
{
    int test_cases, lines;

    cin >> test_cases;
 
    while(test_cases--) {
        cin >> lines;
        
        for(int i = 0; i < lines; i++) {
            cin >> words[i];
        }

        //Quick Sort on Size of the Words Array
        quick_sort(0, lines-1);

        //Print Array
        for (int i = 0; i < lines; i++) {
            cout << words[i] << endl;
        }
        
    }
    
    return 0;
}