class ICE
{
   class assets
   {
      class FO
      {
         maxAllowed = 10;
      };
      class SRP
      {
         maxAllowed = 10;
      };
      class HO
      {
         maxAllowed = 10;
      };
      class TRP
      {
         maxAllowed = 10;
      };
   };
	class vehicles
    {
    class armaments
        {
        startFullyRearmed = 1;
        };
	};
  class zones
  {
    #include "zoneList.hpp"
  };
  class mission
  {
    gameMode = "A&D";
    missionScale = "tiny";
    recommendedTotalPlayers = 10;
    attackingSide = "east"; // required for A&D
	
      class briefings
	{
		class west
		{
		  original = "briefing_blue.hpp";
		};
		class east
		{
		  original = "briefing_red.hpp";
		};
	};
		class factions // or sides
		{
			class faction
			{
				bluFor = "BLU_F";
				opFor = "OPF_G_F";
			};
			class teamName
			{
				bluFor = "Ukraine";
			};
			class teamFlag
			{
				bluFor = "flags\UA.paa";
			};
		};
    class scoring
    {
      class tickets
      {
        // In A&S, specify the tickets per hour, (not total tickets). It will later be scaled by duration.
        // In A&D, specify the tickets per zone. It is usually a 7:5 ratio, for attackers/defenders respectively.
        // In S&D, do not specify any tickets. It is automatically calculated, with the defenders ticket count representing the total caches.
        bluFor = 10;
        opFor = 40;
      };
    };
  };
  class respawn
  {
    class FO
    {
      minSpacingDist = 200;
      maxFriendlySiteDist = 500;
      minZoneDist = 50;
      //minEnemyFBDist = 500;
      //minEnemyBaseDist = 1000;
    };
    class SRP
    {
      maxFriendlySiteDist = 350;
    };
    class HO
    {
      maxFriendlySiteDist = 350;
      minSpacingDist = 250;
    };
		class infantry
		{
			baseDuration = 40;
			class unevenTeamsPenaltyTime
			{
				ratioDuration = 60; // "pivot value" where low player count differences result in small time penalties, 
				// but large differences result in exponential time penalties
				maxDuration = 240;
			};
		};
 class vehicles
		{
            class respawnDelay
			{
                multiplier = 1;
            };
        };
  };
  class gameModes
  {
    class objectives
    {
      class zones
      {
        class captureRates
        {
          // Eg: A higher value (eg: 2 to 3) is ideal for smaller missions.
          heldZoneMultiplier = 1; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate). Eg: 0.25, 0.5, 0.75, 1.0, 1.25, 1.5

          // This value is a cumulative multiplier with 'captureRateMultiplier'. (So if captureRateMultiplier == 2 and neutralZoneCaptureRateMultiplier == 3, then overall rate is 6 times faster.)
          // Eg: A value of 2 is ideal for missions which have very few neutral zones at the start.
          // Eg: A high value (eg: 3 to 6) is ideal for missions which have many neutral zones at the start or for smaller missions.
          neutralZoneMultiplier = 10; // Decimal value between 0 and N. (> 0, < 1 will reduce capture rate), (> 1 will increase capture rate)

          negateNeutral = 1; // set to 1 to make both Multipliers totally independent, not a "cumulative multiplier".
		  
  delayedActivation = 90;
        };
      };
    };
    class AAD
    {
			attackerTicketsPerZoneCapture = 15;
			attackerMaxTotalTickets = 100;
    };
  };
    class gear
    {
        #include "tb_kitDefines.sqh" // Unconfirmed. These files might need to be copied local to mission.
        #include "tb_magazineExclusions.hpp"
	    class NVGogglesForAll
        {
            west = 0;
            east = 0;
            resistance = 0;
            civilian = 0;
        };
    class roles
    {
      #define __unlimited -99
      kits[] =
      {
		#include "factions\BLU_F_roleRatio.hpp"
        #include "factions\OPF_G_F_roleRatio.hpp"
      };
    };
    class armaments
    {
        
      class BLU_F
      {
        defaultGear = "factions\BLU_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\BLU_F_gear.sqh"
        #include "factions\BLU_F_uniforms.sqh"
      };
      class OPF_G_F
      {
        defaultGear = "factions\OPF_G_F.sqh";
        #include "factions\_common_smallItems.sqh"
        #include "factions\OPF_G_F_gear.sqh"
        #include "factions\OPF_G_F_uniforms.sqh"
      };
    };
  };
};
