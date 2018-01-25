/// \ingroup base
/// \class ttk::ftr::DynamicGraph
/// \author Gueunet Charles <charles.gueunet+ttk@gmail.com>
/// \date 2018-01-15
///
/// \brief TTK %fTRGraph dynamic graph tracking the evolution of level sets
///
/// This class deal with dynamic graph part of the algorithm, thracking the number of contour
/// on each vertex to deduce the Reeb graph.
/// This is done using an ST-tree.
///
/// \sa ttk::FTRGraph

#pragma once

#include "FTRCommon.h"

// TODO implement this using ST-tree.

namespace ttk
{
   namespace ftr
   {
      class DynamicGraph : public Allocable
      {
        private:
        public:
         DynamicGraph();
         virtual ~DynamicGraph();

         // Initialize functions
         // --------------------

         void alloc() override;

         void init() override;
      };
   }
}

