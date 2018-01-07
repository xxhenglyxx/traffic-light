
#include <circle.h>
#include <GLUT/glut.h>

// global vars
Circle circleRed ( 200 );
Circle circleYellow ( 200 );
Circle circleGreen ( 200 );

void render ();
void windowOnChange ( int width, int height );

int main ( int args_len, char ** args_context ) {

    glutInit ( &args_len, args_context );
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Traffic Light - OpenGL2" );

    glClearColor ( .2, .3, .5, .8 );
    glClear ( GL_COLOR_BUFFER_BIT );
    glLoadIdentity ();
    gluOrtho2D ( -800, 800, -800, 800 );

    // set circles center
    circleRed.setCenter ( -500.0, .0 );
    circleGreen.setCenter ( 500.0, .0 );

    // set initial circle color
    circleRed.setOutlineColor ( .3, .1, .1 );
    circleYellow.setOutlineColor ( .3, .1, .1 );
    circleGreen.setOutlineColor ( .3, .1, .1 );

    circleRed.setColorFill ( 1.0, .0, .0 );
    circleYellow.setColorFill ( 1.0, 1.0, .0 );
    circleGreen.setColorFill ( .0, .0, 1.0 );

    // toggle circle show
    circleRed.toggleShow ();
    circleYellow.toggleShow ();
    circleGreen.toggleShow ();

    glutDisplayFunc ( render );
    glutReshapeFunc ( windowOnChange );

    glutMainLoop ();

    return 0;

};

void render () {

    if ( circleRed.show ) circleRed.draw ();

    if ( circleYellow.show ) circleYellow.draw ();

    if ( circleGreen.show ) circleGreen.draw ();

    glFlush ();

};

void windowOnChange ( int width, int height ) {
    
    
};