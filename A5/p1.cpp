#include <bits/stdc++.h>
using namespace std;

/*
test1:
eceba
output:
3

test2:
ccaabbb
output:
5

*/
int func(string s) // solve the question
{
    int chars[256] = {0};
    int cnt = 0;
    int ans = 0;
    for (int i = 0, j = 0; i < s.size(); ++i)
    {
        ++chars[s[i]];
        if (chars[s[i]] == 1)
            ++cnt;
        while (cnt > 2)
        {
            --chars[s[j]];
            if (chars[s[j]] == 0)
                --cnt;
            ++j;
        }

        ans = max(ans, i - j + 1);
    }

    return ans;
}

int main()
{

    string num; // input
    cin >> num;
    cout << func(num) << endl;
}