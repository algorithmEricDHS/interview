#include <iostream>

using namespace std;



//C(x+y, x) = (x + y)!/(x! * y !)
long actual_times(int x, int y)
{
    int n = 1;
    int i;
    for(i = x + 1; i <= x + y; i++){
        n *= i;
    }

    for(i = 1; i <= y; i++){
        n /= i;
    }

    return n;
}


void robot_path(long &num, int right, int down)
{
    if(right < 0 || down < 0){
        cout << " Grid size should be greate then zero " << endl;
        return ;
    }

    if(right == 0 || down == 0){
        num ++;
        return ;
    }

    if(right > 0){
        robot_path(num, right - 1, down);
    }

    if(down > 0){
        robot_path(num, right, down - 1);
    }
}

typedef struct region{
    int x;
    int y;
    int width;
    int height;
}Rgn;

bool is_valid(Rgn &r, int x, int y)
{
    if(x >= r.x && x <= r.x + r.width && y >= r.y && y <= r.y + r.height){
        return false;
    }
    else{
        return true;
    }
}

void robot_path_with_obstalce(long &num, int right, int down, Rgn &r)
{
    if(right < 0 || down < 0){
        cout << " Grid size should be greate then zero " << endl;
        return ;
    }

    if(is_valid(r, right, down) == false){
        return;
    }

    if(right == 0 || down == 0){
        num ++;
        return ;
    }

    if(right > 0){
        robot_path(num, right - 1, down);
    }

    if(down > 0){
        robot_path(num, right, down - 1);
    }
}

#define OBSTALCE

int main(int argc, char* argv[])
{
#ifndef OBSTALCE
    for(int i = 1; i < 9; i++){
        long num = 0;
        robot_path(num, i, i);
        cout << num << " actual times" << actual_times(i, i) << endl;
    }
#else 
    Rgn r;
    r.x = 1;
    r.y = 1;
    r.width = 1;
    r.height = 1;

    for(int i = 1; i < 9; i ++){
        long num = 0;
        robot_path_with_obstalce(num, i, i, r);

        cout << "region " << i << " x " << i << " ways: " <<num << endl;
    }

#endif
    return 0;
}
