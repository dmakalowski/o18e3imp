// o18e3imp.cpp : This is a solution for XVIII IT Olympiad task: Impreza.
// It mainly works on a principle that we delete from the list those friends that doesn't know each other.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int friends, connections, friend1, friend2;
    cin >> friends;
    cin >> connections;
    vector<vector<bool>> adjacencyMatrix(friends, vector<bool>(friends, false));
    vector<bool> erased(friends, false);
    for (int i = 0; i < connections; i++)
    {
        cin >> friend1;
        cin >> friend2;
        adjacencyMatrix[--friend1][--friend2] = true;
        adjacencyMatrix[friend2][friend1] = true;
    }
    for (int i = 0; i < friends; i++)
    {
        for (int j = i + 1; j < friends && !erased[i]; j++)
        {
            if (!adjacencyMatrix[i][j] && !erased[j])
            {
                erased[i] = true;
                erased[j] = true;
            }
        }
    }
    int leftResult = (friends / 3); //You always need to provide only friends/3 friends on the output.
    for (int i = 0; leftResult && i < friends; i++)
    {
        if (!erased[i])
        {
            cout << i + 1 << " ";
            leftResult--;
        }
    }
    cout << endl;
    return 0;
}
