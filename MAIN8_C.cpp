#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Method and Array of Candies Declaration
int partition(int low, int right);
void quick_sort(int left, int right);
int num_candies[100000];

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
    int pivot = num_candies[right];

    int index = left;

    int i;

    int temp;

    for(i = left; i < right; i++) {
        if(num_candies[i] <= pivot) {
            temp = num_candies[i];
            num_candies[i] = num_candies[index];
            num_candies[index] = temp;
            index++;
        }
    }

    temp = num_candies[right];
    num_candies[right] = num_candies[index];
    num_candies[index] = temp;

    return index;
}

//Function to Check for Students getting their candies from the same box
bool check(int boxes, int students, int mid)
{
    if(students == 1) {
        return true;
    }

    int sum = 0;

    for(int i = boxes-1; i >= 0; i--) {
        sum += (num_candies[i]/mid);
    }

    if(sum >= students) {
        return true;
    }
    else {
        return false;
    }
}

//Binary Search Function
void binarySearch(int boxes, int students)
{
    int left = 1;
    int right = num_candies[boxes-1] + 1;
    int mid = 0;

    while(right > left) {
        mid = (left + right)/2;
        if(check(boxes, students, mid) == true) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    cout << left-1 << endl;
}

int main()
{
    int total_candies = 0;

    int test_cases;
    cin >> test_cases;
    
    while(test_cases--) {
        
        int boxes, students;

        cin >> boxes >> students;

        for(int i = 0; i < boxes; i++) {
            cin >> num_candies[i];
        }
        
        //Quick Sort Integer Array of Number of Candies in each Box
        quick_sort(0, boxes-1);

        //Binary Search to return max number of candies per student per box
        binarySearch(boxes, students);
    }
    
    return 0;
}