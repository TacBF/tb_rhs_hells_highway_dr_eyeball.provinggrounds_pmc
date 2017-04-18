//V2.0
//Add this to the INIT line of the vehicle you want to use nul = [this] execVM "OffroadAUG.sqf";
//Configured to work on Offroaders and trucks. Will work on nearly everything but weapon placing may be unrelyable.



//setup MP
mpAddEventHand = {
private["_obj","_type","_code"];
_obj = _this select 0;
_type = _this select 1;
_code = _this select 2;
_add = _obj addEventHandler [_type,_code];
_obj setVariable ["EH_GETOUT",_add,true];
};
mpRemoveEventHand = {
private["_obj","_type","_index"];
_obj = _this select 0;
_type = _this select 1;
_index = _this select 2;
_obj removeEventHandler [_type, _index];
//hint str _index;
};
mpSetDir = {
private["_obj","_dir"];
_obj = _this select 0;
_dir = _this select 1;
_obj setDir _dir;
};
mpSetPos = {
private["_obj","_pos"];
_obj = _this select 0;
_pos = _this select 1;
_obj setPosATL _pos;
};



//SetupLocal
_veh = (_this select 0);
_moved = false;
_Cname = nil;
_Dname = nil;
_add = nil;
_MG = ["RHS_M2StaticMG_D","RHS_M2StaticMG_WD","RHS_M2StaticMG_USMC_D","RHS_M2StaticMG_USMC_WD","rhs_KORD_high_MSV","rhs_KORD_high_VDV","rhs_KORD_high_VMF","rhsgref_ins_DSHKM","rhsgref_cdf_DSHKM","rhsgref_cdf_b_DSHKM","rhsgref_ins_g_DSHKM","rhsgref_nat_DSHKM","rhs_Igla_AA_pod_msv","rhsgref_cdf_b_Igla_AA_pod","RHS_Stinger_AA_pod_WD","RHS_Stinger_AA_pod_D","RDS_DSHKM_CSAT","RDS_Igla_AA_pod_CSAT"];
_ZU = ["RDS_ZU23_FIA","RDS_ZU23_CSAT","RHSgref_cdf_ZU23","rhsgref_ins_ZU23","rhsgref_cdf_b_ZU23","rhsgref_ins_ZU23","RHS_ZU23_VDV","RHS_ZU23_MSV"];
_LMG = ["RHS_M2StaticMG_MiniTripod_D","RHS_M2StaticMG_MiniTripod_WD","RHS_M2StaticMG_MiniTripod_USMC_D","RHS_M2StaticMG_MiniTripod_USMC_WD","RDS_M2StaticMG_MiniTripod_CSAT","RHS_MK19_TriPod_WD","RHS_MK19_TriPod_D","rhsgref_cdf_b_AGS30_TriPod","RHS_AGS30_TriPod_MSV","RHS_NSV_TriPod_MSV","rhs_KORD_VDV","rhs_KORD_VMF","rhsgref_ins_DSHKM_Mini_TriPod","rhsgref_cdf_b_DSHKM_Mini_TriPod","rhsgref_ins_g_DSHKM_Mini_TriPod","rhs_Metis_9k115_2_msv","rhssaf_army_metis_9k115","RDS_KORD_CSAT","RDS_DSHkM_Mini_TriPod_CSAT"];
_SPG = ["RDS_SPG9_FIA","RDS_SPG9_CSAT","rhsgref_cdf_b_SPG9","rhsgref_cdf_b_SPG9M","rhsgref_ins_SPG9M","rhs_SPG9M_MSV","rhsgref_ins_SPG9"];
_L = ["RDS_TOW_TriPod_FIA","RDS_TOW_TriPod_CSAT","RHS_TOW_TriPod_D","RHS_TOW_TriPod_WD","rhs_Kornet_9M133_2_vdv","rhs_Kornet_9M133_2_msv"];
_M = ["rhs_2b14_82mm_msv","rhsgref_ins_2b14","rhsgref_nat_2b14","RHS_M252_D","RHS_M252_USMC_D","rhsgref_cdf_reg_M252","RDS_2b14_82mm_CSAT","RDS_M252_CSAT","RHS_M119_D","rhsgref_cdf_b_reg_d30","rhsgref_cdf_b_reg_d30_at","rhs_D30_at_vdv","rhs_D30_vdv","rhs_D30_at_msv","rhs_D30_msv"];

if(isNil { _veh getVariable "offAug_attached"}) then {
  _veh setVariable [ "offAug_attached",false,false];
} else {
  _veh setVariable [ "offAug_attached",(_veh getVariable "offAug_attached"),false];
};

