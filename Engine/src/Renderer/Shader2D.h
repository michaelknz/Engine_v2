#pragma once
#include "Core/Shader.h"

class Shader2D : public Shader {
public:
	Shader2D();
	~Shader2D() override;
private:
	void MakeProg(const std::string& shader_name) override;
};