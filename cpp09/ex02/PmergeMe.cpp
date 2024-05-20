/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:42:02 by facu              #+#    #+#             */
/*   Updated: 2024/05/20 17:53:34 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [number1] [number2] ... [numberN]" << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        if (i != 1)
            _str += " ";
        _str += argv[i];
    }
    try {
        _sequenceVector = argsToVector(_str);
        _sequenceList = argsToList(_str);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1);
    }
    SortVector();
    SortList();
    display();
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::display()
{
    std::cout << "Before" << std::endl;
    std::cout << _str << std::endl;
    std::cout << "After" << std::endl;
    displayVector();
    displayList();
    std::cout << "Time to process a range of " << _sequenceVector.size() << " elements " << "with std::vector<int>: " << _timeVector << "ms" << std::endl;
    std::cout << "Time to process a range of " << _sequenceList.size() << " elements " << "with std::list<int>: " << _timeList << "ms" << std::endl;
}

std::list<int> PmergeMe::argsToList(std::string str)
{
	std::list<int> list;
	std::istringstream iss(str);
	std::string token;
	int nbr;
	while (std::getline(iss, token, ' '))
	{
		std::istringstream iss_token(token);
		if (!(iss_token >> nbr) || !iss_token.eof() || nbr < 0)
		{
			throw std::invalid_argument("Invalid number");
		}
		list.push_back(nbr);
	}
	if (isDuplicate(list))
		throw std::invalid_argument("Duplicate number");
	return list;
}

std::vector<int> PmergeMe::argsToVector(std::string str)
{
	std::vector<int> vector;
	std::istringstream iss(str);
	std::string token;
	int nbr;
	while (std::getline(iss, token, ' '))
	{
		std::istringstream iss_token(token);
		if (!(iss_token >> nbr) || !iss_token.eof())
		{
			throw std::invalid_argument("Invalid number");
		}
		vector.push_back(nbr);
	}
	if (isDuplicate(vector))
		throw std::invalid_argument("Duplicate number");
	return vector;
}

void PmergeMe::InsertionSort(std::vector<int> &sequence)
{
    unsigned long i;
    int key, j;
    for (i = 1; i < sequence.size(); i++)
    {
        key = sequence[i];
        j = i - 1;
        while (j >= 0 && sequence[j] > key)
        {
            sequence[j + 1] = sequence[j];
            j = j - 1;
        }
        sequence[j + 1] = key;
    }
}

void PmergeMe::InsertionSort(std::list<int> &sequence)
{
    std::list<int> sorted;
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
    {
        std::list<int>::iterator it2 = sorted.begin();
        while (it2 != sorted.end() && *it2 < *it)
            it2++;
        sorted.insert(it2, *it);
    }
    sequence = sorted;
}

void PmergeMe::MergeInsertionSort(std::vector<int> &sequence)
{
    if (sequence.size() <= 10)
    {
        InsertionSort(sequence);
        return;
    }
    std::vector<int> left;
    std::vector<int> right;
    int middle = sequence.size() / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(sequence[i]);
    for (unsigned long i = middle; i < sequence.size(); i++)
        right.push_back(sequence[i]);
    MergeInsertionSort(left);
    MergeInsertionSort(right);
    sequence = Merge(left, right);
}


void PmergeMe::MergeInsertionSort(std::list<int> &sequence)
{
    if (sequence.size() <= 10)
    {
        InsertionSort(sequence);
        return;
    }
    std::list<int> left;
    std::list<int> right;
    int middle = sequence.size() / 2;
    int i = 0;
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
    {
        if (i < middle)
            left.push_back(*it);
        else
            right.push_back(*it);
        i++;
    }
    MergeInsertionSort(left);
    MergeInsertionSort(right);
    sequence = Merge(left, right);
}

std::vector<int> PmergeMe::Merge(std::vector<int> &left, std::vector<int> &right)
{
	std::vector<int> result;
	unsigned long i = 0, j = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
	}
	while (i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}
	while (j < right.size())
	{
		result.push_back(right[j]);
		j++;
	}
	return result;
}


std::list<int> PmergeMe::Merge(std::list<int> &left, std::list<int> &right)
{
	std::list<int> result;
	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.pop_front();
		}
		else
		{
			result.push_back(right.front());
			right.pop_front();
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.pop_front();
	}
	return result;
}

void PmergeMe::displayVector()
{
	std::ostringstream oss;
	for (unsigned long i = 0; i < _sequenceVector.size(); i++)
	{
		if (i != 0)
			oss << " ";
		oss << _sequenceVector[i];
	}
	std::cout << oss.str() << std::endl;
}

void PmergeMe::displayList()
{
	std::ostringstream oss;
	for (std::list<int>::iterator it = _sequenceList.begin(); it != _sequenceList.end(); ++it)
	{
		if (it != _sequenceList.begin())
			oss << " ";
		oss << *it;
	}
	std::cout << oss.str() << std::endl;
}

void PmergeMe::SortVector()
{
    std::clock_t start = std::clock();

    MergeInsertionSort(_sequenceVector);
    std::clock_t end = std::clock();
    _timeVector = 1000.0 * (end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::SortList()
{
    std::clock_t start = std::clock();

    MergeInsertionSort(_sequenceList);
    std::clock_t end = std::clock();
    _timeList = 1000.0 * (end - start) / CLOCKS_PER_SEC;
}

bool PmergeMe::isDuplicate(std::vector<int> &sequence)
{
    for (size_t i = 0; i < sequence.size(); i++)
    {
        for (size_t j = i + 1; j < sequence.size(); j++)
        {
            if (sequence[i] == sequence[j])
                return true;
        }
    }
    return false;
}

bool PmergeMe::isDuplicate(std::list<int> &sequence)
{
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
    {
        for (std::list<int>::iterator it2 = it; it2 != sequence.end(); it2++)
        {
            if (it != it2 && *it == *it2)
                return true;
        }
    }
    return false;
}