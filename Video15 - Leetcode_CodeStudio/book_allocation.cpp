bool isPossible(vector<int>& arr ,  int n, int m , int mid){
    
    int pageSum = 0;
    int studentCount = 1;
    for(int i=0 ; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount<m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    int s = 0;
    int end = 0;
    for(int i=0;i<n;i++){
       end += arr[i];
    }

    int e = end ;
    int mid= s + (e-s)/2;
    int ans = -1;

    while(s<e){

        if(isPossible(arr , n , m , mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    mid = s + (e-s)/2;
}
    return ans;
}