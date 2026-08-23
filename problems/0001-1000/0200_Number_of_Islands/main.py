from collections import deque

class Solution:
    def numIsLands(self, grid: list[list[str]]) -> int:
        if not grid:
            return 0
        
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1
        return count
    
    def dfs(self, grid: list[list[str]], i: int, j: int) -> None:
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] != '1':
            return
        grid[i][j] = '0'
        self.dfs(grid, i+1, j)
        self.dfs(grid, i-1, j)
        self.dfs(grid, i, j+1)
        self.dfs(grid, i, j-1)

    def bfs(self, grid: list[list[str]], i: int, j: int) -> None:
        q = deque()
        q.append([i, j])
        while q:
            x, y = q.pop()
            grid[x][y] = '0'
            directions = [[1,0],[0,1],[-1,0],[0,-1]]

            for x_dir, y_dir in directions:
                x_new, y_new = x + x_dir, y + y_dir
                if x_new >= 0 and y_new >= 0 and x_new < len(grid) and y_new < len(grid[0]) and grid[x_new][y_new] == '1':
                    q.append([x_new, y_new])

        return

if __name__ == "__main__":
    solution = Solution()
    test_cases = [
        [["1", "1", "0", "0", "0"],
         ["1", "1", "0", "0", "0"],
         ["0", "0", "1", "0", "0"],
         ["0", "0", "0", "1", "1"]],
        [["1", "1", "1"],
         ["0", "1", "0"],
         ["1", "1", "1"]],
        [["1"]],
        [["0"]],
        []
    ]
    
    for grid in test_cases:
        print(f"Number of islands: {solution.numIsLands(grid)}")