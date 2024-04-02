#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(const vector<vector<int>>& maze, const Point& p) {
    if (p.x < 0 || p.x >= maze.size() || p.y < 0 || p.y >= maze[0].size() || maze[p.x][p.y] == 0) {
        return false;
    }
    return true;
}

void BFS(const vector<vector<int>>& maze, Point start, Point end) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    int rowNum[] = {-1, 0, 0, 1}; // Up, Left, Right, Down
    int colNum[] = {0, -1, 1, 0};

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) {
            cout << "BFS: Found a path to the exit." << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            Point adj = {curr.x + rowNum[i], curr.y + colNum[i]};
            if (isValid(maze, adj) && !visited[adj.x][adj.y]) {
                visited[adj.x][adj.y] = true;
                q.push(adj);
            }
        }
    }

    cout << "BFS: No path found to the exit." << endl;
}

void DFS(const vector<vector<int>>& maze, Point start, Point end) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    stack<Point> s;
    s.push(start);
    visited[start.x][start.y] = true;

    int rowNum[] = {-1, 0, 0, 1}; // Up, Left, Right, Down
    int colNum[] = {0, -1, 1, 0};

    while (!s.empty()) {
        Point curr = s.top();
        s.pop();

        if (curr.x == end.x && curr.y == end.y) {
            cout << "DFS: Found a path to the exit." << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            Point adj = {curr.x + rowNum[i], curr.y + colNum[i]};
            if (isValid(maze, adj) && !visited[adj.x][adj.y]) {
                visited[adj.x][adj.y] = true;
                s.push(adj);
            }
        }
    }

    cout << "DFS: No path found to the exit." << endl;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1}
    };

    Point start = {0, 0}; // Start point of the maze
    Point end = {4, 5}; // End point (exit) of the maze

    cout << "Starting BFS..." << endl;
    BFS(maze, start, end);

    cout << "\nStarting DFS..." << endl;
    DFS(maze, start, end);

    return 0;
}
