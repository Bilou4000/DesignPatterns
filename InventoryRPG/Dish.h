#pragma once

#include "IObserver.h"
#include "DishData.h"
#include "GameObject.h"

class Dish : public IObserver, public GameObject
{
public:
	Dish(float newTimeToPrepare, int newId);

	void Init() override;
	void Update() override;
	void Draw() override;

	void OnNotify() override;
	
	void ChangeDishData(std::shared_ptr<DishData> newData);

public:
	std::shared_ptr<DishData> dishData;

	float timeToPrepare;
	int id;
};

