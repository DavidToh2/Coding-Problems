#pragma GCC optimise("Ofast")
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

void print_coordinates(int x, int y, int z) {
    cout << "(" << x << " " << y << " " << z << ")";
}

char check_adjacency(int x0, int y0, int z0, int x1, int y1, int z1) {
    int xadj = 0, yadj = 0, zadj = 0;
    if ((x0 - x1 == 1) || (x0 - x1 == -1)) {
        xadj = 1;
    }
    if ((y0 - y1 == 1) || (y0 - y1 == -1)) {
        yadj = 1;
    }
    if ((z0 - z1 == 1) || (z0 - z1 == -1)) {
        zadj = 1;
    }
    if (xadj + yadj + zadj == 1) {
        if (xadj == 1) {
            return 'x';
        } else if (yadj == 1) {
            return 'y';
        } else if (zadj == 1) {
            return 'z';
        }
    } else {
        if (xadj + yadj + zadj == 3) {
            return 'a';
        } else {
            return 'n';
        }
    }
}

int main() {
    int x0, y0, z0, a0, b0, c0, x1, y1, z1, a1, b1, c1;
    cin >> x0 >> y0 >> z0 >> a0 >> b0 >> c0;
    cin >> x1 >> y1 >> z1 >> a1 >> b1 >> c1;

    int dx0 = a0 - x0, dy0 = b0 - y0, dz0 = c0 - z0, dx1 = a1 - x1, dy1 = b1 - y1, dz1 = c1 - z1;
    char phase0 = 'x', phase1 = 'x';

    print_coordinates(x0, y0, z0);
    cout << " ";
    print_coordinates(x1, y1, z1);
    cout << endl;

    while (!((phase0 == 'd') && (phase1 == 'd'))) {

        // Robot 0 logic

        switch(phase0) {
            case 'x':
                if (dx0 > 0) {
                    x0++;
                } else if (dx0 < 0) {
                    x0--;
                } else {
                    phase0 = 'y';
                }
            break;
            case 'y':
                if (dy0 > 0) {
                    y0++;
                } else if (dy0 < 0) {
                    y0--;
                } else {
                    phase0 = 'z';
                }
            break;
            case 'z':
                if (dz0 > 0) {
                    z0++;
                } else if (dz0 < 0) {
                    z0--;
                } else {
                    phase0 = 'd';
                }
            break;
            case 'd':
            break;
        }
        print_coordinates(x0, y0, z0);
        cout << " ";

        char intersect = check_adjacency(x0, y0, z0, x1, y1, z1);
        if (intersect != 'n') {
            if (phase0 == 'd') {
                if (intersect == 'x' && phase1 == 'x') {
                    if (dy1 > 0) {
                        y1++;
                    } else {
                        y1--;
                    }
                } else if (intersect == 'y' && phase1 == 'y') {
                    if (dz1 > 0) {
                        z1++;
                    } else {
                        z1--;
                    }
                } else if (intersect == 'z' && phase1 == 'z') {

                }
            } else {

            }
        } else {
            switch(phase0) {
            case 'x':
                if (dx1 > 0) {
                    x1++;
                } else if (dx1 < 0) {
                    x1--;
                } else {
                    phase0 = 'y';
                }
            break;
            case 'y':
                if (dy1 > 0) {
                    y1++;
                } else if (dy1 < 0) {
                    y1--;
                } else {
                    phase0 = 'z';
                }
            break;
            case 'z':
                if (dz1 > 0) {
                    z1++;
                } else if (dz1 < 0) {
                    z1--;
                } else {
                    phase0 = 'd';
                }
            break;
            case 'd':
            break;
        }
        }
        print_coordinates(x1, y1, z1);
        cout << endl;

    }

}