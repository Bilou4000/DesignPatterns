#pragma once
#include "Event.h"
#include "GameObject.h"
#include "Customer.h"
#include "DishData.h"

#include <string>
#include <vector>
#include <memory>

class CommandScheduler;

class GameManager : public IObserver, public std::enable_shared_from_this<GameManager>
{
public :
	void Init();
	void Update();
	void Draw();
	void Unload();

	void NewCustomer();
	void NewDish();
	void AddObject(std::shared_ptr<GameObject> object);
	void EraseObject(std::shared_ptr<GameObject> object);

	void OnNotify() override;

private:

	const int minTimeToPrepare = 1;
	const int maxTimeToPrepare = 6;
	const int minTimeBetweenCustomers = 2;
	const int maxTimeBetweenCustomers = 4;

	int randomTimeBetweenCustomer = 2;
	int randomTimeToPrepare = 2; 
	int newDishID = 0;
	
	float timeElapsedCustomer = 0.0f;

	std::shared_ptr<CustomerData> waitingCustomerData;
	std::shared_ptr<CustomerData> runningCustomerData;
	std::shared_ptr<DishData> foodData;

	std::vector<std::shared_ptr<Customer>> allCustomers;
	std::vector<std::shared_ptr<GameObject>> objectsToAdd;
	std::vector<std::shared_ptr<GameObject>> allObjects;
	std::vector<std::shared_ptr<GameObject>> objectsToRemove;

	std::shared_ptr<CommandScheduler> commandScheduler;
};

