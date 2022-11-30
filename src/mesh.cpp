#include "mesh.hpp"

int Mesh::pushVertex(glm::vec3 v, glm::vec3 vn)
{
    vertices.push_back(v.x);
    vertices.push_back(v.y);
    vertices.push_back(v.z);
    vertices.push_back(vn.x);
    vertices.push_back(vn.y);
    vertices.push_back(vn.z);
    this->numVertices++;
    return numVertices;
}