





# given a lsit of edges and number of vertices - find the number of
# connected components there are in the graph


def num_connected_comps(edges, n):
    parents = [ i for i in range(0,n)];
    unique_vals = set()
    def find(u):
        while parents[u] != u:
            u = parents[u]
        return u

    def union(u, v):
        u = find(u)
        v = find(v)
        if u == v:
            return False
        parents[u] = v
        return True

    for e in edges:
        if union(e[1], e[0]):
            print('hello')
    print(parents)
            
def find_connected_components(edges, n):
    parents = [i for i in range(0,n)]

    def find(cur, union_list):
        root = cur
        while root != union_list[root]:
            root = union_list[root]
        while cur != root:
            nxt = union_list[cur]
            union_list[cur] = root
            cur = nxt
        return root
        
    def union(left, right, union_list):
        if left > right:
            union_list[left] = right
        else:
            union_list[right] = left
        return

    for e in edges:
        union(e[0],e[1],parents) 
    print(parents)


find_connected_components([[0,1],[2,3], [1,3]],4)
