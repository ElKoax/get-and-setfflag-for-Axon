// Credits to GoGo or whatever his name is for the orignal functions

// you just pop this in your axon paste! and boom u got it :)
// ill keep these offsets updated weekly.

typedef bool(__cdecl* FLog)(const std::string& name, std::string& value, bool alsoCheckUnknown);
FLog GetValue = reinterpret_cast<FLog>(x(0x015A55F0));

typedef bool(__cdecl* SLog)(const std::string& name, const std::string& value, int Type, bool loadedFromServer);
SLog SetValue = reinterpret_cast<SLog>(x(0x015A5DB0));

int impl_getflag(lua_State* L)
{
    Bridge::push(L, m_rL, 1);
    std::string flag = lua_tostring(L, 1);
    std::string ret;
    bool out = GetValue(flag, ret, 1);
    if (!out)
        luaL_error(L, "flag not found u coon");
    lua_pushstring(L, ret.c_str());
    return 1;
}

int impl_setfflag(lua_State* L)
{
    Bridge::push(L, m_rL, 1);
    std::string flag = lua_tostring(L, 1);
    std::string value = lua_tostring(L, 2);
    std::string ret;
    bool exist = GetValue(flag, ret, 1);
    if (!exist)
        luaL_error(L, "flag not found u coon");
    SetValue(flag, value, 63, 0);
    return 0;
}
