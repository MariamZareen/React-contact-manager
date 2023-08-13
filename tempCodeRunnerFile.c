void heapify(int a[100],int i,int size){
    int left=2*i+1;
    int right=2*i+2;
    int maxIdx=i;

    if(left<size && a[left]>a[maxIdx])
    maxIdx=left;
    else
    maxIdx=right;

    if(maxIdx!=i){
        int temp=a[i];
        a[i]=a[maxIdx];
        a[maxIdx]=temp;

        heapify(a,maxIdx,size);
    }
}

void heapSort(int a[100]){
int n=5;
for(int i=n/2;i>=0;i--){
    heapify(a,i,n);
}
}