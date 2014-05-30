#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Entities/Entity.h"

namespace Zk {
namespace Game {

class Camera
{
public:
	virtual ~Camera() {};
	
	virtual void setupViews() = 0;
	std::vector<sf::View> getViews() const;
	
protected:
	void discardInvalidEntities();
	
	std::vector<std::weak_ptr<Entity>> trackedEntities;
	std::vector<sf::View> computedViews;
};

class SplitScreenCamera : public Camera
{
public:
	enum class Alignment : int
	{
		Horizontal = 0,
		Vertical = 1
	};
	
	SplitScreenCamera(
		std::initializer_list<std::weak_ptr<Entity>> entities
	);
	SplitScreenCamera(
		const std::vector<std::weak_ptr<Entity>> & entities
	);
	virtual ~SplitScreenCamera();
	
	virtual void setupViews() override;
	
	void setAlignment(Alignment a);
	Alignment getAlignment() const;
	
private:
	Alignment alignment;
};

class BoundingBoxCamera : public Camera
{
public:
	BoundingBoxCamera();
	virtual ~BoundingBoxCamera();
	
	virtual void setupViews() override;
};

}}
