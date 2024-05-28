#include <fps_tracker.hpp>

FpsTracker::FpsTracker() {
    clock = sf::Clock();
    fps = 0;
    noFrames = 0;
}

FpsTracker::~FpsTracker() {
}

void FpsTracker::Update() {
    if (clock.getElapsedTime().asSeconds() >= 1.f) {
        fps = noFrames;
        noFrames = 0;
        clock.restart();
    }
    ++noFrames;

    std::cout << "FPS: " << fps << std::endl;
}