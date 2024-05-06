#include <iostream>
#include <vector>

class IMovable
{
    int speed;
public:
    int& Speed() { return speed; }
    virtual std::string Move() = 0;
};

class ISleepable
{
public:
    virtual std::string SleepStart() = 0;
    virtual std::string SleepFinish() = 0;
};

class ILiving : public IMovable, public ISleepable
{

};


class Computer : public ISleepable
{
public:
    std::string SleepStart() override
    {
        return "Computer is hypersleep start";
    }
    std::string SleepFinish() override
    {
        return "Computer is hypersleep finish";
    }
};

class Car : public IMovable
{
public:
    std::string Move() override
    {
        return "Car is moved!";
    }
};


class Human : public ILiving
{
public:
    std::string Move() override
    {
        return "Human walk";
    }

    std::string SleepStart() override
    {
        return "Human fаlling asleep"; 
    }
    std::string SleepFinish() override
    {
        return "Human wakes up";
    }
};


int main()
{
    std::vector<IMovable*> moves;
    std::vector<ISleepable*> sleeps;

    Human* human = new Human();

    moves.push_back(new Car());
    sleeps.push_back(new Computer());

    moves.push_back(human);
    sleeps.push_back(human);
}
