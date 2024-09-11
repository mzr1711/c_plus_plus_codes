//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char b[11]{};
//
//	for (int i = 0; i < 10; i++)
//	{
//		cin >> b[i];
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		//b[i] = 90 + i;
//		cout << (void*)(&b[i]) << endl;
//	}
//
//	return 0;
//}


//#include <iostream>
//#include <stdint.h>
//#include <math.h>
//using namespace std;
//
//float normalized_atan(float x)
//{
//    static const uint32_t sign_mask = 0x80000000;
//    static const float b = 0.596227f;
//
//    // Extract the sign bit
//    uint32_t ux_s = sign_mask & (uint32_t&)x;
//
//    // Calculate the arctangent in the first quadrant
//    float bx_a = ::fabs(b * x);
//    float num = bx_a + x * x;
//    float atan_1q = num / (1.f + bx_a + num);
//
//    // Restore the sign bit
//    uint32_t atan_2q = ux_s | (uint32_t&)atan_1q;
//    return (float&)atan_2q;
//}
//
//int main()
//{
//    cout << normalized_atan(2) << endl;
//    cout << atan(2) << endl;
//
//    return 0;
//}


//#include <iostream>
////using namespace std;
//
//float map(int x, int in_min, int in_max, int out_min, int out_max) {
//    // 计算输入值的比例
//    float ratio = (float)(x - in_min) / (in_max - in_min);
//
//    // 在输出范围内应用比例
//    float mappedValue = ratio * (out_max - out_min) + out_min;
//
//    // 返回映射后的值
//    return mappedValue;
//}
//
//int main()
//{
//    std::cout << map(150, 0, 300, 20, 40);
//
//    return 0;
//}


//#include <stdio.h>
//#include <graphics.h>
//
//#define CREST_INTEN  16
//#define TROUGH_INTEN  4
//
//int intensity = 0;
//int last_intensity = 0;
//
//int crest_cnt = 0;
//int trough_cnt = 0;
//
//int main() {
//	int dir = 0;
//
//	while (1) {
//		if (dir == 0)
//			intensity++;
//		else
//			intensity--;
//		if (intensity >= 20)
//			dir = 1;
//		else if (intensity <= 0)
//			dir = 0;
//
//		if (intensity >= CREST_INTEN && last_intensity < CREST_INTEN)
//			crest_cnt++;
//		if (intensity <= TROUGH_INTEN && last_intensity > TROUGH_INTEN)
//			trough_cnt++;
//
//		last_intensity = intensity;
//
//		system("cls");
//		printf("intensity = %d\n", intensity);
//		printf("last_intensity = %d\n", last_intensity);
//		printf("crest_cnt = %d, trough_cnt = %d\n", crest_cnt, trough_cnt);
//
//		Sleep(200);
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2]; // 文件描述符数组，fd[0]为读端，fd[1]为写端
    pid_t child_pid1, child_pid2;
    char message[] = "Hello children!";

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    child_pid1 = fork();
    if (child_pid1 == 0) {
        char buffer[100];
        close(fd[1]); // 关闭写端

        read(fd[0], buffer, sizeof(buffer));
        printf("Child 1 received: %s\n", buffer);

        close(fd[0]); // 关闭读端
        exit(0);
    }

    child_pid2 = fork();
    if (child_pid2 == 0) {
        char buffer[100];
        close(fd[1]); // 关闭写端

        read(fd[0], buffer, sizeof(buffer));
        printf("Child 2 received: %s\n", buffer);

        close(fd[0]); // 关闭读端
        exit(0);
    }

    close(fd[0]); // 关闭读端

    write(fd[1], message, sizeof(message));

    close(fd[1]); // 关闭写端

    wait(NULL);
    wait(NULL);

    return 0;
}


