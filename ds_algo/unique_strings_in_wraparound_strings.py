def isSubString(p):
    if len(p) == 1:
        return True
    else:
        for i in range(1, len(p)):
            if p[i-1] == 'z' and p[i] != 'a':
                return False
            elif ord(p[i])-ord(p[i-1]) != 1:
                return False
        return True
                
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        
        #whether a substring exists or not can be decided by just reading the string
        #the string should be of single character or the characters in the string should be circularly consecutive
        
        #maintain 1 pointer that just traverses through the string untill its in s
        #when its doesn't stop there
        #its time complexity is O(n^2)
        #first loop through the string 
        # 1. find the sequence
        # 2. if the string ending with the character has already been found then find the max of that
        dp = [0 for i in range(26)]
        max_len = 1
        for i in range(0, len(p)):
            if i>0 and ((ord(p[i]) -ord(p[i-1]) ==1 ) or (p[i] == 'a' and p[i-1]=='z')):
                max_len += 1
            else :
                max_len = 1
            dp[ord(p[i])-97] = max(dp[ord(p[i])-97], max_len)
        return sum(dp)
        