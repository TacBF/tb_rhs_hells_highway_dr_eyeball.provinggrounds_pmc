// JAF - Army (Royal-Guard)
// Author: Cole

class TB_BLUBasicAmmunitionBox
{
	transportClear = 1;
	proxyObject = "TB_BLUBasicAmmunitionBox";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_mag_30Rnd_556x45_M855A1_Stanag", 20},
			{"rhs_30Rnd_545x39_AK", 20},
			{"rhsusf_20Rnd_762x51_m118_special_Mag", 5},
			{"rhsusf_100Rnd_762x51", 5},
			{"rhs_200rnd_556x45_M_SAW", 5},
			{"CUP_5Rnd_86x70_L115A1", 10},
			{"SmokeShell", 10},
			{"rhs_mag_m67", 10},
			{"rhs_mag_M441_HE", 10},
			{"LaserBatteries", 2},
			{"DemoCharge_Remote_Mag", 0}
		};
		transportWeapons[] = {{"rhs_weap_rsp30_red", 10}, {"rhs_weap_rpg26", 1}, {"rhs_weap_m16a4_carryhandle",2}};
		//transportBackpacks[] = {};
		//transportItems[] = {};
	};
};
class TB_Box_West_Mines_F
{
	transportClear = 1;
	proxyObject = "TB_Box_West_Mines_F";
	class transportCargo
	{
		transportMagazines[] = {
			{"rhs_mine_M19_mag", 4},
			{"SLAMDirectionalMine_Wire_Mag", 0},
			{"rhs_mine_pmn2_mag", 0},
			{"APERSBoundingMine_Range_Mag", 0},
			{"APERSTripMine_Wire_Mag", 2},
			{"ClaymoreDirectionalMine_Remote_Mag", 5}
		};
		//transportWeapons[] = {};
		transportBackpacks[] = {{"B_Kitbag_rgr", 2}};
		transportItems[] = {{"MineDetector", 2}, {"ToolKit", 1}};
	};
};