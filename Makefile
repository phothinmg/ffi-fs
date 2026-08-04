# Target Names
DLL_TARGET = lib/ffifs.dll
SO_TARGET  = lib/ffifs.so

# Compilers
WIN_CXX   = i686-w64-mingw32-g++
LIN_CXX   = g++

# Compiler and Linker Flags
CXXFLAGS  = -O2 -Wall -std=c++17
WIN_LDFLAGS = -shared -Wl,--add-stdcall-alias
LIN_LDFLAGS = -shared

# Source file
SRCS = main.cpp

# Distinct object files to avoid cross-contamination
WIN_OBJS = main_win.o
LIN_OBJS = main_lin.o


win32: $(DLL_TARGET) 

# --- Windows DLL Build Rules ---
$(DLL_TARGET): $(WIN_OBJS)
	$(WIN_CXX) $(WIN_LDFLAGS) -o $@ $(WIN_OBJS)

main_win.o: $(SRCS)
	$(WIN_CXX) $(CXXFLAGS) -c $< -o $@

linux: $(SO_TARGET)
# --- Linux Shared Object Build Rules ---
$(SO_TARGET): $(LIN_OBJS)
	$(LIN_CXX) $(LIN_LDFLAGS) -o $@ $(LIN_OBJS)

main_lin.o: $(SRCS)
	$(LIN_CXX) $(CXXFLAGS) -fPIC -c $< -o $@

# Clean rule
clean:
	rm -f $(WIN_OBJS) $(LIN_OBJS)

.PHONY: linux win32 clean
