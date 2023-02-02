#include <set>
#include <queue>
#include <vector>
#include <fstream>
#include <limits.h>
#include <iostream>

using namespace std;

constexpr int N = 80;
int mat[N][N];
/*
int mat[N][N] = {{131, 673, 234, 103, 18},
                 {201, 96 , 342, 965, 150},
                 {630, 803, 746, 422, 111},
                 {537, 699, 497, 121, 956},
                 {805, 732, 524, 37,  331}};
                 */
int soln[N][N];

set<pair<int, int>> visited;

//DFS
/*
int min_path_sum(int i, int j)
{
	if (i == N-1 && j == N-1)
	{
		return mat[i][j];
	}

	checked[i][j] = true;
	int up = INT_MAX, down = INT_MAX, right = INT_MAX, left = INT_MAX;
	if(i-1 >= 0)
	{
		if(!checked[i-1][j])
			up = min_path_sum(i-1, j);	
	}

	if(i+1 < N)
	{
		if(!checked[i+1][j])
			down = min_path_sum(i+1, j);
	}

	if(j+1 < N && !checked[i][j+1])
		right = min_path_sum(i, j+1);

    if(j-1 >= 0 && !checked[i][j-1])
        left = min_path_sum(i, j-1);

	checked[i][j] = false;

    int minimum = min(up, min(down, min(left, right)));
    if(minimum == INT_MAX)
        return INT_MAX;

    return mat[i][j] + minimum;
}
*/

pair<int, int> minDisV()
{
    int min_val = INT_MAX;
    auto min_index = make_pair(-1, -1);
    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<N; ++j)
        {
            if(soln[i][j] < min_val)
            {
                if(visited.find(make_pair(i, j)) == visited.end())
                {
                    min_val = soln[i][j];
                    min_index = make_pair(i, j);
                }
            }
        }
    }
    return min_index;
}

void dijsktra()
{
    //Pair of distance and position(used to pick the one with min distance form src)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(mat[0][0], make_pair(0, 0)));
    while(pq.size() > 0)
    {
        auto v = pq.top().second;
        pq.pop();

        if(v.first-1 >= 0)
        {
            if(visited.find(make_pair(v.first-1, v.second)) == visited.end())
            {
                int new_dis = mat[v.first-1][v.second] + soln[v.first][v.second];
                if(new_dis < soln[v.first-1][v.second])
                {
                    soln[v.first-1][v.second] = min(soln[v.first-1][v.second], new_dis);
                    pq.push(make_pair(soln[v.first-1][v.second], make_pair(v.first-1, v.second)));
                }
            }
        }

        if(v.first+1 < N)
        {
            if(visited.find(make_pair(v.first+1, v.second)) == visited.end())
            {
                if(visited.find(make_pair(v.first+1, v.second)) == visited.end())
                {
                    int new_dis = mat[v.first+1][v.second] + soln[v.first][v.second];
                    if(new_dis < soln[v.first+1][v.second])
                    {
                        soln[v.first+1][v.second] = min(soln[v.first+1][v.second], new_dis);
                        pq.push(make_pair(soln[v.first+1][v.second], make_pair(v.first+1, v.second)));
                    }
                }
            }
        }

        if(v.second-1 >= 0)
        {
            if(visited.find(make_pair(v.first, v.second-1)) == visited.end())
            {
                if(visited.find(make_pair(v.first, v.second-1)) == visited.end())
                {
                    int new_dis = mat[v.first][v.second-1] + soln[v.first][v.second];
                    if(new_dis < soln[v.first][v.second-1])
                    {
                        soln[v.first][v.second-1] = min(soln[v.first][v.second-1], new_dis);
                        pq.push(make_pair(soln[v.first][v.second-1], make_pair(v.first, v.second-1)));
                    }
                }
            }
        }

        if(v.second+1 < N)
        {
            if(visited.find(make_pair(v.first, v.second+1)) == visited.end())
            {
                if(visited.find(make_pair(v.first, v.second+1)) == visited.end())
                {
                    int new_dis = mat[v.first][v.second+1] + soln[v.first][v.second];
                    if(new_dis < soln[v.first][v.second+1])
                    {
                        soln[v.first][v.second+1] = min(soln[v.first][v.second+1], new_dis);
                        pq.push(make_pair(soln[v.first][v.second+1], make_pair(v.first, v.second+1)));
                    }
                }
            }
        }
        visited.insert(v);
    }
}

int main()
{
	ifstream file("file.txt");
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int temp;
			file >> temp;

			if (j != 79)
			{
				char c;
				file >> c;
			}

            soln[i][j] = INT_MAX;
			mat[i][j] = temp;
		}
	}
	file.close();

/*
	for(int i = 0; i<N; ++i)
	{
		for(int j = 0; j<N; ++j)
		{
            soln[i][j] = INT_MAX;
		}
	}
    */
    soln[0][0] = mat[0][0];

    dijsktra();
    /*
    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<N; ++j)
            cout << soln[i][j] << " ";
        cout << endl;
    }
    */
    cout << soln[N-1][N-1] << endl;
}