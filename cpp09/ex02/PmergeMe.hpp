/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:42:20 by facu              #+#    #+#             */
/*   Updated: 2024/05/20 17:43:13 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iostream>
#include <cstdlib>

class PmergeMe {
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(PmergeMe const &src);
        void display();
    private:
        std::vector<int> _sequenceVector;
        std::list<int> _sequenceList;
        std::list<int> argsToList(std::string str);
        std::vector<int> argsToVector(std::string str);
        void InsertionSort(std::vector<int> &sequence);
        void InsertionSort(std::list<int> &sequence);
        void MergeInsertionSort(std::vector<int> &sequence);
        void MergeInsertionSort(std::list<int> &sequence);
        std::vector<int> Merge(std::vector<int> &left, std::vector<int> &right);
        std::list<int> Merge(std::list<int> &left, std::list<int> &right);
        void SortVector();
        void SortList();
        void displayVector();
        void displayList();
        bool isDuplicate(std::vector<int> &sequence);
        bool isDuplicate(std::list<int> &sequence);
        double _timeVector;
        double _timeList;
        std::string _str;
};

#endif