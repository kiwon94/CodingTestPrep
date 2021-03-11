bool start=false;
int maxgap=0;
int curgap=0;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int x=N;
    while(x>=1)
    {
        if(x%2==1)
        {
            if(start==false)
                start=true;
            else
            {
                if(curgap>maxgap)
                {
                    maxgap=curgap;
                    
                }
                curgap=0;
            }
        }
        else{
            if(start==true)
            {
                curgap++;
            }
        }
        x/=2;
    }
    return maxgap;
}