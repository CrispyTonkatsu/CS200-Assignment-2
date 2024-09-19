/**
 * File: MyMesh.hpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 1
 * Course: CS200
 * Term: FALL24
 */

#include "MyMesh.h"

namespace cs200 {

  int MyMesh::vertexCount() const { return static_cast<int>(vertices.size()); }
  const glm::vec4 *MyMesh::vertexArray() const { return &vertices[0]; }

  int MyMesh::edgeCount() const { return static_cast<int>(edges.size()); }
  const MyMesh::Edge *MyMesh::edgeArray() const { return &edges[0]; }

  int MyMesh::faceCount() const { return static_cast<int>(faces.size()); }
  const MyMesh::Face *MyMesh::faceArray() const { return &faces[0]; }

  glm::vec4 MyMesh::dimensions() const {}
  glm::vec4 MyMesh::center() const {}

} // namespace cs200
