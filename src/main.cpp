#include <BearLibTerminal.h>

#include <cmath>
#include <vector>

int to_pos(float x) { return static_cast<int>(std::round(x)); }

class Controls {
   private:
    bool is_jump_ = false;
    bool is_exit_ = false;
    bool is_over_ = false;

   public:
    bool IsJump() const { return is_jump_; }
    bool IsExit() const { return is_exit_; }
    void SetOver(bool exit) { is_over_ = exit; }
    bool IsOver() const { return is_over_; }

    void Update() {
        if (!is_over_ && !is_exit_) {
            is_jump_ = false;
            is_exit_ = false;

            while (terminal_has_input()) {
                auto key = terminal_read();
                if (key == TK_SPACE) {
                    is_jump_ = true;
                }
                if (key == TK_CLOSE) {
                    is_exit_ = true;
                }
            }
        }
    }
};

class Player {
   private:
    char symbol_ = '@';
    int x_;
    float y_;
    float max_jump_height_;
    float speed_y_ = 0;
    float max_speed_y_;
    int ground_y_;
    float gravity_;

    const Controls &controls_;

    bool IsFlying() const { return y_ < ground_y_; }

    void Render() { terminal_put(x_, to_pos(y_), symbol_); }

    void Move() {
        if (controls_.IsJump() && !IsFlying()) {
            speed_y_ = max_speed_y_;
        }
        if (y_ >= ground_y_) {
            y_ = ground_y_;
        }

        if (y_ <= ground_y_ - max_jump_height_) {
            speed_y_ = 0;
        }

        y_ -= speed_y_;
        y_ += gravity_;
    }

   public:
    Player(const Controls &controls, char symbol, int x, float y,
           float max_jump_height, float max_speed_y, int ground_y,
           float gravity)
        : controls_(controls),
          symbol_(symbol),
          x_(x),
          y_(y),
          max_jump_height_(max_jump_height),
          max_speed_y_(max_speed_y),
          ground_y_(ground_y),
          gravity_(gravity) {}

    int GetX() const { return to_pos(x_); }

    int GetY() const { return to_pos(y_); }

    void Update() {
        Move();
        Render();
    }
};

class Obstacle {
   private:
    char symbol = '!';

   public:
    float x_;
    float y_;

    Obstacle(float x, float y) : x_(x), y_(y) {}

    void Update() { terminal_put(to_pos(x_), y_, symbol); }
};

class ObstaclesManager {
   private:
    float ground_y_ = 0;
    int world_width_ = 80;
    float speed_x_;
    const Player &player_;
    Controls &controls_;
    std::vector<Obstacle> obstacles{
        {40, ground_y_}, {60, ground_y_}, {75, ground_y_}};

   public:
    ObstaclesManager(Controls &controls, const Player &player, float ground_y,
                     int world_width, float speed_x)
        : controls_(controls),
          player_(player),
          ground_y_(ground_y),
          world_width_(world_width),
          speed_x_(speed_x) {}

    void Update() {
        for (auto &o : obstacles) {
            o.x_ -= speed_x_;
            if (o.x_ <= 0) {
                o.x_ = world_width_;
            }

            if (player_.GetX() == to_pos(o.x_) &&
                player_.GetY() == to_pos(ground_y_)) {
                terminal_printf(0, 1, "Boom!");
                controls_.SetOver(true);
            }
            o.Update();
        }
    }
};

class Ground {
   private:
    char symbol_ = '^';
    int width_;
    int y_;

   public:
    Ground(char symbol, int width, int y)
        : symbol_(symbol), width_(width), y_(y){};
    void Update() {
        for (int i = 0; i < width_; i++) {
            terminal_put(i, y_ + 1, symbol_);
        }
    }
};

int main() {
    terminal_open();
    terminal_refresh();

    bool game_over = false;

    const int ground_y = 20;
    const int width = 80;

    float speed_x = 0.16;

    const float gravity = 0.1;
    float player_y = ground_y;
    int player_x = 1;

    const float max_jump = ground_y - 4;
    float speed_y = 0;
    const float max_speed_y = gravity * 3;

    Controls controls;
    Player player{controls, '@',         player_x, ground_y,
                  4,        gravity * 3, ground_y, gravity};
    ObstaclesManager om{controls, player, ground_y, width, speed_x};
    Ground ground{'^', width, ground_y};

    while (!controls.IsOver()) {
        terminal_clear();
        controls.Update();
        om.Update();
        player.Update();
        ground.Update();

        // if (controls.IsExit()) {
        //   break;
        // }

        if (controls.IsOver()) {
            terminal_print(35, 10, "GAME OVER!");
            terminal_refresh();
            continue;
        }

        terminal_refresh();
    }

    terminal_close();
}
