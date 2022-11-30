#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <vector>
#include <cmath>

#include "gl_framework.hpp"
#include "shader_util.hpp"

#include "../glm/vec3.hpp"
#include "../glm/vec4.hpp"
#include "../glm/mat4x4.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/string_cast.hpp"
#include "spheremesh.hpp"
#include "debug.hpp"

#define BUFFER_OFFSET(offset) (reinterpret_cast<void *>(offset))

class View
{
  // screen size
  GLfloat half_width;
  GLfloat half_height;
  GLfloat half_depth;

  GLuint shaderProgram;

  glm::mat4 modelMatrix;
  glm::mat4 viewMatrix;
  glm::mat4 projMatrix;

  SphereMesh sphere;

  void initShadersGL();
  void initBuffersGL();

public:
  View(GLfloat h_width, GLfloat h_height, GLfloat h_depth);
  void renderGL();
};

#endif // VIEW_HPP_
