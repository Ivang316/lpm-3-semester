#pragma once
#include <iostream>
#include "Group.h"
#include <string>

using namespace std;

class ChildrenGarden {
	int numberChildrenGarden;
	int groupsCount;
	Group* groups;
	string directorName;

public:
	ChildrenGarden(int gardenNumber, int groupsNumber, string director) :
		numberChildrenGarden(gardenNumber), groupsCount(groupsNumber), directorName(director)
	{
		groups = new Group[groupsCount];
	}

	bool add(Child& child, int groupNumber) {
		if (groupNumber >= groupsCount || groupNumber <= 0) return false;
		groups[groupNumber - 1].pushChild(child);
		return true;
	}

	void print(int groupNumber) {
		groups[groupNumber - 1].print(groupNumber);
	}

	void setTeacher(int groupNumber, string teacherName) {
		groups[groupNumber - 1].setTeacher(teacherName);
	}

	bool atGroup(const Child& child, int groupNumber) {
		return groups[groupNumber - 1].hasChild(child);
	}

	void moveChild(int groupFrom, int groupTo, const Child& child) {
		if (atGroup(child, groupFrom) && !atGroup(child, groupTo)) {
			groups[groupFrom - 1].deleteChild(child);
			groups[groupTo - 1].pushChild(child);
		}
	}

	~ChildrenGarden() {
		for (int i = 0; i < groupsCount; i++) {
			groups[i].~Group();
		}
		delete[] groups;
	}
};