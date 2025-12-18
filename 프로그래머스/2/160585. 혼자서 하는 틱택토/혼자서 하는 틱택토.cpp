#include <bits/stdc++.h>
using namespace std;

// 안되는 조건
// X 개수 < O 개수 - 1 || x 개수 > O 개수
// O가 완성되었는데 O 개수 != X 개수 + 1
// X가 완성되었는데 O 개수 != X 개수
// 완성된 쌍이 여러개

// O -> 0, X -> 1

const int N = 3;

int solution(vector<string> board) 
{
    int num_0 = 0;
    int num_1 = 0;
    int end_0 = 0;
    int end_1 = 0;
    
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < N ; j++)
        {
            if (board[i][j] == 'O')
                num_0++;
            else if (board[i][j] == 'X')
                num_1++;
        }
    
    if (num_1 < num_0 - 1 || num_1 > num_0)
        return 0;
    
    // 행 체크
    for (int i = 0 ; i < N ; i++)
    {
        int cn0 = 0;
        int cn1 = 0;
        for (int j = 0 ; j < N ; j++)
        {
            if (board[i][j] == 'O')
                cn0++;
            else if (board[i][j] == 'X')
                cn1++;
        }
        
        if (cn0 == N)
        {
            end_0++;
        }
        
        if (cn1 == N)
        {
            end_1++;
        }
    }
    
    // 열 체크
    for (int j = 0 ; j < N ; j++)
    {
        int cn0 = 0;
        int cn1 = 0;
        for (int i = 0 ; i < N ; i++)
        {
            if (board[i][j] == 'O')
                cn0++;
            else if (board[i][j] == 'X')
                cn1++;
        }
        
        if (cn0 == N)
        {
            end_0++;
        }
        
        if (cn1 == N)
        {
            end_1++;
        }
    }
    
    // 대각 체크
    {
        int cn0 = 0;
        int cn1 = 0;
        for (int i = 0 ; i < N ; i++)
        {
            if (board[i][i] == 'O')
                cn0++;
            else if (board[i][i] == 'X')
                cn1++;
        }
        
        if (cn0 == N)
        {
            end_0++;
        }
        
        if (cn1 == N)
        {
            end_1++;
        }
    }
    
    {
        int cn0 = 0;
        int cn1 = 0;
        for (int i = 0 ; i < N ; i++)
        {
            /*
             2 0
             1 1
             0 2
            */
            if (board[N - 1 - i][i] == 'O')
                cn0++;
            else if (board[N - 1 - i][i] == 'X')
                cn1++;
        }
        
        if (cn0 == N)
        {
            end_0++;
        }
        
        if (cn1 == N)
        {
            end_1++;
        }
    }
    
    if (end_0 && end_1)
        return 0;
    
    if (end_0 && (num_0 != num_1 + 1))
        return 0;
    
    if (end_1 && (num_0 != num_1))
        return 0;

    return 1;
}