#include <iostream>
#include <vector>
#include "../include/graph.h"

int main()
{
	Graph graph1(21, true, false, std::vector<float> {17, 22, 29, 15, 18, 20, 25, 12, 14, 19, 21, 9, 7, 10, 12, 15, 0, 3, 8, 10, 12});
	graph1.addEdge(0, 1, 5);
	graph1.addEdge(1, 2, 7);
	graph1.addEdge(2, 11, 8);
	graph1.addEdge(11, 20, 9);
	graph1.addEdge(20, 19, 2);
	graph1.addEdge(19, 18, 2);
	graph1.addEdge(18, 17, 5);
	graph1.addEdge(17, 16, 3);
	graph1.addEdge(3, 4, 3);
	graph1.addEdge(7, 8, 3);
	graph1.addEdge(4, 8, 6);
	graph1.addEdge(8, 9, 2);
	graph1.addEdge(1, 5, 2);
	graph1.addEdge(5, 6, 5);
	graph1.addEdge(5, 9, 6);
	graph1.addEdge(6, 10, 6);
	graph1.addEdge(9, 10, 5);
	graph1.addEdge(9, 14, 2);
	graph1.addEdge(12, 13, 3);
	graph1.addEdge(13, 17, 3);
	graph1.addEdge(13, 14, 2);
	graph1.addEdge(14, 15, 3);
	graph1.addEdge(15, 18, 7);
	graph1.addEdge(10, 19, 9);
	graph1.addEdge(10, 11, 2);
	auto ret = graph1.lessPath(0, 16, "Custo Uniforme");
	std::cout << "\t\tBusca de Custo Uniforme\n" << std::endl;
	std::cout << ret << std::endl;
	ret = graph1.lessPath(0, 16, "Gulosa");
	std::cout << "\n\t\t    Busca Gulosa\n" << std::endl;
	std::cout << ret << std::endl;
	ret = graph1.lessPath(0, 16, "A*");
	std::cout << "\n\t\t\tBusca A*" << std::endl;
	std::cout << "\n" << ret << std::endl;

	Graph graph2(13, true, false, std::vector<float>{366, 374, 253, 329, 380, 193, 176, 244, 241, 242, 160, 100, 0});
	graph2.addEdge(0, 1, 75);
	graph2.addEdge(0, 2, 140);
	graph2.addEdge(0, 3, 118);
	graph2.addEdge(1, 4, 71);
	graph2.addEdge(2, 6, 99);
	graph2.addEdge(2, 5, 80);
	graph2.addEdge(3, 7, 111);
	graph2.addEdge(4, 2, 151);
	graph2.addEdge(5, 11, 97);
	graph2.addEdge(5, 10, 146);
	graph2.addEdge(6, 12, 211);
	graph2.addEdge(7, 8, 70);
	graph2.addEdge(8, 9, 75);
	graph2.addEdge(9, 10, 120);
	graph2.addEdge(10, 11, 138);
	graph2.addEdge(11, 12, 101);
	ret = graph2.lessPath(0, 12, "Custo Uniforme");
	std::cout << "\n\t\tBusca de Custo Uniforme\n" << std::endl;
	std::cout << ret << std::endl;
	ret = graph2.lessPath(0, 12, "Gulosa");
	std::cout << "\n\t\t    Busca Gulosa\n" << std::endl;
	std::cout << ret << std::endl;
	ret = graph2.lessPath(0, 12, "A*");
	std::cout << "\n\t\t\tBusca A*" << std::endl;
	std::cout << "\n" << ret << std::endl;
	system("pause");
	return 0;
}
