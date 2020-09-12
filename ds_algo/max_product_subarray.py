class Solution:
    def maxproduct(self, nums):
        #first if a positve number is found then multiply with max number
        #if a negative number is found then multiply with min number
        #if i find a +ve number then 
        max_product = 0 
        max_product_running = 1
        min_product_running = 1
        n = len(nums)
        for i in range(n):
            if nums[i] >=0 :
                max_product_running = max(max_product_running*nums[i], nums[i])
                min_product_running = min(min_product_running*nums[i], nums[i])
            else :
                temp = max_product_running
                max_product_running = max(min_product_running*nums[i], nums[i])
                min_product_running = min(temp*nums[i], nums[i])

            max_product = max(max_product, max(max_product_running, min_product_running))

        return max_product

sol = Solution()
print(sol.maxproduct([2,3,-1,-2]))
print(sol.maxproduct([-1,0,-2]))
print(sol.maxproduct([1,2,0]))
            
