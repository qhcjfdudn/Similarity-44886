#include <string>
#include "pch.h"
#include "../DAY8-Similar/SimilarityChecker.cpp"

using std::string;
using std::invalid_argument;
using std::exception;

class SimilarityCheckerFixture : public testing::Test {
public:
	void checkTestCase(double expected, double actual) {
		EXPECT_EQ(expected, actual);
	}
};

TEST(SimilarityChecker, ThrowExceptionWhenOriginIsInvalidCase) {
	try {
		SimilarityChecker app{ "ASd" };
		FAIL();
	}
	catch (...) {
		// PASS
	}
}
TEST(SimilarityChecker, ThrowExceptionWhenInvalidCase) {
	SimilarityChecker app{ "ASD" };
	string test = "ASq";

	EXPECT_THROW(app.getLengthSimilarity(test)
		, invalid_argument);
}
TEST_F(SimilarityCheckerFixture, IsSameLength) {
	SimilarityChecker app{ "ASD" };
	string test = "DSA";
	checkTestCase(60, app.getLengthSimilarity(test));
}
TEST_F(SimilarityCheckerFixture, IsOverDoubleLength) {
	SimilarityChecker app{ "A" };
	string test = "BB";
	checkTestCase(0, app.getLengthSimilarity(test));
}
TEST_F(SimilarityCheckerFixture, IsSubScore) {
	SimilarityChecker app{ "AAABB" };
	string test = "BAA";
	checkTestCase(20, app.getLengthSimilarity(test));
}
TEST_F(SimilarityCheckerFixture, IsSubScore2) {
	SimilarityChecker app{ "AA" };
	string test = "AAE";
	checkTestCase(30, app.getLengthSimilarity(test));
}