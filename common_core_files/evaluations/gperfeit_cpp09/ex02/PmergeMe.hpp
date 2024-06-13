/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:39:16 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/11 22:13:47 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <deque>
# include <vector>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <climits>

class PmergeMe {
    private:
		std::string input;
        std::vector<int> vector_container;
        std::deque<int> deque_container;
        int n;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
        PmergeMe &operator=(PmergeMe const &rhs);
        void validateInput(std::string input);
        void startAlgoContainerOne();
        void startAlgoContainerTwo();
		int binarySearch(const std::vector<int>& ordered_list, int nbr, int start, int end);
		int binarySearchDeque(const std::deque<int>& ordered_list, int nbr, int start, int end);
		void PrintVecPairs(std::vector<std::pair<int, int> > _vector_pairs);
        void PrintVector(std::vector<int> &v);
        void PrintDeque(std::deque<int> &v);
        std::vector<int> CreateJacobsthal(size_t max_n);
        std::deque<int> CreateJacobsthalDeque(size_t max_n);
        std::vector<int> CreateInsertionSequence(std::vector<int> jacob);
        std::deque<int> CreateInsertionSequenceDeque(std::deque<int> jacob);
        void insert(std::pair<int, int> _element, std::vector<std::pair<int, int> >& _pairs, int n);
        void sort_pairs(std::vector<std::pair<int, int> >& _pairs, int n);
        void insert_deque(std::pair<int, int> _element, std::deque<std::pair<int, int> >& _pairs, int n);
        void sort_pairs_deque(std::deque<std::pair<int, int> >& _pairs, int n);
};

#endif
