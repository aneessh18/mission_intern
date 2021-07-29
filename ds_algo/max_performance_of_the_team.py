import heapq
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        
        efficiency_speed = [[efficiency[i], speed[i]] for i in range(len(speed))]
        efficiency_speed.sort(reverse=True) #sort the list in descending order of efficiency
        speed_sum = 0
        speed_heap = []
        max_perf = 0
        for i in range(len(efficiency_speed)):
            speed_sum += efficiency_speed[i][1]
            heapq.heappush(speed_heap, efficiency_speed[i][1])
            if len(speed_heap)>k:
                speed_sum -= heapq.heappop(speed_heap)

            max_perf =max(max_perf, speed_sum*efficiency_speed[i][0])
        
        return max_perf%(10**9+7)
