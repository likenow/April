#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <array>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "April/Core/Log.h"
#include "April/Tracing/Instrumentor.h"

#ifdef AL_PLATFORM_WINDOWS
    #include <Windows.h>
#endif