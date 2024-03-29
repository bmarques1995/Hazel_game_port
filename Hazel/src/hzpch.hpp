#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Hazel/Core/Console.hpp"

#include "Hazel/Debugger/Instrumentor.hpp"

#ifdef HZ_PLATFORM_WINDOWS
	#include <Windows.h>
#endif