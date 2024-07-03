#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;

class SimilarityChecker {
public:
	double getLengthSimilarity(string source, string target) {
		for (const auto& c : target) {
			if (c >= 'A' && c <= 'Z')
				continue;

			throw invalid_argument("문자열은 알파벳 대문자이어야 합니다.");
		}
	}
};