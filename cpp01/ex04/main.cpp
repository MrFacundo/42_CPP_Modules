/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:38:54 by facu              #+#    #+#             */
/*   Updated: 2024/01/18 16:48:16 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

int	replaceInFile(std::string filename, std::string s1, std::string s2)
{
	size_t	pos;
	int		occurrences;

	occurrences = 0;
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cout << "Error: unable to find or read in file" << std::endl;
		return (-1);
	}
	std::string line;
	std::string content;
	while (std::getline(ifs, line))
		content += line + "\n";
	ifs.close();
	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cout << "Error: out file not found" << std::endl;
		return (-1);
	}
	pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content = content.substr(0, pos) + s2 + content.substr(pos
				+ s1.length());
		pos += s2.length();
		occurrences++;
	}
	ofs << content;
	ofs.close();
	return (occurrences);
}

bool	validateArgs(int ac, char **av, std::string &filename, std::string &s1,
		std::string &s2)
{
	if (ac != 4)
	{
		std::cout << "usage: ./replace <filename> <oldstring> <newstring>" << std::endl;
		return (false);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	int occurrences;
	std::string filename, s1, s2;

	occurrences = 0;
	if (!validateArgs(ac, av, filename, s1, s2))
		return (EXIT_FAILURE);
	occurrences = replaceInFile(filename, s1, s2);
	if (occurrences == -1)
		return (EXIT_FAILURE);
	std::cout << "File processed. Replaced " << occurrences << " occurrences" << std::endl;
	return (0);
}