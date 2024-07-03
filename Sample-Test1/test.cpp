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
	catch (exception& e) {
		// PASS
	}
}

TEST(SimilarityChecker, ThrowExceptionWhenInvalidCase) {
	SimilarityChecker app{ "ASD" };
	string target = "ASq";

	EXPECT_THROW(app.getLengthSimilarity(target)
		, invalid_argument);
}