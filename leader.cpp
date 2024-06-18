#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<int> superiorElements(vector<int>& a) {
    

    vector<int> ans;
    int maxi=INT_MIN;

    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
           
        }
         maxi=max(a[i],maxi);
        
    }

    sort(ans.begin(),ans.end());
    return ans;
}

