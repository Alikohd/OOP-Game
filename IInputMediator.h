#ifndef GAME_C___IINPUTMEDIATOR_H
#define GAME_C___IINPUTMEDIATOR_H
enum class Command;

class IInputMediator{
public:
    virtual ~IInputMediator() = default;
    virtual void process(Command command) = 0;
};

#endif //GAME_C___IINPUTMEDIATOR_H
