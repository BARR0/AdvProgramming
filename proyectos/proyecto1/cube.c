#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define POSITION_LENGTH 3
#define FACES 6
#define WIDTH 8
#define HEIGHT 8

#define NEAR 0
#define FAR 1
#define TOP 2
#define RIGHT 3
#define BOTTOM 4
#define LEFT 5

#define MOVE_RIGHT 0
#define MOVE_LEFT 1
#define MOVE_UP 2
#define MOVE_DOWN 3

#define WHITE 0
#define GRAY 1
#define BLACK 2

/**
 * min heap from https://rosettacode.org/wiki/Priority_queue#C
 * Modified
**/

typedef struct
{
    int x, y;
    int priority;
    int *data;
} node_t;

typedef struct
{
    node_t *nodes;
    int len;
    int size;
} heap_t;

void push(heap_t *h, int priority, int *data)
{
    if (h->len + 1 >= h->size)
    {
        h->size = h->size ? h->size * 2 : 4;
        h->nodes = (node_t *)realloc(h->nodes, h->size * sizeof(node_t));
    }
    int i = h->len + 1;
    int j = i / 2;
    while (i > 1 && h->nodes[j].priority > priority)
    {
        h->nodes[i] = h->nodes[j];
        i = j;
        j = j / 2;
    }
    h->nodes[i].priority = priority;
    h->nodes[i].data = data;
    h->len++;
}

int *pop(heap_t *h)
{
    int i, j, k;
    if (!h->len)
    {
        return NULL;
    }
    int *data = h->nodes[1].data;

    h->nodes[1] = h->nodes[h->len];
    int priority = h->nodes[1].priority;

    h->len--;

    i = 1;
    while (1)
    {
        k = i;
        j = 2 * i;
        if (j <= h->len && h->nodes[j].priority < priority)
        {
            k = j;
        }
        if (j + 1 <= h->len && h->nodes[j + 1].priority < h->nodes[k].priority)
        {
            k = j + 1;
        }
        if (k == i)
        {
            break;
        }
        h->nodes[i] = h->nodes[k];
        i = k;
    }
    h->nodes[i] = h->nodes[h->len + 1];
    return data;
}

/***
 * END of PQueue
**/

struct Square
{
    int color;
    int prevx, prevy;
    int distance;
};

const int NEXT_POSITION[FACES][4] = {
    {NEAR, NEAR, BOTTOM, TOP},   // from NEAR
    {FAR, FAR, TOP, BOTTOM},     // from FAR
    {RIGHT, LEFT, NEAR, FAR},    // from TOP
    {BOTTOM, TOP, RIGHT, RIGHT}, // from RIGHT
    {LEFT, RIGHT, FAR, NEAR},    // from BOTTOM
    {TOP, BOTTOM, LEFT, LEFT}    // from LEFT
};

// based en position for: BOTTOM and NEAR
const int GET_FACE[FACES][FACES] = {
    {
        // BOTTOM at NEAR
        -1,    // NEAR at NEAR
        -1,    // NEAR at FAR
        FAR,   // NEAR at TOP
        RIGHT, // NEAR at RIGHT
        NEAR,  // NEAR at BOTTOM
        LEFT   // NEAR at LEFT
    },
    {
        // BOTTOM at FAR
        -1,   // NEAR at NEAR
        -1,   // NEAR at FAR
        FAR,  // NEAR at TOP
        LEFT, // NEAR at RIGHT
        NEAR, // NEAR at BOTTOM
        RIGHT // NEAR at LEFT
    },
    {
        // BOTTOM at TOP
        TOP, // NEAR at NEAR
        TOP, // NEAR at FAR
        -1,  // NEAR at TOP
        TOP, // NEAR at RIGHT
        -1,  // NEAR at BOTTOM
        TOP  // NEAR at LEFT
    },
    {
        // BOTTOM at RIGHT
        LEFT,  // NEAR at NEAR
        RIGHT, // NEAR at FAR
        FAR,   // NEAR at TOP
        -1,    // NEAR at RIGHT
        NEAR,  // NEAR at BOTTOM
        -1     // NEAR at LEFT
    },
    {
        // BOTTOM at BOTTOM
        BOTTOM, // NEAR at NEAR
        BOTTOM, // NEAR at FAR
        -1,     // NEAR at TOP
        BOTTOM, // NEAR at RIGHT
        -1,     // NEAR at BOTTOM
        BOTTOM  // NEAR at LEFT
    },
    {
        // BOTTOM at LEFT
        RIGHT, // NEAR at NEAR
        LEFT,  // NEAR at FAR
        FAR,   // NEAR at TOP
        -1,    // NEAR at RIGHT
        NEAR,  // NEAR at BOTTOM
        -1     // NEAR at LEFT
    }};

