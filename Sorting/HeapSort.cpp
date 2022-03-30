/*
* @Author: Zakaria 
* @Date:   2022-03-30 20:19:00
* @Last Modified time: 2022-03-30 20:19:30
*/

#include<stdio.h>

void max_heapify(int heap[], int heap_size, int i)
{
    int left=2*i;
    int right=2*i+1;
    int largest_index=i;

    if(left<=heap_size && heap[left]>heap[i])
        largest_index=left;

    if(right<=heap_size && heap[right]>heap[largest_index])
        largest_index=right;

    if(largest_index==i)
        return;
    else
    {
        int temp=heap[i];

        heap[i]=heap[largest_index];   ///swapping largest child to parent;

        heap[largest_index]=temp;

        max_heapify(heap, heap_size, largest_index); ///recursive call to largest index;

    }

}


int main()
{
     int heap_size=9;
     int heap[]={0,19,7,12,3,5,17,10,1,2};

     puts("Before heapify");
     for(int i=1;i<=heap_size;i++)
     printf("%d ",heap[i]);
     puts("");

     for(int i=heap_size/2 ; i>=1 ;i--)
     max_heapify(heap, heap_size , i); /// heapify call start from 3;

     puts("after heapify");
     for(int i=1;i<=heap_size;i++)
     printf("%d ",heap[i]);

     /// heap sort
     int n=heap_size;
     for(int i=heap_size ; i>1 ;i--)
     {
         int temp=heap[1];
         heap[1]=heap[i];
         heap[i]=temp;
         heap_size-=1;
         max_heapify(heap, heap_size , 1); ///calling heapify function and after each call the length of heap size decrease and heapify from up to down so that every time call 1;
     }

     puts("");
     heap_size=n;
     puts("after heap sort");
     for(int i=1;i<=heap_size;i++)
     printf("%d ",heap[i]);



     return 0;
}
