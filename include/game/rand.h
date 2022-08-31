#ifndef INCLUDE_GAME_RAND_H_
#define INCLUDE_GAME_RAND_H_

#include <random>

static int rand_int(int min, int max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
  return static_cast<int>(dist(rng));
}

#endif  // INCLUDE_GAME_RAND_H_
