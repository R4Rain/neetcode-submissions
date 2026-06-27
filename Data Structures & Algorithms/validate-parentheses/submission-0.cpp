class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairing;
        pairing[')'] = '(';
        pairing[']'] = '[';
        pairing['}'] = '{';


        for (int i = 0;i < s.size();i++) {
            if (pairing.count(s[i]) != 0) {
                char expectedChar = pairing[s[i]];
                if (!st.empty() && expectedChar == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(s[i]);
            }
        }
        return (st.size() == 0) ? true : false;
    }
};