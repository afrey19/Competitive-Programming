#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void heapify(int n, int index);
void heapSort(int n);
string words[50000];

//Function to "Heapify" the array with n = size of array)
void heapify(int n, int index)
{
    string temp;
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && words[left] > words[largest]) {
        largest = left;
    }

    if(right < n && words[right] > words[largest]) {
        largest = right;
    }

    if(largest != index) {
        //Swap Nodes
        temp = words[index];
        words[index] = words[largest];
        words[largest] = temp; 

        heapify(n, largest);
    }
}

//Function to start heap sorting
void heapSort(int n)
{
    string temp;

    for(int i = (n/2 - 1); i >= 0; i--) {
        heapify(n, i);
    }

    for(int i = n-1; i >= 0; i--) {
        //Swap Nodes
        temp = words[0];
        words[0] = words[i];
        words[i] = temp;

        heapify(i, 0);
    }
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

        //Build Max Heap
        heapSort(lines);
        
        //Print Array
        for (int i = 0; i < lines; i++) {
            cout << words[i] << endl;
        }
        
    }
    
    return 0;
}