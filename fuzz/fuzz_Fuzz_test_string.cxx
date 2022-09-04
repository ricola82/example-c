#include <fuzzbuzz.hxx>

extern int Fuzz_test_string(const char *, size_t);

FZBZ_TARGET_CLASS(FuzzFuzz_test_string);
class FuzzFuzz_test_string {
	public:
		FuzzFuzz_test_string(fzbz::Fuzzer &f) {
			fzbz::generator::string<std::string> string0 = fzbz::generator::string<std::string>();
			
			auto target = fzbz::fuzzTarget([](std::string src) {
				Fuzz_test_string(src.c_str(), src.size());
			}, string0);
			
			f.addFuzzTarget(target);
		}
};
