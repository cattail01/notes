# coding=utf-8

class Solution(object):
    def canMakeArithmeticProgression(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr = sorted(arr)
        diff = abs(arr[0] - arr[1])
        for i in range(len(arr) - 1):
            if diff != abs(arr[i] - arr[i + 1]):
                return False
        return True

