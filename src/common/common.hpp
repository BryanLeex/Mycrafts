/*
 * @File Path: src/common/common.hpp
 * @Author: Bryan Lee
 * @Date: 2025-05-30 15:11:02
 * @Last Modified by: Bryan Lee
 * @Last Modified time: 2025-05-30 15:30:51
 */

#pragma once

#include <vector>
#include <string>
#include <exception>

#include "../AsyncLog/AsyncLog.hpp"

#include "../Singleton/Singleton.hpp"

#define for_range(var, n) for (int(var) = 0; (var) < (n); (var++))

#define logger AsyncLog::Logger::GetInstance().get()
