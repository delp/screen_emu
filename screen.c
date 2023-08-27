#include <GL/glut.h>
#include <stdio.h>

const unsigned int W = 256;
const unsigned int H = 256;


/*
I'm gonna use the colors from the pico-8 because I think they're really pleasant.
0 		#000000 	0, 0, 0 	black
1 		#1D2B53 	29, 43, 83 	dark-blue
2 		#7E2553 	126, 37, 83 	dark-purple
3 		#008751 	0, 135, 81 	dark-green
4 		#AB5236 	171, 82, 54 	brown
5 		#5F574F 	95, 87, 79 	dark-grey
6 		#C2C3C7 	194, 195, 199 	light-grey
7 		#FFF1E8 	255, 241, 232 	white
8 		#FF004D 	255, 0, 77 	red
9 		#FFA300 	255, 163, 0 	orange
10 		#FFEC27 	255, 236, 39 	yellow
11 		#00E436 	0, 228, 54 	green
12 		#29ADFF 	41, 173, 255 	blue
13 		#83769C 	131, 118, 156 	lavender
14 		#FF77A8 	255, 119, 168 	pink
15 		#FFCCAA 	255, 204, 170 	light-peach 
*/

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    printf("boop\n");
    GLubyte data[H][W][3];
    GLubyte a = 0xFF;
    for( size_t y = 0; y < H; ++y )
    {
        for( size_t x = 0; x < W; ++x )
        {
            data[y][x][0] = a;//( rand() % 256 );
            data[y][x][1] = //( rand() % 256 );
            data[y][x][2] = 0;//( rand() % 256 );
        }
    }

    glDrawPixels( W, H, GL_RGB, GL_UNSIGNED_BYTE, data );

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