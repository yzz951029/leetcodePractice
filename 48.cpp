class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        int size = matrix.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i;j<size;j++)
            swap(matrix[i][j],matrix[j][i]);
        }
    }
};