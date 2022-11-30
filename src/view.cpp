#include "view.hpp"

#include <string>

View::View(GLfloat h_width, GLfloat h_height, GLfloat h_depth)
{
  half_width = h_width;
  half_height = h_height;
  half_depth = h_depth;

  initShadersGL();
  initBuffersGL();

  modelMatrix = glm::mat4(1);
  glm::vec3 eye(3.0f, 3.0f, 3.0f);
  glm::vec3 look(0.0f, 0.0f, 0.0f);
  glm::vec3 up(0.0f, 2.0f, 0.0f);
  // viewMatrix = glm::lookAt(eye, look, up);
  // projMatrix = glm::perspective(45.0f, (h_width / h_height), 1.0f, 100.0f);
  viewMatrix = glm::mat4(1);
  projMatrix = glm::mat4(1);
  sphere = SphereMesh();
  for (float v : sphere.vertices)
  {
    std::cout << v << " " << std::endl;
  }
}

void View::initShadersGL()
{
  Debug::glErrorCheck();
  std::string vertex_shader_file("shaders/vshader.glsl");
  Debug::glErrorCheck();
  std::string fragment_shader_file("shaders/fshader.glsl");
  Debug::glErrorCheck();

  std::vector<GLuint> shaderList;
  shaderList.push_back(mynamespace::loadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
  shaderList.push_back(mynamespace::loadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));
  Debug::glErrorCheck();

  shaderProgram = mynamespace::createProgramGL(shaderList);
  Debug::glErrorCheck();
  glUseProgram(shaderProgram);
  Debug::glErrorCheck();
}

void View::initBuffersGL()
{
  sphere.generateBuffers();
  sphere.initializeBuffers();
}

void View::renderGL()
{
  Debug::glErrorCheck();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBindBuffer(GL_ARRAY_BUFFER, sphere.vao);
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphere.ebo); // caused error
  // glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
  Debug::glErrorCheck();
  // glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
  Debug::glErrorCheck();
  // glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projMatrix"), 1, GL_FALSE, glm::value_ptr(projMatrix));
  Debug::glErrorCheck();
  //  glDrawElements(GL_TRIANGLES, sphere.indices.size(), GL_UNSIGNED_INT, (void *)0);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  Debug::glErrorCheck();
}
