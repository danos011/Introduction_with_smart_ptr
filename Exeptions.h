#ifndef TECPROG1_EXEPTIONS_H
#define TECPROG1_EXEPTIONS_H

#include <exception>
#include <string>

class BaseException : public std::exception {
public:
    const char *what() const noexcept override { return message_; }

protected:
    const char *message_;
};

class WrongDoubleInput : public BaseException {
public:
    WrongDoubleInput() { message_ = "Double input error!"; }
};

class WrongShapeInput : public BaseException {
public:
    WrongShapeInput() { message_ = "The input of one of the suggested figures was completely incorrect!"; }
};

class WrongUnsighnedDouble : public BaseException {
public:
    WrongUnsighnedDouble() { message_ = "Set a negative number!"; }
};

class WrongNumberOfFigures : public BaseException {
public:
    WrongNumberOfFigures() { message_ = "Going beyond the available number of figures!"; }
};

#endif //TECPROG1_EXEPTIONS_H
