#include <stdio.h>

// 강의 구조체 정의
struct Lecture {
    int number;
    char day;
    int start_time;
    int end_time;
};

// 선택 정렬 함수
void selectionSort(struct Lecture arr[], int n) {
    int i, j, min_index;
    struct Lecture temp;

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].end_time < arr[min_index].end_time) {
                min_index = j;
            }
        }

        // Swap
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// 최소 강의실 수 계산 함수
int minimumClassrooms(struct Lecture lectures[], int n) {
    selectionSort(lectures, n);

    int classrooms[n];
    int i, j, result = 0;

    for (i = 0; i < n; i++) {
        classrooms[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int scheduled = 0;
        for (j = 0; j < result; j++) {
            if (classrooms[j] <= lectures[i].start_time) {
                classrooms[j] = lectures[i].end_time;
                scheduled = 1;
                break;
            }
        }

        if (!scheduled) {
            classrooms[result] = lectures[i].end_time;
            result++;
        }
    }

    return result;
}

int main() {
    int N;
    
    scanf("%d", &N);

    struct Lecture lectures[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %s %d %d", &lectures[i].number, &lectures[i].day, &lectures[i].start_time, &lectures[i].end_time);
    }

    int result = minimumClassrooms(lectures, N);
    printf("최소 강의실 수: %d\n", result);

    return 0;
}