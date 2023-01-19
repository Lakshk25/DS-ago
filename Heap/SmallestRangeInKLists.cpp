class Solution{
    class node{
    public:
     int data;
     int row;
     int col;
     node(int data , int row , int col){
         this -> data = data;
         this -> row = row;
         this -> col = col;
     }
};

class compare{
    public:
    bool operator()(node* a , node* b){
        return a -> data > b -> data;
    }
};
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          int mini = INT_MAX;
          int maxi = INT_MIN;
          priority_queue<node* , vector<node*> , compare> minHeap;
          
          for(int i=0; i<k; i++){
              int element = KSortedArray[i][0];
              mini = min(mini , element);
              maxi = max(maxi , element);
              minHeap.push(new node(element , i , 0));
          }
          
          int start = mini , end = maxi;
          
          while(!minHeap.empty()){
              node* temp = minHeap.top();
              minHeap.pop();
              
              mini = temp -> data;
              if(maxi - mini < end - start){
                  start = mini;
                  end = maxi;
              }
              
              if(temp -> col + 1 < n){
                  maxi = max(maxi , KSortedArray[temp -> row][temp -> col + 1]);
                  minHeap.push(new node(KSortedArray[temp -> row][temp -> col + 1] , temp -> row , temp -> col+1));
              }
              else
                    break;
          }
          pair<int , int>p = make_pair(start , end);
          return p;
    }
};