#include <iostream>
#include <string>

#include "Rectangle.h"
#include "Ring.h"
#include "Diamond.h"
#include "Exeptions.h"

const size_t SIZE = 10;

double makeCut(const point_t& a, const point_t& b)
{
    return sqrt(pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2));
}

bool checkTriangle(const point_t& center,const point_t& a, const point_t& c){
    double d1 = makeCut(center, a);
    double d2 = makeCut(center, c);
    double hypo = makeCut(center, c);

    if(abs(pow(hypo, 2) - sqrt(pow(d1, 2) - pow(d2, 2))) >= 0.1){
        return false;
    }
    return true;
}

int doCheck(std::string &str){

   if(str == "RECTANGLE"){
       return 1;
   }
   else if(str == "RING"){
       return 2;
   }
   else if(str == "DIAMOND"){
       return 3;
   }
   else if(str == "SCALE"){
       return 4;
   }

   return 0;
}

void print(std::unique_ptr<std::shared_ptr<Shape>[]> &shapeArray, double &scale) {
    for (size_t i = 0; i < SIZE; ++i) {

        if (shapeArray[i] == nullptr) {
            continue;
        }

        printf("%.1f ", shapeArray[i]->getArea());
        shapeArray[i]->show();

        std::cout << std::endl;
        shapeArray[i]->scale(scale);

        printf("%.1f ", shapeArray[i]->getArea());
        shapeArray[i]->show();

        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void doEnter(std::unique_ptr<std::shared_ptr<Shape>[]> &shapeArray, double &scale, bool &flag){

    std::cout << "Enter a name" << std::endl;

    for(size_t i = 0; i < SIZE; ++i) {
        std::string buf;
        std::cin >> buf;

        int choice = doCheck(buf);

        if(choice == 1) {

            double massRectangle[4];

            for (size_t y = 0; y < 4; ++y) {
                std::cin >> massRectangle[y];

                if(!std::cin){
                    flag = true;
                    std::cin.clear();
                    continue;
                }

            }

            if(massRectangle[0] > massRectangle[2] || massRectangle[1] > massRectangle[3]){
                flag = true;
                continue;
            }

            std::shared_ptr<Shape> test_rectangle = std::make_shared<Rectangle>(Rectangle({massRectangle[0], massRectangle[1]},
                                                                                          {massRectangle[2], massRectangle[3]}));
            shapeArray[i] = test_rectangle;
            std::cin.clear();
        }
        else if (choice == 2) {

            double massRing[4];

            for (size_t y = 0; y < 4; ++y) {
                std::cin >> massRing[y];

                if(!std::cin || massRing[2] < massRing[3]){
                    flag = true;
                    std::cin.clear();
                    continue;
                }

            }

            if(massRing[2] < massRing[3]){
                flag = true;
                continue;
            }

            std::shared_ptr<Shape> test_ring = std::make_shared<Ring>(Ring {{massRing[0], massRing[1]},
                                                                            massRing[2], massRing[3]});
            shapeArray[i] = test_ring;
            std::cin.clear();
        }
        else if (choice == 3) {
            double massDiamond[6];

            for (size_t y = 0; y < 6; ++y) {
                std::cin >> massDiamond[y];

                if(!std::cin){
                    flag = true;
                    std::cin.clear();
                    continue;
                }

            }

            if(!checkTriangle({massDiamond[0], massDiamond[1]},{massDiamond[2], massDiamond[3]},{massDiamond[4], massDiamond[5]}))
            {
                flag = true;
                continue;
            }

            std::shared_ptr<Shape> test_diamond = std::make_shared<Diamond>(Diamond {{massDiamond[0], massDiamond[1]},
                                                                                       {massDiamond[2], massDiamond[3]},
                                                                                       {massDiamond[4], massDiamond[5]}});
            shapeArray[i] = test_diamond;
            std::cin.clear();
        }
        else if(choice == 4){
            std::cin >> scale;

            if(!std::cin){
                throw WrongDoubleInput();
            }
            else if(scale < 0){
                throw WrongUnsighnedDouble();
            }

            break;
        }
        else{
            continue;
        }

        if(i == SIZE){
            throw WrongNumberOfFigures();
        }

    }
}


int main() {
    std::unique_ptr<std::shared_ptr<Shape>[]> array = std::make_unique<std::shared_ptr<Shape>[]>(SIZE);
    double scale;
    bool flag = false;
    try {

        doEnter(array, scale, flag);
        print(array, scale);

        if(flag){
            throw WrongShapeInput();
        }
    }
    catch (std::exception &exception) {
        std::cerr << std::endl << exception.what() << std::endl;
        if(!flag) {
            return -1;
        }
    }
    return 0;
}