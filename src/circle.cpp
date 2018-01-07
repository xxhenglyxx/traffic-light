
#include "circle.h"

Circle::Circle ( const double radius ) : radius ( radius ), show ( false ) {

    this -> center [ 0 ] = 0;
    this -> center [ 1 ] = 0;

    this -> outline_color [ 0 ] = .0;
    this -> outline_color [ 1 ] = .0;
    this -> outline_color [ 2 ] = .0;

    this -> fill_color [ 0 ] = 1.0;
    this -> fill_color [ 1 ] = 1.0;
    this -> fill_color [ 2 ] = 1.0;

};

void Circle::setCenter ( const double x, const double y ) {

    this -> center [ 0 ] = x;
    this -> center [ 1 ] = y;

};

void Circle::setRadius ( const double radius ) {

    this -> radius = radius;

};

void Circle::setColorFill ( const double red, const double green, const double blue ) {

    this -> fill_color [ 0 ] = red;
    this -> fill_color [ 1 ] = green;
    this -> fill_color [ 2 ] = blue;

};

void Circle::setOutlineColor ( const double red, const double green, const double blue ) {

    this -> outline_color [ 0 ] = red;
    this -> outline_color [ 1 ] = green;
    this -> outline_color [ 2 ] = blue;

};

void Circle::toggleShow () {

    this -> show = ! this -> show;

};

void Circle::draw () {

    unsigned int angle = 0;

    const double ( &fill ) [ 3 ] = this -> fill_color;
    const double ( &outline ) [ 3 ] = this -> outline_color;
    const double ( &c ) [ 2 ] = this -> center;
    const double & r = this -> radius;
    const double to_rad = 3.14 / 180;

    // draw outline

    glBegin ( GL_TRIANGLE_FAN );

        glColor3d ( outline [ 0 ], outline [ 1 ], outline [ 2 ] );

        for ( ; angle < 360; ++ angle )

            // + 50 to draw outline slightly visible and apply different stlye to traffic light
            glVertex2d ( ( r + 20 ) * cos ( angle * to_rad ) + c[ 0 ], ( r + 20 ) * sin ( angle * to_rad ) + c[ 1 ] );

    glEnd ();

    angle = 0;
    
    // draw filled

    glBegin ( GL_TRIANGLE_FAN );

        glColor3d ( fill [ 0 ], fill[ 1 ], fill[ 2 ] );

        for ( ; angle < 360; ++ angle )

            glVertex2d ( r * cos ( angle * to_rad ) + c[ 0 ], r * sin ( angle * to_rad ) + c[ 1 ] );

    glEnd ();

};