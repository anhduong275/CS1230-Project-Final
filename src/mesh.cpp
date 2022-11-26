#include "mesh.hpp"

void Mesh::insertVec3(glm::vec3 vertex)
{
    this->meshData.push_back(vertex[0]);
    this->meshData.push_back(vertex[1]);
    this->meshData.push_back(vertex[2]);
}