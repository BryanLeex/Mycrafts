/*
 * @File Path: src/AsyncLog/AsyncLog.hpp
 * @Author: Bryan Lee
 * @Date: 2025-05-30 15:11:26
 * @Last Modified by:   Bryan Lee
 * @Last Modified time: 2025-05-30 15:11:26
 */

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <atomic>
#include <memory>
#include <vector>
#include <format>

#include "../Singleton/Singleton.hpp"

namespace AsyncLog {

enum class level_enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

enum class dist_enum {
    CONSOLE,
    FILE,
};

class Logger : public Singleton<Logger> {
public:
    virtual ~Logger() = default;

    template <typename... Args>
    void print(level_enum level, const std::string &fmt, Args &&...args) {
        std::string level_str;
        switch (level) {
        case level_enum::DEBUG:
            level_str = "[DEBUG] ";
            break;
        case level_enum::INFO:
            level_str = "[INFO]  ";
            break;
        case level_enum::WARNING:
            level_str = "[WARN]  ";
            break;
        case level_enum::FATAL:
            level_str = "[FATAL] ";
            break;
        default:
            throw std::runtime_error("Unknow level");
            break;
        }

        for (auto &dist : _logFiles) {
            dist << std::vformat(level_str + fmt + '\n', std::make_format_args(args...));
        }
        if (_logConsole) {
            std::cout << std::vformat(level_str + fmt + '\n', std::make_format_args(args...));
        }
    }

    template <typename... Args>
    void debug(const std::string &fmt, Args &&...args) {
        print(level_enum::DEBUG, fmt, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void info(const std::string &fmt, Args &&...args) {
        print(level_enum::INFO, fmt, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void warn(const std::string &fmt, Args &&...args) {
        print(level_enum::WARNING, fmt, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void err(const std::string &fmt, Args &&...args) {
        print(level_enum::ERROR, fmt, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void fatal(const std::string &fmt, Args &&...args) {
        print(level_enum::FATAL, fmt, std::forward<Args>(args)...);
    }

    size_t addDistinationFile(const std::string &filename) {
        std::ofstream distfile(filename, std::ios::app | std::ios::out);
        if (!distfile.is_open()) {
            throw std::runtime_error("Failed to open the log file");
        }
        _logFiles.emplace_back(std::move(distfile));
        info(R"(Distination file change to "{}"!)", filename);
        return _logFiles.size();
    }

    void enableConsoleOutput() {
        _logConsole = true;
    }

    void disableConsoleOutput() {
        _logConsole = false;
    }

private:
    friend class Singleton<Logger>;

    Logger() {
    };

    bool _logConsole;
    std::vector<std::ofstream> _logFiles;
    std::atomic<bool> _exitFlag;
};

}; // namespace AsyncLog
