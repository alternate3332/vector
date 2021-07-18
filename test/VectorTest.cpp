#include <stdio.h>
#include <string>
#include "Vector.h"

using Vec2 = suzu::Vector2;
const double NEAR_ZERO = 0.00001;

bool calcRadianX(Vec2& v1, Vec2& v2, double result, std::string funcName){

    double rad = Vec2::calcRadian(v1, v2);

    bool res = (abs(rad - result) < NEAR_ZERO);
    if(res != true){
        printf("%s --- NG\n", funcName.c_str());
        printf("current deg => %lf\n", 180.0 * rad / (M_PI));
    }
    else {
        printf("%s --- OK\n", funcName.c_str());
    }
    return res;
}

bool calcRadian0(){
    Vec2 v1(0, 1);
    Vec2 v2(0, 1);
    double res = 0;
    return calcRadianX(v1, v2, res, std::string(__func__));
}

bool calcRadian45(){
    Vec2 v1(0, 1);
    Vec2 v2(1, 1);
    double res = M_PI / 4.0;
    int deg = 45;
    return calcRadianX(v1, v2, res, std::string(__func__));
}

bool calcRadian90(){
    Vec2 v1(0, 1);
    Vec2 v2(1, 0);
    double res = M_PI / 2.0;
    int deg = 90;
    return calcRadianX(v1, v2, res, std::string(__func__));
}
bool calcRadian90_pattern2(){
    Vec2 v1(1, 1);
    Vec2 v2(1, -1);
    double res = M_PI / 2.0;
    int deg = 90;
    return calcRadianX(v1, v2, res, std::string(__func__));
}

bool calcRadian180(){
    Vec2 v1(0, 1);
    Vec2 v2(0, -1);
    double res = M_PI;
    int deg = 180;
    return calcRadianX(v1, v2, res, std::string(__func__));
}

bool calcRadian270(){
    Vec2 v1(0, 1);
    Vec2 v2(-1, 0);
    double res = 3 * M_PI / 2;
    int deg = 270;
    return calcRadianX(v1, v2, res, std::string(__func__));
}

int main(int argc, char** argv){
    calcRadian0();
    calcRadian45();
    calcRadian90();
    calcRadian180();
    calcRadian270();
    calcRadian90_pattern2();

/*
    Vec2 org(1, 0);
    for(int i = 0; i < 36; i++){
        double deg = 10 * i;
        double rad = 2*M_PI * deg / 360;
        
        Vec2 current(cos(rad), sin(rad));
        
        double res =  Vec2::calcRadian(org, current);
        
        printf("%d deg => %lf\n", 10*i, 180*res / M_PI);

    }
    */
    return 0;
}