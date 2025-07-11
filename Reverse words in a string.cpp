class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string str="";
        char d;
        for(char ch:s)
        {
            d=ch;
            if(ch!=' ')
            {
                str+=ch;
            }
            else
            {
                if(str!="")
                vec.push_back(str);
                str="";

            }
        } 
        if(d!=' ')
        {
            vec.push_back(str);
        }
        int g=vec.size()-1;
        str=vec[g];
        for(int i=g-1;i>=0;i--)
        {
            str=str+" ";
            str=str+vec[i];
        }
        /*for(string q:vec)
        {
            cout<<q<<" ";
        }*/
        return str;
    }
    
};
