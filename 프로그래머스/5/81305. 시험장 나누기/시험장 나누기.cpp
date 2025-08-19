#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int p = -1;
    int l = -1;
    int r = -1;
};

int solution(int k, vector<int> num, vector<vector<int>> links)
{
    int answer = 0;
    int size = num.size();

    /*
    합이 n 보다 큰 최소 subtree를 골라서 자르기
    이걸 반복해서 k - 1 번 끊었을 때 남은 트리 합이 n이상인지 체크
    n 기준 이분탐색
    */

    vector<Node> tree(size);
    for (int v = 0; v < size; v++)
    {
        const auto &link = links[v];
        int l = link[0];
        int r = link[1];

        tree[v].l = l;
        if (l != -1)
            tree[l].p = v;

        tree[v].r = r;
        if (r != -1)
            tree[r].p = v;
    }

    int rootIdx{};
    for (int i = 0; i < size; i++)
    {
        if (tree[i].p == -1)
        {
            rootIdx = i;
            break;
        }
    }

    // n이상인 서브트리는 제거하고
    // groupNum를 늘리기
    // 제거하고 남은 서브트리의 합을 반환
    function<int(int, int, int &, int &)> check =
        [&](int idx, int n, int &groupNum, int &maxGroupSize)
    {
        int sum = num[idx];
        Node &v = tree[idx];

        priority_queue<int> pq;

        if (v.l != -1)
        {
            int leftSize = check(v.l, n, groupNum, maxGroupSize);
            pq.push(leftSize);
            sum += leftSize;
        }

        if (v.r != -1)
        {
            int rightSize = check(v.r, n, groupNum, maxGroupSize);
            pq.push(rightSize);
            sum += rightSize;
        }

        // cout << n << '\n';
        // cout << "sum1: " << sum << '\n';
        while (!pq.empty() && sum > n)
        {
            int subTreeSize = pq.top();
            pq.pop();
            maxGroupSize = max(maxGroupSize, subTreeSize);
            sum -= subTreeSize;
            groupNum++;
        }

        // cout << "sum2: " << sum << '\n';
        maxGroupSize = max(maxGroupSize, sum);

        return sum;
    };

    // cout
    // for (int i = 0; i < size; i++)
    // {
    //     Node v = tree[i];
    //     cout << v.p << ' ' << v.l << ' ' << v.r << '\n';
    // }

    int left = 1;
    int right = 1e8;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        // cout << mid << '\n';
        int groupNum = 0;
        int maxGroupSize = 0;
        check(rootIdx, mid, groupNum, maxGroupSize);

        if (groupNum >= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            answer = maxGroupSize;
        }
    }

    return answer;
}
