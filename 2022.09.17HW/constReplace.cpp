//
// Created by Pavlov Egor on 19.09.2022.
//


#include <iostream>

using namespace std;

int main()
{   double x,y;
    cout << "Give definition of x:";
    cin >> x; // x = x0
    cout << "Give definition of y:";
    cin >> y; // y = y0
    x += y; // x1 = x0 + y0
    y += x; // y1 = x0 + 2y0
    x = y - x; // x2 = (x0 + 2y0) - (x0 + y0) = y0
    y -= 2 * x; // y2 = (x0 + 2y0) - 2y0 = x0
    cout <<"x=" << x <<' ' <<"y="<< y << endl;
    return 0;
}
