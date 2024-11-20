#include "processing.h"
#include "FSTree.h"
#include "DirNode.h"
#include <iostream>
#include <string>
#include <cctype>


void traverse_helper(DirNode *next_node, const std::string &updated_path) {
    if (next_node == nullptr) {
        return;
    }

    std::string current_path = updated_path;

    if (not (next_node->getParent() == nullptr)) {
        if (not (current_path.back() == '/')) {
            current_path += "/";
        }
        current_path += next_node->getName();
    }


    if (next_node->hasFiles()) {
        for (int i = 0; i < next_node->numFiles(); i++) {
            std::cout << current_path + "/" + next_node->getFile(i) 
            << std::endl;
        }
    }


    if (next_node->hasSubDir()) {
        for (int i = 0; i < next_node->numSubDirs(); i++) {
            traverse_helper(next_node->getSubDir(i), current_path);
        }
    }
}

void traverseDirectory(string directory) {
    FSTree new_tree(directory);
    DirNode *root_of_tree = new_tree.getRoot();
    traverse_helper(root_of_tree, directory);
}

std::string stripNonAlphaNum(string input) {
    if (input == "") {
        return "";
    }

    int beginning_index = 0;
    int ending_index = input.length() - 1;

    while ((beginning_index <= ending_index) and 
    (not (std::isalnum(input[beginning_index])))) {
        beginning_index++;
    }

    while ((ending_index >= beginning_index) and 
        (not (std::isalnum(input[ending_index])))) {
            ending_index--;
    }

    if (beginning_index > ending_index) {
        return "";
    }

    std::string final_string = input.substr(beginning_index, 
                                ending_index - beginning_index + 1);
    return final_string;
}
