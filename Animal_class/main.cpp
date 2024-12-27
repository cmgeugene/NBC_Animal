#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/* 
필수 기능
1. 기본 클래스 Animal 정의, makeSound() 라는 순수 가상함수 정의
2. Animal 클래스를 상속받는 동물 클래스 생성, 각자 makeSound() 재정의하고 출력
3. main 함수에서 Animal 타입 포인터 배열 선언. 상속 클래스를 각각 배열의 원소로 선언
4. 반복문으로 배열을 순회하며 울음소리 출력

도전 기능
1. Zoo 클래스 정의
2. 랜덤으로 동물객체를 반환하는 createRandomAnimal() 함수 구현
*/

// 필수 기능 1,2
class Animal {
public: 
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	void makeSound() {
		cout << "Dog : Bow Wow!" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() {
		cout << "Cat : Meow Meow!" << endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() {
		cout << "Cow : Moo ~" << endl;
	}
};

class Zoo {			// 도전 기능 1. Zoo 클래스 정의하고 addAnimal 추가 기능
private:
	Animal* animals[10]; 
	int zoocurrent = 0;
public:
	void addAnimal(Animal* animal) {				// 매개변수의 포인터 animal 을 그대로 쓰는 방법에서 헤맸음. 
		if (zoocurrent < 10) {
			animals[zoocurrent] = animal;
			zoocurrent++;
		}
		else cout << "Every zoo cell is occupied." << endl;
	}
	void performActions() {
		for (int i = 0; i < zoocurrent; i++) {
			animals[i]->makeSound();
		}
	}
	~Zoo() {
		for (int i = 0; i < zoocurrent; i++)			// zoocurrent 보다 작거나 같도록 했더니 런타임 에러 발생했음. 
			delete animals[i];
		cout << endl << endl << "All animals have been released." << endl;
	}

	Animal* createRandomAnimal() {				// 도전 기능2. 무작위 동물 포인터 반환
		int a = rand() % 3;
		if (a == 0) {
			cout << endl << "Random new Dog";
			return new Dog();
		}
		else if (a == 1) {
			cout << endl << "Random new Cat";
			return new Cat();
		}
		else {
			cout << endl <<"Random new Cow";
			return new Cow();
		}
	}
};

int main() {
	srand(time(NULL));

	Animal* Barns[3];	// 필수기능 3. Animal 타입의 포인터 배열 선언
	Barns[0] = new Dog;
	Barns[1] = new Cat;
	Barns[2] = new Cow;

	for (size_t i = 0; i <= 2; i++) {	// 필수 기능 2. 반복문으로 순회하며 makeSound 출력
		Barns[i]->makeSound();
	}

	for (size_t i = 0; i <= 2; i++) {
		delete Barns[i];
	}

	Zoo myZoo;							// 멤버 함수 호출을 위해 클래스 생성해야만 함
	myZoo.addAnimal(new Dog());				
	myZoo.addAnimal(new Cat());
	myZoo.addAnimal(new Cow());

	myZoo.performActions();
	myZoo.createRandomAnimal();
	

	return 0;
}