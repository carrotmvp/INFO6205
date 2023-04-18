#include <bits/stdc++.h>
using namespace std;

/*
test1:
3
WordDistance shortest shortest
0
5
practice makes perfect coding makes
2
coding practice
makes coding
0
output:
null 3 1

test2:
3
WordDistance shortest shortest
2
WordDistance shortest
shortest shortest
0
output:
1 0

*/

class WordDistance
{
private:
    unordered_map<string, vector<int>> wordMap; // struct

public:
    WordDistance(vector<string> &words) // wordDistance function
    {
        for (int i = 0; i < words.size(); i++)
            wordMap[words[i]].push_back(i);
    }
    int shortest(string word1, string word2) // find the shortest distance
    {
        int i = 0, j = 0, dist = INT_MAX;
        while (i < wordMap[word1].size() && j < wordMap[word2].size())
        {
            dist = min(dist, abs(wordMap[word1][i] - wordMap[word2][j]));
            wordMap[word1][i] < wordMap[word2][j] ? i++ : j++;
        }
        return dist;
    }
};

int main()
{
    vector<int> ans; // answer vector

    // input
    while (1)
    {
        int n;
        cin >> n; // number of word
        if (n <= 0)
            break; // if word is 0 break, or just finish the input
        vector<string> words;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            words.push_back(s);
        }
        WordDistance *wordDistance = new WordDistance(words);
        cin >> n; // number of shortest words need find
        if (n == 0)
        {
            ans.push_back(-1);
            continue; // if don't need to find shortest continue
        }
        string s1, s2;
        for (int i = 0; i < n; i++)
        {
            cin >> s1 >> s2;
            ans.push_back(wordDistance->shortest(s1, s2));
        }
    }
    // output
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
            cout << "null ";
        else
            cout << ans[i] << ' ';
    }

    return 0;
}