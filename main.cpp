#if defined(_WIN32) || defined(__WIN32__)
#include <windows.h>
#define FFI_EXPORT __declspec(dllexport)
#elif defined(__APPLE__) || defined(__MACH__)
#define FFI_EXPORT __attribute__((visibility("default")))
#else
#define FFI_EXPORT __attribute__((visibility("default")))
#endif

#include <cstring>
#include <cstdlib>
#include <algorithm> // For std::min
#include "ffi_fs.hpp"

#if defined(_WIN32) || defined(__WIN32__)
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
#endif

// This block strips out C++ name mangling so JavaScript can find 'writeFile' and 'readFile'
extern "C"
{
    // 1. Read File Wrapper
    FFI_EXPORT unsigned int readFile(const char *filePath, char *output, unsigned int outputSize)
    {
        if (!filePath || !output || outputSize == 0)
        {
            if (output && outputSize > 0)
            {
                output[0] = '\0';
            }
            return 0;
        }
        std::string content = ffifs::readFile(std::string(filePath));
        const unsigned int length = static_cast<unsigned int>(std::min(content.size(), static_cast<size_t>(outputSize - 1)));
        std::memcpy(output, content.c_str(), length);
        output[length] = '\0';
        return length;
    }

    // 2. Write File Wrapper (Must accept plain C-strings!)
    FFI_EXPORT void writeFile(const char *path, const char *content)
    {
        if (!path || !content)
            return;
        ffifs::writeFile(std::string(path), std::string(content));
    }

    // 3. Memory Cleanup Function
    FFI_EXPORT void free_string(char *ptr)
    {
        std::free(ptr);
    }
}
