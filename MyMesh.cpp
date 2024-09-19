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
    // Defining some variables
    const int peak_count = 5; // How many peaks the star will have
    const float core_width = 2.f; // How thick the core is supposed to be

    // Adding the origin to the list
    vertices.emplace_back(center());

    glm::mat4 translation = translate(glm::vec4(core_width, 0, 0, 1));

    for (int i = 1; i < peak_count + 1; i++) {
      glm::mat4 rotation = rotate(i * (360 / peak_count));

      vertices.emplace_back(rotation * translation * glm::vec4(1, 1, 0, 1));

      edges.emplace_back(0, i);
      edges.emplace_back(i - 1, i);

      faces.emplace_back(0, i, i + 1);
    }

    // Adding the last face
    edges.emplace_back(1, peak_count);
    faces.emplace_back(0, 1, peak_count);
  }

  int MyMesh::vertexCount() const { return static_cast<int>(vertices.size()); }
  const glm::vec4 *MyMesh::vertexArray() const { return &vertices[0]; }

  int MyMesh::edgeCount() const { return static_cast<int>(edges.size()); }
  const MyMesh::Edge *MyMesh::edgeArray() const { return &edges[0]; }

  int MyMesh::faceCount() const { return static_cast<int>(faces.size()); }
  const MyMesh::Face *MyMesh::faceArray() const { return &faces[0]; }

  // TODO: Give the correct center
  glm::vec4 MyMesh::dimensions() const { return vector(10.f, 10.f); }
  glm::vec4 MyMesh::center() const { return point(0, 0); }

} // namespace cs200
