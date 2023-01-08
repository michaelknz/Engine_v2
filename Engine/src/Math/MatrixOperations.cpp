#include "MatrixOperations.h"
#include <cmath>

MatrixOperations::MatrixOperations()
{

}

MatrixOperations::~MatrixOperations()
{

}

Matrix4x4f MatrixOperations::Translate(const Vector3f& vec)
{
	Matrix4x4f output;
	output.mas[3] = vec.x;
	output.mas[7] = vec.y;
	output.mas[11] = vec.z;
	return output;
}

Matrix4x4f MatrixOperations::Rotation(const Vector3f& angle)
{
	Vector3f rad_angle(angle.x * ((float)PI / 180.0f), angle.y * ((float)PI / 180.0f), angle.z * ((float)PI / 180.0f));

	Matrix4x4f output;
	output.mas[0] = cos(rad_angle.y) * cos(rad_angle.z);
	output.mas[1] = sin(rad_angle.z);
	output.mas[2] = -sin(rad_angle.y);
	output.mas[3] = 0;
	output.mas[4] = -sin(rad_angle.z);
	output.mas[5] = cos(rad_angle.x) * cos(rad_angle.z);
	output.mas[6] = sin(rad_angle.x);
	output.mas[7] = 0;
	output.mas[8] = sin(rad_angle.y);
	output.mas[9] = -sin(rad_angle.x);
	output.mas[10] = cos(rad_angle.x) * cos(rad_angle.y);
	output.mas[11] = 0;
	output.mas[12] = 0;
	output.mas[13] = 0;
	output.mas[14] = 0;
	output.mas[15] = 1;

	return output;
}

Matrix4x4f MatrixOperations::Scale(const Vector3f& scales)
{
	Matrix4x4f output;
	output.mas[0] = scales.x;
	output.mas[5] = scales.y;
	output.mas[10] = scales.z;
	return output;
}