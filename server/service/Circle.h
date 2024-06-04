#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

namespace Service {
    class Circle : public Service::Shape {
        private:
            float area;
            float radius;
        public:
            Circle(float radius);
            float getArea();
            void computeArea();
    };
};

#endif