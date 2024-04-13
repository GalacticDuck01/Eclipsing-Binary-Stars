#include <star.hpp>

Star::Star() {
    position = sf::Vector3f(300.f, 300.f, 0.f);
    radius = 100;

    float goldenRatio = 0.5f*(1.f + sqrt(5.f));
    float a = 1.f;
    float b = 1.0f/goldenRatio;

    sf::Vector3f v1 = sf::Vector3f(0, b, -a);
    sf::Vector3f v2 = sf::Vector3f(b, a, 0);
    sf::Vector3f v3 = sf::Vector3f(-b, a, 0);
    sf::Vector3f v4 = sf::Vector3f(0, b, a);
    sf::Vector3f v5 = sf::Vector3f(0, -b, a);
    sf::Vector3f v6 = sf::Vector3f(-a, 0, b);
    sf::Vector3f v7 = sf::Vector3f(0, -b, -a);
    sf::Vector3f v8 = sf::Vector3f(a, 0, -b);
    sf::Vector3f v9 = sf::Vector3f(a, 0, b);
    sf::Vector3f v10 = sf::Vector3f(-a, 0, -b);
    sf::Vector3f v11 = sf::Vector3f(b, -a, 0);
    sf::Vector3f v12 = sf::Vector3f(-b, -a, 0);

    vertices.insert(vertices.end(), {v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12});

    ProjectToUnitSphere();

    AddTriangle(v3, v2, v1);
    AddTriangle(v2, v3, v4);
    AddTriangle(v6, v5, v4);
    AddTriangle(v5, v9, v4);
    AddTriangle(v8, v7, v1);
    AddTriangle(v7, v10, v1);
    AddTriangle(v12, v11, v5);
    AddTriangle(v11, v12, v7);
    AddTriangle(v10, v6, v3);
    AddTriangle(v6, v10, v12);
    AddTriangle(v9, v8, v2);
    AddTriangle(v8, v9, v11);
    AddTriangle(v3, v6, v4);
    AddTriangle(v9, v2, v4);
    AddTriangle(v10, v3, v1);
    AddTriangle(v2, v8, v1);
    AddTriangle(v12, v10, v7);
    AddTriangle(v8, v11, v7);
    AddTriangle(v6, v12, v5);
    AddTriangle(v11, v9, v5);
}

Star::~Star() {

}

void Star::Draw(sf::RenderWindow& window) {
    for (auto& triangle : triangles) {
        std::cout << "Printed a triangle!" << std::endl;
        window.draw(triangle);
    }
}

void Star::ProjectToUnitSphere() {
    for (auto& vertex : vertices) {
        float magnitude = sqrt(pow(vertex.x, 2) + pow(vertex.y, 2) + pow(vertex.z, 2));
        vertex /= magnitude;
    }
}

void Star::AddTriangle(sf::Vector3f vertex1, sf::Vector3f vertex2, sf::Vector3f vertex3) {
    sf::Vector3f translatedVertex1 = sf::Vector3f(position.x + radius*vertex1.x, position.y + radius*vertex1.y, position.z + radius*vertex1.z);
    sf::Vector3f translatedVertex2 = sf::Vector3f(position.x + radius*vertex2.x, position.y + radius*vertex2.y, position.z + radius*vertex2.z);
    sf::Vector3f translatedVertex3 = sf::Vector3f(position.x + radius*vertex3.x, position.y + radius*vertex3.y, position.z + radius*vertex3.z);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(translatedVertex1.x, translatedVertex1.y));
    triangle.setPoint(1, sf::Vector2f(translatedVertex2.x, translatedVertex2.y));
    triangle.setPoint(2, sf::Vector2f(translatedVertex3.x, translatedVertex3.y));
    triangle.setFillColor(sf::Color(0, 0, 0));
    triangle.setOutlineThickness(-2);
    triangle.setOutlineColor(sf::Color(255, 255, 255));

    triangles.push_back(triangle);
}