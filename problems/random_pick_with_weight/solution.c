typedef struct {
    int * a;
    int size;
    int sum;
}
Solution;

Solution * solutionCreate(int * w, int wSize) {
    Solution * s = malloc(sizeof(Solution));
    s -> a = malloc(sizeof(int) * wSize);
    s -> size = wSize;
    int sum1 = 0;
    for (int i = 0; i < wSize; i++) {
        sum1 += (w[i]);
        s -> a[i] = sum1;
    }
    s -> sum = sum1;
    s -> size = wSize;
    return s;
}

int solutionPickIndex(Solution * obj) {
    int r = rand() % (obj -> sum);
    int i = 0;
    for (i = 0; i < obj -> size; i++) {
        if (r < obj -> a[i])
            break;
    }

    return i;
}

void solutionFree(Solution * obj) {
    free(obj -> a);
    free(obj);
}