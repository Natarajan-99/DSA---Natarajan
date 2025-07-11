class Solution {
public:
    string longestPalindrome(string s) {
    string str="";
    int n=s.length();
    int max_length=0,templength;
    for(int i=1;i<n;i++)
    {
        templength=1;
        if(s[i-1]==s[i+1])
        {
            int k=i-2,h=i+2;
            while(k>=0 && h<n && s[k]==s[h])
            {
                k--;h++;
            }
            k++;h--;
            templength=h-k+1;
            if(templength>max_length)
            {
                max_length=templength;
                str=s.substr(k,max_length);
                /*if(k==0)
                {
                    str=s.substr(k,h+1);
                }
                else
                {
                    str=s.substr(k,h);
                }*/
            }
        }
        if(s[i]==s[i-1])
        {
            templength=2;
            int k=i-2,h=i+1;
            while(k>=0 && h<n && s[k]==s[h])
            {
                k--;h++;
            }
            k++;h--;
            templength=h-k+1;
            if(templength>max_length)
            {
                max_length=templength;
                str=s.substr(k,max_length);
                /*if(k==0)
                {
                    str=s.substr(k,h+1);
                }
                else
                {
                    str=s.substr(k,h);
                }*/
                
            }
        }
    }
    if(str=="")
    {
        str=s[0];
    }
    return str;
    }
};
