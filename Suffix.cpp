#include "Suffix.h"
#include "Node.h"
#include "SuffixTree.h"

Suffix::Suffix(Node* n, int c) : node(n), char_index(c) {
	new_internal_node = false;
}

bool Suffix::ends_at_node() const { 
    return char_index == *node->end_index;
}

bool Suffix::ends_at_leaf() const {
    return node->is_leaf() && ends_at_node();
}

bool Suffix::continues_with_char(const SuffixTree& tree, char ch) const {
    return (ends_at_node() && node->get_child(tree, ch) != NULL)
            || (!ends_at_node() && tree.tree_string[char_index + 1] == ch);
}
