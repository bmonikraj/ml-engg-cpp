#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

namespace Service {
    class Square : public Service::Shape {
        private:
            float area;
            float length;
        public:
            Square(float length);
            float getArea();
            void computeArea();
    };
};

#endif