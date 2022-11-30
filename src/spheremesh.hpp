#pragma once
#include "mesh.hpp"
#include <vector>
// #include <glm/glm.hpp>
#include <glm.hpp>
#include <tuple>
// #include <unordered_map>
#include <map>
#include <utility>
#include <GL/glew.h>
#include "debug.hpp"

class SphereMesh : public Mesh
{
public:
    SphereMesh() { createIcosahedron(); }
    void pushTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);
    void subdivide();
    // void addFace();
    // std::vector<float> meshData;
    void createSphere();
    void createIcosahedron();

    void generateBuffers();
    void deleteBuffers();
    void initializeBuffers();
    GLuint vbo;
    GLuint vao;
    GLuint ebo; // index buffer

private:
    std::map<std::pair<int, int>, int> edgeMap; // pair = (left, right)
};