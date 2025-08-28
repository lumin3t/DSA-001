# Neetcode Blind75 Stack

### Valid Parentheses (easy)
```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i=0;i<s.length(); i++) {
            char curr = s.charAt(i);
            if (curr == '(' || curr == '[' || curr == '{') {
                stack.push(curr);
            } else if (curr == ')' || curr == ']' || curr == '}' ) {
                if (stack.isEmpty() || !isMatch(stack.pop(), curr)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
    public boolean isMatch(char opening, char closing) {
        return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');  
    }
}
```