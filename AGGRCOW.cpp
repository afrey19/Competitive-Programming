#include <iostream>
#include <cstdio>
using namespace std;

//Function and Array Declarations
void heapify(int n, int index);
void heapSort(int n);
int locations[100001];

//Function to "Heapify" the array (with n = size of array)
void heapify(int n, int index)
{
    int temp;
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && locations[left] > locations[largest]) {
        largest = left;
    }

    if(right < n && locations[right] > locations[largest]) {
        largest = right;
    }

    if(largest != index) {
        //Swap Nodes
        temp = locations[index];
        locations[index] = locations[largest];
        locations[largest] = temp; 

        heapify(n, largest);
    }
}

//Function to start heap sorting
void heapSort(int n)
{
    int temp;

    for(int i = (n/2 - 1); i >= 0; i--) {
        heapify(n, i);
    }

    for(int i = n-1; i >= 0; i--) {
        //Swap Nodes
        temp = locations[0];
        locations[0] = locations[i];
        locations[i] = temp;

        heapify(i, 0);
    }
}

//Function to Check if distance is possible
bool check(int stalls, int cows, int mid)
{
    int count = 1;
    long long pos = locations[0];

    for(int i = 1; i < stalls; i++) {
        if(locations[i] - pos >= mid) {
            pos = locations[i];
            count++;
            if(count == cows)
                return true;
       }
    }
    return false;
}

//Binary Search Function
int binarySearch(int stalls, int cows)
{
    int left = 0, mid = 0;
    int right = locations[stalls-1] - locations[0];

    while(left < right) {
        mid = (left + right)/2;
        if(check(stalls, cows, mid)) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return (left - 1);
}

int main()
{
    int test_cases;
    cin >> test_cases;
    
    while(test_cases--) {
        
        int stalls, cows;

        cin >> stalls >> cows;

        for(int i = 0; i < stalls; i++) {
            cin >> locations[i];
        }
        
        //Heap Sort integer Array of Stall Locations
        heapSort(stalls);

        //Binary Search integer Array for Largest Minimum Distance
        if(test_cases > 0) {
            cout << binarySearch(stalls, cows) << endl;
        }
        else {
            cout << binarySearch(stalls, cows);
        }
    }
    
    return 0;
}