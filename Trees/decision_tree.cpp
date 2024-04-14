#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <fstream>

using namespace std;

class Table {
    public:
        vector<vector<string>> data;
        vector<string> attrName;

        vector<vector<string>> attrValueList;

        void extractAttrValue() {
            /*
            * Extract the attribute values from the data
            * and store them in the attrValueList
            */
            attrValueList.resize(attrName.size());
            for(int j=0; j<attrName.size(); j++){
                map<string, int> valueMap;
                for(int i=0; i<data.size(); i++){
                    valueMap[data[i][j]] = 1;
                }

                for(auto it = valueMap.begin(); it != valueMap.end(); it++){
                    attrValueList[j].push_back(it->first); // it->first is the key of the map valueMap 
                }
            }
        }
};

class Node {
    public:
        int criteriaAttrIndex;
        string attrValue;

        int treeIndex;
        bool isLeaf;
        string label;

        vector<int > children;

        Node() {
            isLeaf = false;
        } // constructor
};

class DecisionTree {
    public:
        Table initialTable;
        vector<Node> tree;

        DecisionTree(Table table) {
            initialTable = table;
            initialTable.extractAttrValue();

            Node root;
            root.treeIndex = 0;
            tree.push_back(root);

            
        }

        string guess(vector<string> row){
            string label = "";
            int leafNode = dfs(row, 0);
            if(leafNode == -1){
                return "dfs failed"
            } 
            label = tree[leafNode].label;
            return label;
        }

        int dfs(vector<string>& row, int here){
            if(tree[here].isLeaf){
                return here;
            }

            int criteriaAttrIndex = tree[here].criteriaAttrIndex;
            
            for(int i=0; i<tree[here].children.size())
        }
}