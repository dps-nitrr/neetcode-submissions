class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char curr : s) {

            // Opening bracket
            if (curr == '(' || curr == '{' || curr == '[') {
                st.push(curr);
            }

            // Closing bracket
            else {
                if (st.empty()) return false;

                char x = st.top();

                if ((x == '(' && curr == ')') ||
                    (x == '[' && curr == ']') ||
                    (x == '{' && curr == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
