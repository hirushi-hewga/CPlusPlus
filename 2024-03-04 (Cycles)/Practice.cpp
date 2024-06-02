#include <iostream>
using namespace std;
int main() {
    /*int country;
    do{
        enum countries{Ukraine = 1, USA, Japan, Germany, Brazil};
        cout << Ukraine << " - Ukraine" << endl;
        cout << USA << " - USA" << endl;
        cout << Japan << " - Japan" << endl;
        cout << Germany << " - Germany" << endl;
        cout << Brazil << " - Brazil" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choice country: ";
        cin >> country;
        switch (country)
        {
        case 0:
            cout << "Good bye.";
            break;
        case 1:
            cout << "Capital: Kyiv\n------------------" << endl;
            break;
        case 2:
            cout << "Capital: Washington\n------------------" << endl;
            break;
        case 3:
            cout << "Capital: Tokyo\n------------------" << endl;
            break;
        case 4:
            cout << "Capital: Berlin\n------------------" << endl;
            break;
        case 5:
            cout << "Capital: Brasilia\n------------------" << endl;
            break;
        default:
            cout << "Invalid country!.\n------------------" << endl;
            break;
        }
    }while (country!=0);*/




    /*int day;
    do{
        enum days{Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
        cout << Monday << " - Monday" << endl;
        cout << Tuesday << " - Tuesday" << endl;
        cout << Wednesday << " - Wednesday" << endl;
        cout << Thursday << " - Thursday" << endl;
        cout << Friday << " - Friday" << endl;
        cout << Saturday << " - Saturday" << endl;
        cout << Sunday << " - Sunday" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choice day: ";
        cin >> day;
        switch (day){
        case 0:
            cout << "Good bye.";
            break;
        case Monday:
            cout << "Monday - holiday.\n------------------" << endl;
            break;
        case Tuesday:
            cout << "Tuesday - weekday.\n------------------" << endl;
            break;
        case Wednesday:
            cout << "Wednesday - weekday.\n------------------" << endl;
            break;
        case Thursday:
            cout << "Thursday - weekday.\n------------------" << endl;
            break;
        case Friday:
            cout << "Friday - weekday.\n------------------" << endl;
            break;
        case Saturday:
            cout << "Saturday - holiday.\n------------------" << endl;
            break;
        case Sunday:
            cout << "Sunday - holiday.\n------------------" << endl;
            break;
        default:
            break;
        }
    }while(day!=0);*/




    /*int quarter = 1, choice;
    enum cardinal{North = 1, East, South, West};
    do{
        cout << North << " - North" << endl;
        cout << East << " - East" << endl;
        cout << South << " - South" << endl;
        cout << West << " - West" << endl;
        cout << "Choice way: ";
        cin >> quarter;
        cout << "------------------" << endl;
    }while(quarter<=0 || quarter>4);
    do{
        switch (quarter){
        case North:
            cout << "Your direction - North" << endl;
            break;
        case East:
            cout << "Your direction - East" << endl;
            break;
        case South:
            cout << "Your direction - South" << endl;
            break;
        case West:
            cout << "Your direction - West" << endl;
            break;
        default:
            break;
        }
        cout << "1 - Turn right" << endl;
        cout << "2 - Turn left" << endl;
        cout << "3 - Turn back" << endl;
        cout << "0 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            quarter++;
            break;
        case 2:
            quarter+=3;
            break;
        case 3:
            quarter+=2;
            break;
        case 0:
            cout << "Good bye.";
            break;
        default:
            cout << "Invalid choice! Try again:" << endl;
        }
        cout << "------------------" << endl;
        if (quarter!=4){
            quarter%=4;
        }
    }while(choice!=0);*/




    /*int animal;
    enum animals{Dog = 1, Cat, Elephant, Lion, Tiger, Giraffe, Bear};
    do{
        cout << "------------------" << endl;
        cout << Dog << " - Dog" << endl;
        cout << Cat << " - Cat" << endl;
        cout << Elephant << " - Elephant" << endl;
        cout << Lion << " - Lion" << endl;
        cout << Tiger << " - Tiger" << endl;
        cout << Giraffe << " - Giraffe" << endl;
        cout << Bear << " - Bear" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choice animal: ";
        cin >> animal;
        switch (animal){
        case Dog:
            cout << "Dog - herbivore" << endl;
            break;
        case Cat:
            cout << "Cat - predator" << endl;
            break;
        case Elephant:
            cout << "Elephant - herbivore" << endl;
            break;
        case Lion:
            cout << "Lion - predator" << endl;
            break;
        case Tiger:
            cout << "Tiger - predator" << endl;
            break;
        case Giraffe:
            cout << "Giraffe - herbivore" << endl;
            break;
        case Bear:
            cout << "Bear - predator" << endl;
            break;
        case 0:
            cout << "Good bye.";
            break;
        default:
            cout << "Invalid choice! Try again:" << endl;
        }
    }while(animal!=0);*/
}