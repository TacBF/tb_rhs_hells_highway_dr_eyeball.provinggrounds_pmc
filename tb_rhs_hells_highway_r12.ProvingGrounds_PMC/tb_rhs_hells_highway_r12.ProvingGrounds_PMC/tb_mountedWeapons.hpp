class TacBF
{
        class Supply
        {
                // Generates cargo IDs (More effecient broadcasting for these items + their ammo)
                staticWeapons[] = {"RHS_M2StaticMG_MiniTripod_D", "RHS_M2StaticMG_MiniTripod_WD", "RHS_M2StaticMG_MiniTripod_USMC_D", "RHS_M2StaticMG_MiniTripod_USMC_WD", "RHS_M2StaticMG_D", "RHS_M2StaticMG_WD", "RHS_M2StaticMG_USMC_D", "RHS_M2StaticMG_USMC_WD", "rhs_KORD_high_MSV", "rhs_KORD_high_VDV", "rhs_KORD_high_VMF", "rhs_KORD_MSV", "rhs_KORD_VDV", "rhs_KORD_VMF", "rhsgref_ins_DSHKM", "rhsgref_cdf_DSHKM", "rhsgref_cdf_b_DSHKM", "rhsgref_ins_g_DSHKM", "rhsgref_nat_DSHKM", "rhsgref_ins_DSHKM_Mini_TriPod","rhsgref_cdf_DSHKM_Mini_TriPod", "rhsgref_ins_g_DSHKM_Mini_TriPod", "RHS_M252_D", "RHS_M252_USMC_D", "rhsgref_cdf_reg_M252", "rhs_2b14_82mm_msv", "rhsgref_ins_2b14", "rhsgref_nat_2b14", "RHS_TOW_TriPod_D", "RHS_TOW_TriPod_WD", "rhs_Metis_9k115_2_msv", "rhssaf_army_metis_9k115", "rhs_SPG9M_MSV", "rhsgref_cdf_SPG9M", "rhsgref_cdf_b_SPG9M", "rhsgref_ins_SPG9M", "rhsgref_ins_SPG9", "rhsgref_cdf_SPG9", "rhs_D30_at_msv", "rhsgref_cdf_reg_d30_at", "rhs_D30_msv", "rhsgref_cdf_reg_d30", "RHS_ZU23_MSV", "RHSgref_cdf_ZU23", "rhsgref_cdf_b_ZU23", "RHS_M119_D", "RHS_AGS30_TriPod_MSV", "rhsgref_cdf_b_AGS30_TriPod", "RHS_MK19_TriPod_D", "RHS_MK19_TriPod_WD", "rhsgref_cdf_b_Igla_AA_pod", "rhs_Igla_AA_pod_msv", "RHS_Stinger_AA_pod_WD", "RHS_Stinger_AA_pod_D", "rhs_Kornet_9M133_2_vdv", "rhs_Kornet_9M133_2_msv"};
                class CargoCollections
                {
                        class statics_west {
                                transportClear = 1;
                                cargo[] = {{"rhsgref_ins_g_DSHKM_Mini_TriPod", 3, 12}, {"rhsgref_ins_DSHKM", 3, 12}, {"rhsgref_cdf_b_SPG9M", 1, 5}, {"TB_Box_East_Mines_F", 5, 0}};
                        };
                        class statics_east {
                                transportClear = 1;
                                cargo[] = {{"rhs_KORD_MSV", 5, 15}, {"rhs_SPG9M_MSV", 1, 5}, {"TB_Box_East_Mines_F", 5, 0}};
                        };
                        class statics_res {
                                transportClear = 1;
                                cargo[] = {{"rhsgref_ins_DSHKM_Mini_TriPod", 6, 12}, {"rhs_2b14_82mm_msv", 0, 0}, {"rhs_SPG9M_MSV", 0, 0}, {"RHS_ZU23_MSV", 0, 0}, {"TB_Box_East_Mines_F", 0, 0}};
                        };
			class rds_westFO {
				transportClear = 1;
				cargo[] = {{"RHS_M2StaticMG_MiniTripod_D", 2, 4}};
			};

			class rds_eastFO {
				transportClear = 1;
				cargo[] = {{"rhsgref_ins_DSHKM", 2, 4}, {"rhs_2b14_82mm_msv", 1, 3}};
			};
                };
		class Containers
		{
			class ICE_ForwardOutpost_container_WestMG
			{
				crateCollection = "rds_westFO";
				mass = 1750; 
			};

			class ICE_ForwardOutpost_container_EastMG
			{
				crateCollection = "rds_eastFO";
				mass = 1750; 
			};
		};
 
        };
};