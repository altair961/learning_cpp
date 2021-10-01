#pragma once

class IAdd {
public:
//    virtual ~IAdd() noexcept = default;
    virtual int Add(int firstNumber, int secondNumber) = 0;
};
