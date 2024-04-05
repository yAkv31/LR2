#include <iostream>
#include <vector> // Для использования std::vector

// Определение класса Animal
class Animal {
private:
    std::string color; // Атрибут класса
    std::string name;

public:
    // Безопасное обращение к полям класса (инкапсуляция)
    std::string GetName() {
        return name;
    }

    std::string GetColor() {
        return color;
    }

    void SetName(std::string NewName) {
        name = NewName;
    }

    void SetColor(std::string NewColor) {
        color = NewColor;
    }

    // Конструктор без параметров
    Animal() {

    }

    // Конструктор с параметрами
    Animal(std::string p_name, std::string p_color) {
        name = p_name;
        color = p_color;
    }

    // Конструктор копирования
    Animal(const Animal& other) {
        name = other.name;
        color = other.color;
    }

    // Виртуальный деструктор
    virtual ~Animal() {
        std::cout << "Kill: " << name << std::endl;
    }

    // Метод вывода на экран
    void print() {
        std::cout << "Name: " << name << ", color: " << color << std::endl;
    }
};

// Определение класса Cat, который наследуется от Animal
class Cat : public Animal {
public:

    Cat() : Animal() {

    }

    Cat(std::string p_name, std::string p_color) : Animal(p_name, p_color) {

    }

    Cat(const Cat& other) : Animal(other) {

    }

    void print() {
        std::cout << "Cat: Name: " << GetName() << ", color: " << GetColor() << std::endl;
    }

    ~Cat() {

    }
};

// Определение класса Dog, который также наследуется от Animal
class Dog : public Animal {
public:
    Dog() : Animal() {

    }

    Dog(std::string p_name, std::string p_color) : Animal(p_name, p_color) {

    }

    Dog(const Dog& other) : Animal(other) {

    }

    void print() {
        std::cout << "Dog: Name: " << GetName() << ", color: " << GetColor() << std::endl;
    }

    ~Dog() {

    }
};

class Zoo {
private:
    std::vector<Animal*> animals; // Вектор указателей на объекты класса Animal
    Animal zookeeper; // Объект класса Animal для хранения информации о смотрителе зоопарка

public:
    Zoo(std::string zookeeper_name, std::string zookeeper_color) : zookeeper(zookeeper_name, zookeeper_color) {

    }

    ~Zoo() {
        for (auto animal : animals) {
            delete animal; // Уничтожение всех объектов класса Animal, хранящихся в векторе
        }
    }

    void AddAnimal(std::string animal_name, std::string animal_color, std::string animal_type) {
        if (animal_type == "Cat") {
            animals.push_back(new Cat(animal_name, animal_color)); // Добавление нового объекта класса Cat в вектор
        }
        else if (animal_type == "Dog") {
            animals.push_back(new Dog(animal_name, animal_color)); // Добавление нового объекта класса Dog в вектор
        }
    }

    void PrintAllAnimals() {
        for (auto animal : animals) {
            animal->print(); // Вывод информации о каждом объекте класса Animal в векторе
        }
    }

    void PrintZookeeper() {
        std::cout << "Zookeeper: ";
        zookeeper.print(); // Вывод информации о смотрителе зоопарка
    }
};

int main() {
    // Создание объекта класса Zoo с смотрителем
    Zoo zoo("John", "Blue");

    // Добавление объектов разных типов в зоопарк
    zoo.AddAnimal("Tom", "Black", "Cat");
    zoo.AddAnimal("Mars", "Black", "Cat");
    zoo.AddAnimal("Rex", "Brown", "Dog");

    // Вывод информации о всех объектах класса Animal в зоопарке
    zoo.PrintAllAnimals();

    // Вывод информации о смотрителе зоопарка
    zoo.PrintZookeeper();

    // Помещение объектов в переменные различных типов
    Cat* myCat = new Cat("Whiskers", "Gray"); // Создаем объект класса Cat и помещаем его в переменную myCat
    Dog* myDog = new Dog("Buddy", "Golden");  // Создаем объект класса Dog и помещаем его в переменную myDog

    // Вызов методов для каждого объекта
    myCat->print();
    myDog->print();

    // Освобождаем выделенную память
    delete myCat;
    delete myDog;

    return 0;
}
