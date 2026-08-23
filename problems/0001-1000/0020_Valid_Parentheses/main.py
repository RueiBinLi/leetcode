class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if len(stack) > 0:
                if stack[-1] == '(' and c == ')':
                    stack.pop()
                elif stack[-1] == '[' and c == ']':
                    stack.pop()
                elif stack[-1] == '{' and c == '}':                  
                    stack.pop()
                else:
                    stack.append(c)
            else:
                stack.append(c)

        if len(stack) == 0:
            return True
        return False
            

if __name__ == "__main__":
    solution = Solution()
    test_cases = ["()", "()[]{}", "(]", "([)]", "{[]}", "", "((()))", "(()())"]
    for case in test_cases:
        print(f"Is '{case}' valid? {solution.isValid(case)}")