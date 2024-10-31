#include <SFML/Graphics.hpp>
#include <vector>

class Renderer
{
public:
    // Stop the compiler generating methods to copy the object
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    static Renderer& GetRenderer() {
        static Renderer renderer;
        return renderer;
    }

    void AddVertexArray(sf::VertexArray& vertices) {
        for (std::size_t i = 0; i < vertices.getVertexCount(); ++i) {
            vertexArray.append(vertices[i]);
        }
    }

    void Draw(sf::RenderTarget& target) {
        if (vertexArray.getVertexCount() > 0) {
            target.draw(vertexArray);
        }

        vertexArray.clear();
    }

private:
    sf::VertexArray vertexArray;

    // Private constructor for singleton
    Renderer() : vertexArray(sf::Triangles) {}
};