//
//  main.cpp
//  OpenGLSkeletonCode
//
//  Created by Sri Raghu Malireddi on 20/01/16.
//  Copyright © 2016 Sri Raghu Malireddi. All rights reserved.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void ){
    GLFWwindow *window;
    
    //initialize the library
    if(!glfwInit()){
        return -1;
    }
    
    //Create a Windowed mode window and its OpenGL Context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello Graphics!", NULL, NULL);
    
    if(!window){
        glfwTerminate();
        return -1;
    }
    
    //Make the window's context current
    glfwMakeContextCurrent(window);
    
    float vertices[] =
    {
        20.0,100.0,0.0, //Top right
        100.0,100.0,0.0,  //Top left
        100.0,20.0,0.0, //Bottom left
        20.0,20.0,0.0 //Bottom right
    };
    
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        
        //render the OpenGL, put all your OpenGL code right here.
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        
        //Swap front and back buffers
        glfwSwapBuffers(window);
        
        //pool for and process events
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}