class Solution {
    void heapify(vector<int>&nums,int n,int i){
        int largest=i;                                          
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&nums[left]>nums[largest]){
            largest=left;
        }
        if(right<n&&nums[right]>nums[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapify(nums,n,largest);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // 1st method heap sort(the best) as it is o(1) space, and o(nlog(n)) time
        // building the max-heap takes o(n)
        // the sorting phase involves n iterations each requiring o(log(n)) for heapify resulting in o(nlog(n))
        int n=nums.size();
        // bottom up approach -> take each non leaf node and heapify it
        for(int i=(n/2)-1;i>=0;i--){
            heapify(nums,n,i);
        }
        // extract elements from the heap 
        for(int i=n-1;i>=0;i--){
            swap(nums[0],nums[i]); // this extracts the first max element at the root and puts it at the end of the array
            // then runs the heapify function again with i not n where the original function uses n so this correctly doesn't take the max element into account when heapifying again
            heapify(nums,i,0);
        }
        return nums;

    } 
};
