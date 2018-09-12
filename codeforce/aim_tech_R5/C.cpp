#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
#define ll long long

/*
초기 설계에서 잘못 생각하면 망한다.

이중 if문에서 모든 case를 고려하는 것이 얼마나 어려운가
*/

struct rectangle
{
    int xd;
    int yd;
    int xu;
    int yu;
};

struct xlist{
    int x;
    int idx;
};
struct ylist{
    int y;
    int idx;
};


int cmpx(const void *  f,const void * s){
    return (*(xlist*)f).x - (*(xlist*)s).x;
}


int cmpy(const void *  f,const void * s){
    return (*(ylist*)f).y - (*(ylist*)s).y;
}



int main()
{
    int n = 0;
    cin >> n;
    vector<rectangle> vr(n);
    xlist* xl = new xlist[n];
    xlist* xr= new xlist[n];
    ylist* yr= new ylist[n];
    ylist* yl= new ylist[n];

    int p[4] = {0, };
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            cin >> p[k];
        }
        vr[i] = rectangle{p[0],p[1],p[2],p[3]};
        xl[i] = xlist{p[0],i};
        xr[i] = xlist{p[2],i};
        yl[i] = ylist{p[1],i};
        yr[i] = ylist{p[3],i};
        
    }

    qsort((void*)xl, size_t(n), sizeof(xlist), cmpx);
    qsort((void*)xr, size_t(n), sizeof(xlist), cmpx);
    qsort((void*)yl, size_t(n), sizeof(ylist), cmpy);
    qsort((void*)yr, size_t(n), sizeof(ylist), cmpy);


    int ax=100000001,ay=100000001;
    // 
    if(xl[n-1].x <= xr[0].x){
        if(yl[n-1].y <= yr[0].y || yl[n-1].y <=yr[1].y){
            ax = xl[n-1].x; ay = yl[n-1].y;
        }
        if(ax>100000000 && yl[n-2].y <=yr[0].y){
            ax = xl[n-1].x; ay = yl[n-2].y;
        }
        else if(yl[n-2].y <= yr[1].y){
            if(yl[n-1].idx == yr[0].idx){
                ax = xl[n-1].x; ay = yl[n-2].y;
            }
        }
    }
    else if(xl[n-1].x <=xr[1].x){
        int cmpidx = xr[0].idx;
        if(yl[n-1].y <= yr[0].y){
            ax = xl[n-1].x; ay = yl[n-1].y;
        }
        else if(yl[n-1].y <=yr[1].y){
            if(yr[0].idx == cmpidx){
                ax = xl[n-1].x; ay = yl[n-1].y;
            }
        }
        if(ax>100000000 && yl[n-2].y <=yr[0].y){
            if(yl[n-1].idx == cmpidx){
                ax = xl[n-1].x; ay = yl[n-2].y;
            }
        }
        else if(yl[n-2].y <= yr[1].y){
            if(yl[n-1].idx == yr[0].idx && yl[n-1].idx == cmpidx){
                ax = xl[n-1].x; ay = yl[n-2].y;
            }
        }
    }

    if(ax > 100000000 && xl[n-2].x <=xr[0].x){
        int cmpidx = xl[n-1].idx;
        if(yl[n-1].y <= yr[0].y){
            ax = xl[n-2].x; ay = yl[n-1].y;
        }
        else if(yl[n-1].y <=yr[1].y){
            if(yr[0].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-1].y;
            }
        }
        if(ax>100000000 && yl[n-2].y <=yr[0].y){
            if(yl[n-1].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-2].y;
            }
        }
        else if(yl[n-2].y <= yr[1].y){
            if(yl[n-1].idx == yr[0].idx && yl[n-1].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-2].y;
            }
        }
    }
    else if(xl[n-2].x <=xr[1].x && xl[n-1].idx == xr[0].idx){
        int cmpidx = xr[0].idx;
        if(yl[n-1].y <= yr[0].y){
            ax = xl[n-2].x; ay = yl[n-1].y;
        }
        else if(yl[n-1].y <=yr[1].y){
            if(yr[0].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-1].y;
            }
        }
        if(ax>100000000 && yl[n-2].y <=yr[0].y){
            if(yl[n-1].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-2].y;
            }
        }
        else if(yl[n-2].y <= yr[1].y){
            if(yl[n-1].idx == yr[0].idx && yl[n-1].idx == cmpidx){
                ax = xl[n-2].x; ay = yl[n-2].y;
            }
        }
    }



    cout<<ax<<" "<<ay;
    return 0;
}
