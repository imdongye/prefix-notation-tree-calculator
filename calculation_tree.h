// 201820189 ÀÓµ¿¿¹
#pragma once
#include <iostream>
#include <sstream>

class CalcurationTree {
private:
	class Node {
		friend class CalcurationTree;
	public:
		virtual float result() const = 0; // abstract class
	};
	class NumberNode :Node {
		float value;
	public:
		NumberNode(float v) :value(v) {}
		virtual float result() const override {
			return value;
		}
	};
	class Operation :Node {
		friend class CalcurationTree;
	protected:
		Node* left = nullptr;
		Node* right = nullptr;
	public:
		Operation(Node* l = nullptr, Node* r = nullptr) :left(l), right(r) {}
	};

	class Addition : Operation {
		friend class CalcurationTree;
	public:
		Addition() {}
		virtual float result() const override {
			return left->result() + right->result();
		}
	};
	class Subtraction : Operation {
		friend class CalcurationTree;
	public:
		Subtraction() {}
		virtual float result() const override {
			return left->result() - right->result();
		}
	};
	class Multiplication : Operation {
		friend class CalcurationTree;
	public:
		Multiplication() {}
		virtual float result() const override {
			return left->result() * right->result();
		}
	};
	class Division : Operation {
		friend class CalcurationTree;
	public:
		Division() {}
		virtual float result() const override {
			return left->result() / right->result();
		}
	};

	static std::string getToken(std::istream& is) {
		std::string s;
		is >> s;
		return s;
	}
	static bool isNumber(const std::string& s) {
		return s[0] >= '0' && s[0] <= '9';
	}
	static Node* buildTree(std::istream& is) {
		std::string s = getToken(is);
		if (isNumber(s)) {
			float n = atoi(s.c_str());
			return (Node*)new NumberNode(n);
		}
		Operation* op = nullptr;
		switch (s[0]) {
		case '+':
			op = new Addition();
			break;
		case '-':
			op = new Subtraction();
			break;
		case '*':
			op = new Multiplication();
			break;
		case '/':
			op = new Division();
			break;
		default:
			return nullptr;
		}
		op->left = buildTree(is);
		op->right = buildTree(is);
		return (Node*)op;
	}
public:
	static float eval(std::istream& prefix_notation) {
		Node* root = buildTree(prefix_notation);
		return root->result();
	}
	static float eval(std::string& prefix_notation) {
		std::stringstream st;
		st.str(prefix_notation);
		return eval(st);
	}
};