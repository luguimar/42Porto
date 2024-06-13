/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:39:20 by gperfeit          #+#    #+#             */
/*   Updated: 2024/06/11 22:16:18 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    this->input = src.input;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        this->input = rhs.input;
    }
    return *this;
}

void PmergeMe::PrintVector(std::vector<int> &v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::PrintDeque(std::deque<int> &d) {
    for (std::size_t i = 0; i < d.size(); i++) {
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::PrintVecPairs(std::vector<std::pair<int, int> > _vector_pairs) {
	std::vector<std::pair<int, int> >::iterator _it = _vector_pairs.begin();
	while (_it != _vector_pairs.end())
	{
		if (_it != _vector_pairs.begin())
			std::cout << " ";
		std::cout << "[" << _it->first << ", " << _it->second << "]";
		_it++;
	}
	std::cout << std::endl;
}

void PmergeMe::validateInput(std::string input) {
    // check if all digits
    size_t i = 0;
    while (input[i]) {
        if ((input[i] < '0' || input[i] > '9') && input[i] != ' ' && input[i]) {
            std::cout << "Error: Only positive numbers allowed." << std::endl;
            exit(1);
        }
        i++;
    }

    // fill containers
    std::string dest;
    std::istringstream iss(input);
    std::getline(iss, dest, ' ');
    while (iss) {
        if (std::atoi(dest.c_str()) > INT_MAX || std::atoi(dest.c_str()) < INT_MIN) {
            std::cout << "Error: Number out of range." << std::endl;
            exit(1);
        }
        this->deque_container.push_back(std::atoi(dest.c_str()));
        this->vector_container.push_back(std::atoi(dest.c_str()));
        std::getline(iss, dest, ' ');
    }
    
    if (deque_container.size() == 0) {
        std::cout << "Error: Empty string." << std::endl;
        exit(1);
    }

    // check for doubles
    std::deque<int>::iterator it1;
    std::deque<int>::iterator it2;
    for (it1 = deque_container.begin(); it1 != deque_container.end(); it1++) {
        for (it2 = deque_container.begin(); it2 != deque_container.end(); it2++) {
            if (*it1 == *it2 && it1 != it2) {
                std::cout << "Error: Repeated numbers" << *it1 << std::endl;
                exit(1);
            }
        }
    }
    this->n = deque_container.size();
}

std::vector<int> PmergeMe::CreateJacobsthal(size_t max_n) {
    size_t i = 0;
    std::vector<int> jacob;
    if (max_n < 3)
        max_n = 3;
    while (jacob.size() <= max_n) {
        if (jacob.size() == 0)
            jacob.push_back(0);
        else if (jacob.size() == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[i - 2] * 2 + jacob[i - 1]);
        i++;
        if ((size_t)jacob.back() > max_n)
            break;
    }
    return jacob;
}

std::vector<int> PmergeMe::CreateInsertionSequence(std::vector<int> jacob) {
    std::vector<int> insertion_sequence;
    std::vector<int>::iterator it55;
    for (it55 = jacob.begin(); it55 != jacob.end(); it55++) {
        // add the first 3 numbers
        if (*it55 == 1 || *it55 == 0) {
            insertion_sequence.push_back(*it55);
            //std::cout << "inserting: " << *it55 << std::endl;
        // second - first = amount of numbers to insert, if repeated do not insert
        } else {
            
           int diff = *it55 - *(it55 - 1);
           for (int i = diff; i >= 0; i--) {
                if ((*(it55 - 1) + i) <= *(it55) && ( *(it55 -1) + i) > *(it55 - 1)) {
                    // acrescentar funçao p ver s ja ta inserido e nesse caso nao inserir
                    int flag = 0;
                    std::vector<int>::iterator it666;
                    for (it666 = insertion_sequence.begin(); it666 != insertion_sequence.end(); it666++) {
                        //std::cout << "comparing: " << *(it55 - 1) + i << " with " << *it666 << std::endl;
                        int tmp = *(it55 - 1) + i;
                        if (*(it666) == tmp) {
                            flag = 1;
                            //std::cout << "not inserting: " << *(it55 - 1) + i << std::endl;
                        }
                    }
                    if (flag == 0)
                        insertion_sequence.push_back(*(it55 - 1) + i);
                    //std::cout << "inserting: " << *(it55 - 1) + i << std::endl;
                }
           }
        }
    }
    return insertion_sequence;
}

void PmergeMe::insert(std::pair<int, int> _element, std::vector<std::pair<int, int> >& _pairs, int n)
{
	if (n < 0)
		_pairs.insert(_pairs.begin(), _element);
	else if (_element.second >= _pairs[n].second)
		_pairs.insert(_pairs.begin() + n + 1, _element);
	else
		insert(_element, _pairs, n - 1);
}

void PmergeMe::sort_pairs(std::vector<std::pair<int, int> >& _pairs, int n)
{
	if (n < 1)
		return ;
	sort_pairs(_pairs, n - 1);
	std::pair<int, int> _element = _pairs[n];
	_pairs.erase(_pairs.begin() + n);
	insert(_element, _pairs, n - 1);
}

void PmergeMe::insert_deque(std::pair<int, int> _element, std::deque<std::pair<int, int> >& _pairs, int n)
{
	if (n < 0)
		_pairs.insert(_pairs.begin(), _element);
	else if (_element.second >= _pairs[n].second)
		_pairs.insert(_pairs.begin() + n + 1, _element);
	else
		insert_deque(_element, _pairs, n - 1);
}

void PmergeMe::sort_pairs_deque(std::deque<std::pair<int, int> >& _pairs, int n)
{
	if (n < 1)
		return ;
	sort_pairs_deque(_pairs, n - 1);
	std::pair<int, int> _element = _pairs[n];
	_pairs.erase(_pairs.begin() + n);
	insert_deque(_element, _pairs, n - 1);
}

void PmergeMe::startAlgoContainerOne()
{
    std::cout << "Before: ";
    PrintDeque(deque_container);
    double start = clock();

    // std::cout << "First stage container:" << std::endl;
    //  make groups of two nbrs (if not pair last stays solo)
    std::vector<std::pair<int, int> > first_stage_container;
    std::vector<int>::iterator it;
    for (it = vector_container.begin(); it != vector_container.end(); it += 2)
    {
        if (it + 1 == vector_container.end())
        {
            first_stage_container.push_back(std::pair<int, int>(*it, -1));
            break;
        }
        else
            first_stage_container.push_back(std::pair<int, int>(*it, *(it + 1)));
    }
    // std::cout << "First stage container:" << std::endl;
    PrintVecPairs(first_stage_container);

    // order the nbrs numbers inside the groups (crescent order)
    std::vector<std::pair<int, int> >::iterator it2;
    for (it2 = first_stage_container.begin(); it2 != first_stage_container.end(); it2++)
        if (it2->first > it2->second)
            std::swap(it2->first, it2->second);
    PrintVecPairs(first_stage_container);

    // order the groups considereing the highest element on the group (crescent order)
    //order_groups_rec(first_stage_container, first_stage_container.begin(), true);
    sort_pairs(first_stage_container, first_stage_container.size() - 1);

    PrintVecPairs(first_stage_container);

    // calculate jacobsthal sequence
    size_t max_n = vector_container.size() / 2;
    std::vector<int> jacob = CreateJacobsthal(max_n);
    // print jacobsthal sequence
    PrintVector(jacob);

    // CHECK FOR DOUBLES ON JACOB AND REMOVE THEM
    std::vector<int>::iterator it1_v;
    std::vector<int>::iterator it2_v;
    for (it1_v = jacob.begin(); it1_v != jacob.end(); it1_v++)
        for (it2_v = jacob.begin(); it2_v != jacob.end(); it2_v++)
            if (*it1_v == *it2_v && it1_v != it2_v)
                jacob.erase(it1_v);

    // print jacobsthal sequence without repeated
    PrintVector(jacob);

    // create insertion order
    std::vector<int> insertion_sequence = CreateInsertionSequence(jacob);

    // print insertion sequence
    PrintVector(insertion_sequence);

    // create the two lists
    std::vector<int> not_ordered_list;
    std::vector<int> ordered_list;

    std::vector<std::pair<int, int> >::iterator it_888;
    for (it_888 = first_stage_container.begin(); it_888 != first_stage_container.end(); ++it_888)
    {
        if (it_888->first != -1)
            not_ordered_list.push_back(it_888->first);
        ordered_list.push_back(it_888->second);
    }

    // print not ordered list
    std::cout << "Not Ordered: ";
    PrintVector(not_ordered_list);
    std::cout << "Ordered: ";
    PrintVector(ordered_list);

    // Sort the insertion sequence
    for (std::vector<int>::size_type i = 0; i < insertion_sequence.size(); ++i)
    {
        if (static_cast<std::vector<int>::size_type>(insertion_sequence[i]) < not_ordered_list.size())
        {
            int nbr = not_ordered_list[insertion_sequence[i]];
            // Find the correct position in the sorted list using binary search
            std::vector<int>::size_type index = binarySearch(ordered_list, nbr, 0, ordered_list.size());
            // Insert the number into the sorted list
            ordered_list.insert(ordered_list.begin() + index, nbr);
        }
    }

    // print ordered list
    std::cout << "After: ";
    PrintVector(ordered_list);

    // stop performance
    double end = clock();

    // print performance
    std::cout << "Time to process a range of " << this->n << " elements with std::vector : " << ((end - start) * 1000000 / CLOCKS_PER_SEC) << " us" << std::endl;
}

int PmergeMe::binarySearch(const std::vector<int> &ordered_list, int nbr, int start, int end)
{
    if (start == end)
        return start;

    int mid = start + (end - start) / 2;
    if (nbr > ordered_list[mid])
        return binarySearch(ordered_list, nbr, mid + 1, end);
    else
        return binarySearch(ordered_list, nbr, start, mid);
}

std::deque<int> PmergeMe::CreateJacobsthalDeque(size_t max_n) {
    size_t i = 0;
    std::deque<int> jacob;
    if (max_n < 3)
        max_n = 3;
    while (jacob.size() <= max_n) {
        if (jacob.size() == 0)
            jacob.push_back(0);
        else if (jacob.size() == 1)
            jacob.push_back(1);
        else
            jacob.push_back(jacob[i - 2] * 2 + jacob[i - 1]);
        i++;
        if ((size_t)jacob.back() > max_n)
            break;
    }
    return jacob;
}

std::deque<int> PmergeMe::CreateInsertionSequenceDeque(std::deque<int> jacob) {
    std::deque<int> insertion_sequence;
    std::deque<int>::iterator it55;
    for (it55 = jacob.begin(); it55 != jacob.end(); it55++) {
        if (*it55 == 1 || *it55 == 0)
            insertion_sequence.push_back(*it55);
        else {
           int diff = *it55 - *(it55 - 1);
           for (int i = diff; i >= 0; i--) {
                if ((*(it55 - 1) + i) <= *(it55) && ( *(it55 -1) + i) > *(it55 - 1)) {
                    int flag = 0;
                    std::deque<int>::iterator it666;
                    for (it666 = insertion_sequence.begin(); it666 != insertion_sequence.end(); it666++) {
                        int tmp = *(it55 - 1) + i;
                        if (*(it666) == tmp)
                            flag = 1;
                    }
                    if (flag == 0)
                        insertion_sequence.push_back(*(it55 - 1) + i);
                }
           }
        }
    }
    return insertion_sequence;
}

void PmergeMe::startAlgoContainerTwo()
{
    std::cout << "Before: ";
    PrintDeque(deque_container);
    double start = clock();

    std::deque<std::pair<int, int> > first_stage_container;
    std::deque<int>::iterator it;
    for (it = deque_container.begin(); it != deque_container.end(); it += 2)
    {
        if (it + 1 == deque_container.end())
        {
            first_stage_container.push_back(std::pair<int, int>(*it, -1));
            break;
        }
        else
            first_stage_container.push_back(std::pair<int, int>(*it, *(it + 1)));
    }

    std::deque<std::pair<int, int> >::iterator it2;
    for (it2 = first_stage_container.begin(); it2 != first_stage_container.end(); it2++)
        if (it2->first > it2->second)
            std::swap(it2->first, it2->second);

    //order_groups_rec_deque(first_stage_container, first_stage_container.begin(), false);
    sort_pairs_deque(first_stage_container, first_stage_container.size() - 1);
    
    size_t max_n = deque_container.size() / 2;

    std::deque<int> jacob = CreateJacobsthalDeque(max_n);

    std::deque<int>::iterator it1_v;
    std::deque<int>::iterator it2_v;
    for (it1_v = jacob.begin(); it1_v != jacob.end(); it1_v++)
        for (it2_v = jacob.begin(); it2_v != jacob.end(); it2_v++)
            if (*it1_v == *it2_v && it1_v != it2_v)
                jacob.erase(it1_v);

    std::deque<int> insertion_sequence = CreateInsertionSequenceDeque(jacob);

    std::deque<int> not_ordered_list;
    std::deque<int> ordered_list;
    std::deque<std::pair<int, int> >::iterator it_888;
    for (it_888 = first_stage_container.begin(); it_888 != first_stage_container.end(); ++it_888)
    {
        if (it_888->first != -1)
            not_ordered_list.push_back(it_888->first);
        ordered_list.push_back(it_888->second);
    }

    for (std::deque<int>::size_type i = 0; i < insertion_sequence.size(); ++i)
    {
        if (static_cast<std::deque<int>::size_type>(insertion_sequence[i]) < not_ordered_list.size())
        {
            int nbr = not_ordered_list[insertion_sequence[i]];
            std::deque<int>::size_type index = binarySearchDeque(ordered_list, nbr, 0, ordered_list.size());
            ordered_list.insert(ordered_list.begin() + index, nbr);
        }
    }
    std::cout << "After: ";
    PrintDeque(ordered_list);
    double end = clock();
    std::cout << "Time to process a range of " << this->n << " elements with std::deque : " << ((end - start) * 1000000 / CLOCKS_PER_SEC) << " us" << std::endl;
}

int PmergeMe::binarySearchDeque(const std::deque<int> &ordered_list, int nbr, int start, int end)
{
    if (start == end)
        return start;
    int mid = start + (end - start) / 2;
    if (nbr > ordered_list[mid])
        return binarySearchDeque(ordered_list, nbr, mid + 1, end);
    else
        return binarySearchDeque(ordered_list, nbr, start, mid);
}
