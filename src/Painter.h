//
// Created by dontc on 2022/5/9.
//

#ifndef LEARN_OPENGL_PAINTER_H
#define LEARN_OPENGL_PAINTER_H
#include "glheader.h"

class Painter {
public:
    virtual void OnInit() {}
    virtual void OnRender() {}
    virtual void OnWindowAttach(GLFWwindow* wnd) {}
    virtual void HandleInput(GLFWwindow* wnd) {}
    virtual void OnMouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {}
    virtual void OnMouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset) {}
    virtual void OnDeInit() {}
};


#endif //LEARN_OPENGL_PAINTER_H
