//
//  main.cpp
//  OpenGLSkeletonCode
//
//  Created by Sri Raghu Malireddi on 20/01/16.
//  Copyright © 2016 Sri Raghu Malireddi. All rights reserved.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main( void ){
    GLFWwindow *window;
    
    //initialize the library
    if(!glfwInit()){
        return -1;
    }
    
    //Create a Windowed mode window and its OpenGL Context
    window = glfwCreateWindow(640, 480, "Hello Graphics!", NULL, NULL);
    
    if(!window){
        glfwTerminate();
        return -1;
    }
    
    //Make the window's context current
    glfwMakeContextCurrent(window);
    
    float vertices[] =
    {
        0.0,0.5,0.0, //Top Corner
        -0.5,-0.5,0.0, //bottom left corner
        0.5,-0.5,0.0 //bottom right corner
    };
    
    //Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        
        //render the OpenGL, put all your OpenGL code right here.
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        //Swap front and back buffers
        glfwSwapBuffers(window);
        
        //pool for and process events
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}