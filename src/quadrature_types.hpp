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
	using Counter = std::size_t;
	
	using Quadrature = std::size_t;
	const Quadrature quadrature_one = 1;
	const Quadrature quadrature_two = 2;
	const Quadrature quadrature_three = 3;
	const Quadrature quadrature_four = 4;
	const Quadrature quadrature_undefined = 0xFFFFFFFF;

} // namespace quadrature

#endif /* QUADRATURE_TYPES_HPP_ */