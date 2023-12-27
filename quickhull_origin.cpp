﻿#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MAXN 100
const double EPS = 1E-8;
struct Point {
    double x, y;
};

//================================================================================
int sig(double d) { return (d > EPS) - (d < -EPS); }

bool point_same(Point &a, Point &b) {
    return sig(a.x - b.x) == 0 && sig(a.y - b.y) == 0;
}

void printPoints(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << endl;
    }
}

void copyToResult(Point pPoint[MAXN], int n_arranged_point, Point *pPoint1, int &size) {
    size = n_arranged_point;
    for (int i = 0; i < size; i++) {
        pPoint1[i].x = pPoint[i].x;
        pPoint1[i].y = pPoint[i].y;
    }
}

void removeDuplicatePoints(Point *points, int &n) {
    int new_n = 0;
    for (int i = 0; i < n; i++) {
        bool is_duplicate = false;
        for (int j = 0; j < new_n; j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate) {
            points[new_n++] = points[i];
        }
    }

    n = new_n; // Update the original n value
}

double findMaxY(Point points[], int n) {
    double maxY = points[0].y;
    for (int i = 1; i < n; i++) {
        if (points[i].y > maxY) {
            maxY = points[i].y;
        }
    }
    return maxY;
}

double findMinY(Point points[], int n) {
    double minY = points[0].y;
    for (int i = 1; i < n; i++) {
        if (points[i].y < minY) {
            minY = points[i].y;
        }
    }
    return minY;
}

double findMaxX(Point points[], int n) {
    double maxX = points[0].y;
    for (int i = 1; i < n; i++) {
        if (points[i].x > maxX) {
            maxX = points[i].x;
        }
    }
    return maxX;
}

double findMinX(Point points[], int n) {
    double minX = points[0].x;
    for (int i = 1; i < n; i++) {
        if (points[i].x < minX) {
            minX = points[i].x;
        }
    }
    return minX;
}


void findPointsByY(Point point[], int size, double maxY, Point foundPoints[], int &foundPointsCount) {

    // Duyệt qua mảng
    for (int i = 0; i < size; i++) {
        // Nếu tọa độ y của phần tử tại vị trí i bằng với maxY
        if (point[i].y == maxY) {
            // Thêm phần tử vào mảng foundPoints
            foundPoints[foundPointsCount++] = point[i];
        }
    }

}

void findPointsByX(Point *points, int n, double x, Point result[], int &n_result) {


    // Duyệt qua mảng points
    for (int i = 0; i < n; i++) {
        // Nếu hoành độ của phần tử thứ i bằng x
        if (points[i].x == x) {
            // Lưu phần tử đó vào mảng result
            result[n_result++] = points[i];
        }
    }
}

