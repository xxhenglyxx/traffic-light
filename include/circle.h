
#include <iostream>
#include <OpenGL/gl.h>
#include <math.h>

#ifndef CIRCLE_H
#define CIRCLE_H

struct Circle {

    double center [ 2 ], outline_color [ 3 ], fill_color [ 3 ], radius;
    bool show;

    Circle ( const double radius = 5 );

    void setColorFill ( const double red, const double green, const double blue );
    void setOutlineColor ( const double red, const double green, const double blue );
    void setCenter ( const double x, const double y );
    void setRadius ( const double radius );

    void toggleShow ();
    void draw ();

};

#endif