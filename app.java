class app{
    public static void heapify(int a[],int i,int size){
        int left=2*i+1;
        int right=2*i+2;
        int maxIdx=i;

        if(left<size && a[left]>a[maxIdx])
        maxIdx=left;
        if(right<size && a[right]>a[maxIdx])
        maxIdx=right;

        if(maxIdx!=i){
            int temp=a[i];
            a[i]=a[maxIdx];
            a[maxIdx]=temp;

            heapify(a, maxIdx, size);
        }
    }
    public static void heapSort(int a[]){
        int n=5;
        for(int i=n/2;i>=0;i--){
            heapify(a,i,n);
        }
    }
    public static void main(String[] args) {
        int a[]={1,2,4,5,3};
        heapSort(a);
        for(int i=0;i<5;i++){
            System.out.print(a[i]+" ");
        }
    }
}