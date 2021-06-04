import collections 
def mutate(s, index, letter):
  list_of_letters = list(s)
  list_of_letters[index] = letter
  return "".join(list_of_letters)

class Solution:
    def openLock(self, deadends, target):
        
        visited = collections.defaultdict(bool)
        
        bfs_queue = []
        source = '0000'
        bfs_queue.append([source, 0]) #keeping track of distance from the source node
        visited[source] = True
        dialer_movements = { #record the movements for both forward and backward
          "0":["9", "1"],
          "1":["0", "2"],
          "2":["1", "3"],
          "3":["2", "4"],
          "4":["3", "5"],
          "5":["4", "6"],
          "6":["5", "7"],
          "7":["6", "8"],
          "8":["7", "9"],
          "9":["8", "0"]
        }
        while len(bfs_queue)>0:

          node_info = bfs_queue.pop(0) # get the first node

          #now push the 8 combinations for the current node
          current_node = node_info[0]
          distance_from_source_node = node_info[1]
          if current_node == target:
            return distance_from_source_node
          elif current_node in deadends:
            continue
          for index, letter in enumerate(current_node):
            forward_move, backward_move = dialer_movements[letter]
            forward_node = mutate(current_node, index, forward_move)
            backward_node = mutate(current_node, index, backward_move)
            if not visited[forward_node]:
              visited[forward_node] = True
              bfs_queue.append[[forward_node, distance_from_source_node+1]]
            if not visited[backward_node]:
              visited[backward_node] = True
              bfs_queue.append([[backward_node, distance_from_source_node+1]])

          

        return -1 

