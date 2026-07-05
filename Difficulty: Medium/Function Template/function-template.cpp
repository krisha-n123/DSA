template <class T>
T largest(T arr[], int n) {

    // code here
     T maxi=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}