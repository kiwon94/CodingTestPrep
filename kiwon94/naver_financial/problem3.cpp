#include <stdlib.h>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(<int> &A) {
    int max=-10;
    for(vector::iterator it;it!=A.end();it++)
    {
        int tmp = abs(*it);
        if(tmp < 10 && max < *it)
        {
            max=*it;
        }
    }
    return max;
}
