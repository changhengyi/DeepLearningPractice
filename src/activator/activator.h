//
//  activator.h
//  deeplearning
//
//  Created by 邱威 on 2020/1/19.
//  Copyright © 2020 qiuwei. All rights reserved.
//

#ifndef activator_h
#define activator_h

#include <stdio.h>
#include <algorithm>
#include <math.h>

namespace dl
{

class Activator {
public:
    virtual double Forward(double value) const = 0;
    virtual double Backward(double value) const = 0;

    virtual ~Activator() {}
};

class ReluActivator: public Activator
{
public:
    // ReluActivator(/* args */);
    // ~ReluActivator();

    virtual double Forward(double value) const {
        return std::max(0.0, value);
    };

    virtual double Backward(double value) const {
        return value > 0 ? 1 : 0;
    };
};

class SigmoidActivator: public Activator
{
public:
    // SigmoidActivator(/* args */);
    // ~SigmoidActivator();

    virtual double Forward(double value) const {
        return 1 / (1 + exp(-value));
    };

    virtual double Backward(double value) const {
        return value * (1 - value);
    };

};

class LinearActivator: public Activator
{
public:

    virtual double Forward(double value) const {
        return 1;//1 / (1 + exp(-value));
    };

    virtual double Backward(double value) const {
        return value;
    };

};

}

#endif /* activator_h */
