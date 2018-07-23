#include "KDTree.h"
#include<algorithm>
#include "GL/glew.h"
int cur_axis;

bool KDTree::compareNodes(Node *a, Node *b) {
	glm::vec3 apos = a->getPosition();
	glm::vec3 bpos = b->getPosition();
	return apos[cur_axis] < bpos[cur_axis];
}

KDNode * KDTree::buildKDTree(std::vector<Node *> nodes, int depth = 0) {
	if (nodes.size()==0) {
		return nullptr;
	}
	//create leaf
	if (nodes.size()==1) {
		KDNode *leafNode = new KDNode(true);
		leafNode->node = nodes.front();
		//leafNode->leaf = true;
		if(depth==0){
			this->rootNode = leafNode;
		}
		return leafNode;
	}
	cur_axis = depth % 3;//Another high-efficiency way to pick a axis is counting the Variance of each feature of the dataset  
	std::nth_element(nodes.begin(),nodes.begin()+nodes.size()/2-1,nodes.end(), this->compareNodes);
	//nth_element comes from the lib <algorithm>
	//to make the n_th element locates at where it should be
	//here we use nth to get the Median of nodes to construct a kd-tree
	//cuz the original comparison is using operator< which cannot apply for nodes(vector)
	//so we need to redefine the compare operation
	GLfloat plane = (nodes[(nodes.size() / 2 - 1)]->getPosition())[cur_axis];//Hyperplane
	KDNode *curNode = new KDNode(false);
	std::vector<Node *> leftList;
	std::vector<Node *> rightList;
	glm::vec3 pos;
	for (size_t i = 0; i < nodes.size(); i++) {
		pos = nodes[i]->getPosition();
		if (pos[cur_axis] <= plane) {
			leftList.push_back(nodes[i]);
		}
		else if (pos[cur_axis] > plane) {
			rightList.push_back(nodes[i]);
		}
	}
	//DFS recursion
	KDNode *leftChild = buildKDTree(leftList, depth + 1);
	KDNode *rightChild = buildKDTree(rightList, depth + 1);
	curNode->setLeft(leftChild);
	curNode->setRight(rightChild);
	return curNode;
}