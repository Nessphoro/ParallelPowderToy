#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_BRON PT_BRON 179
Element_BRON::Element_BRON()
{
	Identifier = "DEFAULT_PT_BRON";
	Name = "BRON";
	Colour = PIXPACK(0x707080);
	MenuVisible = 1;
	MenuSection = SC_NUCLEAR;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 1;
	Hardness = 0;

	Weight = 10;

	Temperature = R_TEMP + 4.0f + 273.15f;
	HeatConduct = 251;
	Description = "Boron. Inhibits neutrons and radioactive acivity";

	State = ST_SOLID;
	Properties = TYPE_SOLID | PROP_HOT_GLOW|PROP_CONDUCTS | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2349;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_BRON::update;
}


int Element_BRON::update(UPDATE_FUNC_ARGS)
{
	
	for (int rx = -1; rx < 2; rx++) {
		for (int ry = -1; ry < 2; ry++) {
			if ((!rx != !ry) && BOUNDS_CHECK) {
				int part = sim->photons[y + ry][x + rx];
				if ((part & 0xFF) == PT_NEUT)
				{
 					parts[part >> 8].vx *= 0.985f;
					parts[part >> 8].vy *= 0.985f;
					
				}
			}
		}
	}
	return 0;
}

Element_BRON::~Element_BRON()
{

}