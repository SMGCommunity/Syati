#pragma once

enum AreaFormType
{
	AreaForm_Cube,
	AreaForm_CenteredCube,
	AreaForm_Sphere,
	AreaForm_Cylinder,
	AreaForm_Bowl
};

class AreaForm;

namespace MR
{
	AreaForm* createAreaForm(AreaFormType);
};
