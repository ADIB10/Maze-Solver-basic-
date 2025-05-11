#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int T = 1, t = 0, x = 1, y = 2, n = 0, mtx, mty;

int X = 9, Y = 23;
vector<int> tx;
vector<int> ty;
string s;

void MAP_DRAW(char map[50][50])

{
    // Print the map
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

void PATH_FINDING(char map[50][50])

{
    n = 0;
    if (map[x + 1][y] == ' ')
    {
        n++;
    }
    if (map[x - 1][y] == ' ')
    {
        n++;
    }
    if (map[x][y + 1] == ' ')
    {
        n++;
    }
    if (map[x][y - 1] == ' ')
    {
        n++;
    }
    if (n >= 2)
    {
        tx.push_back(x);
        ty.push_back(y);
    } // findng junctiuon point
    else
    {
        n = 0;
    }
}

void BACK_TRACK(char map[50][50])

{
    while (true)
    {
        int b = s.size() - 1;
        cout << s << endl;
        if (s[b] == 'd')
        {
            x--;
            s.resize(b);
        }
        if (s[b] == 'u')
        {
            x++;
            s.resize(b);
        }
        if (s[b] == 'r')
        {
            y--;
            s.resize(b);
        }
        if (s[b] == 'l')
        {
            y++;
            s.resize(b);
        }
        if (x == tx.back() && y == ty.back())
        {
            tx.pop_back();
            ty.pop_back();
            break;
        }
    }
}

void SOLVER(char map[50][50])

{
    x = mtx;
    y = mty;
    map[x][y] = char(219);
    system("cls");
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'd')
        {
            x++;
        }
        if (s[i] == 'u')
        {
            x--;
        }
        if (s[i] == 'r')
        {
            y++;
        }
        if (s[i] == 'l')
        {
            y--;
        }
        s[i] = ' ';
        map[x][y] = char(219);
    }
    MAP_DRAW(map);
}

void MOVE(char map[50][50])
{
    while (map[x + 1][y] == ' ' || map[x - 1][y] == ' ' || map[x][y + 1] == ' ' || map[x][y - 1] == ' ')
    {
        while (map[x + 1][y] == ' ')
        {
            if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || map[x][y + 1] == '0' || map[x][y - 1] == '0')
            {
                t = 1;
                break;
            }
            PATH_FINDING(map);
            x++;
            map[x][y] = '.';
            s = s + "d";
        }

        while (map[x - 1][y] == ' ')
        {
            if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || map[x][y + 1] == '0' || map[x][y - 1] == '0')
            {
                t = 1;
                break;
            }
            PATH_FINDING(map);
            x--;
            map[x][y] = '.';
            s = s + "u";
        }

        while (map[x][y + 1] == ' ')
        {
            if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || map[x][y + 1] == '0' || map[x][y - 1] == '0')
            {
                t = 1;
                break;
            }
            PATH_FINDING(map);
            y++;
            map[x][y] = '.';
            s = s + "r";
        }

        while (map[x][y - 1] == ' ')
        {
            if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || map[x][y + 1] == '0' || map[x][y - 1] == '0')
            {
                t = 1;
                break;
            }
            PATH_FINDING(map);
            y--;
            map[x][y] = '.';
            s = s + "l";
        }
        if (t == 1)
        {
            break;
        }
    }
    system("cls");
    /// MAP_DRAW(map);map analysiing
    // cout<<tx.back()<<ty.back()<<endl<<x<<y<<endl;

    if (map[x + 1][y] == '0' || map[x - 1][y] == '0' || map[x][y + 1] == '0' || map[x][y - 1] == '0')
    {
        t = 1;
    }
    if (t == 0)
    {
        if (map[x + 1][y] != ' ' && map[x - 1][y] != ' ' && map[x][y + 1] != ' ' && map[x][y - 1] != ' ') // whent it comes to an dead end
        {
            BACK_TRACK(map);
        }
        // cout<<s<<endl;//for path analysing1
    }
}

int main()
{

    char map[50][50] = {
        "########################X",
        "#       #   # # # # # ##1",
        "# # # # # ###   # # #  #2",
        "# # # # #   # # # # # ##3",
        "# #   # ###   #   # #  #4",
        "# # #       #   # # ## #5",
        "# # # ### # # # # #    #6",
        "##  #   ### # #   #### #7",
        "#  ###    #   #        #8",
        "########################9",
    };
    /// Y12345678911111111112222
    ///           01234567890123
    MAP_DRAW(map);
    cout << "End Point:Y & X >";
    cin >> x >> y;
    map[x][y] = '0';
    cout << "Y & X axis >";
    cin >> x >> y;
    system("cls");
    MAP_DRAW(map);
    system("pause>nul");
    mtx = x;
    mty = y;
    while (T > 0)
    {
        system("cls");
        // to naalyse every movement
        /// MAP_DRAW(map);
        MOVE(map);
        if (t == 1)
        {
            break;
        }
        // system("pause>nul");
    }
    {
        SOLVER(map);
    }
    system("pause>nul");

    return 0;
}
