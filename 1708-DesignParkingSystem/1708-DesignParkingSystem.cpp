// Last updated: 02/05/2026, 22:39:05
class ParkingSystem {
public:
    int bigCars;
    int mediumCars;
    int smallCars;

    ParkingSystem(int big, int medium, int small) {
        bigCars = big;
        mediumCars = medium;
        smallCars = small;
    }

    bool addCar(int carType) {

        switch (carType) {

        case 1:
            if (bigCars <= 0)
                return false;
            bigCars--;
            break;
        case 2:
            if (mediumCars <= 0)
                return false;
            mediumCars--;
            break;
        case 3:
            if (smallCars <= 0)
                return false;
            smallCars--; 
            break;
        }

        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */