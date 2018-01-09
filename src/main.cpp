
#include <circle.h>
#include <GLUT/glut.h>

// global vars
bool is_green;
int times;
int max_times;
Circle circleRed ( 160 );
Circle circleYellow ( 160 );
Circle circleGreen ( 160 );

void render ();
void interval ( int value );
void windowOnChange ( int width, int height );

int main ( int args_len, char ** args_context ) {

    glutInit ( &args_len, args_context );
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Traffic Light - OpenGL2" );

    // set circles center
    circleRed.setCenter ( -390.0, .0 );
    circleGreen.setCenter ( 390.0, .0 );

    // set initial circle color
    circleRed.setOutlineColor ( .3, .1, .1 );
    circleYellow.setOutlineColor ( .3, .1, .1 );
    circleGreen.setOutlineColor ( .3, .1, .1 );

    circleRed.setColorFill ( .0, .0, .0 );
    circleYellow.setColorFill ( .0, .0, .0 );
    circleGreen.setColorFill ( .0, 128 / 255.0, .0 );

    // toggle circle show
    circleRed.toggleShow ();
    circleYellow.toggleShow ();
    circleGreen.toggleShow ();

    glutDisplayFunc ( render );
    glutReshapeFunc ( windowOnChange );

    is_green = false;
    times = 0;
    max_times = 10;

    glutTimerFunc ( 1000, interval, times );

    glutMainLoop ();

    return 0;

};

void render () {

    glClearColor ( .2, .3, .5, .8 );
    glClear ( GL_COLOR_BUFFER_BIT );
    glLoadIdentity ();
    glOrtho ( -800, 800, -800, 800, -2, 10 );

    glBegin ( GL_TRIANGLES );

        glColor3d ( .0, .0, .0 );

        glVertex2i ( -630, 300 );
        glVertex2i ( 630, -300 );
        glVertex2i ( 630, 300 );

    glEnd ();

    glBegin ( GL_TRIANGLES );

        glColor3d ( .0, .0, .0 );
        
        glVertex2i ( -630, 300 );
        glVertex2i ( -630, -300 );
        glVertex2i ( 630, -300 );

    glEnd ();

    if ( circleRed.show ) {

        glPushMatrix ();
        
            circleRed.draw ();

        glPopMatrix ();

    }

    if ( circleYellow.show ) {

        glPushMatrix ();
        
            circleYellow.draw ();

        glPopMatrix ();

    }

    if ( circleGreen.show ) {

        glPushMatrix ();
        
            circleGreen.draw ();

        glPopMatrix ();

    }

    glutSwapBuffers ();

};

void windowOnChange ( int width, int height ) {

    glViewport ( 0, 0, ( GLsizei ) width, ( GLsizei ) height );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();
    gluPerspective( 60, ( GLfloat ) width / ( GLfloat ) height, 100.0, 100.0 );
    glMatrixMode ( GL_MODELVIEW );
    
};

void interval ( int value ) {

    int & time_value = value;

    std::cout << "Max Time: " << max_times << std::endl;
    std::cout << "Time: " << time_value << std::endl;

    if ( max_times - 2 == time_value ) {

        circleYellow.setColorFill ( 1.0, 1.0, .0 );
        circleRed.setColorFill ( .0, .0, .0 );
        circleGreen.setColorFill ( .0, .0, .0 );

    } else if ( max_times == time_value ) {

        is_green ?
            (
                circleYellow.setColorFill ( .0, .0, .0 ),
                circleRed.setColorFill ( .0, .0, .0 ),
                circleGreen.setColorFill ( .0, 128 / 255.0, .0 )
            )
            :
            (
                circleYellow.setColorFill ( .0, .0, .0 ),
                circleRed.setColorFill ( 1.0, .0, .0 ),
                circleGreen.setColorFill ( .0, .0, .0 )
            );

        is_green = !is_green;

        time_value = 0;

    }

    glutPostRedisplay ();

    ++ time_value;

    glutTimerFunc ( 1000, interval, time_value );

};