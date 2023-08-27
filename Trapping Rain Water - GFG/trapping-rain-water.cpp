//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n){
        // code here
        int left=0,right=n-1;
        int l=0,r=0;
        long long ans=0;
        while(left<=right){
            if(a[left]<=a[right]){
                // left may be contrtibuting
                l=max(l,a[left]);
                ans+=l-a[left];
                left++; 
            }
            else if(a[left]>a[right]){
                r=max(r,a[right]);
                ans+=r-a[right];
                right--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends