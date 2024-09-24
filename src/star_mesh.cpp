#include <star_mesh.hpp>

/**
 * Constructor for StarMesh class that generates the vertices of an icosahedron and subdivides its triangles
 *
 * @param recursionLevel The level of recursion for subdividing the triangles
 *
 * @throws None
 */
StarMesh::StarMesh(int recursionLevel, sf::Color colour) {
    this->recursionLevel = recursionLevel;
    this->colour = colour;

    float goldenRatio = (1.f + sqrt(5.f))/2.f;

    // Create the 12 vertices of the icosahedron
    auto v0 = sf::Vector3f {-1.f,  goldenRatio,  0.f};
    auto v1 = sf::Vector3f { 1.f,  goldenRatio,  0.f};
    auto v2 = sf::Vector3f {-1.f, -goldenRatio, 0.f};
    auto v3 = sf::Vector3f { 1.f, -goldenRatio, 0.f};
    auto v4 = sf::Vector3f {0.f, -1.f,  goldenRatio};
    auto v5 = sf::Vector3f {0.f,  1.f,  goldenRatio};
    auto v6 = sf::Vector3f {0.f, -1.f, -goldenRatio};
    auto v7 = sf::Vector3f {0.f,  1.f, -goldenRatio};
    auto v8 =  sf::Vector3f {goldenRatio, 0.f, -1.f};
    auto v9 =  sf::Vector3f {goldenRatio, 0.f,  1.f};
    auto v10 = sf::Vector3f {-goldenRatio, 0.f, -1.f};
    auto v11 = sf::Vector3f {-goldenRatio, 0.f,  1.f};

    vertices.insert(vertices.end(), {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11});
    numOfVertices = 12;

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
        std::vector<FaceIndices> newFaces;
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
        faces = newFaces;
    }
    ProjectToUnitSphere();
}

StarMesh::~StarMesh() {
    faces.clear();
    vertices.clear();
}

/*!
    Draws the star mesh to the screen.
    @param positionOffset: Translates all vertices by this offset.
    @param radius: Scales the vertices.
*/
void StarMesh::Draw(sf::Vector3f positionOffset, float radius) {
    for (auto& face : faces) {
        sf::Vector3f v1 = GetOffsettedPosition(positionOffset, radius, face.index0);
        sf::Vector3f v2 = GetOffsettedPosition(positionOffset, radius, face.index1);
        sf::Vector3f v3 = GetOffsettedPosition(positionOffset, radius, face.index2);

        float averageZ = (v1.z + v2.z + v3.z)/3.f;

        if (averageZ > 0.f) {
            colour.a = 255*averageZ/radius;
            sf::VertexArray triangle = sf::VertexArray(sf::Triangles, 3);
            triangle[0].position = sf::Vector2f(v1.x, v1.y);
            triangle[1].position = sf::Vector2f(v2.x, v2.y);
            triangle[2].position = sf::Vector2f(v3.x, v3.y);
            triangle[0].color = triangle[1].color = triangle[2].color = colour;

            Renderer::GetRenderer().AddVertexArray(triangle);
        }
    }
}

/*!
    Updates the star mesh by rotating by given theta and phi angles.
    @param theta: Rotation around the star's x axis.
    @param phi: Rotation around the star's y axis.

    @throws None

    @returns void

    @see LinearAlgebra::RotateAroundX
    @see LinearAlgebra::RotateAroundY
*/
void StarMesh::Update(float theta, float phi) {
    float deltaTheta = theta - currentTheta;
    float deltaPhi = phi - currentPhi;

    if (deltaTheta != 0.f) {
        RotateAroundXAxis(deltaTheta);
        ProjectToUnitSphere();
    }
    if (deltaPhi != 0.f) {
        RotateAroundYAxis(deltaPhi);
        ProjectToUnitSphere();
    }

    currentTheta = theta;
    currentPhi = phi;
}

void StarMesh::RotateAroundXAxis(float deltaTheta) {
    for (auto& vertex: vertices) {
        vertex = LinearAlgebra::RotateAroundX(deltaTheta, vertex);
    }
}

void StarMesh::RotateAroundYAxis(float deltaPhi) {
    for (auto& vertex: vertices) {
        vertex = LinearAlgebra::RotateAroundY(deltaPhi, vertex);
    }
}

/*!
    Translates and scales a vertex.
    @param positionOffset: Translation to be applied to the vertex.
    @param radius: Scale to be applied to the vertex.
    @param index: Index of the desired vertex in the vertices vector.
*/
sf::Vector3f StarMesh::GetOffsettedPosition(sf::Vector3f positionOffset, float radius, int index) {

    return sf::Vector3f{
            positionOffset.x + radius*vertices[index].x, 
            positionOffset.y + radius*vertices[index].y, 
            positionOffset.z + radius*vertices[index].z};
}

/*!
    Normalises all vertices in the vertices vector member, i.e. projects each vertex on to a unit sphere.
*/
void StarMesh::ProjectToUnitSphere() {
    for (auto& vertex : vertices) {
        vertex = LinearAlgebra::Normalise(vertex);
    }
}

/*!
    Adds a triangle to a given vector of FaceIndices, given the indices of each desired vertex in the vertices vector.
    @param facesList: The existing list of faces to append the triangle on to.
    @param index0: Index of first vertex.
    @param index1: Index of second vertex.
    @param index2: Index of third vertex.
*/
void StarMesh::AddTriangle(std::vector<FaceIndices>& facesList, int index0, int index1, int index2) {
    sf::Vector3f vertex0 = vertices[index0];
    sf::Vector3f vertex1 = vertices[index1];
    sf::Vector3f vertex2 = vertices[index2];

    FaceIndices face = FaceIndices(index0, index1, index2);
    facesList.push_back(face);
}

/*!
    Calculates the midpoint of two pre-existing vertices and adds this midpoint to the vertices vector.
    @param: index1 Index of the first vertex.
    @param: index2 Index of the second vertex.
    @returns: The index of the newly created midpoint vertex in the vertices vector.
*/
int StarMesh::GetMidpointOfVertices(int index1, int index2) {
    sf::Vector3f point2 = vertices[index2];
    sf::Vector3f point1 = vertices[index1];

    sf::Vector3f middlePoint = sf::Vector3f {
        (point1.x + point2.x)/2.f,
        (point1.y + point2.y)/2.f,
        (point1.z + point2.z)/2.f};

    vertices.push_back(middlePoint);
    numOfVertices++;
    
    int newestIndex = numOfVertices - 1;
    
    return newestIndex;
}