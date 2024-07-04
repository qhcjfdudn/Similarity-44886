#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;

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

		return 0;
	}

private:
	string origin_;
};