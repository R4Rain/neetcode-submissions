class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";

        for (auto c : s) {
            if (isdigit(c) || c >= 'a' && c <= 'z') {
                str += c;
            }
            else if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
                str += c;
            }
        }
        cout << str << endl;

        int start = 0, ending = str.size()-1;
        while (start <= ending) {
            if (str[start] != str[ending]) {
                return false;
            }
            start++;
            ending--;
        }
        return true;
    }
};