
#include <iostream>
using namespace std;
void printArr(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1) cout<<" ";
    }
    cout<<"\n";
}

void selectionSort(int nums[], int n){
    for(int i=0;i<nums.size();i++){
            int mini = i;
            for(int j=i;j<nums.size();j++){
                if(nums[mini]>nums[j]){
                    mini = j;
                }
            }
            swap(nums[mini],nums[i]);
        }
}

void insertionSort(int nums[], int n){
    for(int i=1;i<nums.size();i++){
            for(int j=i;j>=1;j--){
                if(nums[j-1]>nums[j]){
                    swap(nums[j-1],nums[j]);
                }
            }
        }
}

void bubbleSort(int nums[], int n){
    for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<i;j++){
               if (nums[j+1]<nums[j]){
                    swap(nums[j],nums[j+1]);
               }
            }
        }
}

void merge(int nums[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i=0;i<n1;i++) L[i] = nums[l+i];
    for(int j=0;j<n2;j++) R[j] = nums[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else nums[k++] = R[j++];
    }
    while(i<n1) nums[k++] = L[i++];
    while(j<n2) nums[k++] = R[j++];
    delete [] L; delete [] R;
}

void mergeSortRec(int a[], int l, int r){
    if(l>=r) return;
    int m = l + (r-l)/2;
    mergeSortRec(a,l,m);
    mergeSortRec(a,m+1,r);
    merge(a,l,m,r);
}
void mergeSort(int a[], int n){ if(n>0) mergeSortRec(a,0,n-1); }

/* ---------- Quick Sort (Lomuto) ---------- */
int partitionQ(int a[], int l, int r){
    int pivot = a[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(a[j] <= pivot){
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i+1]; a[i+1] = a[r]; a[r] = t;
    return i+1;
}
void quickSortRec(int nums[], int l, int r){
    if(l<r){
        int p = partitionQ(nums,l,r);
        quickSortRec(nums,l,p-1);
        quickSortRec(nums,p+1,r);
    }
}
void quickSort(int a[], int n){ if(n>0) quickSortRec(a,0,n-1); }

int main(){
    cin.tie(nullptr);
    int n;
    cout<<"Enter n: ";
    if(!(cin>>n)) return 0;
    int *orig = new int[n];
    cout<<"enter "<<n<<" elements:";
    for(int i=0;i<n;i++) cin>>orig[i];

    int ch; cin>>ch;

    int *a = new int[n];
    for(int i=0;i<n;i++) a[i]=orig[i];

    if(ch==1){
        selectionSort(a,n);
        cout<<"after Selection: ";
        printArr(a,n);
    } else if(ch==2){
        insertionSort(a,n);
        cout<<"after Insertion: ";
        printArr(a,n);
    } else if(ch==3){
        bubbleSort(a,n);
        cout<<"after Bubble: ";
        printArr(a,n);
    } else if(ch==4){
        mergeSort(a,n);
        cout<<"after Merge: ";
        printArr(a,n);
    } else if(ch==5){
        quickSort(a,n);
        cout<<"after Quick: ";
        printArr(a,n);
    } else {
        cout<<"Invalid\n";
    }

    delete [] orig;
    delete [] a;
    return 0;
}
