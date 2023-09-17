#pragma once
#include <glm/glm.hpp>
#include <vector>

std::vector<std::vector<Vertex>> primitiveAssembly(const std::vector<Vertex>& transformedVertices) {

    std::vector<std::vector<Vertex>> assembledVertices;

    if(transformedVertices.size() % 3 == 0) {

        for (int i = 0; i < transformedVertices.size(); i += 3) {
            std::vector<Vertex> triangle = {
                transformedVertices[i],
                transformedVertices[i + 1],
                transformedVertices[i + 2]
            };
            assembledVertices.push_back(triangle);
        }
    }

    return assembledVertices;
}