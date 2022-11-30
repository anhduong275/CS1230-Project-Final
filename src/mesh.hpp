#pragma once
#include <vector>
#include "../glm/glm.hpp"

class Mesh
{
public:
    virtual int pushVertex(glm::vec3 v, glm::vec3 vn);
    // virtual method makes Mesh an abstract class (interface)
    virtual void pushTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) = 0;
    void addFace();

    int numVertices = 0;
    std::vector<float> vertices;
    std::vector<int> indices;
};