/* sierpinski gasket using vertex buffer objects */

#include "Angel.h"

const int NumPoints = 10000;

//----------------------------------------------------------------------------

void
init( void )
{
    vec3 points[NumPoints];

    // Specifiy the vertices for a tetrahedron
    vec3 vertices[] = {
	vec3( -0.5, -0.5, -0.5 ),
	vec3(  0.5, -0.5, -0.5 ),
	vec3(  0.0,  0.5,  0.0 ),
	vec3(  0.0, -0.5,  0.5 )
    };

    // Select an arbitrary initial point inside of the triangle
    points[0] = vec3( 0.0, 0.0, 0.0 );

    // compute and store N-1 new points
    for ( int i = 1; i < NumPoints; ++i ) {
        int j = rand() % 3;   // pick a vertex at random

        // Compute the point halfway between the selected vertex
        //   and the previous point
        points[i] = ( points[i - 1] + vertices[j] ) / 2.0;
    }


    // Create a vertex array object
    GLuint vao;
#ifdef __APPLE__
    glGenVertexArraysAPPLE( 1, &vao );
    glBindVertexArrayAPPLE( vao );
#else
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );
#endif

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW );

    // Load shaders and use the resulting shader program
	std::string evname = "ANGELDIR";
	std::string path = getEnvironmentVariable(evname);
	path += "/shaders";
#ifdef __APPLE__
	path += "/MAC_VERSIONS/";
#else
	path += "/WINDOWS_VERSIONS/";
#endif
	std::string vshader = path + "vshader23.glsl";
	std::string fshader = path + "fshader23.glsl";
    GLuint program = InitShader( vshader.c_str(), fshader.c_str() );
    glUseProgram( program );

    // Initialize the vertex position attribute from the vertex shader
    GLuint loc = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( loc );
    glVertexAttribPointer( loc, 3, GL_FLOAT, GL_FALSE, 0, 
                           BUFFER_OFFSET(0) );

    glClearColor( 1.0, 1.0, 1.0, 1.0 ); // white background
}

//----------------------------------------------------------------------------

void
display( void )
{
    glClear( GL_COLOR_BUFFER_BIT );     // clear the window
    glDrawArrays( GL_POINTS, 0, NumPoints );    // draw the points
    glFlush();
}

//----------------------------------------------------------------------------

void
keyboard( unsigned char key, int x, int y )
{
    switch ( key ) {
    case 033:
        exit( EXIT_SUCCESS );
        break;
    }
}

//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA );
    glutInitWindowSize( 512, 512 );
#ifndef __APPLE__
	glutInitContextVersion(3, 2);
    glutInitContextProfile(GLUT_CORE_PROFILE);
#endif
    glutCreateWindow( "Simple GLSL example" );
#ifdef GLEW_EXPERIMENTAL
    glewExperimental = GL_TRUE;
#endif
#ifndef __APPLE__
    glewInit();
#endif

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );

    glutMainLoop();
    return 0;
}
