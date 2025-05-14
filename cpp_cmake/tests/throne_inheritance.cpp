//
// Created by Dhruv Sharma on 14/05/25.
//

#include "throne_inheritance.h"
#include "utils.h"

#include <gtest/gtest.h>

TEST(ThroneInheritance, Assertion1) {
    ThroneInheritance t("king");
    t.birth("king", "andy"); // order: king > andy
    t.birth("king", "bob"); // order: king > andy > bob
    t.birth("king", "catherine"); // order: king > andy > bob > catherine
    t.birth("andy", "matthew"); // order: king > andy > matthew > bob > catherine
    t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex > asha > catherine
    t.death("bob"); // order: king > andy > matthew > bob > alex > asha > catherine
    auto order = t.getInheritanceOrder(); // return ["king", "andy", "matthew", "alex", "asha", "catherine"]

    std::vector<std::string> expected{"king", "andy", "matthew", "alex", "asha", "catherine"};
    compareVectors(order, expected);
}
