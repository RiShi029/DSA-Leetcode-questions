//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool valid(int i,int j,vector<vector<int>>&matrix)
{
    if(i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size() && matrix[i][j]==0)
    {
        return true;
    }
    
    return false;
}
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=0;
        int r[]={0,0,1,-1,1,-1,-1,1};
        int c[]={1,-1,0,0,1,-1,1,-1};
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                int zeros=0;
                if(matrix[i][j]==1)
                {
                    for(int k=0;k<8;k++)
                    {
                        if(valid(i+r[k],j+c[k],matrix))
                        {
                            zeros++;
                        }
                    }
                    
                    if(zeros%2==0 && zeros>0)
                    {
                        ans++;
                    }
                   
                }
                

            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends