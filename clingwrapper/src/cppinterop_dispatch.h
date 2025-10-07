#ifndef CPPINTEROP_DISPATCH_H
#define CPPINTEROP_DISPATCH_H

#include <dlfcn.h>
#include <mutex>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>
#include <CppInterOp/CppInterOpDispatch.h>

// static inline void* dlGetProcAddress(const char* name, std::optional<void*> libHandle = std::nullopt)
static inline void* dlGetProcAddress(const char* name)
{
    if (!name) return nullptr;

    static std::once_flag loaded;
    static void* handle = nullptr;
    static void* (*getCppProcAddress)(const char*) = nullptr;
    static bool initialization_successful = false;
    
    // Initialize the library once
    std::call_once(loaded, []() {
        const char* libPath = "/home/ajomy/cppyy-interop-dev/CppInterOp/build/lib/libclangCppInterOp.so";
        handle = dlopen(libPath, RTLD_LOCAL | RTLD_NOW);
        if (!handle) {
            std::cout << "Failed to open library: " << dlerror() << std::endl;
            return;
        }
        
        getCppProcAddress = reinterpret_cast<void*(*)(const char*)>(dlsym(handle, "CppGetProcAddress"));
        if (!getCppProcAddress) {
            std::cout << "Failed to find CppGetProcAddress: " << dlerror() << std::endl;
            dlclose(handle);
            handle = nullptr;
            return;
        }
        
        initialization_successful = true;
    });
    if (!initialization_successful || !getCppProcAddress) {
        return nullptr;
    }
    return getCppProcAddress(name);
}

namespace CppDispatch {
    FOR_EACH_CPP_FUNCTION(EXTERN_CPP_FUNC);

static inline int init_functions() {
    FOR_EACH_CPP_FUNCTION(LOAD_CPP_FUNCTION);
    return 0;
}
}
#endif // CPPINTEROP_DISPATCH_H
