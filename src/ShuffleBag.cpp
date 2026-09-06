#include "ShuffleBag.h"
#include <algorithm>

void ShuffleBag::Add(const std::string& name, int count)
{
    for (int i = 0; i < count; i++) {
        items.push_back(name);
    }
}

void ShuffleBag::Shuffle(std::mt19937& rng)
{
    std::shuffle(items.begin(), items.end(), rng);
    currentIndex = 0;
}

const std::string& ShuffleBag::GetNext(std::mt19937& rng)
{
    if (currentIndex >= items.size()) {
        Shuffle(rng);
    }
    return items[currentIndex++];
}
