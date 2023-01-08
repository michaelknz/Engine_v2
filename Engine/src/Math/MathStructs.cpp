#include "MathStructs.h"

Vector3f::Vector3f(float x, float y, float z)
	:x(x), y(y), z(z)
{

}

Vector3f::Vector3f()
	:x(0), y(0), z(0)
{

}

Vector3f Vector3f::operator+(Vector3f other)
{
	return Vector3f(x + other.x, y + other.y, z + other.z);
}

Matrix4x4f operator*(double scale, const Matrix4x4f& mat)
{
	Matrix4x4f output;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			output.mas[i * 4 + j] = mat.mas[i * 4 + j] * scale;
		}
	}
	return output;
}

Matrix4x4f operator*(const Matrix4x4f& mat, double scale)
{
	return scale * mat;
}

Matrix4x4f::Matrix4x4f()
{
	mas = {};
	for (int i = 0; i < 4; ++i) {
		mas[i * 4 + i] = 1.0f;
	}
}

Matrix4x4f::Matrix4x4f(const std::array<float, 16>& mas)
{
	this->mas = mas;
}

Matrix4x4f Matrix4x4f::operator*(Matrix4x4f other)
{
	Matrix4x4f output;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			float tmp = 0.0;
			for (int k = 0; k < 4; ++k) {
				tmp += mas[i * 4 + k] * other.mas[k * 4 + j];
			}
			output.mas[i * 4 + j] = tmp;
		}
	}
	return output;
}