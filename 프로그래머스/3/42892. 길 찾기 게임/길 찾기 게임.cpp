#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int idx;
    int x;
    Node *left;
    Node *right;

    Node(int inIdx, int inX) : idx(inIdx), x(inX), left(nullptr), right(nullptr) {};
};

class BST
{
private:
    Node *root;

    void insertRec(int idx, int x, Node *node)
    {
        auto *cl = node->left;
        auto *cr = node->right;
        int cx = node->x;

        if (cx < x)
        {
            if (cr)
                insertRec(idx, x, cr);
            else
                node->right = new Node(idx, x);
        }
        else
        {
            if (cl)
                insertRec(idx, x, cl);
            else
                node->left = new Node(idx, x);
        }
    }

    void preOrderRec(Node *node, vector<int> &result)
    {
        auto *cl = node->left;
        auto *cr = node->right;
        int cidx = node->idx;

        result.push_back(cidx);
        if (cl)
            preOrderRec(cl, result);
        if (cr)
            preOrderRec(cr, result);
    }

    void postOrderRec(Node *node, vector<int> &result)
    {
        auto *cl = node->left;
        auto *cr = node->right;
        int cidx = node->idx;

        if (cl)
            postOrderRec(cl, result);
        if (cr)
            postOrderRec(cr, result);
        result.push_back(cidx);
    }

public:
    BST(int idx, int x)
    {
        root = new Node(idx, x);
    }

    void insert(int idx, int x)
    {
        insertRec(idx, x, root);
    }

    vector<int> preOrder()
    {
        vector<int> result;
        preOrderRec(root, result);
        return result;
    }

    vector<int> postOrder()
    {
        vector<int> result;
        postOrderRec(root, result);
        return result;
    }
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

    BST bst(nodeinfo[0][2], nodeinfo[0][0]);

    for (int i = 1; i < nodeinfo.size(); i++)
    {
        auto &info = nodeinfo[i];
        bst.insert(info[2], info[0]);
    }

    answer.push_back(bst.preOrder());
    answer.push_back(bst.postOrder());

    return answer;
}
