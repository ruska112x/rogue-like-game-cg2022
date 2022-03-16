#pragma once

class Controls{
private:
    bool is_exit_ = false;
    bool is_over_ = false;
    bool left_, up_, right_, down_;
public:
    bool IsExit() const;
    void SetOver(bool);
    bool IsOver() const;
    bool IsLeft() const;
    bool IsUp() const;
    bool IsRight() const;
    bool IsDown() const;

    void Update();
};