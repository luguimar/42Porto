/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:37:09 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/09 02:25:50 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// https://en.wikipedia.org/wiki/Merge-insertion_sort

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: Usage: " << av[0] << " \"200 2 1 11 3 43\" " << std::endl;
        return 1;
    }

    PmergeMe obj;
    obj.validateInput(av[1]);
    obj.startAlgoContainerOne();
    obj.startAlgoContainerTwo();

    return 0;
}
