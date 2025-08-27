
class Solution {
  public:
    
    int countPairs(vector<int>& arr, int k) {
        int count=0;
       
        sort(arr.begin(),arr.end());
        int i=0;
        int j=1;
        while(i<arr.size() && j<arr.size()) {
            if(i!=j && arr[j]-arr[i]==k){
                count++;
                i++;
                j++;
                
            }
            else if(arr[j]-arr[i]<k){
                j++;
            }
             
            else{
                i++;
            }
            if (i==j){
                j++;
            }
        }
        return count;
    }
};