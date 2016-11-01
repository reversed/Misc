#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file;
    file.open("test.txt");
    if (!file)
    {
        cout << "error reading test.txt" << endl;
        return 1;
    }
    
    int K = 5;
    string L[K];
    string tmp;
    int lines = 0;
    while (file.good())
    {
        // carefully dealing EOF
        if (getline(file, tmp))
        {
            L[lines % K] = tmp;
            ++lines;
        }
    }

    // if less than K lines were read, print them all
    int start, count;
    if (lines < K)
    {
        start = 0;
        count = lines;
    }
    else
    {
        start = lines % K;
        count = K;
    }

    for (int i = 0; i < count; ++i)
    {
        cout << L[(start + i) % K] << endl;
    }
    
    return 0;
}
