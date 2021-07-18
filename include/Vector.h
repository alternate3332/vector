#ifndef __SUZU_VECTOR_H__
#define __SUZU_VECTOR_H__
#include <cmath>

namespace suzu{

    class Vector2{
        public:
            Vector2(double _x, double _y){
                this->x = _x;
                this->y = _y;
            }

            void set(double _x, double _y){
                this->x = _x;
                this->y = _y;
            }

            double L2Norm() const {
                return sqrt(pow(this->x, 2) + pow(this->y, 2));
            }

            static double dot(const Vector2& vec1, const Vector2& vec2){
                return (vec1.x * vec2.x + vec1.y * vec2.y);
            };

            static double cross(const Vector2& vec1, const Vector2& vec2){
                return (vec1.x * vec2.y - vec1.y * vec2.x);
            }

            static double calcRadian(const Vector2& vec1, const Vector2& vec2){
                double dotVal = dot(vec1, vec2);
                double power = vec1.L2Norm() * vec2.L2Norm();
                double cosTheta = dotVal / power;
                double radian = acos(cosTheta);

                double crossVal = cross(vec1, vec2);

                if(crossVal > 0){
                    return 2*M_PI - radian;
                }
                else {
                    return radian;
                }
            }



        private:
            double x;
            double y;
    };
};

#endif