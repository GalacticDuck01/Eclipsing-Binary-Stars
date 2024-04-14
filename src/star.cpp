#include <star.hpp>

Star::Star() {
    position = sf::Vector3f(500.f, 500.f, 0.f);
    radius = 400;
    recursionLevel = 4;

    float goldenRatio = (1.f + sqrt(5.f))/2.f;

    // Create the 12 vertices of the icosahedron
    sf::Vector3f v0 = sf::Vector3f(-1.f,  goldenRatio, 0);
    sf::Vector3f v1 = sf::Vector3f( 1.f,  goldenRatio, 0);
    sf::Vector3f v2 = sf::Vector3f(-1.f, -goldenRatio, 0);
    sf::Vector3f v3 = sf::Vector3f( 1.f, -goldenRatio, 0);
    sf::Vector3f v4 = sf::Vector3f(0, -1.f,  goldenRatio);
    sf::Vector3f v5 = sf::Vector3f(0,  1.f,  goldenRatio);
    sf::Vector3f v6 = sf::Vector3f(0, -1.f, -goldenRatio);
    sf::Vector3f v7 = sf::Vector3f(0,  1.f, -goldenRatio);
    sf::Vector3f v8 =  sf::Vector3f( goldenRatio, 0.f, -1.f);
    sf::Vector3f v9 =  sf::Vector3f( goldenRatio, 0.f,  1.f);
    sf::Vector3f v10 = sf::Vector3f(-goldenRatio, 0.f, -1.f);
    sf::Vector3f v11 = sf::Vector3f(-goldenRatio, 0.f,  1.f);

    vertices.insert(vertices.end(), {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11});
    numOfVertices = 12;

    ProjectToUnitSphere();

    // Add triangles around point 0
    AddTriangle(faces, 0, 11, 5);
    AddTriangle(faces, 0, 5, 1);
    AddTriangle(faces, 0, 1, 7);
    AddTriangle(faces, 0, 7, 10);
    AddTriangle(faces, 0, 10, 11);

    // 5 adjacent faces
    AddTriangle(faces, 1, 5, 9);
    AddTriangle(faces, 5, 11, 4);
    AddTriangle(faces, 11, 10, 2);
    AddTriangle(faces, 10, 7, 6);
    AddTriangle(faces, 7, 1, 8);

    // 5 faces around point 3
    AddTriangle(faces, 3, 9, 4);
    AddTriangle(faces, 3, 4, 2);
    AddTriangle(faces, 3, 2, 6);
    AddTriangle(faces, 3, 6, 8);
    AddTriangle(faces, 3, 8, 9);

    // 5 adjacent faces
    AddTriangle(faces, 4, 9, 5);
    AddTriangle(faces, 2, 4, 11);
    AddTriangle(faces, 6, 2, 10);
    AddTriangle(faces, 8, 6, 7);
    AddTriangle(faces, 9, 8, 1);

    //Subdivide Triangles
    for (int i = 0; i < recursionLevel; i++) {
        std::vector<StarFace> newFaces;
        int i0, i1, i2, i3, i4, i5;
        for (auto& face : faces) {
            i0 = face.index0;
            i1 = face.index1;
            i2 = face.index2;

            i3 = GetMidpointOfVertices(i0, i1);
            i4 = GetMidpointOfVertices(i0, i2);
            i5 = GetMidpointOfVertices(i1, i2);

             AddTriangle(newFaces, i0, i3, i4);
            AddTriangle(newFaces, i4, i3, i5);
            AddTriangle(newFaces, i3, i1, i5);
            AddTriangle(newFaces, i4, i5, i2);
        }
        ProjectToUnitSphere();
        faces = newFaces;
    }
}

Star::~Star() {
    faces.clear();
    vertices.clear();
}

void Star::Draw(sf::RenderWindow& window) {
    for (auto& face : faces) {
        sf::Vector3f translatedVertex0 = GetOverallPosition(face.index0);
        sf::Vector3f translatedVertex1 = GetOverallPosition(face.index1);
        sf::Vector3f translatedVertex2 = GetOverallPosition(face.index2);

        sf::ConvexShape shape;
        shape.setPointCount(3);
        shape.setPoint(0, sf::Vector2f(translatedVertex0.x, translatedVertex0.y));
        shape.setPoint(1, sf::Vector2f(translatedVertex1.x, translatedVertex1.y));
        shape.setPoint(2, sf::Vector2f(translatedVertex2.x, translatedVertex2.y));
        shape.setFillColor(sf::Color(0, 0, 0));
        shape.setOutlineColor(sf::Color(255, 255, 255));
        shape.setOutlineThickness(-1);
        window.draw(shape);
    }
}

void Star::ProjectToUnitSphere() {
    for (auto& vertex : vertices) {
        float magnitude = sqrt(pow(vertex.x, 2) + pow(vertex.y, 2) + pow(vertex.z, 2));
        vertex /= magnitude;
    }
}

void Star::AddTriangle(std::vector<StarFace>& facesList, int index0, int index1, int index2) {
    sf::Vector3f vertex0 = vertices[index0];
    sf::Vector3f vertex1 = vertices[index1];
    sf::Vector3f vertex2 = vertices[index2];

    StarFace face = StarFace(index0, index1, index2);
    facesList.push_back(face);
}

int Star::GetMidpointOfVertices(int index1, int index2) {
    sf::Vector3f point1 = vertices[index1];
    sf::Vector3f point2 = vertices[index2];

    sf::Vector3f middlePoint = sf::Vector3f(
        (point1.x + point2.x)/2.f,
        (point1.y + point2.y)/2.f,
        (point1.z + point2.z)/2.f);

    vertices.push_back(middlePoint);
    numOfVertices++;
    
    int newestIndex = numOfVertices - 1;
    
    return newestIndex;
}

sf::Vector3f Star::GetOverallPosition(int index) {
    return sf::Vector3f(
            position.x + radius*vertices[index].x, 
            position.y + radius*vertices[index].y, 
            position.z + radius*vertices[index].z);
}