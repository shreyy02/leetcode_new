class Solution {
public:
    string removeKdigits(string num, int k) {
         string st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // Agar k abhi bhi bacha hai
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Leading zeroes remove
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        // Empty number
        if (st.empty()) {
            return "0";
        }

        return st;
    }
};