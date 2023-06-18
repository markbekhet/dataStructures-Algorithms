// Time complexity O(n)
int sum(int a[], int n){
    int s, i;
    s= 0;
    for(i=0; i<n;i++){
        s= s+ a[i];
    }
    return s;
}

// Time complexity O(n^2)
void add(int* a[] , int* b[], int* c[], int n){
    int i,j;
    for(i=0; i<n;i++){
        for(j=0; j< n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Time complexity O(1)
void swap(int x, int y){
    int t;
    t= x;
    x= y;
    y= t;
}