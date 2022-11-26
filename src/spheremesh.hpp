#pragma once
#include "mesh.hpp"
#include <vector>
#include <glm/glm.hpp>
#include<tuple>
#include <unordered_map>

struct Edge {
    int left;
    int right;
};

class SphereMesh : public Mesh
{
public:
    void pushTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);
    void subdivide();
    // void addFace();
    // std::vector<float> meshData;
    void createSphere();
    void createIcosahedron();
private:
    std::unordered_map<Edge, int> edgeMap;
};