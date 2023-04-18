#include <bits/stdc++.h>
using namespace std;

/*
test1:
4
the sky is blue
output:
blue is sky the

test2:
1
a
output:
a

*/
// struct
string mp[1000];

// solve the question
void myReverse(int n)
{
    // output
    for (int i = n - 1; i >= 0; i--)
    {
        cout << mp[i] << ' ';
    }
}

int main()
{

    // input
    int n;
    cin >> n; // number of word

    for (int i = 0; i < n; i++)
    {
        cin >> mp[i];
    }
    myReverse(n);
}