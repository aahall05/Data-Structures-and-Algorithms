#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{

}

void AdjacencyList::insert(std::string from, std::string to) {
	// If 'from' doesn't exist in graph, add it with an empty pair of vectors
	if (graph.find(from) == graph.end()) {
		graph[from] = { std::vector<std::string>(), std::vector<std::string>() };
		size++;
	}
	// Add 'to' to the vector of websites 'from' points to
	graph[from].first.push_back(to);

	// If 'to' doesn't exist in graph, add it with an empty pair of vectors
	if (graph.find(to) == graph.end()) {
		graph[to] = { std::vector<std::string>(), std::vector<std::string>() };
		size++;
	}
	// Add 'from' to the vector of websites that point to 'to'
	graph[to].second.push_back(from);
}

void AdjacencyList::PageRank(int n)
{
	std::map<std::string, double> newPageRank;

	// Perform n power iterations, starting from 1
	for (int i = 1; i <= n; i++) {
		// if i == 1, set all page ranks to 1 / graph size
		if (i == 1) {

			for (auto& page : graph) {
				newPageRank[page.first] = 1.0 / graph.size();
			}
		}
		else {
			// loop through each page in graph
			for (auto& page : graph) {
				double sum = 0;
				// for each page that points to the current page
				for (int j = 0; j < page.second.second.size(); j++) {
					// add the page rank of the pointing page divided by the out degree of the pointing page
					sum += pageRank[page.second.second[j]] / graph[page.second.second[j]].first.size();
				}
				// assign new page rank to the current page
				newPageRank[page.first] = sum;
			}
		}
		// update pageRank with the new page ranks
		pageRank = newPageRank;
	}

	// print pageRank
	for(auto& page : pageRank) {
		std::cout << page.first << " " << std::fixed << std::setprecision(2) << page.second << std::endl;
	}
	
}


double AdjacencyList::getPageRank(std::string page)
{
	// return pageRank[page] rounded to two decimal places
	return std::round(pageRank[page] * 100.0) / 100.0;

}

bool AdjacencyList::hasEdge(std::string from, std::string to)
{
	if (std::find(graph[from].first.begin(), graph[from].first.end(), to) != graph[from].first.end())
		return true;

	return false;
}
