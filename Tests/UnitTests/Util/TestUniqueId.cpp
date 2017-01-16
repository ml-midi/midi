#include <gtest/gtest.h>

#include <gtest.hh>

#include <SpacyMusic/Util/UniqueId.h>

TEST(TestUniqueId, EachObjectGetsTheNextId)
{
    SpacyMusic::Util::UniqueId id, other_id;

    EXPECT_EQ(id.id() + 1,
              other_id.id());
}
