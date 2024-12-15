#include "quadrature_gauss.hpp"

namespace quadrature
{
GaussHexaPtr CreateGaussHexa()
{
	auto res = GaussHexa::Create();

	return res;
}
GaussHexaPtr GaussHexa::Create()
{
	class MakeSharedEnabler : public GaussHexa
	{
	};

	auto res = std::make_shared<MakeSharedEnabler>();

	return res;
}
GaussHexaPtr GaussHexa::GetPtr()
{
	return this->shared_from_this();
}
ConstGaussHexaPtr GaussHexa::GetPtr() const
{
	return const_cast<GaussHexa*>(this)->GetPtr();
}	
GaussHexa::GaussHexa()
{
	SetQuadrature(quadrature_);
}
const Index& GaussHexa::GetIndex() const
{
	return index_;
}
const Points& GaussHexa::GetPoints() const
{
	return points_;
}
const Weights& GaussHexa::GetWeights() const
{
	return weights_;
}
const Counter& GaussHexa::GetCounter() const
{
	return counter_;
}
const Quadrature& GaussHexa::GetQuadrature() const
{
	return quadrature_;
}
void GaussHexa::SetQuadrature(const Quadrature& value)
{
	switch (value)
	{
	case 1:
		quadrature_ = 1;
		index_ = 0;
		break;
	case 2:
		quadrature_ = 2;
		index_ = 1;
		break;
	case 3:
		quadrature_ = 3;
		index_ = 3;
		break;
	case 4:
		quadrature_ = 4;
		index_ = 6;
		break;
	default:
		quadrature_ = 2;
		index_ = 1;
		break;
	}

	SetPoints();
}
void GaussHexa::SetPoints()
{
	Vector point(3);

	counter_ = 0;
	points_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 3));
	weights_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 3));

	for (Quadrature i = 0; i < quadrature_; ++i)
	{
		for (Quadrature j = 0; j < quadrature_; ++j)
		{
			for (Quadrature  k = 0; k < quadrature_; ++k)
			{
				point(0) = GaussTable[i + index_][0];
				point(1) = GaussTable[j + index_][0];
				point(2) = GaussTable[k + index_][0];
				
				points_[counter_] = point;
				weights_[counter_] = GaussTable[i + index_][1] * GaussTable[j + index_][1] * GaussTable[k + index_][1];
				
				++counter_;
			}
		}
	}
}

GaussRectPtr CreateGaussRect()
{
	auto res = GaussRect::Create();

	return res;
}
GaussRectPtr GaussRect::Create()
{
	class MakeSharedEnabler : public GaussRect
	{
	};

	auto res = std::make_shared<MakeSharedEnabler>();

	return res;
}
GaussRectPtr GaussRect::GetPtr()
{
	return this->shared_from_this();
}
ConstGaussRectPtr GaussRect::GetPtr() const
{
	return const_cast<GaussRect*>(this)->GetPtr();
}
GaussRect::GaussRect()
{
	SetQuadrature(quadrature_);
}
const Index& GaussRect::GetIndex() const
{
	return index_;
}		
const Points& GaussRect::GetPoints() const
{
	return points_;
}
const Weights& GaussRect::GetWeights() const
{
	return weights_;
}
const Counter& GaussRect::GetCounter() const
{
	return counter_;
}
const Quadrature& GaussRect::GetQuadrature() const
{
	return quadrature_;
}
void GaussRect::SetQuadrature(const Quadrature& value)
{
	switch (value)
	{
	case 1:
		quadrature_ = 1;
		index_ = 0;
		break;
	case 2:
		quadrature_ = 2;
		index_ = 1;
		break;
	case 3:
		quadrature_ = 3;
		index_ = 3;
		break;
	case 4:
		quadrature_ = 4;
		index_ = 6;
		break;
	default:
		quadrature_ = 2;
		index_ = 1;
		break;
	}

	SetPoints();
}
void GaussRect::SetPoints()
{
	Vector point(2);

	counter_ = 0;
	weights_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 2));
	points_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 2));

	for (Quadrature i = 0; i < quadrature_; ++i)
	{
		for (Quadrature j = 0; j < quadrature_; ++j)
		{
			point(0) = GaussTable[i + index_][0];
			point(1) = GaussTable[j + index_][0];
			
			points_[counter_] = point;
			weights_[counter_] = GaussTable[i + index_][1] * GaussTable[j + index_][1];
			
			++counter_;
		}
	}
}

GaussLinePtr CreateGaussLine()
{
	auto res = GaussLine::Create();

	return res;
}
GaussLinePtr GaussLine::Create()
{
	class MakeSharedEnabler : public GaussLine
	{
	};

	auto res = std::make_shared<MakeSharedEnabler>();

	return res;
}
GaussLinePtr GaussLine::GetPtr()
{
	return this->shared_from_this();
}
ConstGaussLinePtr GaussLine::GetPtr() const
{
	return const_cast<GaussLine*>(this)->GetPtr();
}
GaussLine::GaussLine()
{
	SetQuadrature(quadrature_);
}
const Index& GaussLine::GetIndex() const
{
	return index_;
}		
const Points& GaussLine::GetPoints() const
{
	return points_;
}
const Weights& GaussLine::GetWeights() const
{
	return weights_;
}
const Counter& GaussLine::GetCounter() const
{
	return counter_;
}
const Quadrature& GaussLine::GetQuadrature() const
{
	return quadrature_;
}
void GaussLine::SetQuadrature(const Quadrature& value)
{
	switch (value)
	{
	case 1:
		quadrature_ = 1;
		index_ = 0;
		break;
	case 2:
		quadrature_ = 2;
		index_ = 1;
		break;
	case 3:
		quadrature_ = 3;
		index_ = 3;
		break;
	case 4:
		quadrature_ = 4;
		index_ = 6;
		break;
	default:
		quadrature_ = 2;
		index_ = 1;
		break;
	}

	SetPoints();
}
void GaussLine::SetPoints()
{
	Vector point(1);

	counter_ = 0;
	weights_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 1));
	points_.resize(utils::math::Power(static_cast<unsigned int>(quadrature_), 1));

	for (Quadrature i = 0; i < quadrature_; ++i)
	{
		point(0) = GaussTable[i + index_][0];
		
		points_[counter_] = point;
		weights_[counter_] = GaussTable[i + index_][1];
		
		++counter_;
	}
}
} //namespace quadrature