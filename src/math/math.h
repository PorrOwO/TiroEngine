#pragma once

#include "common/defines.h"

#define PI 3.14159265358979323846

static inline f32 radians(f32 degrees) { return degrees * (f32)PI / 180.0f; }
