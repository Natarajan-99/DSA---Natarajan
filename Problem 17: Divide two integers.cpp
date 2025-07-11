class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign;
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend==1<<31 && divisor==-1) return INT_MAX;
        if (divisor == 1) return dividend;
        if(dividend<0 && divisor>0)sign=true;
        else if(dividend>0 && divisor<0)sign=true;
        else sign=false;
         long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int ans = 0;

        while (n >= d) {
            int p = 0;
            while (n >= (d << p)) p++;
            p--;
            n -= (d << p);
            ans += (1 << p);
        }
        //if(dividend==1<<31 && divisor=-1)return INT_MAX;
        /*long long n = abs((long long)dividend);
        long long di = abs((long long)divisor);
        int result=0;
        int d=divisor;
        while(n-di>=0)
        {
            int count=0;
           // d=di;
            while(n-(di<<1<<count)>=0)
            {
                count++;
                //d=d<<1;
            }
            result=result+int((1<<count));
            n=n-(di<<count);
        }*/
        if(sign==true)
        {
            //result=result*-1;
            ans=ans*-1;
        }

        return ans;
    }
};
