#pragma once

#include "../../../collections/HashMap/include/HashMap.hpp"

template <typename Key, typename T, typename Hash = std::hash<Key>>
using IDictionary = HashMap<Key, T, Hash>;