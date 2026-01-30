from typing import List

class Solution:
    def candy(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 0:
            return 0

        left = [1] * n
        right = [1] * n

        # Left to Right
        for i in range(1, n):
            if arr[i] > arr[i-1]:
                left[i] = left[i-1] + 1

        # Right to Left
        for j in range(n-2, -1, -1):
            if arr[j] > arr[j+1]:
                right[j] = right[j+1] + 1

        total = 0
        for i in range(n):
            total += max(left[i], right[i])

        return total


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    s = Solution()
    print(s.candy(arr))
