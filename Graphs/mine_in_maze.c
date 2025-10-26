#include <stdio.h>
#define MAX 100

char cell[MAX][MAX];
int visited[MAX][MAX];
int dir_X[] = {-1, 1, 0, 0};
int dir_Y[] = {0, 0, -1, 1};

struct node {
    int x;
    int y;
    int d;
};

struct node queue[MAX * MAX];
int front = 0, rear = 0;

int is_valid(int nx, int ny, int m, int n) {
    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
        return 0;
    if (cell[nx][ny] != 'O')
        return 0;
    if (visited[nx][ny])
        return 0;
    return 1;
}

void display(int m, int n, int dist[MAX][MAX]) {
		printf("\nShortest distance to mine from each cell: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (cell[i][j] == 'X') 
                printf(" X ");
            else if (dist[i][j] == -1)
                printf(" - ");
            else 
                printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }
}

void mine_dist(int m, int n) {
    int dist[MAX][MAX];
    front = rear = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
            visited[i][j] = 0;

            if (cell[i][j] == 'M') {
                struct node temp = {i, j, 0};
                queue[rear++] = temp;
                dist[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }

    while (front < rear) {
        struct node curr = queue[front++];
        for (int k = 0; k < 4; k++) {
            int nx = curr.x + dir_X[k];
            int ny = curr.y + dir_Y[k];

            if (is_valid(nx, ny, m, n)) {
                visited[nx][ny] = 1;
                dist[nx][ny] = curr.d + 1;
                queue[rear++] = (struct node){nx, ny, curr.d + 1};
            }
        }
    }

    display(m, n, dist);
}

int main() {
    int m, n;
    printf("Enter dimensions of the maze (rows cols): ");
    scanf("%d %d", &m, &n);

    printf("Enter maze data\nM -> Landmine\nO -> Open Cell\nX -> Wall\n\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &cell[i][j]);
        }
    }

    mine_dist(m, n);
    return 0;
}

