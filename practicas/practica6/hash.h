typedef struct e
{
    void *key;
    void *value;
} Element;

typedef struct v
{
    unsigned count;
    unsigned size;
    Element *elements;
} Vector;

typedef struct h
{
    unsigned size;
    Vector *data;
    unsigned (*hash)(void *, unsigned);
    void *(*copyKey)(void *);
    void *(*copyValue)(void *);
    int (*compareKeys)(void *, void *);
} Hash;

void initHash(Hash *, unsigned,
              unsigned (*)(void *, unsigned),
              void *(*)(void *), void *(*)(void *),
              int (*compareKeys)(void *, void *));
void insertHash(Hash *, void *, void *);
void *getHash(Hash *, void *);
