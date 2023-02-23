The first is the standard Kahn"s Algorithm:
Pseudocode:
- Construct adjacency list graph and inDegrees array
- Create two arrays S and L both empty initially
- Put all nodes of `supplies` in S
- While S is not empty 
	- Pop a node from S and insert in L
	- Traverse through adjacency list of this node and for each destination node in this adjacency list:
	  - Decrement `inDegree` of this destination node. This is equivalent to breaking an edge
	  - if `InDegree` is 0 then insert it into S

Notice that at any point in the pseudocode, S consists of only nodes with zero `inDegree`.

<iframe src="https://leetcode.com/playground/8NcX3sbt/shared" frameBorder="0" width="1000" height="800"></iframe>

Time Complexity: O(n)
Space Complexity: O(n)

The second is a cheat way to do topological sort in `O(n^2)` worse case time  complexity (You just keep traversing through the graph again and again till no new node is found). This should throw TLE in a proper contest/interview but surprisingly for me passed all the tests.
<iframe src="https://leetcode.com/playground/Eyhyenv8/shared" frameBorder="0" width="1000" height="400"></iframe>