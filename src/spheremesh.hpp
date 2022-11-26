#pragma once
#include "mesh.hpp"
#include <vector>
#include <glm/glm.hpp>

class SphereMesh : public Mesh
{
public:
    // void addVertex(glm::vec3 vertex);
    void addTriangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3);
    // void addFace();
    // std::vector<float> meshData;
    void createSphere();
    void createIcosahedron();
};