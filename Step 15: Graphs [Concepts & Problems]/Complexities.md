# Graph Algorithms Cheat Sheet (Time & Space Complexity)

Let:
- **V** = Number of vertices
- **E** = Number of edges

---

# Graph Traversal

| Algorithm | Time | Space | Notes |
|-----------|------|-------|------|
| BFS | O(V + E) | O(V) | Shortest path in unweighted graph |
| DFS (Recursive) | O(V + E) | O(V) | Traversal, cycle detection |
| DFS (Iterative) | O(V + E) | O(V) | Uses stack |

---

# Connectivity

| Algorithm | Time | Space | Notes |
|-----------|------|-------|------|
| Connected Components (DFS/BFS) | O(V + E) | O(V) | Undirected graph |
| Strongly Connected Components (Kosaraju) | O(V + E) | O(V) | Directed graph |
| Strongly Connected Components (Tarjan) | O(V + E) | O(V) | Single DFS |

---

# Cycle Detection

## Undirected Graph

| Algorithm | Time | Space |
|-----------|------|-------|
| DFS + Parent | O(V + E) | O(V) |
| BFS + Parent | O(V + E) | O(V) |
| Union Find | O(E α(V)) | O(V) |

---

## Directed Graph

| Algorithm | Time | Space |
|-----------|------|-------|
| DFS + Recursion Stack | O(V + E) | O(V) |
| Kahn's Algorithm | O(V + E) | O(V) |

---

# Topological Sorting

| Algorithm | Time | Space |
|-----------|------|-------|
| Kahn's Algorithm (BFS) | O(V + E) | O(V) |
| DFS Based | O(V + E) | O(V) |

---

# Shortest Path

| Algorithm | Works On | Time | Space |
|-----------|----------|------|-------|
| BFS | Unweighted | O(V + E) | O(V) |
| 0-1 BFS | Edge weight = 0 or 1 | O(V + E) | O(V) |
| Dijkstra (Priority Queue) | Positive weights | O((V + E) log V) | O(V) |
| Bellman-Ford | Negative weights | O(VE) | O(V) |
| Floyd-Warshall | All pairs | O(V³) | O(V²) |
| Johnson's Algorithm | Sparse graph APSP | O(V² log V + VE) | O(V²) |

---

# Minimum Spanning Tree (MST)

| Algorithm | Time | Space |
|-----------|------|-------|
| Kruskal | O(E log E) | O(V) |
| Prim (Priority Queue) | O((V + E) log V) | O(V) |
| Prim (Matrix) | O(V²) | O(V²) |

---

# Union Find (Disjoint Set Union)

| Operation | Time |
|-----------|------|
| Find | O(α(V)) |
| Union | O(α(V)) |

Space: **O(V)**

*(α(V) = Inverse Ackermann Function ≈ Constant)*

---

# Bipartite Graph

| Algorithm | Time | Space |
|-----------|------|-------|
| BFS Coloring | O(V + E) | O(V) |
| DFS Coloring | O(V + E) | O(V) |

---

# Bridges & Articulation Points

| Algorithm | Time | Space |
|-----------|------|-------|
| Tarjan's Bridge Algorithm | O(V + E) | O(V) |
| Tarjan's Articulation Point | O(V + E) | O(V) |

---

# Euler Path / Circuit

| Algorithm | Time | Space |
|-----------|------|-------|
| Hierholzer's Algorithm | O(V + E) | O(E) |

---

# Hamiltonian Path/Cycle

| Algorithm | Time | Space |
|-----------|------|-------|
| Backtracking | O(N!) | O(N) |
| Bitmask DP | O(N² · 2ᴺ) | O(N · 2ᴺ) |

---

# Maximum Flow

| Algorithm | Time | Space |
|-----------|------|-------|
| Ford-Fulkerson | O(E × MaxFlow) | O(V + E) |
| Edmonds-Karp | O(VE²) | O(V + E) |
| Dinic | O(V²E) | O(V + E) |

---

# Bipartite Matching

| Algorithm | Time | Space |
|-----------|------|-------|
| Kuhn Algorithm | O(VE) | O(V) |
| Hopcroft-Karp | O(E√V) | O(V + E) |

---

# Lowest Common Ancestor (Trees)

| Algorithm | Time (Preprocessing) | Query | Space |
|-----------|----------------------|-------|-------|
| Binary Lifting | O(N log N) | O(log N) | O(N log N) |
| Euler Tour + Sparse Table | O(N log N) | O(1) | O(N log N) |

---

# Tree Algorithms

| Algorithm | Time | Space |
|-----------|------|-------|
| Tree DFS | O(N) | O(N) |
| Tree Diameter (2 DFS/BFS) | O(N) | O(N) |
| Subtree Size | O(N) | O(N) |
| Centroid Finding | O(N) | O(N) |

---

# Transitive Closure

| Algorithm | Time | Space |
|-----------|------|-------|
| Floyd-Warshall | O(V³) | O(V²) |
| DFS from Every Vertex | O(V(V + E)) | O(V) |

---

# Complexity Summary

| Problem | Best Algorithm |
|----------|---------------|
| Graph Traversal | BFS / DFS |
| Connected Components | DFS / BFS |
| Detect Cycle (Undirected) | DFS / Union Find |
| Detect Cycle (Directed) | DFS / Kahn |
| Topological Sort | Kahn / DFS |
| Unweighted Shortest Path | BFS |
| 0/1 Weighted Shortest Path | 0-1 BFS |
| Positive Weighted Shortest Path | Dijkstra |
| Negative Weights | Bellman-Ford |
| All Pairs Shortest Path | Floyd-Warshall |
| Minimum Spanning Tree | Kruskal / Prim |
| Bipartite Check | BFS / DFS Coloring |
| Bridges | Tarjan |
| Articulation Points | Tarjan |
| Strongly Connected Components | Kosaraju / Tarjan |
| Euler Circuit | Hierholzer |
| Maximum Flow | Dinic |
| Bipartite Matching | Hopcroft-Karp |
| LCA | Binary Lifting |
| Tree Diameter | Two DFS/BFS |