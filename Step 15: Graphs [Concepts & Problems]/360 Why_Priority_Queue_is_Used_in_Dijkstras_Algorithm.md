# Why Priority Queue is Used in Dijkstra's Algorithm

## Idea

Dijkstra's algorithm is a **greedy algorithm**.

At every step, it chooses the **unvisited vertex with the minimum
tentative distance** from the source and relaxes all of its outgoing
edges.

A **priority queue (min-heap)** helps us retrieve this minimum-distance
vertex efficiently.

------------------------------------------------------------------------

## Why Not Use a Normal Queue?

A normal queue processes vertices in **FIFO (First In, First Out)**
order.

Dijkstra requires vertices to be processed in **minimum-distance-first**
order, **not** the order in which they were discovered.

Example:

``` text
      10
0 ---------> 1
 \ 
  \1
   \
    v
    2 ----1----> 1
```

From source `0`:

-   Direct path to `1` = 10
-   Path through `2` = 2

A normal queue may process vertex `1` before discovering the shorter
path through `2`.

------------------------------------------------------------------------

## Why a Priority Queue?

A priority queue always removes the element with the **smallest
distance**.

``` cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

Each element is stored as:

``` cpp
{distance, node}
```

The node with the smallest distance is always processed first.

------------------------------------------------------------------------

## Working

1.  Initialize all distances to `INF`.
2.  Set `dist[src] = 0`.
3.  Push `{0, src}` into the priority queue.
4.  Repeatedly:
    -   Pop the node with the minimum distance.
    -   Relax all adjacent edges.
    -   If a shorter path is found, update the distance and push the new
        pair into the priority queue.

------------------------------------------------------------------------

## Why Are Duplicate Entries Allowed?

The C++ priority queue **cannot decrease a key**.

Suppose:

``` text
Old distance = 10
New distance = 6
```

Instead of updating the old entry, we simply push:

``` text
(10, node)
(6, node)
```

Later:

``` cpp
if (d > dist[node]) continue;
```

skips the stale entry.

------------------------------------------------------------------------

## Time Complexity

Using a min-heap:

-   Push: `O(log V)`
-   Pop: `O(log V)`

Overall:

``` text
O((V + E) log V)
```

------------------------------------------------------------------------

## Why Not Use a Set?

A `set` can erase the old `{distance, node}` pair before inserting the
updated one, so stale entries are avoided.

Both implementations have the same asymptotic complexity:

``` text
O((V + E) log V)
```

However, in practice:

-   `priority_queue` is usually faster due to lower constant factors.
-   `set` is useful for understanding the decrease-key concept.

------------------------------------------------------------------------

## Memory Trick

  Data Structure   Processing Order
  ---------------- ------------------------
  Queue            FIFO
  Stack            LIFO
  Priority Queue   Minimum Distance First

------------------------------------------------------------------------

## A-Z Sheet Notes

``` cpp
// Dijkstra uses a Min-Heap (Priority Queue)
// -> Always processes the node with minimum distance.
// -> Supports Greedy choice.
// -> Duplicate entries are allowed.
// -> Skip stale entries using:
//    if (d > dist[node]) continue;
// -> TC: O((V + E) log V)
// -> SC: O(V + E)
```
