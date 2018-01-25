/// \ingroup base
/// \class ttk::ftr::Propagation
/// \author Gueunet Charles <charles.gueunet+ttk@gmail.com>
/// \date 2018-01-15
///
/// \brief TTK %fTRGraph propagation management with Fibonacci heaps
///
/// This class deal with scalar related operations: store them, compare them, ...
///
/// \sa ttk::FTRGraph

#pragma once

#include "FTRCommon.h"

// TODO implement this using fibonacci heaps

namespace ttk
{
   namespace ftr
   {
      class Propagation : public Allocable
      {
        private:
        public:
         Propagation();
         virtual ~Propagation();

         // Initialize functions
         // --------------------

         void alloc() override;

         void init() override;
      };
   }
}
