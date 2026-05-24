#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe base;
        base.parseInput(av);

        base.printBefore();

        /* ================= VECTOR ================= */
        PmergeMe vec = base;

        clock_t startVec = clock();
        vec.sortVector();
        clock_t endVec = clock();

        /* ================= DEQUE ================= */
        PmergeMe deq = base;

        clock_t startDeq = clock();
        deq.sortDeque();
        clock_t endDeq = clock();

        /* ================= AFTER ================= */
        vec.printAfter();

        double timeVec = (double)(endVec - startVec) * 1e6 / CLOCKS_PER_SEC;
        double timeDeq = (double)(endDeq - startDeq) * 1e6 / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of "
                  << base.getSize()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5)
                  << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of "
                  << base.getSize()
                  << " elements with std::deque : "
                  << std::fixed << std::setprecision(5)
                  << timeDeq << " us" << std::endl;
    }
    catch (std::exception &)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}