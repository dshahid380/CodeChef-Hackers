# Python program to print all paths from a source to destination. 

from collections import defaultdict 

#This class represents a directed graph 
# using adjacency list representation 
class Graph: 

    def __init__(self,vertices): 
        #No. of vertices 
        self.V= vertices 
        
        # default dictionary to store graph 
        self.graph = defaultdict(list) 

    # function to add an edge to graph 
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
        self.graph[v].append(u)

    '''A recursive function to print all paths from 'u' to 'd'. 
    visited[] keeps track of vertices in current path. 
    path[] stores actual vertices and path_index is current 
    index in path[]'''
    def printAllPathsUtil(self, u, d, visited, path): 

        # Mark the current node as visited and store in path 
        visited[u]= True
        path.append(u) 

        # If current vertex is same as destination, then print 
        # current path[] 
        if u == d: 
            print(path)
            
        else: 
            # If current vertex is not destination 
            #Recur for all the vertices adjacent to this vertex 
            for i in self.graph[u]: 
                if visited[i] == False: 
                    self.printAllPathsUtil(i, d, visited, path) 
                    
        # Remove current vertex from path[] and mark it as unvisited 
        path.pop() 
        visited[u]= False


    # Prints all paths from 's' to 'd' 
    def printAllPaths(self,s, d): 

        # Mark all the vertices as not visited 
        visited =[False]*(self.V + 1) 

        # Create an array to store paths 
        path = [] 

        # Call the recursive helper function to print all paths 
        self.printAllPathsUtil(s, d,visited, path) 



# Create a graph given in the above diagram 
N = int(input())
g = Graph(N)
for _ in range(N-1):
    u, v = map(int, input().split())
    g.addEdge(u, v) 

s = 2 ; d = 3
print ("Following are all different paths from %d to %d :" %(s, d)) 
print(g.printAllPaths(4, 5)) 
#This code is contributed by Neelam Yadav 
