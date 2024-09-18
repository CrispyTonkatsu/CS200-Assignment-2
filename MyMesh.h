/**
 * File: MyMesh.hpp
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Assignment: 1
 * Course: CS200
 * Term: FALL24
 */

#pragma once

#include <cstdlib>
#include <vector>
#include "Mesh.h"

namespace cs200 {
  class MyMesh final : public cs200::Mesh {
  public:
    MyMesh() = default;

  private:
  std::vector<glm::vec4> vertices{};
  std::vector<Edge> edges{};
  std::vector<Face> faces{};

  };
} // namespace cs200