void sortPointsByXDescending(Point *points, int n) {
    // Sắp xếp mảng theo hoành độ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của phần tử thứ j
            if (points[i].x < points[j].x) {
                // Đổi chỗ hai phần tử
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void sortPointsByXAscending(Point *points, int n) {
    // Sắp xếp mảng theo hoành độ tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của phần tử thứ j
            if (points[i].x > points[j].x) {
                // Đổi chỗ hai phần tử
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void sortPointsByYDescending(Point *points, int n) {
    // Sắp xếp mảng theo tung độ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Nếu tung độ của phần tử thứ i nhỏ hơn tung độ của phần tử thứ j
            if (points[i].y < points[j].y) {
                // Đổi chỗ hai phần tử
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void sortPointsByYAscending(Point *points, int n) {
    // Sắp xếp mảng theo tung độ tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Nếu tung độ của phần tử thứ i lớn hơn tung độ của phần tử thứ j
            if (points[i].y > points[j].y) {
                // Đổi chỗ hai phần tử
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void getPoints1(Point *points, int n, Point q1, Point qq1, Point *result, int &resultSize) {


    // Duyệt qua mảng points
    for (int i = 0; i < n; i++) {
        // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của q1 và tung độ của phần tử thứ i lớn hơn tung độ của qq1
        if (points[i].x <= q1.x && points[i].y >= qq1.y) {
            // Lưu phần tử đó vào mảng result
            result[resultSize++] = points[i];
        }
    }
}

void getPoints2(Point *points, int n, Point qq2, Point q2, Point *result, int &resultSize) {

    // Duyệt qua mảng points
    for (int i = 0; i < n; i++) {
        // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của q1 và tung độ của phần tử thứ i lớn hơn tung độ của qq1
        if (points[i].x <= qq2.x && points[i].y <= q2.y) {
            // Lưu phần tử đó vào mảng result
            result[resultSize++] = points[i];
        }
    }
}

void getPoints3(Point *points, int n, Point q3, Point qq3, Point *result, int &resultSize) {


    // Duyệt qua mảng points
    for (int i = 0; i < n; i++) {
        // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của q1 và tung độ của phần tử thứ i lớn hơn tung độ của qq1
        if (points[i].x >= q3.x && points[i].y <= qq3.y) {
            // Lưu phần tử đó vào mảng result
            result[resultSize++] = points[i];
        }
    }

}

void getPoints4(Point *points, int n, Point qq4, Point q4, Point *result, int &resultSize) {


    // Duyệt qua mảng points
    for (int i = 0; i < n; i++) {
        // Nếu hoành độ của phần tử thứ i nhỏ hơn hoành độ của q1 và tung độ của phần tử thứ i lớn hơn tung độ của qq1
        if (points[i].x >= qq4.x && points[i].y >= q4.y) {
            // Lưu phần tử đó vào mảng result
            result[resultSize++] = points[i];
        }
    }
}

void findPointsWithYGreaterThan(Point points[], int n, double y, Point results[], int &n_result) {
    for (int i = 0; i < n; i++) {
        if (points[i].y > y) {
            results[n_result++] = points[i];
        }
    }
}

void findPointsWithYSmallerThan(Point points[], int n, double y, Point results[], int &n_result) {
    for (int i = 0; i < n; i++) {
        if (points[i].y < y) {
            results[n_result++] = points[i];
        }
    }
}

void findPointsWithXSmallerThan(Point points[], int n, double x, Point results[], int &n_result) {
    for (int i = 0; i < n; i++) {
        if (points[i].x < x) {
            results[n_result++] = points[i];
        }
    }
}

void findPointsWithXGreaterThan(Point points[], int n, double x, Point results[], int &n_result) {
    for (int i = 0; i < n; i++) {
        if (points[i].x > x) {
            results[n_result++] = points[i];
        }
    }
}

//Point* readPoints(const string& filename)
//{
//	ifstream file(filename);
//	Point* points;
//	double x, y;
//	int count = 0;
//	while (file >> x >> y)
//	{
//		points[count++] = { x, y };
//	}
//
//	return points;
//}
void calculateSquareDifference(Point points[], int n, double q1, double qq1, double results[]) {
    double tmp1[MAXN];
    double tmp2[MAXN];
    for (int i = 0; i < n; i++) {
        tmp1[i] = (points[i].x - q1) * (points[i].x - q1);
    }
    for (int i = 0; i < n; i++) {
        tmp2[i] = (points[i].y - qq1) * (points[i].y - qq1);
    }
    for (int i = 0; i < n; i++) {
        results[i] = tmp1[i] + tmp2[i];
    }
}

double findMax(double array[], int size) {
    double max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void findEqualElements(double key1[], int size, double maxset1, int results[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (key1[i] == maxset1) {
            results[count] = i;
            count++;
        }
    }
}

void findOHull1(Point set1[], int n_set1, Point q1,
                Point qq1, Point arrangedPoints[], int &n_arrangedPoints

) {

    if (n_set1 == 0) {
        return;
    }


    double key1[MAXN];
    int n_key1 = n_set1;
    calculateSquareDifference(set1, n_set1, q1.x, qq1.y, key1);
    double maxset1 = findMax(key1, n_key1);
    int arr_index_newpoint1[100];
    findEqualElements(key1, n_key1, maxset1, arr_index_newpoint1);
    Point new_point1 = set1[arr_index_newpoint1[0]];
    Point new_set11[MAXN], new_set12[MAXN];
    int n_new_set11 = 0;
    int n_new_set12 = 0;
    findPointsWithYGreaterThan(set1, n_set1, new_point1.y, new_set11, n_new_set11);
    findPointsWithXSmallerThan(set1, n_set1, new_point1.x, new_set12, n_new_set12);

    findOHull1(new_set11, n_new_set11, q1, new_point1, arrangedPoints, n_arrangedPoints);

    arrangedPoints[n_arrangedPoints++] = new_point1;
    findOHull1(new_set12, n_new_set12, new_point1, qq1, arrangedPoints, n_arrangedPoints);

}

void findOHull2(Point set2[], int n_set2, Point q2, Point qq2, Point arrangedPoints[], int &n_arrangedPoints,
                int &dept_function2
) {
    dept_function2++;
    if (n_set2 == 0) {
        //n_arrangedPoints = 0;
        return;
    }
    double key2[MAXN];
    int n_key2 = n_set2;
    calculateSquareDifference(set2, n_set2, qq2.x, q2.y, key2);
    double maxset2 = findMax(key2, n_key2);
    int arr_index_newpoint2[200];

    findEqualElements(key2, n_key2, maxset2, arr_index_newpoint2);
    Point new_point2 = set2[arr_index_newpoint2[0]];
    Point new_set21[MAXN], new_set22[MAXN];
    int n_new_set21 = 0;
    int n_new_set22 = 0;
    findPointsWithXSmallerThan(set2, n_set2, new_point2.x, new_set21, n_new_set21);
    findPointsWithYSmallerThan(set2, n_set2, new_point2.y, new_set22, n_new_set22);

    findOHull2(new_set21, n_new_set21, q2, new_point2, arrangedPoints, n_arrangedPoints, dept_function2);
    arrangedPoints[n_arrangedPoints++] = new_point2;
    findOHull2(new_set22, n_new_set22, new_point2, qq2, arrangedPoints, n_arrangedPoints, dept_function2);

}

void findOHull3(Point set3[], int n_set3, Point q3, Point qq3, Point arrangedPoints[], int &n_arrangedPoints,
                int &dept_function3
) {
    dept_function3++;
    if (n_set3 == 0) {
        //n_arrangedPoints = 0;
        return;
    }
    double key3[MAXN];
    int n_key3 = n_set3;
    calculateSquareDifference(set3, n_set3, q3.x, qq3.y, key3);
    double maxset3 = findMax(key3, n_key3);
    int arr_index_newpoint3[100];
    findEqualElements(key3, n_key3, maxset3, arr_index_newpoint3);
    Point new_point3 = set3[arr_index_newpoint3[0]];
    Point new_set31[MAXN], new_set32[MAXN];
    int n_new_set31 = 0;
    int n_new_set32 = 0;
    findPointsWithYSmallerThan(set3, n_set3, new_point3.y, new_set31, n_new_set31);
    findPointsWithXGreaterThan(set3, n_set3, new_point3.x, new_set32, n_new_set32);

    findOHull3(new_set31, n_new_set31, q3, new_point3, arrangedPoints, n_arrangedPoints, dept_function3
    );
    arrangedPoints[n_arrangedPoints++] = new_point3;
    findOHull3(new_set32, n_new_set32, new_point3, qq3, arrangedPoints, n_arrangedPoints, dept_function3);
}

void findOHull4(Point set4[], int n_set4, Point q4, Point qq4, Point arrangedPoints[], int &n_arrangedPoints,
                int &dept_function4
) {
    dept_function4++;
    if (n_set4 == 0) {
        return;
    }
    double key4[MAXN];
    int n_key4 = n_set4;
    calculateSquareDifference(set4, n_set4, qq4.x, q4.y, key4);
    double maxset4 = findMax(key4, n_key4);
    int arr_index_newpoint4[100];
    findEqualElements(key4, n_key4, maxset4, arr_index_newpoint4);
    Point new_point4 = set4[arr_index_newpoint4[0]];
    Point new_set41[MAXN], new_set42[MAXN];
    int n_new_set41 = 0;
    int n_new_set42 = 0;
    findPointsWithXGreaterThan(set4, n_set4, new_point4.x, new_set41, n_new_set41);
    findPointsWithYGreaterThan(set4, n_set4, new_point4.y, new_set42, n_new_set42);

    findOHull4(new_set41, n_new_set41, q4, new_point4, arrangedPoints, n_arrangedPoints, dept_function4);
    arrangedPoints[n_arrangedPoints++] = new_point4;
    findOHull4(new_set42, n_new_set42, new_point4, qq4, arrangedPoints, n_arrangedPoints, dept_function4);

}

void findConvexHull_and_index(Point points[], int &point_size, int *points_to_convex_ind) {
    int n_input = point_size;
    Point input_poly[20];
    for (int i = 0; i < n_input; i++) {
        input_poly[i].x = points[i].x;
        input_poly[i].y = points[i].y;
    }
//=================code thay the nam o duoi==================

    Point arranged_points[MAXN];
    int n_arranged_point = 0;
    double maxY = findMaxY(points, point_size);
    double minY = findMinY(points, point_size);
    double maxX = findMaxX(points, point_size);
    double minX = findMinX(points, point_size);

    Point rightPoints[MAXN];
    int n_rightPoints = 0;
    findPointsByX(points, point_size, maxX, rightPoints, n_rightPoints);

    Point leftPoints[MAXN];
    int n_leftPoints = 0;
    findPointsByX(points, point_size, minX, leftPoints, n_leftPoints);

    Point topPoints[MAXN];
    int n_topPoints = 0;
    findPointsByY(points, point_size, maxY, topPoints, n_topPoints);

    Point bottomPoints[MAXN];
    int n_bottomPoints = 0;
    findPointsByY(points, point_size, minY, bottomPoints, n_bottomPoints);



    //top
    Point top[MAXN];
    int n_top = 0;
    if (n_topPoints == 1) {
        top[0] = topPoints[0];
        n_top = 1;
    } else {
        sortPointsByXAscending(topPoints, n_topPoints);
        n_top = 2;
        top[0] = topPoints[0];
        top[1] = topPoints[n_topPoints - 1];
    }


    //bottom

    Point bottom[MAXN];
    int n_bottom = 0;
    if (n_bottomPoints == 1) {
        bottom[0] = bottomPoints[0];
        n_bottom = 1;
    } else {
        sortPointsByXDescending(bottomPoints, n_bottomPoints);
        n_bottom = 2;
        bottom[0] = bottomPoints[0];
        bottom[1] = bottomPoints[n_bottomPoints - 1];
    }

    //right
    Point right[MAXN];
    int n_right = 0;
    if (n_rightPoints == 1) {
        right[0] = rightPoints[0];
        n_right = 1;
    } else {
        sortPointsByYDescending(rightPoints, n_rightPoints);
        n_right = 2;
        right[0] = rightPoints[0];
        right[1] = rightPoints[n_rightPoints - 1];
    }

    //left
    Point left[MAXN];
    int n_left = 0;
    if (n_leftPoints == 1) {
        left[0] = leftPoints[0];
        n_left = 1;
    } else {
        sortPointsByYAscending(leftPoints, n_leftPoints);
        n_left = 2;
        left[0] = leftPoints[0];
        left[1] = leftPoints[n_leftPoints - 1];
    }
    Point q1, qq1, q2, qq2, q3, qq3, q4, qq4;
    if (n_top == 1) {
        q1 = top[0];
        qq4 = top[0];
    } else {
        q1 = top[0];
        qq4 = top[1];
    }
    q4 = right[0];

    if (n_right == 1) {
        qq3 = right[0];
    } else {
        qq3 = right[1];
    }
    q3 = bottom[0];

    if (n_bottom == 1) {
        qq2 = bottom[0];
    } else {
        qq2 = bottom[1];
    }
    q2 = left[0];

    if (n_left == 1) {
        qq1 = left[0];
    } else {
        qq1 = left[1];
    }

    Point set1[MAXN], set2[MAXN], set3[MAXN], set4[MAXN];
    int n_set1 = 0;
    int n_set2 = 0;
    int n_set3 = 0;
    int n_set4 = 0;
    getPoints1(points, point_size, q1, qq1, set1, n_set1);
    getPoints2(points, point_size, qq2, q2, set2, n_set2);
    getPoints3(points, point_size, q3, qq3, set3, n_set3);
    getPoints4(points, point_size, qq4, q4, set4, n_set4);


    Point new_arranged_points[MAXN];
    new_arranged_points[0] = q1;
    new_arranged_points[1] = q1;
    int n_new_arranged_points = 2;
    int count_depth = 0;
    int dept_function1 = 0;
    int dept_function2 = 0;
    int dept_function3 = 0;
    int dept_function4 = 0;
    findOHull1(set1, n_set1, q1, qq1, new_arranged_points, n_new_arranged_points);
    new_arranged_points[n_new_arranged_points++] = qq1;
    new_arranged_points[n_new_arranged_points++] = q2;
    findOHull2(set2, n_set2, q2, qq2, new_arranged_points, n_new_arranged_points, dept_function2);
    new_arranged_points[n_new_arranged_points++] = qq2;

    new_arranged_points[n_new_arranged_points++] = q3;
    findOHull3(set3, n_set3, q3, qq3, new_arranged_points, n_new_arranged_points, dept_function3);
    new_arranged_points[n_new_arranged_points++] = qq3;

    new_arranged_points[n_new_arranged_points++] = q4;
    findOHull4(set4, n_set4, q4, qq4, new_arranged_points, n_new_arranged_points, dept_function4);
    new_arranged_points[n_new_arranged_points++] = qq4;
    for (int i = 0; i < n_new_arranged_points; i++) {
        arranged_points[i] = new_arranged_points[i];
    }
    n_arranged_point = n_new_arranged_points;
    removeDuplicatePoints(arranged_points, n_arranged_point);
    copyToResult(arranged_points, n_arranged_point, points, point_size);
//======================================
    for (int i = 0; i < point_size; i++) {
        for (int j = 0; j < n_input; j++) {
            if (point_same(points[i], input_poly[j])) {
                points_to_convex_ind[i] = j;
                break;
            }
        }
    }
}

double generateRandomDouble() {
    // Sinh giá trị ngẫu nhiên từ 0 đến 1
    return static_cast<double>(rand()) / RAND_MAX;
}

Point generateRandomPoint() {
    Point point;
    // Chuyển đổi giá trị ngẫu nhiên về khoảng [-150, 150]
    point.x = generateRandomDouble() * 300 + 1024;
    point.y = generateRandomDouble() * 300 - 1024;
    return point;
}

int main() {
    Point points[MAXN];
    points[0] =  {-0.5512564020565307, 5.669173014739911};
    points[1] =  {30.97427554952769, -17.9384430547612};
    points[2] =  {-17.903252092020786, 19.316683730275557};
    points[3] =  {-1.3832827229600753, -14.065512966271868};
    points[4] =  {-9.449995710461899, -17.02004524012405};
    points[5] =  {-33.241171885539615, 13.17971572750811};
    points[6] =  {39.37793635045665, 18.881358274658012};
    points[7] =  {13.47796855441102, -16.245263795272372};
    points[8] =  {-6.648118938143519, -35.58319797523891};
    points[9] =  {22.87254214522619, -20.352968643824067};
    points[10] =  {-20.82317192984462, 48.07532194553028};
    points[11] =  {-15.966129719725672, 47.87237593419228};
    points[12] =  {11.79577586976125, 26.1156900372099};
    points[13] =  {12.798315007256022, -32.13149697937692};
    points[14] =  {21.28936917705137, -24.1230857226888};
    points[15] =  {-9.229115967518084, -36.95339696057519};
    points[16] =  {-44.156897409927254, -13.243141410030624};
    points[17] =  {-48.591254249630076, -11.478657956604742};
    int n_points = 18;
    int point_to_convex_index[20] = {-1, -1, -1, -1, -1, -1, -1, -1, -1,
                                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
//    findConvexHull(points, n_points);
    findConvexHull_and_index(points, n_points, point_to_convex_index);
    cout << "Convex Hull Points: " << n_points << " diem" << endl;
    for (int i = 0; i < n_points; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")" << endl;
    }
    cout << "chi so cua bao loi trong mang cu la:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << point_to_convex_index[i] << " ";
    }
    return 0;
}
//
// Created by ADMIN on 23/12/2023.
//
