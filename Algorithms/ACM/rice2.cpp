    #include <iostream>
    #include <vector>
    #include <iterator>
    #include <algorithm>
#include <cstdio>
    using namespace std;

    typedef struct rice
    {
        int price;
        int height;
    } rice;    
    rice rc;
    bool comp(const rice &a,const rice &b)
    {
        return a.price<b.price;
    }
    int main()
    {

        vector<rice> vec;
        int C;
        scanf("%d",&C);
        while(C--)
        {
            vec.clear();
            int n,m;
            scanf("%d%d",&n,&m);
            float max=0.00;
            for(int i=0;i<m;i++)
            {
                int p,h;
             scanf("%d%d",&rc.price,&rc.height);
             vec.push_back(rc);
         }
         sort(vec.begin(),vec.end(),comp);
         vector<rice>::iterator iter;
         for(iter=vec.begin();iter!=vec.end();iter++)
         {
                if( (*iter).price * (*iter).height>=n)
                {
                  max+=(float)(n)/(*iter).price;
                  break;
             }
                
              else{
                      max+=(*iter).height;
                 }
                n=n-(*iter).price*(*iter).height;
            }
            printf("%.2f\n",max);
        }
    }
