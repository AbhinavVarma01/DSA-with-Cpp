
class Solution {
public:
    bool isValid(std::string s) {
        // A stack to keep track of opening brackets
        std::stack<char> bracketStack;

        for (char c : s) {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            } 
            else {
                // If we encounter a closing bracket but the stack is empty,
                // it means there is no matching opening bracket.
                if (bracketStack.empty()) {
                    return false;
                }

                char top = bracketStack.top();
                // Check if the current closing bracket matches the top of the stack
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    bracketStack.pop();
                } else {
                    // Mismatched bracket types (e.g., "(]")
                    return false;
                }
            }
        }

        // If the stack is empty, all brackets were matched correctly.
        // If not, some opening brackets were never closed.
        return bracketStack.empty();
    }
};
