#include <GL/glut.h>
#include <stdio.h>

const unsigned int W = 256*3;
const unsigned int H = 256*3;

// Pico-8 Palette 8)
const unsigned int colormap[16] = {
    0x000000, //black
    0x1D2B53, //dark-blue
    0x7E2553, //dark-purple
    0x008751, //dark-green
    0xAB5236, //brown
    0x5F574F, //dark-grey
    0xC2C3C7, //light-grey
    0xFFF1E8, //white
    0xFF004D, //red
    0xFFA300, //orange
    0xFFEC27, //yellow
    0x00E436, //green
    0x29ADFF, //blue
    0x83769C, //lavender
    0xFF77A8, //pink
    0xFFCCAA  //light-peach
};

GLubyte getRed(unsigned int value) {
    return (value >> 16) & 0xFF;
}

GLubyte getGreen(unsigned int value) {
    return (value >> 8) & 0xFF;
}

GLubyte getBlue(unsigned int value) {
    return value & 0xFF;
}

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
            data[y][x][0] = getRed(colormap[11]);
            data[y][x][1] = getGreen(colormap[11]);
            data[y][x][2] = getBlue(colormap[11]);
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
