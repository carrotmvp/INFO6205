#include<bits/stdc++.h>
using namespace std;


/*
test1:
5
0 1 1 0 1

test2:
1
0

*/



int main(){
    int n;
    vector<int> dp={0,0};
    vector<int> nums;
    unordered_map<int,int> mp;
    mp[0]=1;
    cin>>n;//n input
    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }

    for(int num:nums){
        vector<int> dp_p=dp;

        if(num==1)sum++;
        else sum--;
        dp[0]=mp[sum];
        if(num==1){
            dp[1]=dp_p[0]+dp_p[1]+1;
        }
        else{
            dp[1]=dp_p[1]-dp[0];
        }
        mp[sum]++;
        ans+=dp[1];
    }

    cout<<ans<<endl;



}