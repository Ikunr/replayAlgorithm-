#include <iostream>
#include <string>
#include <unordered_map>

// std::pair<char, int> findMostFrequentChar(const std::string& str) 
// {
//     std::unordered_map<char, int> charCount;

//     // Count occurrences of each character in the string
//     for (char ch : str) 
//     {
//         /* 检测字符串是否为字符 */
//         if (std::isalpha(ch)) 
//         {
//             charCount[ch]++;
//         }
//     }

//     // Find the character with the maximum count
//     char maxChar = '\0';
//     int maxCount = 0;
//     for (const auto & pair : charCount)
//     {
//         if (pair.second > maxCount) 
//         {
//             maxChar = pair.first;
//             maxCount = pair.second;
//         }
//     }
//     return std::make_pair(maxChar, maxCount);
// }

std::pair<char, int> findMostFrequentChar(const std::string& str) 
{
    std::unordered_map<char, int> my_map;

    for (auto &ch : str)
    {
        if (std::isalpha(ch))
        {
            my_map[ch]++;
        }
    }

    char maxChar = '\0';
    char maxCount = 0;
    for (const auto &pair : my_map)
    {
        if (pair.second > maxCount)
        {
            maxChar = pair.first;
            maxCount = pair.second;
        }
    }

    return std::make_pair(maxChar, maxCount);

}
int main() 
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::pair<char, int> result = findMostFrequentChar(input);

    if (result.second == 0) 
    {
        std::cout << "No valid characters found in the input." << std::endl;
    } 
    else 
    {
        std::cout << "Most frequent character: " << result.first << std::endl;
        std::cout << "Frequency: " << result.second << std::endl;
    }

    return 0;
}