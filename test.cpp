#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
    Span(unsigned int N) : N(N) {}
    
    void addNumber(int number)
    {
        if (numbers.size() >= N)
            throw std::overflow_error("Span is full");
        numbers.push_back(number);
    }
    
    int shortestSpan() const
    {
        if (numbers.size() < 2)
            throw std::runtime_error("Not enough numbers in Span");
        std::vector<int> sorted(numbers);
        std::sort(sorted.begin(), sorted.end());
        int shortest = sorted[1] - sorted[0];
        for (unsigned int i = 2; i < sorted.size(); i++)
        {
            int diff = sorted[i] - sorted[i-1];
            if (diff < shortest)
                shortest = diff;
        }
        return shortest;
    }
    
    int longestSpan() const
    {
        if (numbers.size() < 2)
            throw std::runtime_error("Not enough numbers in Span");
        int max = *std::max_element(numbers.begin(), numbers.end());
        int min = *std::min_element(numbers.begin(), numbers.end());
        return max - min;
    }
    
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end)
    {
        while (begin != end && numbers.size() < N)
        {
            numbers.push_back(*begin);
            ++begin;
        }
        if (begin != end && numbers.size() == N)
            throw std::overflow_error("Span is full");
    }
    
private:
    unsigned int N;
    std::vector<int> numbers;
};

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl; // affiche 2
    std::cout << sp.longestSpan() << std::endl; // affiche 14
    
    std::vector<int> more_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sp.addNumbers(more_numbers.begin(), more_numbers.end());
    std::cout << sp.shortestSpan() << std::endl; // affiche 1
    std::cout << sp.longestSpan() << std::endl; // affiche 16
    
    return 0;
}

