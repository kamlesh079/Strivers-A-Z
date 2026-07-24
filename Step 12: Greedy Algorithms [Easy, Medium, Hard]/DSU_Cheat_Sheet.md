# DSU (Disjoint Set Union / Union-Find) Cheat Sheet

## What is DSU?

DSU is a data structure that efficiently maintains **groups (sets)** of
elements.

It supports two operations:

-   **find(x)** → Returns the leader (representative) of the set
    containing `x`.
-   **union(a, b)** → Merges the sets containing `a` and `b`.

------------------------------------------------------------------------

## Visualization

Initially:

``` text
1   2   3   4

parent:
1->1
2->2
3->3
4->4
```

After `union(1,2)`:

``` text
    1
    |
    2
```

After `union(2,3)`:

``` text
      1
     / \
    2   3
```

All belong to the same set.

------------------------------------------------------------------------

# Parent Array

Initially

``` cpp
parent[i] = i;
```

Meaning every node is its own leader.

------------------------------------------------------------------------

# Find Operation

Without Path Compression

``` cpp
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}
```

With Path Compression (Recommended)

``` cpp
int find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}
```

### Why Path Compression?

Before:

``` text
1
|
2
|
3
|
4
|
5
```

After one `find(5)`:

``` text
      1
   / /|\ \
  2 3 4 5
```

Future finds become almost O(1).

------------------------------------------------------------------------

# Union Operation

``` cpp
void Union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if(leaderA != leaderB)
        parent[leaderB] = leaderA;
}
```

**Important**

Never do:

``` cpp
parent[b] = a;
```

Always connect the **leaders**.

------------------------------------------------------------------------

# Union by Size (Recommended)

``` cpp
vector<int> parent, size;

void makeSet(int n)
{
    parent.resize(n + 1);
    size.assign(n + 1, 1);

    for(int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x)
{
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a == b)
        return;

    if(size[a] < size[b])
        swap(a, b);

    parent[b] = a;
    size[a] += size[b];
}
```

------------------------------------------------------------------------

# Complete DSU Template

``` cpp
class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};
```

Usage

``` cpp
DSU dsu(10);

dsu.Union(1,2);
dsu.Union(2,3);

if(dsu.find(1) == dsu.find(3))
    cout << "Same Set";
```

------------------------------------------------------------------------

# Time Complexity

  Operation   Complexity
  ----------- -------------
  find()      O(alpha(N))
  union()     O(alpha(N))

`alpha(N)` (Inverse Ackermann Function) grows so slowly that it is
effectively constant.

------------------------------------------------------------------------

# Where is DSU Used?

-   Connected Components
-   Cycle Detection (Undirected Graph)
-   Kruskal's MST
-   Number of Provinces
-   Accounts Merge
-   Redundant Connection
-   Job Sequencing (Modified DSU)
-   Dynamic Connectivity

------------------------------------------------------------------------

# Job Sequencing Trick

In normal DSU:

``` cpp
parent[leaderB] = leaderA;
```

In Job Sequencing:

``` cpp
parent[slot] = find(slot - 1);
```

Meaning:

> Slot `slot` is occupied, so next time redirect to the next free slot
> on the left.

Example

``` text
Slots: 1 2 3 4

Take slot 3

parent[3] = find(2)

Now

find(3) -> 2
```

No linear search is needed.

------------------------------------------------------------------------

# Quick Revision

-   `parent[i] = i` → Every node starts in its own set.
-   `find(x)` → Returns the representative (leader).
-   `union(a,b)` → Merge the two sets.
-   Always union **leaders**, not raw nodes.
-   Use **Path Compression**.
-   Use **Union by Size** or **Union by Rank**.
-   Combined complexity is almost O(1) per operation.
