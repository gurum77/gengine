#pragma once
/**
	@brief
		- 4 x 4 matrix
*/
class G_EXT_CLASS CGMatrix
{
public:
	union
	{
		struct
		{
			double _11, _12, _13, _14;
			double _21, _22, _23, _24;
			double _31, _32, _33, _34;
			double _41, _42, _43, _44;
		};
		double m[4][4];
	};




	double       operator() (UINT Row, UINT Column) CONST{ return m[Row][Column]; }
	double&      operator() (UINT Row, UINT Column) { return m[Row][Column]; }

	CGMatrix&  operator= (CONST CGMatrix& M);
	CGMatrix&  operator*= (CONST CGMatrix& M);
	CGMatrix   operator* (CONST CGMatrix& M) CONST;
public:
	CGMatrix(double m00, double m01, double m02, double m03,
		double m10, double m11, double m12, double m13,
		double m20, double m21, double m22, double m23,
		double m30, double m31, double m32, double m33);
	
	CGMatrix();
	~CGMatrix();
};

