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