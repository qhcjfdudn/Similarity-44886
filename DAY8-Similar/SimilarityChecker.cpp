#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class SimilarityChecker {
public:
	SimilarityChecker(const string& origin)
		: origin_{ origin } {
		raiseExceptionWhenInvalidCase(origin);
	}

	double getLengthSimilarity(const string& test) {
		raiseExceptionWhenInvalidCase(test);

		int minLength = getMinLength(test);
		int maxLength = getMaxLength(test);

		if (isSameLength(minLength, maxLength))
			return MAX_SCORE;

		if (isOverDoubleLength(minLength, maxLength))
			return MIN_SCORE;

		return getSubScore(minLength, maxLength);
	}

private:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;

	string origin_;
	
	void raiseExceptionWhenInvalidCase(const std::string& str)
	{
		for (const auto& c : str) {
			if (c >= 'A' && c <= 'Z')
				continue;

			throw invalid_argument("문자열은 알파벳 대문자이어야 합니다.");
		}
	}

	int getMinLength(const string& test) {
		return static_cast<int>(min(origin_.length(), test.length()));
	}
	int getMaxLength(const string& test) {
		return static_cast<int>(max(origin_.length(), test.length()));
	}
	
	bool isSameLength(int len1, int len2)
	{
		return len1 == len2;
	}
	
	bool isOverDoubleLength(int minLength, int maxLength)
	{
		return minLength * 2 <= maxLength;
	}
	
	double getSubScore(int minLength, int maxLength)
	{
		return MAX_SCORE - (maxLength - minLength) * MAX_SCORE / minLength;
	}
};