#pragma once
extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
#include "BehaviorScript.h"

class LuaScript :public BehaviorScript {
public:
	LuaScript();
	~LuaScript() override;
private:

};