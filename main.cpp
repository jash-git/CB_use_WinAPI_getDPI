#include <iostream>
#include <cstdio>
//--
//Step_01
#define _WIN32_WINNT 0x0500//GetDC
#include <windows.h>
//--

using namespace std;

//--
//Step_02
class Point
{
    public:
        int X;
        int Y;
        Point();
};
Point::Point()
{
    X=0;
    Y=0;
}
//--
static Point GetSystemDpi()
{
    Point result;
    HWND myconsole=GetConsoleWindow();
    HDC mydc = GetDC(myconsole);

    result.X = GetDeviceCaps(mydc, 88);//-lgdi32
    result.Y = GetDeviceCaps(mydc, 90);//-lgdi32

    ReleaseDC(myconsole,mydc);

    return result;
}
//--
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    Point result=GetSystemDpi();
    cout <<"dpi="<< result.X <<"*"<< result.Y<< endl;
    Pause();
    return 0;
}
