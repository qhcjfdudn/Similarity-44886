#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;

class SimilarityChecker {
public:
	SimilarityChecker(string origin)
		: origin_{ origin } {
		raiseException(origin);
	}
	void raiseException(std::string& str)
	{
		for (const auto& c : str) {
			if (c >= 'A' && c <= 'Z')
				continue;

			throw invalid_argument("문자열은 알파벳 대문자이어야 합니다.");
		}
	}

	double getLengthSimilarity(string target) {
		raiseException(target);

		return 0;
	}

private:
	string origin_;
};