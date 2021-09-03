#pragma once

namespace cppio::meta
{
    template <class T, class U>
    concept derived = std::is_base_of<U, T>::value;

    // https://en.cppreference.com/w/cpp/utility/variant/visit
    template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
    template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;
} // namespace cppio::meta