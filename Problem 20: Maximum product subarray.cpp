class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxproduct=arr[0],n=arr.size(),product=1;
    for(int i=0;i<n;i++)
    {

        product=product*arr[i];
        if(product>maxproduct)
        {
            maxproduct=product;

        }
        if(product==0)
        {
            product=1;
        }

    }
    product=1;
    for(int i=n-1;i>=0;i--)
    {
        product=product*arr[i];
        if(product>maxproduct)
        {
            maxproduct=product;
        }
        if(product==0)
        {
            product=1;
        }
    }
    return maxproduct;
    /*int product=1,maxprod=arr[0];int count1=0,p=1;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            product=product*arr[i];
        }
        else
        {
            if( product<0)
            {
                product=product*arr[i];
            }
            else
            {
            if(i<(n-1) && arr[i+1]<0)
            {
                 product=product*arr[i];
            }
            else
            {
                maxprod=product>maxprod?product:maxprod;
                if(i!=(n-1))
                product=1;
            }
        }
    }


    }
    maxprod=product>maxprod?product:maxprod;
    if(maxprod==1)
    {
        if(count(arr.begin(),arr.end(),1)>0 || (count(arr.begin(),arr.end(),-1)>0 && count(arr.begin(),arr.end(),-1)%2==0))
        {

        }
        else
        {
              priority_queue<int> pq(arr.begin(), arr.end());
              int k=pq.top();
              maxprod=k;
        }
    }
    return maxprod;*/
    }
};
