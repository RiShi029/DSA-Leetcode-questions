//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class Node{
    public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col)
    {
        this->data=data;
        i=row;
        j=col;
    }
};
class compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }

};
    vector<int> mergeKArrays(vector<vector<int>> kArrays, int k)
    {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

    //step1: insert first element of all arrays
    for(int i=0;i<k;i++)
    {
        Node* tmp=new Node(kArrays[i][0],i,0);
        minHeap.push(tmp);
    } 
    vector<int> ans;

    //step2 : 
    while(minHeap.size() > 0)
    {
        Node* temp=minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();
        int i=temp->i;
        int j=temp->j;

        if(j+1 < kArrays[i].size())
        {
            Node* next=new Node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends