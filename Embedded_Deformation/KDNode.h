#pragma once
class KDNode {
public:
	int axis;
	bool leaf;

	KDNode *Left;
	KDNode *Right;

	Node *node;//the node that this KDNode contains 

	KDNode() :Left(nullptr),Right(nullptr){}
	KDNode(bool _leaf) :leaf(_leaf), Left(nullptr), Right(nullptr) {}

	void setLeft(KDNode *node) {
		Left = node;
	};
	void setRight(KDNode *node) {
		Right = node;
	};
	bool isLeaf() {
		return leaf;
	}
	//void setLeaf(KDNode *node) {
	//	this->leaf = true;
	//	this->node = node;
	//}

};