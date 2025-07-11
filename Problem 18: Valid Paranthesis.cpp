class Solution {
public:
    bool isValid(string s) {
        stack<char> arr;
        for(char ch:s)
        {
            if(ch=='(' || ch=='[' || ch=='{')
            {
                arr.push(ch);
            }
            else
            {
                if(arr.empty())
                {
                    return false;
                }
                char c=arr.top(); 
                if((ch==')' && c=='(') || (ch=='}' && c=='{') || (ch==']' && c=='['))
                {
                    arr.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(arr.empty())
        {
            return true;
        }
        return false;
    }
};
