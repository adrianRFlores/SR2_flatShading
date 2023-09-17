#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <string>
#include <glm/glm.hpp>
#include "fragment.hpp"

struct Face
{
  std::array<int, 3> vertexIndices;
  std::array<int, 3> normalIndices;
  std::array<int, 3> texIndices;
};

bool loadOBJ(
    const std::string& path,
    std::vector<glm::vec3>& out_vertices,
    std::vector<Face>& out_faces,
    std::vector<glm::vec3>& out_normals,
    std::vector<glm::vec3>& out_tex
)
{
    std::ifstream file(path);
    if (!file)
    {
        std::cout << "Failed to open the file: " << path << std::endl;
        return false;
    }

    std::string line;
    std::istringstream iss;
    std::string lineHeader;
    glm::vec3 vertex;
    Face face;

    while (std::getline(file, line))
    {
        iss.clear();
        iss.str(line);
        iss >> lineHeader;

        if (lineHeader == "v")
        {
            iss >> vertex.x >> vertex.y >> vertex.z;
            out_vertices.push_back(vertex);
        }
        else if (lineHeader == "vn")
        {
            glm::vec3 normal;
            iss >> normal.x >> normal.y >> normal.z;
            out_normals.push_back(normal);
        }
        else if (lineHeader == "vt")
        {
            glm::vec3 tex;
            iss >> tex.x >> tex.y >> tex.z;
            out_tex.push_back(tex);
        }
        else if (lineHeader == "f")
        {
            Face face;
            for (int i = 0; i < 3; ++i)
            {
                std::string faceData;
                iss >> faceData;

                std::replace(faceData.begin(), faceData.end(), '/', ' ');

                std::istringstream faceDataIss(faceData);
                faceDataIss >> face.vertexIndices[i] >> face.texIndices[i] >> face.normalIndices[i];

                // obj indices are 1-based, so convert to 0-based
                face.vertexIndices[i]--;
                face.normalIndices[i]--;
                face.texIndices[i]--;
            }
            out_faces.push_back(face);
        }
    }

    return true;
}

std::vector<Vertex> setupVertexArray(const std::vector<glm::vec3>& vertices, const std::vector<Face>& faces, const std::vector<glm::vec3>& normals) {
    std::vector<Vertex> vertexArray;
    
    for (const auto& face : faces)
    {
        for(int i = 0; i < 3; ++i) {
            glm::vec3 pos = vertices[face.vertexIndices[i]];
            glm::vec3 normal = normals[face.normalIndices[i]];
            vertexArray.push_back(Vertex{pos, normal});
        }
    }

    return vertexArray;
}