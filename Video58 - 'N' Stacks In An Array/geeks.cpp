class kStacks {

    // main array to store elements
    int *arr;

  public:
    int *next;
    int *top;
    int N , int K;
    int freeSpot;
    
    kStacks(int n, int k) {
        // initialize data structures for k stacks
        N = n;
        K = k;
        arr = new int[N];
        next = new int[N];
        top = new int[K];
        
        for(int i = 0 ; i < K ; i++){
            top[i] = -1;
        }
        
        for(int i = 0 ; i < N ; i++){
            next[i] = i+1;
        }
        
        next[n-1] = -1;
        
        freeSpot = 0;
    }

    void push(int x, int i) {
        // push element x into stack i
        
        int index = freeSpot;
        
        freeSpot = next[index];
        
        arr[index] = x;
        
        next[index] = top[i-1];
        
        top[i-1] = index;
        
    }

    int pop(int i) {
        // pop element from stack i
        if(top[i-1] == -1){
            return -1;
        }
        
        int index = top[i-1];
        
        top[i-1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};