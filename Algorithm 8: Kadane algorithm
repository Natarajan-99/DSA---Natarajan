#include <iostream>
#include <vector>
using namespace std;


int kadane(vector<int> const& arr)
{
    int max_so_far = 0;

    
    int max_ending_here = 0;

    
    for (int i = 0; i < arr.size(); i++)
    {
       
        max_ending_here = max_ending_here + arr[i];

        if (max_ending_here < 0)
        {
			max_ending_here = 0;
        }

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
		}
    }

    return max_so_far;
}

int main()
{
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    cout << "The maximum sum of a contiguous subarray is " << kadane(arr);

    return 0;
}
