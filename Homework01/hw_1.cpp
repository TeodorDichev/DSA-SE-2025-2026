#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// custom merge
void merge(vector<string>& names, vector<int>& points, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<string> names_arr_1(n1), names_arr_2(n2);
    vector<int> points_arr_1(n1), points_arr_2(n2);
    for (int i = 0; i < n1; i++) {
        names_arr_1[i] = names[l + i];
        points_arr_1[i] = points[l + i];
    }

    for (int i = 0; i < n2; i++) {
        names_arr_2[i] = names[m + i + 1];
        points_arr_2[i] = points[m + i + 1];
    } 
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(points_arr_1[i] > points_arr_2[j] 
            || (points_arr_1[i] == points_arr_2[j] && names_arr_1[i].compare(names_arr_2[j]) < 0)) {
            names[k] = names_arr_1[i];
            points[k] = points_arr_1[i];
            i++;
        }
        else {
            names[k] = names_arr_2[j];
            points[k] = points_arr_2[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        names[k] = names_arr_1[i];
        points[k] = points_arr_1[i];
        i++; k++;
    }

    while(j < n2) {
        names[k] = names_arr_2[j];
        points[k] = points_arr_2[j];
        j++; k++;
    }
}

void merge_sort(int l, int r, vector<string>& names, vector<int>& points) {
    if(l < r) {
        int m = l + (r - l)/2;
        merge_sort(l, m, names, points);
        merge_sort(m+1, r, names, points);
        merge(names,points,l,m,r);
    }   
}

int main() {
    int n = 0;
    cin >> n;
    
    vector<string> names(n);
    vector<int> points(n);
    
    for(int i = 0; i < n; i++) cin >> names[i];
    for(int i = 0; i < n; i++) cin >> points[i];

    merge_sort(0, n - 1, names, points);

    for(int i = 0; i < n; i++) cout << names[i] << " " << points[i] << endl;

    return 0;
}