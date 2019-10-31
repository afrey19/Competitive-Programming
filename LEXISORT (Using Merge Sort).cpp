#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

//Method and Array of Words Declarations 
void merge(int low, int right, int mid);
void merge_sort(int left, int right);
string words[50000];

//Merge Sort Function
void merge_sort(int left, int right)
{
    int mid;
    if(left < right) {
        mid = ((left + right)/2);
        merge_sort(left, mid);
        merge_sort(mid+1, right);

        merge(left, right, mid);
    }
}

//Merge Function
void merge(int left, int right, int mid)
{
    int i, j, k, nl, nr;
    nl = mid - left + 1;
    nr = right - mid;

    string larr[nl];
    string rarr[nr];

    for(i = 0; i < nl; i++) {
        larr[i] = words[left + i];
    }

    for(j = 0; j < nr; j++) {
        rarr[j] = words[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < nl && j < nr) {
        if(larr[i] <= rarr[j]) {
            words[k] = larr[i];
            i++;
        } else {
            words[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < nl) {
      words[k] = larr[i];
      i++; 
      k++;
    }

    while (j < nr) {
      words[k] = rarr[j];
      j++; 
      k++;
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
        
        //Call Merge Sort on Size of Words Array
        merge_sort(0, lines-1);
        
        //Print Array
        for (int i = 0; i < lines; i++) {
            cout << words[i] << endl;
        }
        
    }
    
    return 0;
}