// based en position for: BOTTOM and NEAR
struct Square board[WIDTH][HEIGHT][FACES][FACES];
int die[FACES];

int min_at_pos(int x, int y, int *bot, int *near)
{
    int min_e = INT_MAX;
    for (int k = 0; k < FACES; ++k)
    {
        for (int l = 0; l < FACES; ++l)
        {
            if (board[x][y][k][l].distance < min_e)
            {
                min_e = board[x][y][k][l].distance;
                if (bot != NULL && near != NULL)
                {
                    *bot = k;
                    *near = l;
                }
            }
        }
    }
    return min_e;
}

void print_board()
{
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            printf("%d\t", min_at_pos(j, i, NULL, NULL) != INT_MAX ? min_at_pos(j, i, NULL, NULL) : -1);
        }
        printf("\n");
    }
}

void print_queue(heap_t *Q)
{
    for (int i = 0; i < Q->len; ++i)
        printf("%d, ", Q->nodes[i].priority);
    printf("\n");
}

int *make_point(int x, int y, int k, int l)
{
    int *point = (int *)malloc(sizeof(int) * 4);
    point[0] = x;
    point[1] = y;
    point[2] = k;
    point[3] = l;
    return point;
}

int all_black(int x, int y)
{
    int flag = 1;
    for (int k = 0; k < FACES; ++k)
    {
        for (int l = 0; l < FACES; ++l)
        {
            if (board[x][y][k][l].color == WHITE)
            {
                flag = 0;
            }
        }
    }
    return flag;
}

void initialize()
{
    for (int i = 0; i < WIDTH; ++i)
    {
        for (int j = 0; j < HEIGHT; ++j)
        {
            for (int k = 0; k < FACES; ++k)
            {
                for (int l = 0; l < FACES; ++l)
                {
                    board[i][j][k][l].color = WHITE;
                    board[i][j][k][l].distance = INT_MAX;
                    board[i][j][k][l].prevx = -1;
                    board[i][j][k][l].prevy = -1;
                }
            }
        }
    }
}

void relax(heap_t *Q, int ux, int uy, int vx, int vy, int bot_pos, int near_pos, int move)
{
    if (!(ux >= 0 && ux < WIDTH && uy >= 0 && uy < HEIGHT))
        return;
    if (!(vx >= 0 && vx < WIDTH && vy >= 0 && vy < HEIGHT))
        return;

    int next_bot = NEXT_POSITION[bot_pos][move];
    int next_near = NEXT_POSITION[near_pos][move];
    int face = GET_FACE[next_bot][next_near];
    int d = die[face];
    if (board[vx][vy][next_bot][next_near].distance > board[ux][uy][bot_pos][near_pos].distance + d)
    {
        board[vx][vy][next_bot][next_near].distance = board[ux][uy][bot_pos][near_pos].distance + d;
        board[vx][vy][next_bot][next_near].prevx = ux;
        board[vx][vy][next_bot][next_near].prevy = uy;
        if (board[vx][vy][next_bot][next_near].color == WHITE)
        {
            push(Q, board[vx][vy][next_bot][next_near].distance, make_point(vx, vy, next_bot, next_near));
            board[vx][vy][next_bot][next_near].color = GRAY;
        }
        else if (board[vx][vy][next_bot][next_near].color == GRAY)
        {
            // printf("REDUCE COST\n");
            push(Q, board[vx][vy][next_bot][next_near].distance, make_point(vx, vy, next_bot, next_near));
        }
        else
        {
            // printf("REDUCE BLACK\n");
            push(Q, board[vx][vy][next_bot][next_near].distance, make_point(vx, vy, next_bot, next_near));
            board[vx][vy][next_bot][next_near].color = GRAY;
        }
    }
}

