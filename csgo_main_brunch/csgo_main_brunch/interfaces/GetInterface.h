#pragma once
#include <Windows.h>

template<typename c_type>
c_type* GetInterface(const char* moduleName, const char* interfaceName) {
    const auto handle = GetModuleHandle(moduleName);

    if (!handle)
        return nullptr;

    const auto functionAddress = GetProcAddress(handle, "CreateInterface");

    if (!functionAddress)
        return nullptr;

    using CreateInterfaceFn = c_type*(*)(const char*, int*);
 
    CreateInterfaceFn CreateInterface = reinterpret_cast<CreateInterfaceFn>(functionAddress);

    return CreateInterface(interfaceName, nullptr);
}