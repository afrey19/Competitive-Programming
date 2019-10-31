#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

// Global Variables
int sequence[300007];
int answer[300007];
int temp[1000005];

// BIT
int BIT[300007];

// Pair Structure for Numbering DQueries
pair <int, pair<int, int>> pr[300000];

// Update BIT
void update(int index, int value)
{
    while(index <= 300000) {
        BIT[index] += value;
        index += (index & -index);
    }
}

// Get Sum in BIT
int getSum(int index)
{
    int sum = 0;
    while(index > 0) {
        sum += BIT[index];
        index -= (index & -index);
    }
    return sum;
}

int main()
{
    int n, test_cases;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &sequence[i]);
    }

    scanf("%d", &test_cases);

    for(int i = 0; i < test_cases; i++) {
        scanf("%d %d", &pr[i].second.first, &pr[i].first);
        pr[i].second.second = i;
    }

    // Sort all DQueries
    sort(pr, pr + test_cases);

    // Fill rest of Memory
    memset(temp, -1, sizeof(temp));
    memset(BIT, 0, sizeof(BIT));

    int x = 0;

    // Construct Answer with BIT
    for(int i = 1; i <= n; i++) {
        if(temp[sequence[i]] != -1) {
            update(temp[sequence[i]], -1);
        }
        temp[sequence[i]] = i;
        update(i, 1);
        while(x < test_cases && pr[x].first == i) {
            answer[pr[x].second.second] = getSum(pr[x].first) - getSum((pr[x].second.first - 1));
            x++;
        }
    }

    // Print Results
    for(int i = 0; i < test_cases; i++) {
        if(i == (test_cases - 1))
            printf("%d", answer[i]);
        else
            printf("%d\n", answer[i]);
    }

    return 0;
}