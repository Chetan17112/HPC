#include <iostream>
#include <vector>
#include <omp.h>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;
void S_B(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++)
    {
        if(i%2==0)
        {
            #pragma omp parallel for num_thread(4)
            for(int c=1;c<arr.size();c+=2)
            {
                if(arr[c-1]>arr[c])
                {swap(arr[c-1],arr[c]);}
            }
        }
        else
        {
        #pragma omp parallel for num_thread(4)
        for(int c=1;c<arr.size();c+=2)
            {
                if(arr[c]>arr[c+1])
                {swap(arr[c],arr[c+1]);}
            }
        }
    }
    for(auto El:arr) cout<<El<<"\t";

}
void Mrg(int arr[],int mid,int si,int ei)
{
    int indx1 = si;
    int indx2 = mid+1;
    int M[ei-si+1];
    int x = 0;
    while(indx1<=mid && indx2<=ei)
    {
        if(arr[indx1]<=arr[indx2])
        {
            M[x] = (arr[indx1]);
            indx1++;x++;

        }
        else{
            M[x] =(arr[indx2]);
            indx2++;x++;
        }
        while(indx1<=mid ){
            M[x] =(arr[indx1]);
            indx1++;x++;
        }
        while(indx2<=ei ){
            M[x] =(arr[indx2]);
            indx2++;x++;
        }


    }
    for(int i=0,j=si;i<sizeof(M)/sizeof(M[0]);i++,j++){
        arr[j] = M[i];
    }
}
void S_MS(int arr[],int si,int ei)
{
    if(si>=ei){
        return;

    }
    int mid = si + (ei-si) / 2;
    S_MS(arr,si,mid);
    S_MS(arr,mid+1,ei);
    Mrg(arr,mid,si,ei);
}
int main()
{
    int arr[] = {11,1,2,6,8,9,10,4};
    const auto t0 = high_resolution_clock::now();

    //S_B(arr);
    const auto t1 = high_resolution_clock::now();

    S_MS(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    for(auto i:arr)
    {
        cout<<i<<"\t";
    }






     std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<float> fsec;
    fsec fs = t1 - t0;
    ms d = std::chrono::duration_cast<ms>(fs);
    std::cout << "\n"<<fs.count() << "s\n";
    std::cout << d.count() << "ms\n";
}
