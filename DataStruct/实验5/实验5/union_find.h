#pragma once
//
// Created by Ì·Ïþ·æ on 2022/5/15.
//

#ifndef ALGORITHM5_UNION_FIND_H
#define ALGORITHM5_UNION_FIND_H

#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int part;

    UnionFind(int N) :size(vector<int>(N, 1)), parent(vector<int>(N)), n(N), part(N)
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }



    int Find(int p)
    {
        //if (parent[x] == x)
        //    return x;
        //return parent[x] = Find(parent[x]);
        //return Find(parent[x]);
        if (p != parent[p])
            parent[p] = Find(parent[p]);
        return parent[p];
    }

    bool Union(int x, int y)
    {
        int root_x = Find(x);
        int root_y = Find(y);
        if (root_x == root_y)
            return false;
        if (size[root_x] > size[root_y])
            swap(root_x, root_y);
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
        part--;
        return true;
    }
};
#endif //ALGORITHM5_UNION_FIND_H
