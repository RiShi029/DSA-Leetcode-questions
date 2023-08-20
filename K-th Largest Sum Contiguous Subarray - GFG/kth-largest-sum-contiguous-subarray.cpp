//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int K){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
	for(int i=0;i<N;i++)
	{
		int sum=0;
		for(int j=i;j<N;j++)
		{
			sum+=arr[j];
			if(min_heap.size()<K)
			{
				min_heap.push(sum);
			}
			else{
				if(sum>min_heap.top())
				{
					min_heap.pop();
					min_heap.push(sum);
				}
			}
		}

	}
	return min_heap.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends