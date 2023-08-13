#include <stdio.h>
#include <time.h>
// void insertionSort(long a[100],int n){
//     for(int i=1;i<n-1;i++){
//         int j=i-1;
//         int curr=a[i];
//         while(j>=0 && curr<a[j]){
//             a[j+1]=a[j];
//             j--;
//         }
//         a[j+1]=curr;
//     }
// }
void heapify(int a[100],int i,int size){
    int left=2*i+1;
    int right = 2*i+2;
    int maxIdx=i;
    if(left<size && a[left]>a[maxIdx]) maxIdx=left;
    if(right<size && a[right]>a[maxIdx]) maxIdx=right;
    if(maxIdx!=i){
    int t=a[i];
    a[i]=a[maxIdx];
    a[maxIdx]=t;
    heapify(a,maxIdx,size);
    }
}

void heapsort(int a[100],int n){
  for(int i=n/2;i>=0;i--){
    heapify(a,i,n);
  }
  for(int i=n-1;i>0;i--){
    int t=a[0];
    a[0]=a[i];
    a[i]=t;
    heapify(a,0,i);
  }
}
int partition(int a[100],int l,int h){
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(a[j]<pivot){
            i++;
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    i++;
    int t=a[i];
    a[i]=a[h];
    a[h]=t;
    return i;
}
void quicksort(int a[100],int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,h);
    }
}

void conqure(int a[1000],int si,int mid,int ei){
  int merged[100],i1=si,i2=mid+1,x=0;
  while(i1<=mid && i2<=ei){
    if(a[i1]<=a[i2]) merged[x++]=a[i1++];
   else merged[x++]=a[i2++];
  }
  while(i1<=mid){
  merged[x++]=a[i1++];
  }
  while(i2<=ei){
  merged[x++]=a[i2++];
  }
  for(int i=0,j=si;i<sizeof(merged)/4;i++,j++){
    a[j]=merged[i];
  }
}
void divide(int a[1000],int si,int ei){
    if(si<ei){
        int mid=(si+ei)/2;
        divide(a,si,mid);
        divide(a,mid+1,ei);
        conqure(a,si,mid,ei);
    }
}
int main(){
    int n;
    int a[1000];
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("\nThe array is: \n");
    for(int i=0;i<n;i++){
        a[i]=(rand()%100)+1;
       printf("%d\t",a[i]);
    }
    clock_t st,et;
    st=clock();
      heapsort(a,n);
    et=clock();
     printf("\nThe sorted array is: \n");
    for(int i=0;i<n;i++){
       printf("%d\t",a[i]);
    }
    double clk=(double)(et-st)/CLOCKS_PER_SEC;
    printf("\nThe runtime is %f",clk);
}