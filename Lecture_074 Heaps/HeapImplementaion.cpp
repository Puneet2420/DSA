#include<bits/stdc++.h>
using namespace std;

class Heap{
    int *nums;
    int size;
    public:
    Heap(){
        nums=new int[100];
        size=0;
    }
    // for inserting purpose
    void heapifyUp(int i){
        while(i>1){
            int parent=i/2;
            if(nums[parent]<nums[i]){
                swap(nums[i],nums[parent]);
                i=parent;
            }
            else break;
        }
    }
    // for deleting purpose
    void heapifyDown(int i){
        int largest=i;
        int left=i*2;
        int right=i*2+1;
        if(left<=size && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<=size && nums[largest]<nums[right]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapifyDown(largest);
        }
    }
    void insert(int val){
        size++;
        nums[size]=val;
        heapifyUp(size);
    }
    void deletetop(){
        if(size==0){
            cout<<"Empty heap !"<<endl;
            return;
        }
        swap(nums[size],nums[0]);
        size--;
        heapifyDown(0);
    }
    int top(){
        return nums[1];
    }
    void print(){
        cout<<"Given heap is printed below !"<<endl;
        for(int i=1;i<=size;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};

// This also works for index zero.
void heapify(vector<int>&nums,int size,int i){
        int largest=i;
        int left=i*2+1;
        int right=i*2+2;
        if(left<=size && nums[largest]<nums[left]){
            largest=left;
        }
        if(right<=size && nums[largest]<nums[right]){
            largest=right;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            heapify(nums,size,largest);
        }
    }
    void heapsort(vector<int>&nums){
        int n=nums.size()-1;
        for(int i=n/2;i>=0;i--){
            heapify(nums,n,i);
        }
        while(n>0){
            swap(nums[n],nums[0]);
            heapify(nums,n-1,0);
            n--;
        }
    }
int main(){
    // Heap heap;
    // vector<int>nums={8,7,3,2,4,2,1,5,6,8,9,100,500};
    // for(auto it:nums){
    //     heap.insert(it);
    // }
    // for(int i=0;i<7;i++){
    //     heap.deletetop();
    //     heap.print();
    // }
    // heap.print();


    vector<int>nums={1000,7,3,2,4,2,1,5,6,8,9,100,500};
    int n=nums.size();
    heapsort(nums);
    for(auto it:nums) cout<<it<<" ";
    cout<<endl;

    return 0;
}
