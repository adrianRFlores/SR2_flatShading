#pragma once
#include <glm/glm.hpp>
#include "camera.hpp"

struct Uniforms {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 viewport;
};

glm::mat4 createViewportMatrix(const int screenWidth, size_t screenHeight) {
    glm::mat4 viewport = glm::scale(glm::mat4(1.0f), glm::vec3(screenWidth / 2.0f, screenHeight / 2.0f, 0.5f));

    return glm::translate(viewport, glm::vec3(1.0f, 1.0f, 0.5f));
}

glm::mat4 createViewMatrix(const Camera& camera) {
    return glm::lookAt(
        camera.pos,
        camera.target,
        camera.up
    );
}

glm::mat4 createProjectionMatrix(const float fov, const float aspectRatio, const float nearClip, const float farClip) {
    return glm::perspective(
        glm::radians(fov),
        aspectRatio,
        nearClip,
        farClip
    );
}

glm::mat4 createModelMatrix(const glm::mat4& translation, const glm::mat4& rotation, const glm::mat4& scale){
    return translation * rotation * scale;
}