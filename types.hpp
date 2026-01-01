#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include <deque>
#include <tuple>
#include <utility>
#include <type_traits>

namespace types {

    using std::string;

    template <typename K, typename V>
    using dict = std::unordered_map<K, V>;

    using std::vector;
    using std::deque;
    using std::tuple;

    // Union de tipos (variant)
    template <typename... TS>
    using TypeUnion = std::variant<TS...>;

    // holds_alternative seguro
    template <typename T, typename Variant>
    bool GetTypeUnion(const Variant& v) {
        return std::holds_alternative<T>(v);
    }

    // tuple get genérico
    template <std::size_t I>
    constexpr auto TupleGet = [](auto&& t) -> decltype(auto) {
        return std::get<I>(std::forward<decltype(t)>(t));
    };

    // primero
    constexpr auto TupleGetFirst = [](auto&& t) -> decltype(auto) {
        return std::get<0>(std::forward<decltype(t)>(t));
    };

    // último
    constexpr auto TupleGetLast = [](auto&& t) -> decltype(auto) {
        using T = std::remove_reference_t<decltype(t)>;
        constexpr std::size_t N = std::tuple_size_v<T>;
        static_assert(N > 0, "tuple vacio: no hay ultimo elemento");
        return std::get<N - 1>(std::forward<decltype(t)>(t));
    };

    using Integer   = long long;
    using u_Integer = unsigned long long;
    using Float     = double;
    using Char      = char;
    using C_str     = const char*;
}
