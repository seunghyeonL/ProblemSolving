#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int n;
    int x;
    int left = -1;
    int right = -1;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        auto &info = nodeinfo[i];
        info.push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), [](auto a, auto b)
         { return a[1] > b[1]; });

    vector<Node> bst;
    bst.push_back({nodeinfo[0][2], nodeinfo[0][0]});

    function<void(int, int, int)> insert = [&](int n, int x, int idx)
    {
        Node node = bst[idx];
        int cn = node.n;
        int cl = node.left;
        int cr = node.right;
        int cx = node.x;

        if (cx > x)
        {
            if (cl == -1)
            {
                bst.push_back({n, x});
                bst[idx].left = bst.size() - 1;
            }
            else
            {
                insert(n, x, cl);
            }
        }
        else
        {
            if (cr == -1)
            {
                bst.push_back({n, x});
                bst[idx].right = bst.size() - 1;
            }
            else
            {
                insert(n, x, cr);
            }
        }
    };

    // Printc<vector<vector<int>>, Printc<vector<int>>> printc;
    // printc(nodeinfo);

    for (int i = 1; i < nodeinfo.size(); i++)
    {
        auto info = nodeinfo[i];
        insert(info[2], info[0], 0);
        // {
        //     for (auto node : bst)
        //     {
        //         cout << '(' << node.n << ", " << node.left << ", " << node.right << ") ";
        //     }
        //     cout << '\n';
        // }
    }

    vector<int> preOrderResult;
    vector<int> postOrderResult;

    function<void(int)> preOrder = [&](int idx)
    {
        auto node = bst[idx];
        int cl = node.left;
        int cr = node.right;
        int n = node.n;

        preOrderResult.push_back(n);
        if (cl != -1)
            preOrder(cl);
        if (cr != -1)
            preOrder(cr);
    };

    function<void(int)> postOrder = [&](int idx)
    {
        auto node = bst[idx];
        int cl = node.left;
        int cr = node.right;
        int n = node.n;

        if (cl != -1)
            postOrder(cl);
        if (cr != -1)
            postOrder(cr);
        postOrderResult.push_back(n);
    };

    preOrder(0);
    postOrder(0);

    answer.push_back(preOrderResult);
    answer.push_back(postOrderResult);

    return answer;
}