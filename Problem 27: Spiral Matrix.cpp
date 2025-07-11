class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> result;
        int i=0,j=0;
        int up=0,right=1,down=2,left=3;
        int direction=right;
        int upwall=0,downwall=row,rightwall=col,leftwall=-1;
        while(result.size()<(row*col))
        {
            if(direction==right)
            {
                while(j<rightwall)
                {
                    result.push_back(matrix[i][j]);
                    j++;
                }
                i++;j--;
                rightwall--;
                direction=down;
            }
            else if(direction==down)
            {
                while(i<downwall)
                {
                    result.push_back(matrix[i][j]);
                    i++;
                }
                i--;j--;
                downwall--;
                direction=left;
            }
            else if(direction==left)
            {
                while(j>leftwall)
                {
                    result.push_back(matrix[i][j]);
                    j--;
                }
                i--;j++;
                leftwall++;
                direction=up;
            }
            else if(direction==up)
            {
                while(i>upwall)
                {
                    result.push_back(matrix[i][j]);
                    i--;
                }
                i++;j++;
                upwall++;
                direction=right;
            }
        }
        return result;
    }
};
