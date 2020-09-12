class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        
        #read the array
        #if even is found then leave it
        #if odd is found then swap with the last element and decrement the last pointer
        
        end = len(A)-1
        # 1 3 2 4
        for i in range(len(A)):
            while A[i]%2 == 1 and i<end: # A[end] is odd
                A[i], A[end] = A[end], A[i]
                print(A[i],A[end])
                end  = end - 1 if i != end else 2
        return A
        