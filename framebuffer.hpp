#pragma once
#include <glm/glm.hpp>
#include <omp.h>
#include "color.hpp"
#include "fragment.hpp"

const int FRAMEBUFFER_WIDTH = 1000, FRAMEBUFFER_HEIGHT = 800;
const int FRAMEBUFFER_SIZE = FRAMEBUFFER_WIDTH * FRAMEBUFFER_HEIGHT;

std::array<zFragment, FRAMEBUFFER_SIZE> framebuffer;

void clear() {
    for (int i = 0; i < FRAMEBUFFER_SIZE; i++) {
        framebuffer[i] = zFragment{Color(0,0,0), 9999.0f};
    }
}

void point(const Fragment& f) {
    if (f.z < framebuffer[f.pos.y * FRAMEBUFFER_WIDTH + f.pos.x].z) {
       framebuffer[f.pos.y * FRAMEBUFFER_WIDTH + f.pos.x] = zFragment{f.color, f.z};
    }
}