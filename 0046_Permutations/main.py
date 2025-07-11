from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums[:]]
        
        ans = []

        for _ in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)
            
            for p in perms:
                p.append(n)

            ans.extend(perms)
            nums.append(n)

        return ans
    
if __name__ == "__main__":
    solution = Solution()
    nums = [[1, 2, 3], [0, 1], [1], [], [1, 2, 3, 4]]
    for num in nums:
        print(f"Permutations of {num}: {solution.permute(num)}")     