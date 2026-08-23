from collections import deque

class RecentCounter:
    def __init__(self):
        self.q = deque()

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q and self.q[0] < t-3000:
            self.q.popleft()
        return len(self.q)
    
if __name__ == "__main__":
    rc = RecentCounter()
    test_cases = [1, 100, 3001, 3002, 6000]
    for t in test_cases:
        print(f"Number of recent calls at time {t}: {rc.ping(t)}")