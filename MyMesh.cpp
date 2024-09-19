/**
 * File: MyMesh.hpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 1
 * Course: CS200
 * Term: FALL24
 */

#include "MyMesh.h"
#include <glm/fwd.hpp>
#include "Affine.h"

namespace cs200 {
  MyMesh::MyMesh() {
  vertices.emplace_back(30.f,30.f,30.f,30.f);
  vertices.emplace_back(-30.f,30.f,30.f,30.f);
  vertices.emplace_back(-30.f,-30.f,30.f,30.f);
  vertices.emplace_back(0.f,0.f,0.f,0.f);

  edges.emplace_back(0,1);
  edges.emplace_back(1,2);
  edges.emplace_back(2,3);
  edges.emplace_back(3,0);

  faces.emplace_back(0,1,2);
  faces.emplace_back(3,1,2);
}

  int MyMesh::vertexCount() const { return static_cast<int>(vertices.size()); }
  const glm::vec4 *MyMesh::vertexArray() const { return &vertices[0]; }

  int MyMesh::edgeCount() const { return static_cast<int>(edges.size()); }
  const MyMesh::Edge *MyMesh::edgeArray() const { return &edges[0]; }

  int MyMesh::faceCount() const { return static_cast<int>(faces.size()); }
  const MyMesh::Face *MyMesh::faceArray() const { return &faces[0]; }

// TODO: Give the correct center
  glm::vec4 MyMesh::dimensions() const { return vector(30.f, 30.f); }
  glm::vec4 MyMesh::center() const { return point(0, 15); }

} // namespace cs200
