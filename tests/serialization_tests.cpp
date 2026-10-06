#include <bigint23/bigint.hpp>

#include <gtest/gtest.h>

#include <array>
#include <span>
#include <sstream>

namespace {
    constexpr auto BYTE_ARRAY_BIG_ENDIAN = std::to_array<std::uint8_t>({0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF});
    constexpr auto BYTE_ARRAY_LITTLE_ENDIAN = std::to_array<std::uint8_t>({0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE});

    TEST(bigint23, serialize_to_bytes) {
        std::istringstream iss("deadbeefdeadbeefdeadbeefdeadbeef");
        iss >> std::hex;
        bigint::bigint<bigint::BitWidth(128), bigint::Signedness::Unsigned> a;
        iss >> a;

        EXPECT_TRUE(std::ranges::equal(a.to_bytes<std::endian::big>(), BYTE_ARRAY_BIG_ENDIAN));
        EXPECT_TRUE(std::ranges::equal(a.to_bytes<std::endian::little>(), BYTE_ARRAY_LITTLE_ENDIAN));
    }
}
