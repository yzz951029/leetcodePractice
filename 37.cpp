#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board, 0);
	}

	bool solve(vector<vector<char>> &board, int pos)
	{
		if (pos == 81)
			return true;
		int row = pos / 9;
		int col = pos % 9;
		if (board[row][col] == '.')
		{
			for (int i = 1; i <= 9; i++)
			{
				board[row][col] = i + '0';
				if (check(board, pos))
				{
					if (solve(board, pos + 1))
						return true;
				}
				board[row][col] = '.';
			}
		}
		else
		{
			if (solve(board, pos + 1))
				return true;
		}
		return false;	
	}

	bool check(vector<vector<char>> &board, int pos)
	{
		int row = pos / 9;
		int col = pos % 9;
		if (checkRow(board, row, col) && checkCol(board, row, col) && checkBlock(board, row, col))
			return true;
		else
			return false;
	}
	
	bool checkRow(vector<vector<char>> &board, int row, int col)
	{
		for (int i = 0; i < 9; i++)
		{
			if (col == i)
				continue;
			if (board[row][i] == board[row][col])
			{
				return false;
			}
		}
		return true;
	}
	bool checkCol(vector<vector<char>> &board, int row, int col)
	{
		for (int i = 0; i < 9; i++)
		{
			if (row == i)
				continue;
			if (board[i][col] == board[row][col])
			{
				return false;
			}
		}
		return true;
	}
	bool checkBlock(vector<vector<char>> &board, int row, int col)
	{
		int rowS;
		int colS;
		if (row >= 0 && row <= 2)
			rowS = 0;
		if (row >= 3 && row <= 5)
			rowS = 3;
		if (row >= 6)
			rowS = 6;
		if (col >= 0 && col <= 2)
			colS = 0;
		if (col >= 3 && col <= 5)
			colS = 3;
		if (col >= 6)
			colS = 6;
		for (int i = 0; i < 9; i++)
		{
			if (rowS + i / 3 == row&&colS + i % 3 == col)
				continue;
			if (board[rowS + i / 3][colS + i % 3] == board[row][col])
				return false;
		}
		return true;
	}
};