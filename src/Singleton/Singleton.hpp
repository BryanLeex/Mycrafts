/*
 * @File Path: src/Singleton/Singleton.hpp
 * @Author: Bryan Lee
 * @Date: 2025-05-30 15:09:23
 * @Last Modified by: Bryan Lee
 * @Last Modified time: 2025-05-30 15:09:50
 */

#pragma once

#include <memory>
#include <mutex>
#include <iostream>
namespace __singleton_details {

template <typename T>
class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton<T> &single) = delete;
    const Singleton &operator=(const Singleton<T> &_) = delete;

    static std::shared_ptr<T> _singleton;

public:
    virtual ~Singleton() = default;

    static std::shared_ptr<T> GetInstance() {
        static std::once_flag flag;
        std::call_once(flag, [&] {
            _singleton = std::shared_ptr<T>(new T());
        });
        return _singleton;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_singleton = nullptr;

} // namespace __singleton_details

using __singleton_details::Singleton;
