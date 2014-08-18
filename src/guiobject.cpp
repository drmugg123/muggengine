#include "guiobject.hpp"

mugg::gui::GUIObject::GUIObject(mugg::gui::GUIManager* parent, unsigned int index) {
    this->parent = parent;
    this->index = index;
    this->rotationAngle = 0.0f;
    this->scale = glm::vec2(1.0f, 1.0f);
}
mugg::gui::GUIManager* mugg::gui::GUIObject::GetParent() {
    return this->parent;
}

void mugg::gui::GUIObject::SetScale(const glm::vec2& scale) {
    this->scale = scale;
    
    this->scaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(this->scale.x, this->scale.y, 0.0f));
}
glm::vec2 mugg::gui::GUIObject::GetScale() {
    return this->scale;
}

void mugg::gui::GUIObject::SetRotationAngle(const float rotationAngle) {
    this->rotationAngle = rotationAngle;

    this->rotationMatrix = glm::rotate(glm::mat4(1.0f), this->rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
}
float mugg::gui::GUIObject::GetRotationAngle() {
    return this->rotationAngle;
}

void mugg::gui::GUIObject::SetPosition(const glm::vec2& position) {
    this->position = position;

    this->translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(this->position.x, this->position.y, 0.0f));
}
glm::vec2 mugg::gui::GUIObject::GetPosition() {
    return this->position;
}

void mugg::gui::GUIObject::SetTexture(mugg::graphics::Texture2D* texture) {
    this->texture = texture;
}
mugg::graphics::Texture2D* mugg::gui::GUIObject::GetTexture() {
    return this->texture;

}

void mugg::gui::GUIObject::SetModelMatrix(const glm::mat4& matrix) {
    this->modelMatrix = matrix;
}
glm::mat4 mugg::gui::GUIObject::GetModelMatrix() {
    return this->translationMatrix * this->rotationMatrix * this->scaleMatrix;
}

unsigned int mugg::gui::GUIObject::GetIndex() {
    return this->index;
}
