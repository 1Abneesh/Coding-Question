#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x,y;

    Point(int p,int q){
        x=p;
        y=q;
    }

    Point operator+(const Point &obj){
        int p = x+obj.x;
        int q = y+obj.y;

        Point pt(0,0);
        pt.x = p;
        pt.y = q;
            return pt;

    }
};

int main(){
    Point p1(1,2);
    Point p2(2,3);
    Point p3 = p1+p2;
    cout<<p3.x;

    return 0;
}