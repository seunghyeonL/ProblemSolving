#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

void dfs(const vector<vector<int>> &users, const vector<int> &emoticons, vector<int> &discounts, int idx, pair<int, int> &p)
{
    if(idx == emoticons.size()) 
    {
        int subscribeNum  = 0;
        int sales = 0;
        
        for(auto user : users)
        {
            int minDiscount = user[0];
            int minSubPrice = user[1];
            int totalPrice = 0;
            
            for(int i = 0 ; i < emoticons.size() ; i++)
            {
                // cout << "minDiscount: " << minDiscount << " discounts" << i << " "<< discounts[i] << '\n';
                if(discounts[i] >= minDiscount) 
                {
                    totalPrice += emoticons[i] * (100 - discounts[i]) / 100;
                    
                }
                // cout << "totalPrice: " << totalPrice << '\n';
            }
            // cout << "totalPrice: " << totalPrice << '\n';
            if(totalPrice >= minSubPrice) subscribeNum++;
            else sales += totalPrice;
            
            // cout << "discounts: \n";
            // cout << "subscribeNum: " << subscribeNum << " sales: " << sales << "\n";
        }
        
        // for(int el : discounts)
        // {
        //     cout << el << " ";    
        // }
        // cout << '\n';
        pair<int, int> curP = make_pair(subscribeNum, sales);
        if (p < curP) p = curP;
        // cout << "p: (" << p.first << ", " << p.second << ")\n";
        return;
    }
    
    for(int discount = 10 ; discount <= 40 ; discount += 10)
    {
        discounts.push_back(discount);
        dfs(users, emoticons, discounts, idx + 1, p);
        discounts.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> discounts;
    pair<int, int> p(0, 0); // 구독자수, 판매액
    
    dfs(users, emoticons, discounts, 0, p);
    
    return {p.first, p.second};
}