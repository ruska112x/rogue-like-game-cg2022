#pragma once

#include <stdio.h>

#include <BearLibTerminal.h>

class Map {
   private:
    int width_;
    int heigth_;
    char filename_[128];

   public:
    Map(char filename) : filename_(filename) {}
    void ReadFromFile() {
        FILE *map;
        map = fopen(filename_, "r");
        
        char t;
        int i, j;
        for (i = 0; i < heigth_; i++) {
            for (j = 0; j < width_; j++) {
                
            }
        }
    }
};