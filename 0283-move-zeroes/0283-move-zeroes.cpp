class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();

        for(int j {0} ;j<n; j++){
            for(int i {0}; i<n-1; i++){
                if(arr[i] == 0){
                    int temp = arr[i];
                    arr[i] =  arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
        for(int i {0}; i<n; i++){
            cout<<arr[i];
        }

    }
};