/**
 * File: MyMesh.hpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 1
 * Course: CS200
 * Term: FALL24
 */

#include "MyMesh.h"
#include <array>
#include "Affine.h"

namespace cs200 {
  MyMesh::MyMesh() {
    std::array<glm::vec4, 3> triangle = {
        glm::vec4(1, 0, 0, 1),
        glm::vec4(-1, 1, 0, 1),
        glm::vec4(-1, -1, 0, 1),
    };

    for (int i = 0; i < 3; i++) {
      glm::mat4 rotation = rotate(i );

      vertices.push_back(rotation * triangle[0]);
      vertices.push_back(rotation * triangle[1]);
      vertices.push_back(rotation * triangle[2]);

      edges.emplace_back(i, i + 1);
      edges.emplace_back(i + 1, i + 2);
      edges.emplace_back(i, i + 2);

      faces.emplace_back(i, i + 1, i + 2);
    }
  }

  int MyMesh::vertexCount() const { return static_cast<int>(vertices.size()); }
  const glm::vec4 *MyMesh::vertexArray() const { return &vertices[0]; }

  int MyMesh::edgeCount() const { return static_cast<int>(edges.size()); }
  const MyMesh::Edge *MyMesh::edgeArray() const { return &edges[0]; }

  int MyMesh::faceCount() const { return static_cast<int>(faces.size()); }
  const MyMesh::Face *MyMesh::faceArray() const { return &faces[0]; }

  // TODO: Give the correct center
  glm::vec4 MyMesh::dimensions() const { return vector(2.f, 2.f); }
  glm::vec4 MyMesh::center() const { return point(0, 0); }

} // namespace cs200
