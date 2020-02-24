
// Leetcode : https://leetcode.com/problems/validate-binary-tree-nodes/
//
//
// What is a binary tree
// - every node has one inward edge -  < 3 outward edge
// - has one connected component
// - the root has no inward edges
// - parent child is one way


#include <vector>
#include <iostream>

using namespace std;

bool validate(int n, vector<int>& left, vector<int>& right)
{
    vector<int> parents(n,-1);

    for (int i = 0; i < n; ++i)
    {
        if (left[i] != -1)
        {
            if (parents[left[i]] != -1 || left[i] == i)
            {
                return false;
            }
            parents[left[i]] = i;
        }

        if(right[i] != -1)
        {
            if (parents[right[i]] != -1 || right[i] == i)
            {
                return false;
            }
            parents[right[i]] = i;
        }
    }

    int flag = false;
    for (int p : parents)
    {
        if (p == -1)
        {
            if (flag) return false;
            flag = true;
        } 
    }
    return flag;
}

int main()
{
    vector<int> l({1, -1, 3, -1});
    vector<int> r({2, -1,-1, -1});
    cout << "validate(4, l, r) = " << std::boolalpha << validate(4, l, r) << std::endl;

    l = vector<int>({1, -1, -1, 4, -1, -1});
    r = vector<int>({2,-1,-1,5,-1,-1});
    cout << "validate(6,l r) = " << validate(6, l, r) << std::endl;

    l = vector<int>({-1,-1});
    r = vector<int>({1,0});
    cout << "validate(2,l,r) = " << validate(2,l,r) << std::endl;
    return 0;
}
