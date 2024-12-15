#ifndef QUADRATURE_TYPES_HPP_
#define QUADRATURE_TYPES_HPP_

#include "eilig.hpp"
#include <memory>

namespace quadrature
{
	using Scalar = eilig::Scalar;
	using Vector = eilig::Vector;
	using Index = eilig::Index;
	using Points = eilig::Vectors;
	using Weights = eilig::Scalars;

} // namespace quadrature

#endif /* QUADRATURE_TYPES_HPP_ */