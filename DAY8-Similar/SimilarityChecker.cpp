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
	void raiseExceptionWhenInvalidCase(const std::string& str)
	{
		for (const auto& c : str) {
			if (c >= 'A' && c <= 'Z')
				continue;

			throw invalid_argument("문자열은 알파벳 대문자이어야 합니다.");
		}
	}

	double getLengthSimilarity(const string& target) {
		raiseExceptionWhenInvalidCase(target);

		int minLength = getMinLength(target);
		int maxLength = getMaxLength(target);

		if (minLength == maxLength)
			return MAX_SCORE;

		if (minLength * 2 <= maxLength)
			return MIN_SCORE;

		return MIN_SCORE;
	}

private:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;

	string origin_;

	int getMinLength(const string& target) {
		return static_cast<int>(min(origin_.length(), target.length()));
	}
	int getMaxLength(const string& target) {
		return static_cast<int>(max(origin_.length(), target.length()));
	}
};