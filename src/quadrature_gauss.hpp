#ifndef QUADRATURE_GAUSS_HPP_
#define QUADRATURE_GAUSS_HPP_

#include "quadrature_types.hpp"

namespace quadrature
{
	static const Scalar GaussTable[10][2] ={{ 0.000000000000000, 2.000000000000000},
											{-0.577350269189626, 1.000000000000000},
											{ 0.577350269189626, 1.000000000000000},
											{-0.774596669241483, 0.555555555555556},
											{ 0.000000000000000, 0.888888888888889},
											{ 0.774596669241483, 0.555555555555556},
											{-0.861136311594053, 0.347854845137454},
											{-0.339981043584856, 0.652145154862546},
											{ 0.339981043584856, 0.652145154862546},
											{ 0.861136311594053, 0.347854845137454} };

	class IGauss
	{
	public:
		virtual ~IGauss() = default;

		virtual const Points& GetPoints() const = 0;
		virtual const Weights& GetWeights() const = 0;
		virtual const Counter& GetCounter() const = 0;
		virtual const Quadrature& GetQuadrature() const = 0;

		virtual void SetQuadrature(const Quadrature& value) = 0;

	protected:
		virtual const Index& GetIndex() const = 0;
	};

	class GaussHexa : public IGauss
	{
	public:
		GaussHexa();
		GaussHexa(const Quadrature& quadrature);

		~GaussHexa() = default;

		const Points& GetPoints() const override;
		const Weights& GetWeights() const override;
		const Counter& GetCounter() const override;
		const Quadrature& GetQuadrature() const override;

		void SetQuadrature(const Quadrature& quadrature) override;

	private:
		const Index& GetIndex() const override;
		void SetPoints();

		Quadrature quadrature_{ 2 };
		Index index_;
		Points points_;
		Counter counter_;
		Weights weights_;
	};

	//-----------------------------------------------------------------------------
	class GaussRect : public IGauss
	{
	public:
		GaussRect();
		GaussRect(const Quadrature& quadrature);

		~GaussRect() = default;

		const Points& GetPoints() const override;
		const Weights& GetWeights() const override;
		const Counter& GetCounter() const override;
		const Quadrature& GetQuadrature() const override;

		void SetQuadrature(const Quadrature& quadrature) override;

	private:
		const Index& GetIndex() const override;
		void SetPoints();

		Quadrature quadrature_{ 2 };
		Index index_;
		Points points_;
		Counter counter_;
		Weights weights_;
	};

	//-----------------------------------------------------------------------------
	class GaussLine : public IGauss, public std::enable_shared_from_this<GaussLine>
	{
	public:
		GaussLine();
		GaussLine(const Quadrature& quadrature);

		~GaussLine() = default;

		const Points& GetPoints() const override;
		const Weights& GetWeights() const override;
		const Counter& GetCounter() const override;
		const Quadrature& GetQuadrature() const override;

		void SetQuadrature(const Quadrature& quadrature) override;

	private:
		const Index& GetIndex() const override;
		void SetPoints();

		Quadrature quadrature_{ 2 };
		Index index_;
		Points points_;
		Counter counter_;
		Weights weights_;
	};

} //namespace quadrature

#endif /* QUADRATURE_GAUSS_HPP_ */