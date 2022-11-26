#include "spheremesh.hpp"

/**
 * @brief add a triangle, where vertices 1, 2 & 3 follow a counterclockwise order
 *
 * @param vertex1
 * @param vertex2
 * @param vertex3
 */
void SphereMesh::addTriangle(glm::vec3 vertex1, glm::vec3 vertex2, glm::vec3 vertex3)
{
    this->insertVec3(vertex1);
    this->insertVec3(glm::normalize(vertex1));
    this->insertVec3(vertex2);
    this->insertVec3(glm::normalize(vertex2));
    this->insertVec3(vertex3);
    this->insertVec3(glm::normalize(vertex3));
}

void SphereMesh::createIcosahedron()
{
    float phi = (1.0f + sqrt(5.0f)) * 0.5f; // golden ratio
    float a = 1.0f;
    float b = 1.0f / phi;

    glm::vec3 v1 = glm::normalize(glm::vec3((0, b, -a)));
    glm::vec3 v2 = glm::normalize(glm::vec3((b, a, 0)));
    glm::vec3 v3 = glm::normalize(glm::vec3((-b, a, 0)));
    glm::vec3 v4 = glm::normalize(glm::vec3((0, b, a)));
    glm::vec3 v5 = glm::normalize(glm::vec3((0, -b, a)));
    glm::vec3 v6 = glm::normalize(glm::vec3((-a, 0, b)));
    glm::vec3 v7 = glm::normalize(glm::vec3((0, -b, -a)));
    glm::vec3 v8 = glm::normalize(glm::vec3((a, 0, -b)));
    glm::vec3 v9 = glm::normalize(glm::vec3((a, 0, b)));
    glm::vec3 v10 = glm::normalize(glm::vec3((-a, 0, -b)));
    glm::vec3 v11 = glm::normalize(glm::vec3((b, -a, 0)));
    glm::vec3 v12 = glm::normalize(glm::vec3((-b, -a, 0)));

    this->addTriangle(v3, v2, v1);
    this->addTriangle(v2, v3, v4);
    this->addTriangle(v6, v5, v4);
    this->addTriangle(v5, v9, v4);
    this->addTriangle(v8, v7, v1);
    this->addTriangle(v7, v10, v1);
    this->addTriangle(v12, v11, v5);
    this->addTriangle(v11, v12, v7);
    this->addTriangle(v10, v6, v3);
    this->addTriangle(v6, v10, v12);
    this->addTriangle(v9, v8, v2);
    this->addTriangle(v8, v9, v11);
    this->addTriangle(v3, v6, v4);
    this->addTriangle(v9, v2, v4);
    this->addTriangle(v10, v3, v1);
    this->addTriangle(v2, v8, v1);
    this->addTriangle(v12, v10, v7);
    this->addTriangle(v8, v11, v7);
    this->addTriangle(v6, v12, v5);
    this->addTriangle(v11, v9, v5);
}