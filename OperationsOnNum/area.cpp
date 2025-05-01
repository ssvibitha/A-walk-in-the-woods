//Calculate area of square,cube,rectangle,cuboid
#include <cstdio>
#include <cstdlib>

class area_calc {
private:
    int length;
    int breadth;
    int height;

public:
    area_calc() : length(0), breadth(0), height(0) {}
    area_calc(int l) : length(l), breadth(l), height(l) {}
    area_calc(int l, int b) : length(l), breadth(b), height(0) {}
    area_calc(int l, int b, int h) : length(l), breadth(b), height(h) {}

    int getarea_Square() { 
        return length * length; 
    }
    int getarea_Cube() { 
        return 6 * length * length; 
    }
    int getarea_Rectangle() { 
        return length * breadth; 
    }
    int getarea_Cuboid() {
         return 2 * (length * breadth + length * height + height * breadth); 
    }
};

int main() {
    int choice, length, breadth, height, result;

    while (1) {
        printf("\nMenu - Display Area of:\n");
        printf("1. Square\n");
        printf("2. Cube\n");
        printf("3. Rectangle\n");
        printf("4. Cuboid\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            do {
                printf("Enter length of square: ");
                scanf("%d", &length);
            } while (length < 0);

            {
                area_calc square(length);
                result = square.getarea_Square();//Area of square
                printf("Area of square = %d sq units\n", result);
            }
            break;

        case 2:
            do {
                printf("Enter length of cube: ");
                scanf("%d", &length);
            } while (length < 0);

            {
                area_calc cube(length);
                result = cube.getarea_Cube();//Area of cube
                printf("Area of cube = %d sq units\n", result);
            }
            break;

        case 3:
            do {
                printf("Enter length of rectangle: ");
                scanf("%d", &length);
            } while (length < 0);

            do {
                printf("Enter breadth of rectangle: ");
                scanf("%d", &breadth);
            } while (breadth < 0);

            {
                area_calc rectangle(length, breadth);
                result = rectangle.getarea_Rectangle();//Area of rectangle
                printf("Area of rectangle = %d sq units\n", result);
            }
            break;

        case 4:
            do {
                printf("Enter length of cuboid: ");
                scanf("%d", &length);
            } while (length < 0);

            do {
                printf("Enter breadth of cuboid: ");
                scanf("%d", &breadth);
            } while (breadth < 0);

            do {
                printf("Enter height of cuboid: ");
                scanf("%d", &height);
            } while (height < 0);

            {
                area_calc cuboid(length, breadth, height);
                result = cuboid.getarea_Cuboid();//Area of cuboid
                printf("Area of cuboid = %d sq units\n", result);
            }
            break;

        case 5:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid input....Try again\n");
        }
    }

    return 0;
}
