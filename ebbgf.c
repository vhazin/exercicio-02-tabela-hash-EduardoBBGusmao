#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ord 5
#define t 3

struct b_tree {
	int nodes_num;
	int keys[ord-1];
	int leaf;
	struct b_tree* nodes[ord];
	struct b_tree* root;
	
};

struct b_tree* create(struct b_tree* tree);
void print_tree(struct b_tree* tree);
void search();
struct b_tree* insert_non_full(struct b_tree* tree, int node_key);
struct b_tree* insert(struct b_tree* tree, int node_key);
struct b_tree* split(struct b_tree* tree, int index);

int main(){

	struct b_tree* tree = (struct b_tree*)malloc(sizeof(struct b_tree));
	tree = create(tree);
	int input;
	scanf("%d", &input);
	tree = insert(tree, input);
	while (input != 0){
		scanf("%d",&input);
		 tree =insert(tree, input);
		 print_tree(tree);
		}
}


struct b_tree* create(struct b_tree* tree){
	struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
	current -> leaf = 1;
	current-> nodes_num = 0;
	current -> root = tree;
	return current;
}

void print_tree(struct b_tree* tree){
        int index = 0;
        while (index <= tree->nodes_num-1){
                printf("chave: %d\n", tree->keys[index]);
                index++;
        } 
        if (tree->leaf)
                return;
        print_tree(tree-> nodes[index]);
        
}
struct b_tree* split(struct b_tree* tree, int index){

	struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
	struct b_tree* node = (struct b_tree*)malloc(sizeof(struct b_tree));
	
	node = tree -> nodes[index];
	current -> leaf = node -> leaf;
	current -> nodes_num = t-1;
	for (int i = 1; i < t-1; i++){
		 current -> nodes[i] = node -> nodes[t+i];
		 }
	if (!(node -> leaf)){
		for(int i = 01; i<t-1; i++){
			current -> keys[i] = node -> keys[t+i];
			}
		}
	node -> nodes_num = t-1;
	
	for (int i = tree -> nodes_num; i==index;i--){
		tree -> nodes[i+1] = tree -> nodes[i];
		}
		
	tree -> keys[index] = node -> keys[t];
	tree -> nodes_num = tree -> nodes_num +1;
	return tree;
	
		
}
struct b_tree* insert(struct b_tree* tree, int node_key){

	struct b_tree* rt;
	rt = tree->root;
	printf("nodes num: %d\n", tree-> nodes_num);
	if (tree-> nodes_num+1 >4 ){
		struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
		printf("split ->> problem!!\n");
		tree -> root = current;
		current -> leaf = 0;
		current -> nodes_num = 0;
		current -> nodes[0] = rt;
		current = split(current, 0);
		return current = insert_non_full(current, node_key);
	} else{
		return tree = insert_non_full(tree, node_key);
		}
}

struct b_tree* insert_non_full(struct b_tree* tree, int node_key){
	
	printf("add key = %d non full\n", node_key);
	int index = tree -> nodes_num;
	if (tree -> leaf == 1){
		while (index >=0 && node_key < (tree ->keys[index])){
			tree -> nodes[index+1] = tree -> nodes[index];
			index = index-1;
		}
		tree -> keys[index] = node_key;		
		tree -> nodes_num = tree -> nodes_num +1;
		return tree;
	} 
	
	if(tree-> leaf == 0) {
		while (index>=0 && node_key < (tree -> keys[index]))
			index = index-1;
		index = index+1;
		if (tree -> nodes[index] -> nodes_num == 2*(t)-1){
			tree -> nodes[index] = split(tree -> nodes[index], index);
			if (node_key > tree -> keys[index])
				index = index +1;
		}
		insert_non_full(tree -> nodes[index], node_key); 	
	}
		
}



















