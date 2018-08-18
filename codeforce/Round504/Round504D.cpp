#include <iostream>
#include <string>
#include <stdio.h>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define ll long long

void idxinsert(vector<int> &idxtree, int pos)
{
    while (pos >= 1)
    {
        idxtree[pos]++;
        pos /= 2;
    }
}

int findps(vector<int> &idxtree, int start, int end)
{
    int result = 0;
    while (end > start)
    {
        if ((start & 1) == 1)
        {
            result += idxtree[start];
            start = (start + 1) / 2;
        }
        else
        {
            start = start / 2;
        }
        if ((end & 1) == 0)
        {
            result += idxtree[end];
            end = (end - 1) / 2;
        }
        else
        {
            end = end / 2;
        }
        if (end == start)
        {
            result += idxtree[start];
            break;
        }
    }
    return result;
}

//  every position from 1 to n got covered by at least one segment.
int main()
{
    int n = 0, q = 0;
    cin >> n >> q;

    vector<int> arr;
    int mxval = 0;
    int idxcnt = 0;
    int idxzero = -1;

    vector<vector<int>> vi(q);
    for (int i = 0; i < n; i++)
    {
        int a = 0;
        scanf("%d", &a);
        arr.push_back(a);
        if(a>mxval){
            mxval = a;
        }
        if(a==0){
            idxcnt++;
            idxzero = i;
        }

        if(a>0){
            vi[a-1].push_back(i);
        }
    }

    vector<int> idxtree(4 * n, 0);
    int twoval = 1;
    while (twoval < n)
    {
        twoval *= 2;
    }

    int i = 0;
    for (i; i < q; i++)
    {
        if (vi[i].size() == 0)
        {
            continue;
        }
        if (vi[i].size() == 1)
        {
            idxinsert(idxtree, twoval + vi[i][0]);
            continue;
        }
        int min = vi[i][0], max = vi[i][vi[i].size()-1];
        int cnt = findps(idxtree, twoval + min, twoval + max);
        if (cnt > 0)
        {
            cout << "NO";
            break;
        }
        for (int j = 0; j < vi[i].size(); j++)
        {
            idxinsert(idxtree, twoval + vi[i][j]);
        }
    }


    if(mxval<q && idxzero!=-1){
        arr[idxzero]=q;
    }

    stack<int> changeval;
    changeval.push(1);
    for(int k=0; k<n; k++){
        if(arr[k] > changeval.top() && vi[arr[k]-1].size()>1){
            changeval.push(arr[k]);
        }
        else if(arr[k]==changeval.top()){
            if(arr[k]>1 && vi[arr[k]-1][vi[arr[k]-1].size()-1] == k){
                changeval.pop();
            }
        }
        else if(arr[k]==0){
            arr[k] = changeval.top();
        }
    }

    // for(int k = q-1; k>=0; k--){
    //     if(idxcnt<=0){
    //         break;
    //     }
    //     if(vi[k].size()<=1){
    //         continue;
    //     }
    //     for(int t = vi[k][0]; t<=vi[k][vi[k].size()-1]; t++){
    //         if(arr[t] == 0){
    //             arr[t] = k+1;
    //             idxcnt--;
    //         }
    //     }
    // }

    for(int k=0; k<n; k++){
        if(arr[k]==0){
            idxzero = k;
        }
    }
    if(i==q && mxval<q && idxzero==-1){
        cout<<"NO";
    }
    else if (i == q)
    {   
        cout << "YES\n";
        if(mxval <q){
            arr[idxzero] = q;
        }
        for(int k=0; k<n; k++){
            if(arr[k]==0){
                cout<<"1 ";
            }
            else{
                cout<<arr[k]<<" ";
            }
        }
    }
    return 0;
}