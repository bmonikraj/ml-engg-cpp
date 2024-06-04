#ifndef SHAPE_H
#define SHAPE_H

namespace Service {
    class Shape {
        public:
            virtual float getArea() = 0;
            virtual void computeArea() = 0;
    };
};

#endif