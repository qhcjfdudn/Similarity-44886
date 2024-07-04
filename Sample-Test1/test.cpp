#include <string>
#include "pch.h"
#include "../DAY8-Similar/SimilarityChecker.cpp"

using std::string;
using std::invalid_argument;
using std::exception;

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
TEST(SimilarityChecker, IsSameLength) {
	SimilarityChecker app{ "ASD" };
	string test = "DSA";

	double expected = 60;
	double actual = app.getLengthSimilarity(test);
	EXPECT_EQ(expected, actual);
}
TEST(SimilarityChecker, IsOverDoubleLength) {
	SimilarityChecker app{ "A" };
	string test = "BB";

	double expected = 0;
	double actual = app.getLengthSimilarity(test);
	EXPECT_EQ(expected, actual);
}