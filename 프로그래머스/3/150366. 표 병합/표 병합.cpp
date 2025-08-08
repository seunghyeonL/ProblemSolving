#include <string>
#include <vector>

using namespace std;

vector<string> strSplit(string str, char seperator = ' ')
{
    vector<string> result;

    string buffer{};

    for (char chr : str)
    {
        if (chr == seperator)
        {
            result.push_back(buffer);
            buffer.clear();
            continue;
        }

        buffer.push_back(chr);
    }

    if (!buffer.empty())
    {
        result.push_back(buffer);
    }

    return result;
}

class Table
{
private:
    int size;
    vector<vector<string>> data;
    vector<vector<string *>> p;
    vector<string> prints;

    // Printc<vector<vector<string>>, Printc<vector<string>>> printc;

public:
    Table() : size(50), data(size, vector<string>(size)), p(size, vector<string *>(size))
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                p[i][j] = &data[i][j];
            }
        }
    }

    void update(int r, int c, string value)
    {
        r -= 1;
        c -= 1;

        *p[r][c] = value;
    }

    void update(string value1, string value2)
    {
        if (value1 == value2)
            return;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (*p[i][j] == value1)
                    *p[i][j] = value2;
            }
        }
    }

    void merge(int r1, int c1, int r2, int c2)
    {
        r1 -= 1;
        c1 -= 1;
        r2 -= 1;
        c2 -= 1;

        string *mp1 = p[r1][c1];
        string *mp2 = p[r2][c2];

        if (mp1 == mp2)
            return;

        string d = (*mp1).empty() ? *mp2 : *mp1;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (p[i][j] == mp2)
                {
                    p[i][j] = mp1;
                    data[i][j] = string{};
                }
            }
        }

        *mp1 = d;
    }

    void unmerge(int r, int c)
    {
        r -= 1;
        c -= 1;

        string *mp = p[r][c];
        string d = *mp;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (p[i][j] == mp)
                {
                    p[i][j] = &data[i][j];
                    data[i][j] = string{};
                }
            }
        }

        data[r][c] = d;
    }

    void print(int r, int c)
    {
        r -= 1;
        c -= 1;

        if ((*p[r][c]).empty())
            prints.push_back("EMPTY");
        else
            prints.push_back(*p[r][c]);
    }

    void operate(string command)
    {
        vector<string> cmdstr = strSplit(command);

        string op = cmdstr[0];

        if (op == "UPDATE")
        {
            if (cmdstr.size() == 4)
            {
                int r = stoi(cmdstr[1]);
                int c = stoi(cmdstr[2]);
                string value = cmdstr[3];

                update(r, c, value);
            }
            else
            {
                string value1 = cmdstr[1];
                string value2 = cmdstr[2];

                update(value1, value2);
            }
        }
        else if (op == "MERGE")
        {
            int r1 = stoi(cmdstr[1]);
            int c1 = stoi(cmdstr[2]);
            int r2 = stoi(cmdstr[3]);
            int c2 = stoi(cmdstr[4]);

            merge(r1, c1, r2, c2);
        }
        else if (op == "UNMERGE")
        {
            int r = stoi(cmdstr[1]);
            int c = stoi(cmdstr[2]);

            unmerge(r, c);
        }
        else if (op == "PRINT")
        {
            int r = stoi(cmdstr[1]);
            int c = stoi(cmdstr[2]);

            print(r, c);
        }

        // printc(data);
    }

    vector<string> getPrints()
    {
        return prints;
    }
};

vector<string> solution(vector<string> commands)
{
    Table table;

    for (const string &command : commands)
    {
        table.operate(command);
    }

    return table.getPrints();
}