class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        """
        :type s: str
        :type t: str
        :type maxCost: int
        :rtype: int
        """
        
        change = 0
        n = len(s)
        cost = [abs(ord(s[i])-ord(t[i])) for i in range(n)]
        length = 0
        s = 0
        print(cost)
        i = 0
        while i < n:
            s += cost[i]
            length += 1
            print(s, length)
            while s > maxCost :
                s -= cost[i-length+1]
                print(s)
                length -= 1
            change = max(change, length)
            i += 1
        return change
                
            
        
