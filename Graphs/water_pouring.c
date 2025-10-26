#include <stdio.h>

#define MAX 105

typedef struct state {
    int x;
    int y;
    int z;
} State;

State queue[MAX * MAX];
int front = 0, rear = 0;
int visited[MAX][MAX][MAX];
State parent[MAX][MAX][MAX];
int capacity[3];

void enqueue(State s) {
    queue[rear++] = s;
}

State dequeue() {
    return queue[front++];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

void print_path(State goal) {
    State path[MAX * MAX];
    int path_len = 0;
    State curr = goal;

    while (!(curr.x == 0 && curr.y == 0 && curr.z == capacity[2])) {
        path[path_len++] = curr;
        curr = parent[curr.x][curr.y][curr.z];
    }

    path[path_len++] = curr;
    for (int i = path_len - 1; i >= 0; i--) {
        printf("Step %d: (%d, %d, %d)\n", path_len - i, path[i].x, path[i].y, path[i].z);
    }
}

void reset_bfs_state(){
	for (int i = 0; i < MAX; i++) {
	    for (int j = 0; j < MAX; j++) {
		for (int k = 0; k < MAX; k++) {
		    visited[i][j][k] = 0;
		    parent[i][j][k] = (State){-1, -1, -1};
		}
	    }
	}
	front = 0;
	rear = 0;

}
void bfs_wp(int X, int Y, int Z, int target) {
    reset_bfs_state();
    capacity[0] = X;
    capacity[1] = Y;
    capacity[2] = Z;

    State initial = {0, 0, Z};
    enqueue(initial);
    visited[0][0][Z] = 1;

    while (front < rear) {
        State curr = dequeue();

        if (curr.x == target || curr.y == target || curr.z == target) {
	    print_path(curr);
            printf("Goal reached: (%d, %d, %d)\n", curr.x, curr.y, curr.z);
            return;
        }

        int curr_vals[3] = {curr.x, curr.y, curr.z};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (curr_vals[i] == 0 || curr_vals[j] == capacity[j]) continue;

                int pour = min(curr_vals[i], capacity[j] - curr_vals[j]);

                int next_vals[3] = {curr_vals[0], curr_vals[1], curr_vals[2]};
                next_vals[i] -= pour;
                next_vals[j] += pour;

                if (!visited[next_vals[0]][next_vals[1]][next_vals[2]]) {
                    visited[next_vals[0]][next_vals[1]][next_vals[2]] = 1;

                    State next = {next_vals[0], next_vals[1], next_vals[2]};
                    parent[next.x][next.y][next.z] = curr;
                    enqueue(next);
                }
            }
        }
    }

    printf("No solution found\n");
}

int main() {
    int x, y, z, target;
    printf("Enter capacities of 3 containers (X Y Z): ");
    scanf("%d %d %d", &x, &y, &z);
    printf("Enter target amount: ");
    scanf("%d", &target);

    if (target > x && target > y && target > z) {
        printf("Target cannot be more than every container capacities.\n");
        return 0;
    }

    bfs_wp(x, y, z, target);

    return 0;
}

