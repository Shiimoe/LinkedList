struct Node {
    int value;
    struct Node *next;
};

typedef struct Node node_t;

node_t *ll_prepend(int, node_t *);
node_t *ll_node(int);
node_t *ll_append(int, node_t *);
size_t ll_length(node_t *);
node_t *ll_get(node_t *, size_t);
node_t *ll_remove_after(node_t *);
node_t *ll_remove(node_t *, size_t);
node_t *ll_last(node_t *);
void ll_insert_after(node_t *, node_t *);
void ll_insert(node_t *, size_t, node_t *);
char *ll_string(node_t*);
