#include<bits/stdc++.h>
using namespace std;


/*
test1:
3
0 30
5 10
15 20

test2:
2
7 10
2 4

*/

struct Intervals{
    int s;//start
    int e;//end
};


int main(){
    int n;
    vector<Intervals> arr;
    cin>>n;//n pairs of input
    for(int i=0;i<n;i++){
        Intervals tmp;
        cin>>tmp.s>>tmp.e;
        arr.push_back(tmp);
    }

    sort(arr.begin(),arr.end(),[](Intervals& a,Intervals& b){return a.s<b.s;});
    //quick sort by start

    for(int i=1;i<arr.size();i++){
        if(arr[i].s<arr[i-1].e){
            cout<<"false"<<endl;
            return 0;
        }
    }

    cout<<"true"<<endl;



}