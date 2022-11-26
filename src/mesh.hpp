#pragma once
#include <vector>
#include <glm/glm.hpp>

class Mesh
{
public:
    int pushVertex(glm::vec3 v, glm::vec2 vt, glm::vec3 vn);
    // virtual method makes Mesh an abstract class (interface)
    virtual void addTriangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3) = 0;
    void addFace();

    int numVertices = 0;
    std::vector<float> vertices;
    std::vector<int> indices;
};