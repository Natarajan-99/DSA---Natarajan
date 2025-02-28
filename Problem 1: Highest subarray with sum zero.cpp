#include <iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

int maxLen(vector<int>& A)
{
    int n=A.size();
    // Your code here
    unordered_map<int,int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i = 0;i<n;i++) {
        sum += A[i];
        if(sum == 0) {
            maxi = i + 1;
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    vector<int> arr={1,2,3,-3,-2,0,9,8};
    //subarraywithsumzero(arr);
    int ans=maxLen(arr);
    cout<<ans;
    return 0;
}
