#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INFINITY 99999
int findMedian(int *, int *, int, int);
void printArray(int *, int);

void main()
{
	int *arr1, *arr2, size1, size2, i, median;
	printf("Enter the size of the first array\n");
	scanf("%d", &size1);
	arr1=(int*)malloc(size1*sizeof(int));
	assert(arr1);
	printf("Enter sorted values to the array\n");
	for(i=0; i<size1; i++)
		scanf("%d", &arr1[i]);
	printf("Enter the size of the second array\n");
	scanf("%d", &size2);
	arr2=(int*)malloc(size2*sizeof(int));
	assert(arr2);
	printf("Enter sorted values to the array\n");
	for(i=0; i<size2; i++)
		scanf("%d", &arr2[i]);
	printf("The first array is: ");
	printArray(arr1, size1);
	printf("The second array is: ");
	printArray(arr2, size2);
	median=findMedian(arr1, arr2, size1, size2);
	printf("The median of the two arrays is: %d\n", median);
	free(arr1);
	free(arr2);
}

int findMedian(int *arr1, int *arr2, int size1, int size2)
{
	int sizeX,sizeY, flag, start, end, median=INFINITY, partitionX, partitionY, *x, *y;
	int maxLeftX, maxLeftY, minRightY, minRightX;
	if(size1<size2)
	{
		sizeX=size1;
		sizeY=size2;
		x=arr1;
		y=arr2;
	}
	else
	{
		sizeX=size2;
		sizeY=size1;
		x=arr2;
		y=arr1;
	}
	start=0;
	end=sizeX;
	partitionX=(start+end)/2;
	partitionY=(size1+size2+1)/2-partitionX;
	while(median==INFINITY)
	{
		if(partitionX-1==-1)
			maxLeftX=-INFINITY;
		else
			maxLeftX=x[partitionX-1];
		if(partitionX==sizeX)
			minRightX=INFINITY;
		else
			minRightX=x[partitionX];
		if(partitionY-1==-1)
			maxLeftY=-INFINITY;
		else
			maxLeftY=y[partitionY-1];
		if(partitionY==sizeY)
			minRightY=INFINITY;
		else
			minRightY=y[partitionY];
		if(maxLeftX<=minRightY && maxLeftY<=minRightX)
		{
			if(maxLeftX>maxLeftY)
				median=maxLeftX;
			else
				median=maxLeftY;
		}
		else if(maxLeftX>minRightY)
		{
			end=partitionX-1;
			partitionX=(start+end)/2;
			partitionY=(size1+size2+1)/2-partitionX;
		}
		else
		{
			start=partitionX+1;
			partitionX=(start+end)/2;
			partitionY=(size1+size2+1)/2-partitionX;
		}
	}
	return median;
}
void printArray(int *arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}