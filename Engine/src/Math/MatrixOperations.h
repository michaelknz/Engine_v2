#pragma once
#include "MathStructs.h"

class MatrixOperations {
public:
	MatrixOperations();
	~MatrixOperations();
	static Matrix4x4f Translate(const Vector3f& vec);
	static Matrix4x4f Rotation(const Vector3f& angle);
	static Matrix4x4f Scale(const Vector3f& scales);

};