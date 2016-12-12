#define min(x, y) ((x) > (y) ? (y) : (x))

int maxArea(int* height, int heightSize) {
    int max = 0;
    int h = height[0];
    int cur = h;
    int *arr = (int*)calloc(heightSize, sizeof(int));
    
    for (int i = 1; i < heightSize; ++i)
    {
        int minmum = min(cur, height[i]);
        
        if (cur < height[i])
        {
            arr[i] = maxArea(height + i, heightSize - i);
        }
        
        if (minmum * i > max)
        {
            max = minmum * i;
        }
    }
    
    for (int i = 1; i < heightSize; ++i)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    free(arr);
    
    return max;
}