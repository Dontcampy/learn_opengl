//
// Created by dontc on 2022/5/9.
//
#include "HelloMaterials.h"

void HelloMaterials::OnInit() {
    glEnable(GL_DEPTH_TEST);

    m_LightingObjShader = new Shader("cube.vert", "cube.frag");
    m_LampShader = new Shader("light.vert", "light.frag");

    glGenVertexArrays(1, &containerVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindVertexArray(containerVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 6, (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void HelloMaterials::OnRender() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    DrawLightParamWindow();

    auto mainCamera = Camera::GetMainCamera();
    m_LightingObjShader->Use();
    m_LightingObjShader->setVec3("light.position", lightPos[0], lightPos[1], lightPos[2]);
    m_LightingObjShader->setVec3("viewPos", mainCamera->Position);

    m_LightingObjShader->setVec3("light.ambient", light_ambient[0], light_ambient[1], light_ambient[2]);
    m_LightingObjShader->setVec3("light.diffuse", light_diffuse[0], light_diffuse[1], light_diffuse[2]);
    m_LightingObjShader->setVec3("light.specular", light_specular[0], light_specular[1], light_specular[2]);

    m_LightingObjShader->setVec3("material.ambient", ambient[0],ambient[1],ambient[2]);
    m_LightingObjShader->setVec3("material.diffuse", diffuse[0], diffuse[1], diffuse[2]);
    m_LightingObjShader->setVec3("material.specular", specular[0], specular[1], specular[2]);
    m_LightingObjShader->setFloat("material.shininess", shininess);

    glm::mat4 view = mainCamera->GetViewMatrix();
    auto projection = glm::perspective(mainCamera->Zoom, F_SCR_WIDTH / F_SCR_HEIGHT, 0.1f, 100.0f);

    glm::mat4 model(1);
    m_LightingObjShader->setMat4("model", model);
    m_LightingObjShader->setMat4("view", view);
    m_LightingObjShader->setMat4("projection", projection);


    glBindVertexArray(containerVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);

    m_LampShader->Use();

    m_LampShader->setMat4("projection", projection);
    m_LampShader->setMat4("view", view);
    model = glm::mat4(1);
    model = glm::translate(model, glm::vec3(lightPos[0], lightPos[1], lightPos[2]));
    model = glm::scale(model, glm::vec3(0.2f));

    m_LampShader->setMat4("model", model);
    m_LampShader->setVec3("lightColor", lightColor[0], lightColor[1], lightColor[2]);
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void HelloMaterials::OnWindowAttach(GLFWwindow *wnd) {
    Painter::OnWindowAttach(wnd);
}

void HelloMaterials::HandleInput(GLFWwindow *wnd) {
    Painter::HandleInput(wnd);
}

void HelloMaterials::OnMouseMoveCallback(GLFWwindow *window, double xpos, double ypos) {
    Painter::OnMouseMoveCallback(window, xpos, ypos);
}

void HelloMaterials::OnMouseScrollCallBack(GLFWwindow *window, double xoffset, double yoffset) {
    Painter::OnMouseScrollCallBack(window, xoffset, yoffset);
}

void HelloMaterials::OnDeInit() {
    Painter::OnDeInit();
}

void HelloMaterials::DrawLightParamWindow() {

}

void HelloMaterials::basic_light_exercise3() {

}

void HelloMaterials::basic_light_exercise4() {

}
