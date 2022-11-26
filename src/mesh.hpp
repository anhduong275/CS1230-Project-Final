#pragma once
#include <vector>
#include <glm/glm.hpp>

class Mesh
{
public:
    void insertVec3(glm::vec3 vertex);
    // virtual method makes Mesh an abstract class (interface)
    virtual void addTriangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3) = 0;
    void addFace();
    std::vector<float> meshData;
};