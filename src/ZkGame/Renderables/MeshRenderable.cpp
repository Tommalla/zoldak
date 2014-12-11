#include <SFML/Graphics.hpp>

#include "../Player.hpp"

#include "MeshRenderable.hpp"
#include "Renderable.hpp"

using namespace Zk::Game;

MeshRenderable::MeshRenderable(const sf::VertexArray & varr)
{
	this->varr = varr;
}

MeshRenderable::~MeshRenderable()
{

}

void MeshRenderable::paint(sf::RenderTarget * rt, const Player & viewer)
{
	rt->draw(varr);
}
