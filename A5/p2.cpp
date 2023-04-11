#include <bits/stdc++.h>
using namespace std;

/*
test1:
2
output:
11 69 88 96

test2:
1
output:
0 1 8

*/
vector<string> func(int n, int m) // solve the question
{
    if (n == 0)
        return vector<string>{""};
    if (n == 1)
        return vector<string>{"0", "1", "8"}; // special decision

    vector<string> list = func(n - 2, m);
    vector<string> result;

    for (int i = 0; i < list.size(); i++)
    {
        string s = list[i];
        if (n != m)
            result.push_back("0" + s + "0");

        result.push_back("1" + s + "1");
        result.push_back("6" + s + "9");
        result.push_back("8" + s + "8");
        result.push_back("9" + s + "6");
    }
    return result;
}

int main()
{
    int n;
    cin >> n; // input

    vector<string> ans = func(n, n);
    for (auto x : ans)
    {
        cout << x << ' ';
    }
}
