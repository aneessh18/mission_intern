def findnum(nums, N, K, curnum, num):
    if curnum < 0 or curnum > 9:
        return 
    if N == 0:
        nums.append(num*10+curnum)
    else :
        for i in range(0,10):
            if abs(curnum-i) == K:
                findnum(nums, N-1, K, i, num*10+curnum)

class Solution:
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        
        nums = []
        for i in range(0,10):
            if N!=1 :
                if i != 0:
                    findnum(nums, N-1, K, i, 0)
            else :
                nums.append(i)
        return nums