// #Question:-

// Link-> https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28

// Date-> 28/03/25

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Cell {
    public:
        int row;
        int col;
        int value;
        Cell(int r, int c, int v) : row(r), col(c), value(v) {}
    };
    
    class Query {
    public:
        int index;
        int value;
        Query(int i, int v) : index(i), value(v) {}
    };
    
    bool operator<(const Query& a, const Query& b) { return a.value < b.value; }
    
    bool operator<(const Cell& a, const Cell& b) { return a.value < b.value; }
    
    class UnionFind {
    private:
        vector<int> parent;
        vector<int> size;
    
    public:
        UnionFind(int n) : parent(vector<int>(n, -1)), size(vector<int>(n, 1)) {}
    
        int find(int node) {
            if (parent[node] < 0) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }
    
        bool union_nodes(int nodeA, int nodeB) {
            int rootA = find(nodeA);
            int rootB = find(nodeB);
            if (rootA == rootB) {
                return false;
            }
            if (size[rootA] > size[rootB]) {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            } else {
                parent[rootA] = rootB;
                size[rootB] += size[rootA];
            }
            return true;
        }
    
        int getSize(int node) { return size[find(node)]; }
    };
    
    const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
    const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};
    
    class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int rowCount = grid.size(), colCount = grid[0].size();
            int totalCells = rowCount * colCount;
    
            vector<Query> sortedQueries;
            for (int i = 0; i < queries.size(); i++) {
                sortedQueries.push_back(Query(i, queries[i]));
            }
            sort(sortedQueries.begin(), sortedQueries.end());
    
            vector<Cell> sortedCells;
            for (int row = 0; row < rowCount; row++) {
                for (int col = 0; col < colCount; col++) {
                    sortedCells.push_back(Cell(row, col, grid[row][col]));
                }
            }
    
            sort(sortedCells.begin(), sortedCells.end());
    
            UnionFind uf = UnionFind(totalCells);
            vector<int> result(queries.size());
            int cellIndex = 0;
    
            for (Query query : sortedQueries) {
                
                while (cellIndex < totalCells &&
                       sortedCells[cellIndex].value < query.value) {
                    int row = sortedCells[cellIndex].row;
                    int col = sortedCells[cellIndex].col;
                    int cellId = row * colCount + col;
    
                    
                    for (int direction = 0; direction < 4; direction++) {
                        int newRow = row + ROW_DIRECTIONS[direction];
                        int newCol = col + COL_DIRECTIONS[direction];
    
                        
                        if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                            newCol < colCount &&
                            grid[newRow][newCol] < query.value) {
                            uf.union_nodes(cellId, newRow * colCount + newCol);
                        }
                    }
                    cellIndex++;
                }
                
                result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
            }
            return result;
        }
    };