
    static void merge(T* start, T* middle, T* end) {
    // TODO
    int l=0,m=middle-start,r=end-start;
    int len1 = m- l + 1, len2 = r - m;
    T left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = start[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = start[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = 0;
 
    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            start[k] = left[i];
            i++;
        }
        else
        {
            start[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        start[k] = left[i];
        k++;
        i++;
    }
 
    // Copy remaining element of right, if any
    while (j < len2)
    {
        start[k] = right[j];
        k++;
        j++;
    }
}

static void InsertionSort(T* start, T* end) {
    // TODO
    int  size = end - start;
     for (int i = 0; i <size; i++)
    {
        T temp = start[i];
        int j = i - 1;
        while (j >= 0  && start[j] > temp)
        {
            start[j+1] = start[j];
            j--;
        }
        start[j+1] = temp;
    }
}
    
    
static void TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.

     int  n = end - start+1;
      for (int i = 0; i < n; i+=min_size)
      {  InsertionSort(start, start+ min((i+min_size-1),(n-1)));}
        cout<<"Insertion Sort: ";
        printArray(start,end);
        int dem=0;
    for (int size = min_size; size < n;size = 2*size)
    {
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));

              if(mid < right)
              {
                  dem++;
              merge(start+left,start+ mid, start+right);
              cout<<"Merge "<<dem<<":";
              printArray(start,end);
              }
        }
    }
    
}
