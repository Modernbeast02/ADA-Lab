#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<vector<vector<char>>> ans;

bool IsPossibleToPlaceQueen(ll row, ll column, ll n, vector<ll> &col, vector<ll> &leftDiagonal, vector<ll> &rightDiagional)
{
    if (col[column] == 1 || rightDiagional[column + row] == 1 || leftDiagonal[n + 1 + column - row] == 1)
    {
        return false;
    }
    return true;
}
void FindAns(ll index, ll n, vector<vector<char>> &grid, vector<ll> &col, vector<ll> &leftDiagonal, vector<ll> &rightDiagional)
{
    if (index == n)
    {
        ans.push_back(grid);
        return;
    }
    for (int column = 0; column < n; column++)
    {
        if (IsPossibleToPlaceQueen(index, column, n, col, leftDiagonal, rightDiagional))
        {
            grid[index][column] = 'Q';
            col[column] = 1;
            rightDiagional[column + index] = 1;
            leftDiagonal[n + 1 + column - index] = 1;
            FindAns(index + 1, n, grid, col, leftDiagonal, rightDiagional);
            grid[index][column] = '.';
            col[column] = 0;
            rightDiagional[column + index] = 0;
            leftDiagonal[n + 1 + column - index] = 0;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<ll> col(n, 0), leftDiagonal(2 * n, 0), rightDiagional(2 * n, 0);
    FindAns(0, n, grid, col, leftDiagonal, rightDiagional);
    cout << "Answer = " << ans.size() << endl;
    for (auto grids : ans)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grids[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
