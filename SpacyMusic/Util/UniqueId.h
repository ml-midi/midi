#pragma once

#include <cstdint>

namespace SpacyMusic
{
    namespace Util
    {
        static std::uint64_t id_counter = 0;

        class UniqueId
        {
        public:
            UniqueId() noexcept
                : id_(id_counter++)
            {}

            std::uint64_t id() const noexcept
            {
                return id_;
            }

        private:
            std::uint64_t id_;
        };
    }
}
