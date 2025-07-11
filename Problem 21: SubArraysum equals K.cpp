#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={1,2,3};int k=3;
map<int, int> m;
        m.insert({ 0,1 });
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
	        sum = sum + nums[i];
//cout << sum << endl;


            auto it = m.find(sum - k);
            //cout << sum - k << endl;
            if (it != m.end())
            {
                count += it->second; //cout<<"it "<<sum-k<<endl;
            }
            it = m.find(sum);
            if (it != m.end())
            {
                it->second++;
            }
            else
            {
                m.insert({ sum,1 }); cout<<sum<<endl;
            }

        } 
        cout<<count;
    }
