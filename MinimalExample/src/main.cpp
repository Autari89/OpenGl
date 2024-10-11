#include <iostream>
#include <windows.h>
#include <GL/glut.h>

// Clears the current window and draws a triangle.
void display() {

    // Set every pixel in the frame buffer to the current clear color.
    glClear(GL_COLOR_BUFFER_BIT);

    // Drawing is done by specifying a sequence of vertices.  The way these
    // vertices are connected (or not connected) depends on the argument to
    // glBegin.  GL_POLYGON constructs a filled polygon.
    glBegin(GL_POLYGON);

    // For each vertex we can specify the color and the position. glColor3f uses the RGB notation
    // glVertex3f accepts x,y,z as parameters. The center of the coordinate system is in the middle of the window
    glColor3f(1, 0, 0);
    glVertex3f(0, 0.6, 0);

    glColor3f(0, 1, 0);
    glVertex3f(-0.6f, -0.6f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.6f, -0.6f, 0.0f);

    glEnd();

    // Flush drawing command buffer to make drawing happen as soon as possible.
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Position window at (80,80)-(480,380) and give it a title.
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(400, 300);
    glutCreateWindow("A Simple Triangle");

    // Tell GLUT that whenever the main window needs to be repainted that it
    // should call the function display().
    glutDisplayFunc(display);

    // Tell GLUT to start reading and processing events.  This function
    // never returns; the program only exits when the user closes the main
    // window or kills the process.
    glutMainLoop();

    return 0;
}
