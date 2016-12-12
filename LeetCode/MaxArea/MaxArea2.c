#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

int maxArea(int* height, int heightSize) {
    int maxarea = 0, l = 0, r = heightSize - 1;
    while (l < r)
    {
        maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return maxarea;
}