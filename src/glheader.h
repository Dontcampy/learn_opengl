//
// Created by dontc on 2022/5/9.
//

#ifndef LEARN_OPENGL_GLHEADER_H
#define LEARN_OPENGL_GLHEADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Camera.h"
#include "ShaderM.h"
#include "Time.h"
#include "Debug.h"
#include "Mouse.h"

// settings
const unsigned int SCR_WIDTH = 1440;
const unsigned int SCR_HEIGHT = 960;

const float F_SCR_WIDTH = (float) SCR_WIDTH;
const float F_SCR_HEIGHT = (float) SCR_HEIGHT;

#endif //LEARN_OPENGL_GLHEADER_H
