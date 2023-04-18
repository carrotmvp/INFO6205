#include <bits/stdc++.h>
using namespace std;

/*
test1:
3
1 1 0
0 1 0
1 1 1
output:
1

test2:
3
1 0 1
1 1 0
0 1 1
output:
-1

*/

int mp[1000][1000]; // for information

bool knows(int a, int b)
{
    return mp[a][b];
}

int findCelebrity(int n)
{
    vector<int> possibleCelebs;
    int candidate = 0;
    for (int i = 1; i < n; i++)
    {
        if (knows(candidate, i))
            candidate = i;
    }

    // Check if candidate found knows anyone or anyone who doesn't know candidate
    // If any of this is true, the candidate is not a celeb.
    for (int i = 0; i < n; i++)
    {
        if (candidate == i)
            continue;
        if (knows(candidate, i) || !knows(i, candidate))
            return -1;
    }
    return candidate;
}

int main()
{

    // input
    int n;
    cin >> n; // number of people
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            mp[i][j] = x;
        }
    }
    cout << findCelebrity(n) << endl;
}