int path(int startx, int starty, int endx, int endy)
{
    heap_t *Q = (heap_t *)calloc(1, sizeof(heap_t));

    initialize(board);
    board[startx][starty][BOTTOM][NEAR].distance = die[BOTTOM];
    board[startx][starty][BOTTOM][NEAR].prevx = startx;
    board[startx][starty][BOTTOM][NEAR].prevy = starty;

    push(Q, die[BOTTOM], make_point(startx, starty, BOTTOM, NEAR));

    while (Q->len > 0)
    {
        int *point = pop(Q);
        int x = point[0], y = point[1], bot_pos = point[2], near_pos = point[3];
        free(point);

        // printf("%c%c : %d : %d : %d\n", x + 'a', y + '1', bot_pos, near_pos, board[x][y][bot_pos][near_pos].distance);
        // print_queue(Q);
        // print_board();

        if (board[x][y][bot_pos][near_pos].color == BLACK)
        {
            // printf("OLD REMOVED\n");
            continue;
        }
        if (x == endx && y == endy && all_black(x, y))
        {
            free(Q->nodes);
            free(Q);
            return min_at_pos(x, y, NULL, NULL);
        }
        board[x][y][bot_pos][near_pos].color = BLACK;

        relax(Q, x, y, x + 1, y, bot_pos, near_pos, MOVE_RIGHT);
        relax(Q, x, y, x - 1, y, bot_pos, near_pos, MOVE_LEFT);
        relax(Q, x, y, x, y - 1, bot_pos, near_pos, MOVE_UP);
        relax(Q, x, y, x, y + 1, bot_pos, near_pos, MOVE_DOWN);
    }
    free(Q->nodes);
    free(Q);
    return min_at_pos(endx, endy, NULL, NULL);
}

void print_path(int startx, int starty, int endx, int endy)
{
    int first_bot_pos, first_near_pos;
    min_at_pos(endx, endy, &first_bot_pos, &first_near_pos);

    int steps = 0;
    int bot_pos = first_bot_pos, near_pos = first_near_pos;
    int x = endx, y = endy;
    int prevx = endx, prevy = endy;
    while (board[x][y][bot_pos][near_pos].prevx != x || board[x][y][bot_pos][near_pos].prevy != y)
    {
        // printf(" %c%c", x + 'a', y + '1');
        // print_board_dir();
        int nextx = board[x][y][bot_pos][near_pos].prevx, nexty = board[x][y][bot_pos][near_pos].prevy;
        prevx = x;
        prevy = y;
        x = nextx;
        y = nexty;

        int next_bot = bot_pos;
        int next_near = near_pos;
        if (x > prevx)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_RIGHT];
            next_near = NEXT_POSITION[near_pos][MOVE_RIGHT];
        }
        else if (x < prevx)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_LEFT];
            next_near = NEXT_POSITION[near_pos][MOVE_LEFT];
        }
        else if (y > prevy)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_DOWN];
            next_near = NEXT_POSITION[near_pos][MOVE_DOWN];
        }
        else if (y < prevy)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_UP];
            next_near = NEXT_POSITION[near_pos][MOVE_UP];
        }
        bot_pos = next_bot;
        near_pos = next_near;
        steps++;
    }
    // printf(" %c%c", x + 'a', y + '1');
    // printf("\n");

    int xs[steps + 1], ys[steps + 1];
    int i = 0;
    bot_pos = first_bot_pos, near_pos = first_near_pos;
    x = endx, y = endy;
    prevx = endx, prevy = endy;
    while (board[x][y][bot_pos][near_pos].prevx != x || board[x][y][bot_pos][near_pos].prevy != y)
    {
        xs[i] = x;
        ys[i] = y;
        i++;

        int nextx = board[x][y][bot_pos][near_pos].prevx, nexty = board[x][y][bot_pos][near_pos].prevy;
        prevx = x;
        prevy = y;
        x = nextx;
        y = nexty;

        int next_bot = bot_pos;
        int next_near = near_pos;
        if (x > prevx)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_RIGHT];
            next_near = NEXT_POSITION[near_pos][MOVE_RIGHT];
        }
        else if (x < prevx)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_LEFT];
            next_near = NEXT_POSITION[near_pos][MOVE_LEFT];
        }
        else if (y > prevy)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_DOWN];
            next_near = NEXT_POSITION[near_pos][MOVE_DOWN];
        }
        else if (y < prevy)
        {
            next_bot = NEXT_POSITION[bot_pos][MOVE_UP];
            next_near = NEXT_POSITION[near_pos][MOVE_UP];
        }
        bot_pos = next_bot;
        near_pos = next_near;
    }

    xs[i] = x;
    ys[i] = y;
    for (; i >= 0; --i)
        printf(" %c%c", xs[i] + 'a', ys[i] + '1');
    printf("\n");
}

int main()
{
    char start[POSITION_LENGTH], end[POSITION_LENGTH];

    int startx, starty, endx, endy;

    scanf("%s %s %d %d %d %d %d %d", start, end, die, die + 1, die + 2, die + 3, die + 4, die + 5);
    startx = start[0] - 'a';
    starty = start[1] - '1';
    endx = end[0] - 'a';
    endy = end[1] - '1';

    int min_score = path(startx, starty, endx, endy);
    printf("%d", min_score);
    print_path(startx, starty, endx, endy);

    return 0;
}
