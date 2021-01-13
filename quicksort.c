#include<time.h>
#include <stdio.h>

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  int j;
  for(j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);
    
    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);
    
    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Function to print eklements of an array
void printArray(int array[], int size) {
  int i;	
  for(i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main()
{
	int a[5000];   
	FILE *fp1;       
    int i;
    clock_t t; 
    for(i=0;i<5000;i++)
        a[i]=0;
    i=0;        
    if ((fp1=fopen("RANDOMS.txt","r"))==NULL)
    {
    printf("Random.txt failed to open\n");
    return 1;
    }
    else{
        while((fscanf(fp1,"%d",&a[i]))!=EOF) //scanf and check EOF
        {
            printf("nums[%d] is %d\n",i,a[i]);
            i++;
        }
	}
	int n = sizeof(a)/sizeof(a[0]); 
	
	t= clock();
	quickSort(a, 0, n - 1);
	t= clock()-t;	
	
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	
	printf("\nSorted array is :");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("Elapsed: %f seconds\n",time_taken); 
	return 0; 																																																																																																																																							
}


