#include <GL/glut.h>
#include <stdio.h>

const unsigned int W = 256;
const unsigned int H = 256;

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    printf("boop\n");
    unsigned int data[H][W][3];
    for( size_t y = 0; y < H; ++y )
    {
        for( size_t x = 0; x < W; ++x )
        {
            data[y][x][0] = ( rand() % 256 ) * 256 * 256 * 256;
            data[y][x][1] = ( rand() % 256 ) * 256 * 256 * 256;
            data[y][x][2] = ( rand() % 256 ) * 256 * 256 * 256;
        }
    }

    glDrawPixels( W, H, GL_RGB, GL_UNSIGNED_INT, data );

    glutSwapBuffers();
}

void timer(int value) {
    glutTimerFunc(16, timer, 0);
    glutPostRedisplay();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( W, H );
    glutCreateWindow( "GLUT" );
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}