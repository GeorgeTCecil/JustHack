#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n" << R"(                  .----.
      .---------. | == |
      |.-"""""-.| |----|
      ||       || | == |
      ||       || |----|
      |'-.....-'| |::::|
      `"")---(""` |___.|
     /:::::::::::\" _  "
    /:::=======:::\`\`\
    `"""""""""""""`  '-')" << "\n";
    std::cout << "You are a secret agent breaking into a server " << Difficulty;
    std::cout << " Secure Server Room...\nEnter the correct code to continue through the firewalls...\n";
}

bool PlayGame(int Difficulty, int Max)
{
    PrintIntroduction(Difficulty);

    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;



    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if(Difficulty < Max)
        {
            std::cout << "\nCorrect! On to the next Firewall!";
        }
        
        return true;
    }
    else
    {
        std::cout << "\nThat answer was incorrect! Retry the Firewall" ;
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, MaxLevel);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "Congratulations! You hacked into the server!";
    return 0;
}
