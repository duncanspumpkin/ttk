/// \ingroup base
/// \class ttk::JacobiSet
/// \author Julien Tierny <julien.tierny@lip6.fr>
/// \date June 2015.
///
/// \brief TTK processing package for the computation of the Jacobi set of
/// bivariate volumetric data.
///
/// Given a bivariate scalar field defined on a PL 3-manifold, this package
/// produces the list of Jacobi edges (each entry is a pair given by the edge
/// identifier and the Jacobi edge type).
/// \param dataTypeU Data type of the input first component field (char, float,
/// etc.).
/// \param dataTypeV Data type of the input second component field (char, float,
/// etc.)
///
/// \b Related \b publication \n
/// "Jacobi sets of multiple Morse functions" \n
/// Herbert Edelsbrunner, John Harer \n
/// Foundations of Computational Mathematics. Cambridge University Press, 2002.
///
/// \sa ttkJacobiSet.cpp %for a usage example.

#pragma once

// base code includes
#include <Debug.h>
#include <ScalarFieldCriticalPoints.h>
#include <Triangulation.h>
#include <UnionFind.h>
#include <vector>

namespace ttk {

  template <class dataTypeU, class dataTypeV>
  class JacobiSet : virtual public Debug {

  public:
    JacobiSet();

    int execute(std::vector<std::pair<SimplexId, char>> &jacobiSet);

    char getCriticalType(const SimplexId &edgeId);

    int perturbate(const dataTypeU &uEpsilon = Geometry::powIntTen(-DBL_DIG),
                   const dataTypeV &vEpsilon
                   = Geometry::powIntTen(-DBL_DIG)) const;

    inline void
      setEdgeFans(const std::vector<std::vector<SimplexId>> *edgeFans) {
      edgeFans_ = edgeFans;
    }

    inline void setEdgeFanLinkEdgeList(
      const std::vector<std::vector<std::pair<SimplexId, SimplexId>>>
        *edgeFanLinkEdgeLists) {
      edgeFanLinkEdgeLists_ = edgeFanLinkEdgeLists;
    }

    inline void setEdgeList(
      const std::vector<std::pair<SimplexId, SimplexId>> *edgeList) {
      edgeList_ = edgeList;
    }

    inline void setInputField(const void *uField, const void *vField) {
      uField_ = uField;
      vField_ = vField;
    }

    inline void setSosOffsets(std::vector<SimplexId> *sosOffsets) {
      // legacy API
      setSosOffsetsU(sosOffsets);
    }

    inline void setSosOffsetsU(std::vector<SimplexId> *sosOffsets) {
      sosOffsetsU_ = sosOffsets;
    }

    inline void setSosOffsetsV(std::vector<SimplexId> *sosOffsets) {
      sosOffsetsV_ = sosOffsets;
    }

    // NOTE: here it's not clear how vtk builds vtkIdType
    // to check on bigger data-sets
    inline void setTetList(const SimplexId *tetList) {
      tetList_ = tetList;
    }

    inline void setVertexNumber(const SimplexId &vertexNumber) {
      vertexNumber_ = vertexNumber;
    }

    inline void
      preconditionTriangulation(AbstractTriangulation *triangulation) {
      triangulation_ = triangulation;
      if(triangulation) {
        triangulation->preconditionEdges();
        triangulation->preconditionEdgeStars();
      }
    }

  protected:
    int executeLegacy(std::vector<std::pair<SimplexId, char>> &jacobiSet);

    SimplexId vertexNumber_{};
    const SimplexId *tetList_{};
    const void *uField_{}, *vField_{};
    const std::vector<std::pair<SimplexId, SimplexId>> *edgeList_{};
    // for each edge, one skeleton of its triangle fan
    const std::vector<std::vector<std::pair<SimplexId, SimplexId>>>
      *edgeFanLinkEdgeLists_{};
    // for each edge, the one skeleton of its triangle fan
    const std::vector<std::vector<SimplexId>> *edgeFans_{};
    std::vector<SimplexId> *sosOffsetsU_{}, *sosOffsetsV_{};
    std::vector<SimplexId> localSosOffsetsU_{}, localSosOffsetsV_{};
    AbstractTriangulation *triangulation_{};
  };
} // namespace ttk

// if the package is not a template, comment the following line
#include "JacobiSet_Template.h"
