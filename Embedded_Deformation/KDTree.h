#pragma once

#include "KDNode.h"
#include "Node.h"
#include <vector>
class KDTree {
public:
	KDTree() {}
	bool compareNodes(Node *a, Node *b);
	KDNode *buildKDTree(std::vector<Node *> nodes, int depth);
	void KNN();
private:
	KDNode *rootNode;
};