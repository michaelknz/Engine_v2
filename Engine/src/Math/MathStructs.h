#pragma once
#include <array>
#define PI 3.14159265358979323846

struct Vector3f {
	float x;
	float y;
	float z;
	Vector3f(float x, float y, float z);
	Vector3f();
	Vector3f operator+(Vector3f other);
};

struct Matrix4x4f {
	std::array<float, 16> mas;
	Matrix4x4f();
	Matrix4x4f(const std::array<float, 16>& mas);
	Matrix4x4f operator*(Matrix4x4f other);
};

Matrix4x4f operator*(float scale, const Matrix4x4f& mat);
Matrix4x4f operator*(const Matrix4x4f& mat, float scale);
Vector3f operator*(float scale, const Vector3f& vec);
Vector3f operator*(const Vector3f& vec, float scale);