//Action
_add = _veh addAction ["",{

	//Import Variables
	_veh = (_this select 3) select 0;
	_L = (_this select 3) select 1;
	_MG = (_this select 3) select 2;
	_M = (_this select 3) select 3;
	_LMG = (_this select 3) select 4;
	_SPG = (_this select 3) select 5;
	_ZU = (_this select 3) select 6;
	_aug = _veh getVariable "offAug_attached";
	_NO = nearestObjects [[(_veh modelToWorld [0,-5,0]) select 0,(_veh modelToWorld [0,-5,0]) select 1,0],_MG + _L + _M + _LMG + _SPG + _ZU,4];

	//Logic
	if(( typeNAME(_veh getVariable["offAug_attached",false]) == "BOOL")  AND ((count _NO) >= 1)) then {

		//Attach
		//Locations
		if(typeOf (_NO select 0) in _L) then {(_NO select 0) attachTo [_veh,[0,-1.5,0.25]];[[(_NO select 0),180],"mpSetDir",true,true]spawn BIS_fnc_MP;};
		if(typeOf (_NO select 0) in _LMG) then {(_NO select 0) attachTo [_veh,[-0.3,-1.5,0.6]];[[(_NO select 0),180],"mpSetDir",true,true]spawn BIS_fnc_MP;_veh animate ["HideDoor3", 1];};
		if(typeOf (_NO select 0) in _SPG) then {(_NO select 0) attachTo [_veh,[-0.1,-2,-0.7]];[[(_NO select 0),180],"mpSetDir",true,true]spawn BIS_fnc_MP;_veh animate ["HideDoor3", 1];};
		if(typeOf (_NO select 0) in _ZU) then {(_NO select 0) attachTo [_veh,[0.05,-2,1.55]];[[(_NO select 0),180],"mpSetDir",true,true]spawn BIS_fnc_MP;_veh animate ["HideDoor3", 1];};
		if(typeOf (_NO select 0) in _MG) then {(_NO select 0)attachTo [_veh,[0.25,-2,1]];};
		if(typeOf (_NO select 0) in _M) then {(_NO select 0) attachTo [_veh,[0,-2,0]];};
		//Event Handler
		[[(_NO select 0),"GetOut",{(_this select 2) setPosATL ((_this select 0) modelToWorld [-3,-1.2,-1])}],"mpAddEventHand",true,true] spawn BIS_fnc_MP;
		 _veh setVariable["offAug_attached",(_NO select 0),true];
	}else{
		if ( typeNAME(_veh getVariable["offAug_attached",false]) == "OBJECT") then {

			//Detach
			private ["_pos2"];
			_pos2 = [(_veh modelToWorld [0,-6,0]) select 0,(_veh modelToWorld [0,-6,0]) select 1,0.25];
			sleep 0.1;
			_aug attachTo [_veh,[0,-2,2.5]];
			sleep 0.1;
			detach _aug;
			[[ _aug,_pos2],"mpSetPos",true,true]spawn BIS_fnc_MP;

			[[_aug,"GetOut", (_aug getVariable 'EH_GETOUT')],"mpRemoveEventHand",true,true]spawn BIS_fnc_MP;
			_veh setVariable["offAug_attached",false,true];
		}else{
			//Null
			hint "Nothing Mount/Dismount.";
		};
	};
},[_veh,_L,_MG,_M,_LMG,_SPG,_ZU],1.5,true,true,"","speed _target <= 1 AND speed _target >= -1"];

_veh setVariable ['AUG','offroad',true];
if(local player) then { _veh setVariable [ "aug_actions",true,false ] };

//scan
while {alive _veh} do {
sleep 1;

	if (speed _veh <= 1 AND speed _veh >= -1 ) then {
		if( typeNAME(_veh getVariable["offAug_attached",false]) == "OBJECT")  then{
            _aug = _veh getVariable "offAug_attached";
			//Display name
			_Cname = typeOf _aug;
			_Dname = getText (configFile >> "cfgVehicles" >> _Cname >> "displayName");
			_veh setUserActionText [ _add,format [ "Detach %1",_Dname]];
		}else{

			//Detection
			_NO = nearestObjects [[(_veh modelToWorld [0,-5,0]) select 0,(_veh modelToWorld [0,-5,0]) select 1,0],_MG + _L + _M + _LMG + _SPG + _ZU,4];

			if((count _NO)>=1)then{

				//Display name
				_Cname = typeOf (_NO select 0);
				_Dname = getText (configFile >> "cfgVehicles" >> _Cname >> "displayName");
				_veh setUserActionText [_add,format[ "Attach %1",_Dname]];
			}else{

				//Null
				_veh setUserActionText [_add,""];
			};
		};

	};
};






