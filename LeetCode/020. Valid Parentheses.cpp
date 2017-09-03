class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 0 || n % 2 == 1)
            return false;
        map<char, char> m;
        m['('] = ')'; m['['] = ']'; m['{'] = '}';
        stack<char> st;
        char tmp;
        for(int i = 0; i < n; i++)
        {
            tmp = s[i];
            if(tmp == '(' || tmp == '[' || tmp == '{')
                st.push(tmp);
            else if(tmp == ')' || tmp == ']' || tmp == '}')
            {
                if(st.empty())
                    return false;
                if(m[st.top()] == tmp)
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else
                return false;
        }
        if(!st.empty())
            return false;
        return true;        
    }
};
