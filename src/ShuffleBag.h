#include <random>
#include <string>

class ShuffleBag
{
    public:
        void Add(const std::string& name, int count);
        void Shuffle(std::mt19937& rng);
        const std::string& GetNext(std::mt19937& rng);
    private:
        std::vector<std::string> items;
        size_t currentIndex = 0;
};
